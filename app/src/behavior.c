/*
 * Copyright (c) 2023 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <zephyr/device.h>
#include <zephyr/init.h>
#include <zephyr/sys/crc.h>
#include <zephyr/sys/util_macro.h>
#include <string.h>

#if IS_ENABLED(CONFIG_ZMK_BEHAVIOR_LOCAL_IDS) &&                                                   \
    IS_ENABLED(CONFIG_ZMK_BEHAVIOR_LOCAL_ID_TYPE_SETTINGS_TABLE)

#include <zephyr/settings/settings.h>

#endif

#include <drivers/behavior.h>
#include <zmk/behavior.h>
#include <zmk/hid.h>
#include <zmk/matrix.h>

#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

const struct device *zmk_behavior_get_binding(const char *name) {
    return behavior_get_binding(name);
}

const struct device *z_impl_behavior_get_binding(const char *name) {
    if (name == NULL || name[0] == '\0') {
        return NULL;
    }

    STRUCT_SECTION_FOREACH(zmk_behavior_ref, item) {
        if (z_device_is_ready(item->device) && item->device->name == name) {
            return item->device;
        }
    }

    STRUCT_SECTION_FOREACH(zmk_behavior_ref, item) {
        if (z_device_is_ready(item->device) && strcmp(item->device->name, name) == 0) {
            return item->device;
        }
    }

    return NULL;
}

#if IS_ENABLED(CONFIG_ZMK_BEHAVIOR_METADATA)

int zmk_behavior_get_empty_param_metadata(const struct device *dev,
                                          struct behavior_parameter_metadata *metadata) {
    metadata->sets_len = 0;
    return 0;
}

#endif // IS_ENABLED(CONFIG_ZMK_BEHAVIOR_METADATA)

#if IS_ENABLED(CONFIG_ZMK_BEHAVIOR_METADATA)
static int validate_hid_usage(uint16_t usage_page, uint16_t usage_id) {
    LOG_DBG("Validate usage %d in page %d", usage_id, usage_page);
    switch (usage_page) {
    case HID_USAGE_KEY:
        if (usage_id == 0 || (usage_id > ZMK_HID_KEYBOARD_NKRO_MAX_USAGE &&
                              usage_id < LEFT_CONTROL && usage_id > RIGHT_GUI)) {
            return -EINVAL;
        }
        break;
    case HID_USAGE_CONSUMER:
        if (usage_id >
            COND_CODE_1(IS_ENABLED(CONFIG_ZMK_HID_CONSUMER_REPORT_USAGES_BASIC), (0xFF), (0xFFF))) {
            return -EINVAL;
        }
        break;
    default:
        LOG_WRN("Unsupported HID usage page %d", usage_page);
        return -EINVAL;
    }

    return 0;
}

int zmk_behavior_validate_param_values(const struct behavior_parameter_value_metadata *values,
                                       size_t values_len, uint32_t param) {
    bool found_match = false;

    if (values_len == 0) {
        return -ENODEV;
    }

    for (int v = 0; v < values_len; v++) {
        const struct behavior_parameter_value_metadata *value_meta = &values[v];

        switch (value_meta->type) {
        case BEHAVIOR_PARAMETER_VALUE_TYPE_NIL:
            if (param == 0) {
                found_match = true;
            }
            break;
        case BEHAVIOR_PARAMETER_VALUE_TYPE_HID_USAGE:
            if (validate_hid_usage(ZMK_HID_USAGE_PAGE(param), ZMK_HID_USAGE_ID(param)) >= 0) {
                found_match = true;
            }

            break;
        case BEHAVIOR_PARAMETER_VALUE_TYPE_LAYER_INDEX:
            if (param >= 0 && param < ZMK_KEYMAP_LEN) {
                found_match = true;
            }
            break;
            /* TODO: Restore with HSV -> RGB refactor
            case BEHAVIOR_PARAMETER_STANDARD_DOMAIN_HSV:
                // TODO: No real way to validate? Maybe max brightness?
                break;
            */
        case BEHAVIOR_PARAMETER_VALUE_TYPE_VALUE:
            if (param == value_meta->value) {
                found_match = true;
            }
            break;
        case BEHAVIOR_PARAMETER_VALUE_TYPE_RANGE:
            if (param >= value_meta->range.min && param <= value_meta->range.max) {
                found_match = true;
            }
            break;
        }

        if (found_match) {
            break;
        }
    }

    return found_match ? 0 : -ENOTSUP;
}

int zmk_behavior_validate_params_metadata(const struct behavior_parameter_metadata *metadata,
                                          uint32_t param1, uint32_t param2) {
    if (!metadata || metadata->sets_len == 0) {
        if (!metadata) {
            LOG_ERR("No metadata to check against");
        }

        return (param1 == 0 && param2 == 0) ? 0 : -ENODEV;
    }

    for (int s = 0; s < metadata->sets_len; s++) {
        const struct behavior_parameter_metadata_set *set = &metadata->sets[s];
        int param1_ret =
            zmk_behavior_validate_param_values(set->param1_values, set->param1_values_len, param1);
        int param2_ret =
            zmk_behavior_validate_param_values(set->param2_values, set->param2_values_len, param2);

        if ((param1_ret >= 0 || (param1_ret == -ENODEV && param1 == 0)) &&
            (param2_ret >= 0 || (param2_ret == -ENODEV && param2 == 0))) {
            LOG_DBG("ALL GOOD!");
            return 0;
        }
    }

    return -EINVAL;
}

#endif // IS_ENABLED(CONFIG_ZMK_BEHAVIOR_METADATA)

int zmk_behavior_validate_binding(const struct zmk_behavior_binding *binding) {
#if IS_ENABLED(CONFIG_ZMK_BEHAVIOR_METADATA)
    const struct device *behavior = zmk_behavior_get_binding(binding->behavior_dev);

    if (!behavior) {
        return -ENODEV;
    }

    struct behavior_parameter_metadata metadata;
    int ret = behavior_get_parameter_metadata(behavior, &metadata);

    if (ret < 0) {
        LOG_WRN("Failed getting metadata for %s: %d", binding->behavior_dev, ret);
        return ret;
    }

    return zmk_behavior_validate_params_metadata(&metadata, binding->param1, binding->param2);
#else
    return 0;
#endif // IS_ENABLED(CONFIG_ZMK_BEHAVIOR_METADATA)
}

#if IS_ENABLED(CONFIG_ZMK_BEHAVIOR_LOCAL_IDS)

zmk_behavior_local_id_t zmk_behavior_get_local_id(const char *name) {
    if (!name) {
        return UINT16_MAX;
    }

    STRUCT_SECTION_FOREACH(zmk_behavior_local_id_map, item) {
        if (z_device_is_ready(item->device) && strcmp(item->device->name, name) == 0) {
            return item->local_id;
        }
    }

    return UINT16_MAX;
}

const char *zmk_behavior_find_behavior_name_from_local_id(zmk_behavior_local_id_t local_id) {
    STRUCT_SECTION_FOREACH(zmk_behavior_local_id_map, item) {
        if (z_device_is_ready(item->device) && item->local_id == local_id) {
            return item->device->name;
        }
    }

    return NULL;
}

#if IS_ENABLED(CONFIG_ZMK_BEHAVIOR_LOCAL_ID_TYPE_CRC16)

static int behavior_local_id_init(void) {
    STRUCT_SECTION_FOREACH(zmk_behavior_local_id_map, item) {
        item->local_id = crc16_ansi(item->device->name, strlen(item->device->name));
    }

    return 0;
}

#elif IS_ENABLED(CONFIG_ZMK_BEHAVIOR_LOCAL_ID_TYPE_SETTINGS_TABLE)

static zmk_behavior_local_id_t largest_local_id = 0;

static int behavior_handle_set(const char *name, size_t len, settings_read_cb read_cb,
                               void *cb_arg) {
    const char *next;

    LOG_DBG("Setting Behavior setting %s", name);

    if (settings_name_steq(name, "local_id", &next) && next) {
        char *endptr;
        uint8_t local_id = strtoul(next, &endptr, 10);
        if (*endptr != '\0') {
            LOG_WRN("Invalid behavior local ID: %s with endptr %s", next, endptr);
            return -EINVAL;
        }

        if (len >= 64) {
            LOG_ERR("Too large binding setting size (got %d expected less than %d)", len, 64);
            return -EINVAL;
        }

        char name[len + 1];

        int err = read_cb(cb_arg, name, len);
        if (err <= 0) {
            LOG_ERR("Failed to handle keymap binding from settings (err %d)", err);
            return err;
        }

        name[len] = '\0';
        STRUCT_SECTION_FOREACH(zmk_behavior_local_id_map, item) {
            if (strcmp(name, item->device->name) == 0) {
                item->local_id = local_id;
                largest_local_id = MAX(largest_local_id, local_id);
                return 0;
            }
        }

        return -EINVAL;
    }

    return 0;
}

static int behavior_handle_commit(void) {
    LOG_DBG("COMMIT!");
    STRUCT_SECTION_FOREACH(zmk_behavior_local_id_map, item) {
        if (item->local_id != 0) {
            LOG_DBG("Has existing id %d", item->local_id);
            continue;
        }

        // TODO: Store it!
        item->local_id = ++largest_local_id;
        LOG_DBG("Generating an ID %d", item->local_id);
        char setting_name[32];
        sprintf(setting_name, "behavior/local_id/%d", item->local_id);
        settings_save_one(setting_name, item->device->name, strlen(item->device->name));
    }

    return 0;
}

SETTINGS_STATIC_HANDLER_DEFINE(behavior, "behavior", NULL, behavior_handle_set,
                               behavior_handle_commit, NULL);

static int behavior_local_id_init(void) {
    // LOAD SETTINGS!
    settings_load_subtree("behavior");
    // TODO: Populate the local IDs from the settings table

    return 0;
}

#else

#error "A behavior local ID mechanism must be selected"

#endif

SYS_INIT(behavior_local_id_init, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);

#endif

#if IS_ENABLED(CONFIG_LOG)
static int check_behavior_names(void) {
    // Behavior names must be unique, but we don't have a good way to enforce this
    // at compile time, so log an error at runtime if they aren't unique.
    ptrdiff_t count;
    STRUCT_SECTION_COUNT(zmk_behavior_ref, &count);

    for (ptrdiff_t i = 0; i < count; i++) {
        const struct zmk_behavior_ref *current;
        STRUCT_SECTION_GET(zmk_behavior_ref, i, &current);

        for (ptrdiff_t j = i + 1; j < count; j++) {
            const struct zmk_behavior_ref *other;
            STRUCT_SECTION_GET(zmk_behavior_ref, j, &other);

            if (strcmp(current->device->name, other->device->name) == 0) {
                LOG_ERR("Multiple behaviors have the same name '%s'", current->device->name);
            }
        }
    }

    return 0;
}

SYS_INIT(check_behavior_names, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);
#endif // IS_ENABLED(CONFIG_LOG)

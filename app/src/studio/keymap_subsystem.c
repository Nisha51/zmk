/*
 * Copyright (c) 2024 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <zephyr/logging/log.h>

LOG_MODULE_DECLARE(zmk_studio, CONFIG_ZMK_STUDIO_LOG_LEVEL);

#include <drivers/behavior.h>

#include <zmk/behavior.h>
#include <zmk/matrix.h>
#include <zmk/keymap.h>
#include <zmk/studio/rpc.h>
#include <zmk/physical_layouts.h>

#include <pb_encode.h>

ZMK_RPC_SUBSYSTEM(keymap)

#define KEYMAP_RESPONSE(type, ...) ZMK_RPC_RESPONSE(keymap, type, __VA_ARGS__)
#define KEYMAP_NOTIFICATION(type, ...) ZMK_RPC_NOTIFICATION(keymap, type, __VA_ARGS__)

static bool encode_layer_bindings(pb_ostream_t *stream, const pb_field_t *field, void *const *arg) {
    const uint8_t layer_idx = *(uint8_t *)*arg;

    for (int b = 0; b < ZMK_KEYMAP_LEN; b++) {
        const struct zmk_behavior_binding *binding =
            zmk_keymap_get_layer_binding_at_idx(layer_idx, b);

        zmk_keymap_BehaviorBinding bb = zmk_keymap_BehaviorBinding_init_zero;

        bb.behavior_id = zmk_behavior_get_local_id(binding->behavior_dev);
        bb.param1 = binding->param1;
        bb.param2 = binding->param2;

        if (!pb_encode_tag_for_field(stream, field)) {
            return false;
        }

        if (!pb_encode_submessage(stream, &zmk_keymap_BehaviorBinding_msg, &bb)) {
            return false;
        }
    }

    return true;
}

static bool encode_layer_name(pb_ostream_t *stream, const pb_field_t *field, void *const *arg) {
    const uint8_t layer_idx = *(uint8_t *)*arg;

    const char *name = zmk_keymap_layer_name(layer_idx);

    if (!name) {
        return true;
    }

    if (!pb_encode_tag_for_field(stream, field)) {
        return false;
    }

    return pb_encode_string(stream, name, strlen(name));
}

static bool encode_keymap_layers(pb_ostream_t *stream, const pb_field_t *field, void *const *arg) {
    for (int l = 0; l < ZMK_KEYMAP_LAYERS_LEN; l++) {

        if (!pb_encode_tag_for_field(stream, field)) {
            LOG_DBG("Failed to encode tag");
            return false;
        }

        zmk_keymap_Layer layer = zmk_keymap_Layer_init_zero;

        layer.name.funcs.encode = encode_layer_name;
        layer.name.arg = &l;

        layer.bindings.funcs.encode = encode_layer_bindings;
        layer.bindings.arg = &l;

        if (!pb_encode_submessage(stream, &zmk_keymap_Layer_msg, &layer)) {
            LOG_DBG("Failed to encode layer submessage");
            return false;
        }
    }

    return true;
}

zmk_Response get_keymap(const zmk_Request *req) {
    zmk_keymap_Keymap resp = zmk_keymap_Keymap_init_zero;

    resp.layers.funcs.encode = encode_keymap_layers;

    return KEYMAP_RESPONSE(get_keymap, resp);
}

zmk_Response set_layer_binding(const zmk_Request *req) {
    const zmk_keymap_SetLayerBindingRequest *set_req =
        &req->subsystem.keymap.request_type.set_layer_binding;

    zmk_behavior_local_id_t bid = set_req->binding.behavior_id;

    const char *behavior_name = zmk_behavior_find_behavior_name_from_local_id(bid);

    if (!behavior_name) {
        return KEYMAP_RESPONSE(set_layer_binding,
                               zmk_keymap_SetLayerBindingResponse_INVALID_BEHAVIOR);
    }

    struct zmk_behavior_binding binding = (struct zmk_behavior_binding){
        .behavior_dev = behavior_name,
        .param1 = set_req->binding.param1,
        .param2 = set_req->binding.param2,
    };

    int ret = zmk_behavior_validate_binding(&binding);
    if (ret < 0) {
        return KEYMAP_RESPONSE(set_layer_binding,
                               zmk_keymap_SetLayerBindingResponse_INVALID_PARAMETERS);
    }

    ret = zmk_keymap_set_layer_binding_at_idx(set_req->layer, set_req->key_position, binding);

    if (ret < 0) {
        LOG_DBG("Setting the binding failed with %d", ret);
        switch (ret) {
        case -EINVAL:
            return KEYMAP_RESPONSE(set_layer_binding,
                                   zmk_keymap_SetLayerBindingResponse_INVALID_LOCATION);
        default:
            return ZMK_RPC_SIMPLE_ERR(GENERIC);
        }
    }

    raise_zmk_studio_rpc_notification((struct zmk_studio_rpc_notification){
        .notification = KEYMAP_NOTIFICATION(unsaved_changes_status_changed, true)});

    return KEYMAP_RESPONSE(set_layer_binding, zmk_keymap_SetLayerBindingResponse_SUCCESS);
}

zmk_Response check_unsaved_changes(const zmk_Request *req) {
    int layout_changes = zmk_physical_layouts_check_unsaved_selection();
    int keymap_changes = zmk_keymap_check_unsaved_changes();

    LOG_DBG("Keymap changes? %d", keymap_changes);
    return KEYMAP_RESPONSE(check_unsaved_changes, layout_changes > 0 || keymap_changes > 0);
}

zmk_Response save_changes(const zmk_Request *req) {
    int ret = zmk_physical_layouts_save_selected();

    if (ret < 0) {
        return ZMK_RPC_SIMPLE_ERR(GENERIC);
    }

    ret = zmk_keymap_save_changes();
    if (ret < 0) {
        return ZMK_RPC_SIMPLE_ERR(GENERIC);
    }

    raise_zmk_studio_rpc_notification((struct zmk_studio_rpc_notification){
        .notification = KEYMAP_NOTIFICATION(unsaved_changes_status_changed, false)});

    return KEYMAP_RESPONSE(save_changes, true);
}

zmk_Response discard_changes(const zmk_Request *req) {
    int ret = zmk_physical_layouts_revert_selected();
    if (ret < 0) {
        return ZMK_RPC_SIMPLE_ERR(GENERIC);
    }

    ret = zmk_keymap_discard_changes();
    if (ret < 0) {
        return ZMK_RPC_SIMPLE_ERR(GENERIC);
    }

    raise_zmk_studio_rpc_notification((struct zmk_studio_rpc_notification){
        .notification = KEYMAP_NOTIFICATION(unsaved_changes_status_changed, false)});

    return KEYMAP_RESPONSE(discard_changes, true);
}

static bool encode_layout_name(pb_ostream_t *stream, const pb_field_t *field, void *const *arg) {
    struct zmk_physical_layout *layout = (struct zmk_physical_layout *)*arg;

    if (!layout->display_name) {
        return true;
    }

    if (!pb_encode_tag_for_field(stream, field)) {
        LOG_WRN("Failed to encode tag");
        return false;
    }

    pb_encode_string(stream, layout->display_name, strlen(layout->display_name));

    return true;
}

static bool encode_layout_keys(pb_ostream_t *stream, const pb_field_t *field, void *const *arg) {
    struct zmk_physical_layout *layout = (struct zmk_physical_layout *)*arg;

    for (int kp = 0; kp < layout->keys_len; kp++) {
        const struct zmk_key_physical_attrs *layout_kp = &layout->keys[kp];

        if (!pb_encode_tag_for_field(stream, field)) {
            LOG_DBG("Failed to encode tag");
            return false;
        }

        zmk_keymap_KeyPhysicalAttrs layout_kp_msg = {
            .width = layout_kp->width,
            .height = layout_kp->height,
            .x = layout_kp->x,
            .y = layout_kp->y,
            .r = layout_kp->r,
            .rx = layout_kp->rx,
            .ry = layout_kp->ry,
        };

        if (!pb_encode_submessage(stream, &zmk_keymap_KeyPhysicalAttrs_msg, &layout_kp_msg)) {
            LOG_WRN("Failed to encode layout key position submessage");
            return false;
        }
    }
    return true;
}

static bool encode_layouts(pb_ostream_t *stream, const pb_field_t *field, void *const *arg) {
    struct zmk_physical_layout const *const *layouts;
    const size_t layout_count = zmk_physical_layouts_get_list(&layouts);

    for (int i = 0; i < layout_count; i++) {
        const struct zmk_physical_layout *l = layouts[i];

        if (!pb_encode_tag_for_field(stream, field)) {
            LOG_DBG("Failed to encode tag");
            return false;
        }

        zmk_keymap_PhysicalLayout layout = zmk_keymap_PhysicalLayout_init_zero;

        layout.name.funcs.encode = encode_layout_name;
        layout.name.arg = l;

        layout.keys.funcs.encode = encode_layout_keys;
        layout.keys.arg = l;

        if (!pb_encode_submessage(stream, &zmk_keymap_PhysicalLayout_msg, &layout)) {
            LOG_WRN("Failed to encode layout submessage");
            return false;
        }
    }

    return true;
}

zmk_Response get_physical_layouts(const zmk_Request *req) {
    zmk_keymap_PhysicalLayouts resp = zmk_keymap_PhysicalLayouts_init_zero;
    resp.active_layout_index = zmk_physical_layouts_get_selected();
    resp.layouts.funcs.encode = encode_layouts;
    return KEYMAP_RESPONSE(get_physical_layouts, resp);
}

static void migrate_keymap(const uint8_t old) {
    int new = zmk_physical_layouts_get_selected();

    uint32_t new_to_old_map[ZMK_KEYMAP_LEN];
    int layout_size = zmk_physical_layouts_get_position_map(old, new, new_to_old_map);

    if (layout_size < 0) {
        return;
    }

    for (int l = 0; l < ZMK_KEYMAP_LAYERS_LEN; l++) {
        struct zmk_behavior_binding new_layer[ZMK_KEYMAP_LEN];

        for (int b = 0; b < layout_size; b++) {
            uint32_t old_b = new_to_old_map[b];

            if (old_b == UINT32_MAX) {
                memset(&new_layer[b], 0, sizeof(struct zmk_behavior_binding));
                continue;
            }

            const struct zmk_behavior_binding *binding =
                zmk_keymap_get_layer_binding_at_idx(l, old_b);

            if (!binding) {
                memset(&new_layer[b], 0, sizeof(struct zmk_behavior_binding));
                continue;
            }

            memcpy(&new_layer[b], binding, sizeof(struct zmk_behavior_binding));
        }

        for (int b = 0; b < layout_size; b++) {
            zmk_keymap_set_layer_binding_at_idx(l, b, new_layer[b]);
        }
    }

    // TODO: Migrate combos?
}

zmk_Response set_active_physical_layout(const zmk_Request *req) {
    uint8_t index = (uint8_t)req->subsystem.keymap.request_type.set_active_physical_layout;
    int old = zmk_physical_layouts_get_selected();

    zmk_keymap_SetActivePhysicalLayoutResponse resp =
        zmk_keymap_SetActivePhysicalLayoutResponse_init_zero;
    resp.which_result = zmk_keymap_SetActivePhysicalLayoutResponse_ok_tag;
    resp.result.ok.layers.funcs.encode = encode_keymap_layers;

    if (old == index) {
        return KEYMAP_RESPONSE(set_active_physical_layout, resp);
    }

    int ret = zmk_physical_layouts_select(index);
    if (ret >= 0) {
        migrate_keymap(old);
    } else {
        resp.which_result = zmk_keymap_SetActivePhysicalLayoutResponse_err_tag;
        resp.result.err = zmk_keymap_SetActivePhysicalLayoutErrorCode_GENERIC;
    }

    raise_zmk_studio_rpc_notification((struct zmk_studio_rpc_notification){
        .notification = KEYMAP_NOTIFICATION(unsaved_changes_status_changed, true)});

    return KEYMAP_RESPONSE(set_active_physical_layout, resp);
}

ZMK_RPC_SUBSYSTEM_HANDLER(keymap, get_keymap, true);
ZMK_RPC_SUBSYSTEM_HANDLER(keymap, set_layer_binding, true);
ZMK_RPC_SUBSYSTEM_HANDLER(keymap, check_unsaved_changes, true);
ZMK_RPC_SUBSYSTEM_HANDLER(keymap, save_changes, true);
ZMK_RPC_SUBSYSTEM_HANDLER(keymap, discard_changes, true);
ZMK_RPC_SUBSYSTEM_HANDLER(keymap, get_physical_layouts, true);
ZMK_RPC_SUBSYSTEM_HANDLER(keymap, set_active_physical_layout, true);

static int event_mapper(const zmk_event_t *eh, zmk_Notification *n) { return 0; }

ZMK_RPC_EVENT_MAPPER(keymap, event_mapper);

/*
 *
 * Copyright (c) 2023 Collin Hodge
 * Copyright (c) 2023 The ZMK Contributors
 * SPDX-License-Identifier: MIT
 *
 */

#include <lvgl.h>

#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_BALLOON
#define LV_ATTRIBUTE_IMG_BALLOON
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_BALLOON uint8_t
    balloon_map[] = {
#if CONFIG_NICE_VIEW_WIDGET_INVERTED
        0xff, 0xff, 0xff, 0xff, /*Color of index 0*/
        0x00, 0x00, 0x00, 0xff, /*Color of index 1*/
#else
        0x00, 0x00, 0x00, 0xff, /*Color of index 0*/
        0xff, 0xff, 0xff, 0xff, /*Color of index 1*/
#endif

  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xfa, 0xaf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xd5, 0x55, 0x7e, 0xaa, 0xaa, 0xf5, 0xff, 0xeb, 0xd7, 0xaf, 0xff, 0x5f, 0xfd, 0x7f, 0xc0, 0x00, 
  0x00, 0x7f, 0xd5, 0x55, 0x5d, 0x55, 0x55, 0x7a, 0xff, 0xd5, 0xab, 0xd7, 0xfe, 0xbf, 0xfd, 0x7f, 0xc0, 0x00, 
  0x00, 0x7f, 0xaa, 0xaa, 0xbe, 0xaa, 0xaa, 0xf5, 0xff, 0xeb, 0xd7, 0x57, 0xff, 0x5f, 0xfd, 0x7f, 0xc0, 0x00, 
  0x00, 0x7f, 0xea, 0xaa, 0xaf, 0x55, 0x55, 0x75, 0x7f, 0xd5, 0x55, 0xaf, 0xfe, 0xaf, 0xfa, 0xbf, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xfd, 0x5f, 0xfe, 0xaa, 0xfa, 0xff, 0xeb, 0xd7, 0x57, 0xff, 0x5f, 0xfd, 0x7f, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xfe, 0xaf, 0xfa, 0xab, 0xf5, 0x7f, 0xd5, 0x55, 0xaf, 0xfe, 0xaf, 0xfa, 0xbf, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0x5f, 0xff, 0x57, 0xfa, 0xaa, 0xab, 0xd7, 0x57, 0xff, 0x55, 0x55, 0x7f, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xfe, 0xaf, 0xfa, 0xaf, 0xf5, 0x55, 0x55, 0x55, 0xaf, 0xfe, 0xaa, 0xaa, 0xbf, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0x5f, 0xfd, 0x5f, 0xfa, 0xaa, 0xab, 0xab, 0x57, 0xff, 0x55, 0x55, 0x7f, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xfe, 0xaf, 0xea, 0xbf, 0xea, 0xaa, 0xaa, 0xd5, 0xaf, 0xfe, 0xaa, 0xaa, 0xbf, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0x5f, 0xf5, 0x7f, 0xf5, 0x55, 0x55, 0xab, 0x57, 0xff, 0x55, 0x55, 0x7f, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xfe, 0xaf, 0xaa, 0xff, 0xfa, 0xbe, 0xaa, 0xaa, 0xab, 0xfe, 0xab, 0xea, 0xbf, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0x5f, 0xd5, 0x7f, 0xf5, 0x7f, 0xd5, 0xd5, 0x57, 0xff, 0x5f, 0xfd, 0x7f, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xfa, 0xae, 0xaa, 0xaf, 0xfa, 0xff, 0xea, 0xaa, 0xaa, 0xfe, 0xaf, 0xfa, 0xbf, 0xc0, 0x00, 
  0x00, 0x7f, 0xd5, 0x55, 0x5f, 0x55, 0x55, 0x75, 0x7f, 0xd5, 0xd5, 0x55, 0x5f, 0x5f, 0xfd, 0x7f, 0xc0, 0x00, 
  0x00, 0x7f, 0xd5, 0x55, 0x5e, 0xaa, 0xaa, 0xfa, 0xff, 0xeb, 0xaa, 0xaa, 0xae, 0xaf, 0xfa, 0xbf, 0xc0, 0x00, 
  0x00, 0x7f, 0xaa, 0xaa, 0xbf, 0x55, 0x55, 0x75, 0xff, 0xd5, 0xea, 0xaa, 0xaf, 0x5f, 0xfd, 0x7f, 0xc0, 0x00, 
  0x00, 0x7f, 0xd5, 0x55, 0x7e, 0xaa, 0xaa, 0xfa, 0xff, 0xeb, 0xf5, 0x55, 0x5e, 0xbf, 0xfd, 0x7f, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
};

const lv_img_dsc_t balloon = {
    .header.cf = LV_IMG_CF_INDEXED_1BIT,
    .header.always_zero = 0,
    .header.reserved = 0,
    .header.w = 140,
    .header.h = 68,
    .data_size = 1232,
    .data = balloon_map,
};

#ifndef LV_ATTRIBUTE_IMG_MOUNTAIN
#define LV_ATTRIBUTE_IMG_MOUNTAIN
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_MOUNTAIN uint8_t
    mountain_map[] = {
#if CONFIG_NICE_VIEW_WIDGET_INVERTED
        0xff, 0xff, 0xff, 0xff, /*Color of index 0*/
        0x00, 0x00, 0x00, 0xff, /*Color of index 1*/
#else
        0x00, 0x00, 0x00, 0xff, /*Color of index 0*/
        0xff, 0xff, 0xff, 0xff, /*Color of index 1*/
#endif

  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xfa, 0xaf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xd5, 0x55, 0x7e, 0xaa, 0xaa, 0xf5, 0xff, 0xeb, 0xd7, 0xaf, 0xff, 0x5f, 0xfd, 0x7f, 0xc0, 0x00, 
  0x00, 0x7f, 0xd5, 0x55, 0x5d, 0x55, 0x55, 0x7a, 0xff, 0xd5, 0xab, 0xd7, 0xfe, 0xbf, 0xfd, 0x7f, 0xc0, 0x00, 
  0x00, 0x7f, 0xaa, 0xaa, 0xbe, 0xaa, 0xaa, 0xf5, 0xff, 0xeb, 0xd7, 0x57, 0xff, 0x5f, 0xfd, 0x7f, 0xc0, 0x00, 
  0x00, 0x7f, 0xea, 0xaa, 0xaf, 0x55, 0x55, 0x75, 0x7f, 0xd5, 0x55, 0xaf, 0xfe, 0xaf, 0xfa, 0xbf, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xfd, 0x5f, 0xfe, 0xaa, 0xfa, 0xff, 0xeb, 0xd7, 0x57, 0xff, 0x5f, 0xfd, 0x7f, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xfe, 0xaf, 0xfa, 0xab, 0xf5, 0x7f, 0xd5, 0x55, 0xaf, 0xfe, 0xaf, 0xfa, 0xbf, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0x5f, 0xff, 0x57, 0xfa, 0xaa, 0xab, 0xd7, 0x57, 0xff, 0x55, 0x55, 0x7f, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xfe, 0xaf, 0xfa, 0xaf, 0xf5, 0x55, 0x55, 0x55, 0xaf, 0xfe, 0xaa, 0xaa, 0xbf, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0x5f, 0xfd, 0x5f, 0xfa, 0xaa, 0xab, 0xab, 0x57, 0xff, 0x55, 0x55, 0x7f, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xfe, 0xaf, 0xea, 0xbf, 0xea, 0xaa, 0xaa, 0xd5, 0xaf, 0xfe, 0xaa, 0xaa, 0xbf, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0x5f, 0xf5, 0x7f, 0xf5, 0x55, 0x55, 0xab, 0x57, 0xff, 0x55, 0x55, 0x7f, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xfe, 0xaf, 0xaa, 0xff, 0xfa, 0xbe, 0xaa, 0xaa, 0xab, 0xfe, 0xab, 0xea, 0xbf, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0x5f, 0xd5, 0x7f, 0xf5, 0x7f, 0xd5, 0xd5, 0x57, 0xff, 0x5f, 0xfd, 0x7f, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xfa, 0xae, 0xaa, 0xaf, 0xfa, 0xff, 0xea, 0xaa, 0xaa, 0xfe, 0xaf, 0xfa, 0xbf, 0xc0, 0x00, 
  0x00, 0x7f, 0xd5, 0x55, 0x5f, 0x55, 0x55, 0x75, 0x7f, 0xd5, 0xd5, 0x55, 0x5f, 0x5f, 0xfd, 0x7f, 0xc0, 0x00, 
  0x00, 0x7f, 0xd5, 0x55, 0x5e, 0xaa, 0xaa, 0xfa, 0xff, 0xeb, 0xaa, 0xaa, 0xae, 0xaf, 0xfa, 0xbf, 0xc0, 0x00, 
  0x00, 0x7f, 0xaa, 0xaa, 0xbf, 0x55, 0x55, 0x75, 0xff, 0xd5, 0xea, 0xaa, 0xaf, 0x5f, 0xfd, 0x7f, 0xc0, 0x00, 
  0x00, 0x7f, 0xd5, 0x55, 0x7e, 0xaa, 0xaa, 0xfa, 0xff, 0xeb, 0xf5, 0x55, 0x5e, 0xbf, 0xfd, 0x7f, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
};

const lv_img_dsc_t mountain = {
    .header.cf = LV_IMG_CF_INDEXED_1BIT,
    .header.always_zero = 0,
    .header.reserved = 0,
    .header.w = 140,
    .header.h = 68,
    .data_size = 1232,
    .data = mountain_map,
};

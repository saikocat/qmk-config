// Copyright 2022 saikocat (@saikocat)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#undef EE_HANDS

#define TAPPING_TERM 175

// #define DEBUG_MATRIX_SCAN_RATE

/* Mod tap settings */
// #define PERMISSIVE_HOLD_PER_KEY
// #define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
// #define TAPPING_FORCE_HOLD_PER_KEY

/* RGBLight Underglow */


/* OLED */
#if defined(OLED_ENABLE)
// #define OLED_DISABLE_TIMEOUT
#   define OLED_IDLE_THRESHOLD 30000U
#   define SPLIT_OLED_ENABLE
#endif

/* One Shot */
#define ONESHOT_TAP_TOGGLE 5
#define ONESHOT_TIMEOUT 3000

/* Combo */
#if defined(COMBO_ENABLE)
#    define COMBO_TERM 25
#    define COMBO_ONLY_FROM_LAYER 0
#    define COMBO_SHOULD_TRIGGER
#endif


/* Pointing Device: Cirque Trackpad */
// #define SPLIT_POINTING_ENABLE
//
// #define POINTING_DEVICE_RIGHT
// #define POINTING_DEVICE_ROTATION_90
// #define POINTING_DEVICE_INVERT_X
// #define POINTING_DEVICE_INVERT_Y
// #define POINTING_DEVICE_TASK_THROTTLE_MS 10
// #define POINTING_DEVICE_GESTURES_SCROLL_ENABLE
// #define POINTING_DEVICE_GESTURES_CURSOR_GLIDE_ENABLE
//
// #define CIRQUE_PINNACLE_DIAMETER_MM 35
// #define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_ABSOLUTE_MODE
// #define CIRQUE_PINNACLE_TAP_ENABLE

/* Split Data Sync Options */
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_MODS_ENABLE
// #define SPLIT_WPM_ENABLE

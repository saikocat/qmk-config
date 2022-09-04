// Copyright 2022 saikocat (@saikocat)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* Key matrix size */
#define MATRIX_COLS 6
#define MATRIX_ROWS 7

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: pins used for columns, left to right
 * ROWS: pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
#define MATRIX_COL_PINS \
    { D4, C6, D7, E6, B4, B5 }
#define MATRIX_ROW_PINS \
    { F4, F5, F6, F7, B1, B3, B2 }

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

/* RGB Underglow */
#define RGB_DI_PIN D3

#ifdef RGBLIGHT_ENABLE
#    define RGBLED_NUM 11
#    define RGBLIGHT_HUE_STEP 8
#    define RGBLIGHT_SAT_STEP 8
#    define RGBLIGHT_VAL_STEP 8
#    define RGBLIGHT_SLEEP

#    define RGBLIGHT_DEFAULT_HUE 224
#    define RGBLIGHT_DEFAULT_SAT 231
#    define RGBLIGHT_DEFAULT_VAL 128
#    define RGBLIGHT_LIMIT_VAL 128
#endif

/* Conversion to Pin Compatible ProMicro MCUs */
#if defined(CONVERT_TO_KB2040) || defined(CONVERT_TO_PROMICRO_RP2040)
#    define RP2040_BOOTLOADER_DOUBLE_TAP_RESET               // Activates the double-tap behavior
#    define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U // Timeout window in ms in which the double tap can occur.

/* I2C Pin mapping (OLED) */
#    define I2C_DRIVER I2CD2
#    define I2C1_SDA_PIN D1 // GP2
#    define I2C1_SCL_PIN D0 // GP3

/* WS2812 LED subsystem driver */
#    define WS2812_PIO_USE_PIO1
#endif

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* OLED */
#ifdef OLED_ENABLE
#    define OLED_DISPLAY_128X32
#    define OLED_UPDATE_INTERVAL 30
#    define OLED_BRIGHTNESS 128
#endif

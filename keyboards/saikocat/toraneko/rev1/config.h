// Copyright 2022 saikocat (@saikocat)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* Key matrix size */
/* Rows are doubled up */
#define MATRIX_ROWS 8
#define MATRIX_COLS 6

/* Split Comm */
#define USE_SERIAL
#define SELECT_SOFT_SERIAL_SPEED 0

/* Side detection / handedness */
#define SPLIT_HAND_PIN B2

/* CRC. */
#define CRC8_USE_TABLE
#define CRC8_OPTIMIZE_SPEED

/* Conversion to Pin Compatible ProMicro MCUs */
#if defined(CONVERT_TO_KB2040) || defined(CONVERT_TO_PROMICRO_RP2040)
#    define RP2040_BOOTLOADER_DOUBLE_TAP_RESET               // Activates the double-tap behavior
#    define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U // Timeout window in ms in which the double tap can occur.

#    undef EE_HANDS

#    define SPLIT_USB_DETECT
#    define SPLIT_USB_TIMEOUT 2000
#    define SPLIT_USB_TIMEOUT_POLL 10

/* Serial driver with PIO subsystem */
#    define SERIAL_PIO_USE_PIO1

/* I2C Pin mapping (OLED) */
#    define I2C_DRIVER I2CD2
#    define I2C1_SDA_PIN D1 // GP2
#    define I2C1_SCL_PIN D0 // GP3
#endif

/* OLED */
#ifdef OLED_ENABLE
#    define OLED_DISPLAY_128X32
#    define OLED_UPDATE_INTERVAL 100
#    define OLED_BRIGHTNESS 128
#    define SPLIT_OLED_ENABLE
#endif

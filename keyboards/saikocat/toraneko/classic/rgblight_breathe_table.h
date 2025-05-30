// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

/*******************************************************************************
  88888888888 888      d8b                .d888 d8b 888               d8b
      888     888      Y8P               d88P"  Y8P 888               Y8P
      888     888                        888        888
      888     88888b.  888 .d8888b       888888 888 888  .d88b.       888 .d8888b
      888     888 "88b 888 88K           888    888 888 d8P  Y8b      888 88K
      888     888  888 888 "Y8888b.      888    888 888 88888888      888 "Y8888b.
      888     888  888 888      X88      888    888 888 Y8b.          888      X88
      888     888  888 888  88888P'      888    888 888  "Y8888       888  88888P'
                                                        888                 888
                                                        888                 888
                                                        888                 888
     .d88b.   .d88b.  88888b.   .d88b.  888d888 8888b.  888888 .d88b.   .d88888
    d88P"88b d8P  Y8b 888 "88b d8P  Y8b 888P"      "88b 888   d8P  Y8b d88" 888
    888  888 88888888 888  888 88888888 888    .d888888 888   88888888 888  888
    Y88b 888 Y8b.     888  888 Y8b.     888    888  888 Y88b. Y8b.     Y88b 888
     "Y88888  "Y8888  888  888  "Y8888  888    "Y888888  "Y888 "Y8888   "Y88888
         888
    Y8b d88P
     "Y88P"
*******************************************************************************/

#pragma once
// clang-format off
#define RGBLIGHT_EFFECT_BREATHE_TABLE

// Breathing center: 1.86
// Breathing max:    64

const uint8_t PROGMEM rgblight_effect_breathe_table[] = {
#if RGBLIGHT_BREATHE_TABLE_SIZE == 256
    0x08, 0x08, 0x09, 0x09, 0x09, 0x0A, 0x0A, 0x0B,
    0x0B, 0x0B, 0x0C, 0x0C, 0x0C, 0x0D, 0x0D, 0x0E,
    0x0E, 0x0E, 0x0F, 0x0F, 0x10, 0x10, 0x10, 0x11,
    0x11, 0x12, 0x12, 0x13, 0x13, 0x13, 0x14, 0x14,
    0x15, 0x15, 0x16, 0x16, 0x17, 0x17, 0x18, 0x18,
    0x19, 0x19, 0x1A, 0x1A, 0x1A, 0x1B, 0x1B, 0x1C,
    0x1C, 0x1D, 0x1D, 0x1E, 0x1E, 0x1F, 0x1F, 0x20,
    0x20, 0x21, 0x21, 0x22, 0x22, 0x23, 0x23, 0x24,
    0x24, 0x25, 0x25, 0x26, 0x26, 0x27, 0x27, 0x28,
    0x28, 0x28, 0x29, 0x29, 0x2A, 0x2A, 0x2B, 0x2B,
    0x2C, 0x2C, 0x2C, 0x2D, 0x2D, 0x2E, 0x2E, 0x2E,
    0x2F, 0x2F, 0x30, 0x30, 0x30, 0x31, 0x31, 0x31,
    0x32, 0x32, 0x32, 0x33, 0x33, 0x33, 0x33, 0x34,
    0x34, 0x34, 0x34, 0x35, 0x35, 0x35, 0x35, 0x35,
    0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36,
    0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37,
    0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37,
    0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36,
    0x35, 0x35, 0x35, 0x35, 0x35, 0x34, 0x34, 0x34,
    0x34, 0x33, 0x33, 0x33, 0x33, 0x32, 0x32, 0x32,
    0x31, 0x31, 0x31, 0x30, 0x30, 0x30, 0x2F, 0x2F,
    0x2E, 0x2E, 0x2E, 0x2D, 0x2D, 0x2C, 0x2C, 0x2C,
    0x2B, 0x2B, 0x2A, 0x2A, 0x29, 0x29, 0x28, 0x28,
    0x28, 0x27, 0x27, 0x26, 0x26, 0x25, 0x25, 0x24,
    0x24, 0x23, 0x23, 0x22, 0x22, 0x21, 0x21, 0x20,
    0x20, 0x1F, 0x1F, 0x1E, 0x1E, 0x1D, 0x1D, 0x1C,
    0x1C, 0x1B, 0x1B, 0x1A, 0x1A, 0x1A, 0x19, 0x19,
    0x18, 0x18, 0x17, 0x17, 0x16, 0x16, 0x15, 0x15,
    0x14, 0x14, 0x13, 0x13, 0x13, 0x12, 0x12, 0x11,
    0x11, 0x10, 0x10, 0x10, 0x0F, 0x0F, 0x0E, 0x0E,
    0x0E, 0x0D, 0x0D, 0x0C, 0x0C, 0x0C, 0x0B, 0x0B,
    0x0B, 0x0A, 0x0A, 0x09, 0x09, 0x09, 0x08, 0x08
#endif

#if RGBLIGHT_BREATHE_TABLE_SIZE == 128
    0x08, 0x09, 0x09, 0x0A,
    0x0B, 0x0C, 0x0C, 0x0D,
    0x0E, 0x0F, 0x10, 0x10,
    0x11, 0x12, 0x13, 0x14,
    0x15, 0x16, 0x17, 0x18,
    0x19, 0x1A, 0x1A, 0x1B,
    0x1C, 0x1D, 0x1E, 0x1F,
    0x20, 0x21, 0x22, 0x23,
    0x24, 0x25, 0x26, 0x27,
    0x28, 0x29, 0x2A, 0x2B,
    0x2C, 0x2C, 0x2D, 0x2E,
    0x2F, 0x30, 0x30, 0x31,
    0x32, 0x32, 0x33, 0x33,
    0x34, 0x34, 0x35, 0x35,
    0x36, 0x36, 0x36, 0x36,
    0x37, 0x37, 0x37, 0x37,
    0x37, 0x37, 0x37, 0x37,
    0x36, 0x36, 0x36, 0x36,
    0x35, 0x35, 0x35, 0x34,
    0x34, 0x33, 0x33, 0x32,
    0x31, 0x31, 0x30, 0x2F,
    0x2E, 0x2E, 0x2D, 0x2C,
    0x2B, 0x2A, 0x29, 0x28,
    0x28, 0x27, 0x26, 0x25,
    0x24, 0x23, 0x22, 0x21,
    0x20, 0x1F, 0x1E, 0x1D,
    0x1C, 0x1B, 0x1A, 0x19,
    0x18, 0x17, 0x16, 0x15,
    0x14, 0x13, 0x13, 0x12,
    0x11, 0x10, 0x0F, 0x0E,
    0x0E, 0x0D, 0x0C, 0x0B,
    0x0B, 0x0A, 0x09, 0x08
#endif

#if RGBLIGHT_BREATHE_TABLE_SIZE == 64
    0x08, 0x09,
    0x0B, 0x0C,
    0x0E, 0x10,
    0x11, 0x13,
    0x15, 0x17,
    0x19, 0x1A,
    0x1C, 0x1E,
    0x20, 0x22,
    0x24, 0x26,
    0x28, 0x2A,
    0x2C, 0x2D,
    0x2F, 0x30,
    0x32, 0x33,
    0x34, 0x35,
    0x36, 0x36,
    0x37, 0x37,
    0x37, 0x37,
    0x36, 0x36,
    0x35, 0x35,
    0x34, 0x33,
    0x31, 0x30,
    0x2E, 0x2D,
    0x2B, 0x29,
    0x28, 0x26,
    0x24, 0x22,
    0x20, 0x1E,
    0x1C, 0x1A,
    0x18, 0x16,
    0x14, 0x13,
    0x11, 0x0F,
    0x0E, 0x0C,
    0x0B, 0x09
#endif
};

static const int table_scale = 256 / sizeof(rgblight_effect_breathe_table);


// Copyright 2024 saikocat (@saikocat)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _DEFAULT = 0,
};

#ifdef COMBO_ENABLE
const uint16_t PROGMEM esc_combo[] = {KC_A, KC_B, COMBO_END};

combo_t key_combos[] = {
    COMBO(esc_combo, KC_ESC),
};
#endif

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT_split_3x5x1_3(
        KC_A, KC_B, KC_C, KC_D, KC_E,                    S(KC_E), S(KC_D), S(KC_C), S(KC_B), S(KC_A),
        KC_F, KC_G, KC_H, KC_I, KC_J,                    S(KC_J), S(KC_I), S(KC_H), S(KC_G), S(KC_F),
        KC_K, KC_L, KC_M, KC_N, KC_O,                    S(KC_O), S(KC_N), S(KC_M), S(KC_L), S(KC_K),
        KC_Z,             KC_P, KC_Q, KC_R,     S(KC_R), S(KC_Q), S(KC_P),                   S(KC_Z)
    )
};
// clang-format on

/* Debug enable */
void keyboard_post_init_user(void) {
    debug_enable   = true;
    debug_matrix   = true;
    debug_keyboard = true;
    debug_mouse    = true;
}

/* Disable internal pullups - from @daskygit */
#if defined(DEBUG_USER_DISABLE_INTERNAL_PULLUP_RP2040)
#    include "pico/bootrom.h"
void i2c_init(void) {
    static bool is_initialised = false;
    if (!is_initialised) {
        is_initialised = true;

        // Try releasing special pins for a short time
        palSetLineMode(I2C1_SCL_PIN, PAL_MODE_INPUT);
        palSetLineMode(I2C1_SDA_PIN, PAL_MODE_INPUT);

        chThdSleepMilliseconds(10);

        palSetLineMode(I2C1_SCL_PIN, PAL_MODE_ALTERNATE_I2C | PAL_RP_PAD_SLEWFAST | PAL_RP_PAD_DRIVE4);
        palSetLineMode(I2C1_SDA_PIN, PAL_MODE_ALTERNATE_I2C | PAL_RP_PAD_SLEWFAST | PAL_RP_PAD_DRIVE4);
    }
}
#endif

/* OLED asymmetrical
 * - https://gist.github.com/drashna/79d14917f98f07e73071cbb391fcb654
 */

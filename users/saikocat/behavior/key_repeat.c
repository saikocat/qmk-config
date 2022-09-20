// Copyright 2022 saikocat (@saikocat)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "declarations.h"
#include "behavior/key_repeat.h"

__attribute__((weak)) uint16_t get_repeat_keycode(void) {
    return UK_REPEAT;
}

// Repeat function
// https://gist.github.com/NotGate/3e3d8ab81300a86522b2c2549f99b131

// Used to extract the basic tapping keycode from a dual-role key.
// Example: GET_TAP_KC(MT(MOD_RSFT, KC_E)) == KC_E
#define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF

uint16_t last_keycode     = KC_NO;
uint8_t  last_modifier    = 0;
uint16_t pressed_keycode  = KC_NO;
uint16_t pressed_modifier = 0;

bool process_repeat_key(uint16_t keycode, const keyrecord_t *record) {
    if (keycode != get_repeat_keycode()) {
        // Early return when holding down a pure layer key
        // to retain modifiers
        switch (keycode) {
            case QK_DEF_LAYER ... QK_DEF_LAYER_MAX:
            case QK_MOMENTARY ... QK_MOMENTARY_MAX:
            case QK_LAYER_MOD ... QK_LAYER_MOD_MAX:
            case QK_ONE_SHOT_LAYER ... QK_ONE_SHOT_LAYER_MAX:
            case QK_TOGGLE_LAYER ... QK_TOGGLE_LAYER_MAX:
            case QK_TO ... QK_TO_MAX:
            case QK_LAYER_TAP_TOGGLE ... QK_LAYER_TAP_TOGGLE_MAX:
            case QK_MODS ... QK_MODS_MAX:
                return true;
        }
        if (record->event.pressed) {
            last_modifier = get_mods() | get_oneshot_mods();
            switch (keycode) {
                case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
                case QK_MOD_TAP ... QK_MOD_TAP_MAX:
                    last_keycode = GET_TAP_KC(keycode);
                    break;
                default:
                    last_keycode = keycode;
                    break;
            }
        }
    } else { // keycode == UK_REPEAT
        if (record->event.pressed) {
            pressed_keycode  = last_keycode;
            pressed_modifier = last_modifier;
            register_mods(pressed_modifier);
            register_code16(pressed_keycode);
            unregister_mods(pressed_modifier);
        } else {
            unregister_code16(pressed_keycode);
        }
        return false;
    }
    return true;
}

// Copyright 2024 saikocat (@saikocat)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "action_layer.h"
#include "keycodes.h"
#include QMK_KEYBOARD_H

// #include "sync_timer.h"

// clang-format off
enum layer {
    _QWERTY = 0,
    _COLEMAK_DH,
    _GAME_OVERWATCH,
    _GAME_NUMPAD,

    _LOWER,
    _RAISE,
    _NAV_LEFT,
    _NUMPAD,
    _ADJUST,

    _SPECIAL,

    _SYMBOL,
    _NAV    = _RAISE,
    _FUNC   = _ADJUST,
};

enum userspace_custom_keycodes {
    QMK_BEST = SAFE_RANGE,

    UK_BRACES,
    UK_CLEAR,
    UK_REPEAT,

    DEL_LWR  = LT(_LOWER,   KC_DEL),
    ENT_NUM  = LT(_NUMPAD,  KC_ENT),
    BSPC_NUM = LT(_NUMPAD,  KC_BSPC),
    TAB_RSE  = LT(_RAISE,   KC_TAB),
    ESC_ADJ  = LT(_ADJUST,  KC_ESC),
    ENT_ADJ  = LT(_ADJUST,  KC_ENT),

    Z_ALT  = MT(MOD_LALT, KC_Z),
    ESC_ALT  = MT(MOD_LALT, KC_ESC),
    QUOT_CTL = MT(MOD_RCTL, KC_QUOTE),
    BSPC_SFT = MT(MOD_LSFT, KC_BSPC),
    ENT_SFT  = MT(MOD_RSFT, KC_ENTER),

    OSM_LGUI = OSM(MOD_LGUI),
    OSM_LALT = OSM(MOD_LALT),
    OSM_LSFT = OSM(MOD_LSFT),
    OSM_LCTL = OSM(MOD_LCTL),

    NEW_SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_split_3x5x1_3(
        KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                         KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
        KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                         KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,
        KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                         KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,
        KC_LCTL,                      DEL_LWR,  BSPC_NUM, OSM_LSFT,           ENT_ADJ,  KC_SPC,   TAB_RSE            ,QUOT_CTL
    ),

    [_COLEMAK_DH] = LAYOUT_split_3x5x1_3(
        KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,                         KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,
        KC_A,     KC_R,     KC_S,     KC_T,     KC_G,                         KC_M,     KC_N,     KC_E,     KC_I,     KC_O,
        KC_Z,     KC_X,     KC_C,     KC_D,     KC_V,                         KC_K,     KC_H,     KC_COMM,  KC_DOT,   KC_SLSH,
        OSM_LCTL,                     DEL_LWR, BSPC_NUM, OSM_LSFT,            ENT_ADJ,  KC_SPC,   TAB_RSE            ,QUOT_CTL
    ),

    [_GAME_OVERWATCH] = LAYOUT_split_3x5x1_3(
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
        KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,
        KC_RSFT,  KC_Z,     KC_X,     KC_C,     KC_V,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,
        KC_RSFT,  MO(_GAME_NUMPAD), KC_SPC,   ESC_ALT,              ENT_ADJ,  KC_ESC,   TAB_RSE,             _______
    ),

    [_GAME_NUMPAD] = LAYOUT_split_3x5x1_3(
        C(KC_3),  C(KC_2),  C(KC_1),  C(KC_0),  C(KC_4),            _______,  _______,  _______,  _______,  _______,
        KC_3,     KC_2,     KC_1,     KC_0,     KC_4,               _______,  _______,  _______,  _______,  _______,
        KC_F3,    KC_F2,    KC_F1,    KC_F4,    KC_F5,              _______,  _______,  _______,  _______,  _______,
        KC_RSFT,            _______,  _______,  _______,            _______,  _______,  _______,            _______
    ),

    [_LOWER] = LAYOUT_split_3x5x1_3(
        KC_ESC,   G(KC_W),  G(KC_G),  XXXXXXX,  UK_BRACES,          C(KC_F4), C(KC_F1), C(KC_F2), C(KC_F3), _______,
        C(KC_A),  KC_LSFT,  KC_LGUI,  KC_TAB,   KC_HASH,            XXXXXXX,  C(KC_Y),  KC_TAB,   KC_RALT,  KC_LCTL,
        C(KC_Z),  C(KC_X),  C(KC_C),  C(KC_V),  C(KC_V),            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        OSM_LALT,           _______,  _______,  _______,            _______,  KC_ENT,   MO(_SPECIAL)       ,UK_CLEAR
    ),

    [_RAISE] = LAYOUT_split_3x5x1_3(
        _______,     C(KC_W),     _______,       CW_TOGG,    G(KC_SPC),        DF(_QWERTY),  DF(_COLEMAK_DH),  DF(_NAV),  DF(_GAME_OVERWATCH),  KC_PSCR,
        C(KC_LEFT),  C(KC_RGHT),  C(S(KC_TAB)),  C(KC_TAB),  CM_TOGG,          KC_LEFT,      KC_DOWN,          KC_UP,     KC_RGHT,    KC_INS,
        C(KC_Z),     C(KC_X),     C(KC_C),       A(KC_ESC),  C(KC_V),          KC_HOME,      KC_PGDN,          KC_PGUP,   KC_END,     DF(_NAV_LEFT),
        _______,                  MO(_SPECIAL),  _______,  _______,            _______,  _______,  _______                           ,_______
    ),

    [_NAV_LEFT] = LAYOUT_split_3x5x1_3(
        _______,     _______,  KC_UP,    _______,   _______,          DF(_QWERTY),  DF(_COLEMAK_DH),  DF(_NAV),  DF(_GAME_OVERWATCH), _______,
        S(KC_LEFT),  KC_LEFT,  KC_DOWN,  KC_RIGHT,  S(KC_RIGHT),      KC_LEFT,      KC_DOWN,          KC_UP,     KC_RGHT,    KC_INS,
        _______,     _______,  _______,  _______,   _______,          KC_HOME,      KC_PGDN,          KC_PGUP,   KC_END,     _______,
        _______,          MO(_SPECIAL),  _______,   _______,          _______,  _______,  _______                           ,_______
    ),

    [_NUMPAD] = LAYOUT_split_3x5x1_3(
        _______,  _______,  _______,  _______,  _______,            KC_PAST,  KC_7,     KC_8,     KC_9,     KC_EQL,
        KC_LGUI,  KC_LALT,  KC_LSFT,  KC_LCTL,  _______,            KC_P0,    KC_4,     KC_5,     KC_6,     KC_PPLS,
        _______,  _______,  _______,  _______,  _______,            KC_PSLS,  KC_1,     KC_2,     KC_3,     KC_PMNS,
        _______,            _______,  _______,  _______,            KC_ENT,   KC_0,     KC_PDOT            ,_______
    ),

    [_FUNC] = LAYOUT_split_3x5x1_3(
        _______,  _______,  _______,  _______,  _______,            _______,  KC_F7,    KC_F8,    KC_F9,    KC_F10,
        KC_LGUI,  KC_LALT,  KC_LSFT,  KC_LCTL,  _______,            _______,  KC_F4,    KC_F5,    KC_F6,    KC_F11,
        _______,  _______,  _______,  _______,  _______,            _______,  KC_F1,    KC_F2,    KC_F3,    KC_F12,
        _______,            _______,  _______,  _______,            _______,  _______,  _______            ,_______
    ),

    [_SPECIAL] = LAYOUT_split_3x5x1_3(
        QK_BOOT,  EE_CLR,   XXXXXXX,  XXXXXXX,  XXXXXXX,            RGB_VAI,  RGB_SAI,  RGB_HUI,  RGB_MOD,  RGB_TOG,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            RGB_VAD,  RGB_SAD,  RGB_HUD,  RGB_RMOD, XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,            _______,  _______,  _______,            _______,  _______,  _______            ,XXXXXXX
    ),

    [_SYMBOL] = LAYOUT_split_3x5x1_3(
        KC_QUOT,  KC_LT,    KC_GT,    KC_DQUO,  UK_BRACES,          KC_AMPR,  KC_UNDS,  KC_LBRC,  KC_RBRC,  KC_PERC,
        KC_EXLM,  KC_MINS,  KC_PLUS,  KC_EQL ,  KC_HASH,            KC_PIPE,  KC_COLN,  KC_LPRN,  KC_RPRN,  KC_QUES,
        KC_BSLS,  KC_SLSH,  KC_ASTR,  KC_CIRC,  KC_GRV,             KC_TILD,  KC_DLR ,  KC_LCBR,  KC_RCBR,  KC_AT,
        _______,            _______,  _______,  _______,            _______,  KC_ENT,   MO(_SPECIAL)       ,UK_CLEAR
    ),
};

// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    const uint8_t mods         = get_mods();
    const uint8_t oneshot_mods = get_oneshot_mods();

    // process_record_user_oled(keycode, record);
    // process_repeat_key(keycode, record);

    switch (keycode) {
        case UK_BRACES: // Types [], {}, or () and puts cursor between braces.
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
                    SEND_STRING("{}");
                } else if ((mods | oneshot_mods) & MOD_MASK_CTRL) {
                    SEND_STRING("[]");
                } else {
                    SEND_STRING("()");
                }
                tap_code(KC_LEFT);             // Move cursor between braces.
                set_mods(mods | oneshot_mods); // Restore mods.
            }
            return false;
        case UK_CLEAR:
            clear_mods();
            clear_oneshot_mods();
            return false;
    }
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    return TAPPING_TERM;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    // Immediately select the hold action when another key is pressed (tapped and released)
    // return true;
    // Do not select the hold action when another key is pressed.
    // return false;
    switch (keycode) {
        case BSPC_NUM:
        case ENT_NUM:
        case BSPC_SFT:
        case DEL_LWR:
        case ESC_ALT:
        case ESC_ADJ:
        case ENT_ADJ:
        case TAB_RSE:
            return true;
        default:
            return false;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    // Immediately select the hold action when another key is tapped:
    // return true;
    // Do not select the hold action when another key is tapped.
    // return false;
    switch (keycode) {
        case BSPC_NUM:
        case ENT_NUM:
        case BSPC_SFT:
        case DEL_LWR:
        case ENT_SFT:
        case ESC_ADJ:
        case ENT_ADJ:
        case ESC_ALT:
        case TAB_RSE:
            return true;
        default:
            return false;
    }
}

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    // Do not force the mod-tap key press to be handled as a modifier
    // if any other key was pressed while the mod-tap key is held down.
    // return true;
    // Force the mod-tap key press to be handled as a modifier if any
    // other key was pressed while the mod-tap key is held down.
    // return false;
    switch (keycode) {
        case QUOT_CTL:
            return true;
        default:
            return false;
    }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    // Disable repeated tapping
    switch (keycode) {
        case QUOT_CTL:
        case ESC_ALT:
        case TAB_RSE:
            return true;
        default:
            return false;
    }
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    // Output keycode regardless after hold is done
    switch (keycode) {
        default:
            return false;
    }
}

/* Combos */
#include "combo_gboards.h"

/* Gaming settings */
layer_state_t layer_state_set_user(layer_state_t state) {
    // layer_state_set_user2(state);
    switch (get_highest_layer(default_layer_state)) {
        case _GAME_OVERWATCH:
        case _GAME_NUMPAD:
#ifdef CAPS_WORD_ENABLE
            caps_word_off();
#endif
#ifdef COMBO_ENABLE
            combo_disable();
#endif
            break;
        default:
#ifdef COMBO_ENABLE
        combo_enable();
#endif
    }

    return state;
}

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    if (layer_state_cmp(layer_state | default_layer_state, _GAME_OVERWATCH) ||
        layer_state_cmp(layer_state | default_layer_state, _GAME_NUMPAD)) {
        return false;
    }

    return true;
}

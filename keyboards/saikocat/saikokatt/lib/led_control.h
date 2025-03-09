// Copyright 2025 saikocat (@saikocat)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// 3 bits = (R,G,B) => 8 possible colors
typedef enum {
    COLOR_BLACK   = 0, // 000: (R=0, G=0, B=0)
    COLOR_RED     = 1, // 001: (R=1, G=0, B=0)
    COLOR_GREEN   = 2, // 010: (R=0, G=1, B=0)
    COLOR_YELLOW  = 3, // 011: (R=1, G=1, B=0)
    COLOR_BLUE    = 4, // 100: (R=0, G=0, B=1)
    COLOR_MAGENTA = 5, // 101: (R=1, G=0, B=1)
    COLOR_CYAN    = 6, // 110: (R=0, G=1, B=1)
    COLOR_WHITE   = 7  // 111: (R=1, G=1, B=1)
} color;

#define led_init_pins()  gpio_set_pin_output(LED_RED_PIN); gpio_set_pin_output(LED_GREEN_PIN); gpio_set_pin_output(LED_BLUE_PIN);

// Setting it low/0 turns it on, and high/1 turns the LED off.
#define led_red_off()   gpio_write_pin_high(LED_RED_PIN)
#define led_red_on()    gpio_write_pin_low(LED_RED_PIN)
#define led_grn_off()   gpio_write_pin_high(LED_GREEN_PIN)
#define led_grn_on()    gpio_write_pin_low(LED_GREEN_PIN)
#define led_blu_off()   gpio_write_pin_high(LED_BLUE_PIN)
#define led_blu_on()    gpio_write_pin_low(LED_BLUE_PIN)

#define led_red_toggle(flag)   if (flag) led_red_on(); else led_red_off()
#define led_grn_toggle(flag)   if (flag) led_grn_on(); else led_grn_off()
#define led_blu_toggle(flag)   if (flag) led_blu_on(); else led_blu_off()

#define led_all_off()     led_red_off(); led_grn_off(); led_blu_off()

void led_set_color(color color) {
    // bit 0 (1) => Red
    if (color & 1) {
        led_red_on();
    } else {
        led_red_off();
    }

    // bit 1 (2) => Green
    if (color & 2) {
        led_grn_on();
    } else {
        led_grn_off();
    }

    // bit 2 (4) => Blue
    if (color & 4) {
        led_blu_on();
    } else {
        led_blu_off();
    }
}

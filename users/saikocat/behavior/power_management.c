// Copyright 2022 saikocat (@saikocat)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "behavior/power_management.h"

__attribute__((weak)) void suspend_wakeup_init_keymap(void) {}

void suspend_wakeup_init_user(void) {
    suspend_wakeup_init_keymap();
}

__attribute__((weak)) void suspend_power_down_keymap(void) {}

void suspend_power_down_user(void) {
    suspend_power_down_keymap();
}

// Copyright 2024 saikocat (@saikocat)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// OLED
#ifdef OLED_ENABLE
#    define OLED_DISPLAY_128X32
#    define OLED_UPDATE_INTERVAL 100
#    define OLED_BRIGHTNESS 128
#    define SPLIT_OLED_ENABLE
#endif

// Full-Duplex Driver
// #define SERIAL_USART_TX_PIN D2     // USART TX pin.
#define SERIAL_USART_FULL_DUPLEX   // Enable full duplex operation mode.
#define SERIAL_USART_RX_PIN D3     // USART RX pin.
#define SERIAL_USART_PIN_SWAP      // Swap TX and RX pins if keyboard is master halve.

#pragma once

#include "config_common.h"
/*
Copyright 2022 Thomas Baart <thomas@splitkb.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* key matrix size */
/* Rows are doubled up */
#define MATRIX_ROWS 10
#define MATRIX_COLS 7

// wiring
#define MATRIX_ROW_PINS { D4, C6, D7, E6, B4 }
#define MATRIX_COL_PINS { B5, B6, B2, B3, B1, F7, F6 }

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE        5
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM 180
#define TAPPING_FORCE_HOLD
#define PERMISSIVE_HOLD

#define USE_I2C
// #define LED_CAPS_LOCK_PIN D1

// #ifdef OLED_ENABLE
// #    define OLED_DISPLAY_128X64
// #    define SPLIT_OLED_ENABLE
// #endif

// /* RGB light support */
#ifdef RGBLIGHT_ENABLE
    #define RGB_DI_PIN F4
    #define RGB_MATRIX_LED_COUNT 1 // Number of LEDs
    #define RGB_MATRIX_SPLIT { 0, 1 }
#endif

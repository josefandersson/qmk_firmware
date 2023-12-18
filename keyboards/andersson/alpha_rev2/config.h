#pragma once

/* key matrix size */
/* Rows are doubled up */
#define MATRIX_ROWS 8
#define MATRIX_COLS 6

// wiring
#define MATRIX_ROW_PINS { E6, D7, C6, D4 }
#define MATRIX_COL_PINS { B4, B5, F4, F5, F6, F7 }

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION ROW2COL

/* define if matrix has ghost (lacks anti-ghosting diodes) */
// #define MATRIX_HAS_GHOST

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE             5
#define TAPPING_TERM         180
#define TAPPING_TERM_PER_KEY
#define QUICK_TAP_TERM       70
#define PERMISSIVE_HOLD

#define SOFT_SERIAL_PIN D2
// #define USE_I2C
// #define I2C_DRIVER I2CD1
// #define LED_CAPS_LOCK_PIN D1

#ifdef OLED_ENABLE
    #define OLED_DISPLAY_128X64
    #define SPLIT_OLED_ENABLE
#endif

#ifdef RGBLIGHT_ENABLE
    #define RGB_DI_PIN D3
    #define RGBLED_NUM 42
    #define RGBLIGHT_SPLIT
    #define RGBLED_SPLIT { 21, 21 }
#endif

#ifdef RGB_MATRIX_ENABLE
    // #define WS2812_DI_PIN F4
    #define RGB_MATRIX_LED_COUNT 60
    #define RGB_MATRIX_SPLIT { 30, 30 }
#endif

#ifdef POINTING_DEVICE_ENABLE
    #define MK_3_SPEED
    #define MK_MOMENTARY_ACCEL
    #define MOUSEKEY_DELAY          0
    #define MOUSEKEY_INTERVAL       16
    #define MOUSEKEY_WHEEL_DELAY    0
    #define MOUSEKEY_MAX_SPEED      6
    #define MOUSEKEY_TIME_TO_MAX    64

    #define CIRQUE_PINNACLE_DIAMETER_MM 35
    #define CIRQUE_PINNACLE_ATTENUATION EXTREG__TRACK_ADCCONFIG__ADC_ATTENUATE_4X
    // #define CIRQUE_PINNACLE_TAP_ENABLE
    // #define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE
    #define POINTING_DEVICE_GESTURES_SCROLL_ENABLE
    #define POINTING_DEVICE_GESTURES_CURSOR_GLIDE_ENABLE
    #define MOUSE_EXTENDED_REPORT
    #define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#endif

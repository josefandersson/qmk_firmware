#pragma once

// May be required for Frood v6? I seem to be able to flash without this however
// #define RP2040_FLASH_GD25Q64CS

// Make the RP2040 bootloader trigger on double tap of reset button
// #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
// #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

// By default, pointing device has to be on master side
// Left can be master with data sync options but it costs more (https://docs.qmk.fm/#/feature_split_keyboard?id=data-sync-options)
#define MASTER_RIGHT

// Rows are doubled up
#define MATRIX_ROWS 8
#define MATRIX_COLS 6

// Wiring
#define MATRIX_ROW_PINS { E6, D7, C6, D4 }
#define MATRIX_COL_PINS { B4, B5, F4, F5, F6, F7 }
#define DIODE_DIRECTION ROW2COL

// Define if matrix has ghost (lacks anti-ghosting diodes)
// #define MATRIX_HAS_GHOST

// Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed
#define DEBOUNCE             5
#define TAPPING_TERM         180
#define TAPPING_TERM_PER_KEY
#define QUICK_TAP_TERM       70
#define PERMISSIVE_HOLD

// The board suppords both serial and I2C depending on which pads are jumped on the PCB.
#define SOFT_SERIAL_PIN D2
// or
// #define USE_I2C

#ifdef OLED_ENABLE
    #define OLED_DISPLAY_128X64

    // Share extra states with slave to show on OLED at a small cost of bandwidth
    #define SPLIT_LAYER_STATE_ENABLE
    #define SPLIT_LED_STATE_ENABLE
#endif

#ifdef RGBLIGHT_ENABLE
    #define WS2812_DI_PIN D3
    #define RGBLED_NUM 42
    #define RGBLIGHT_SPLIT
    #define RGBLED_SPLIT { 21, 21 }
#endif

#ifdef RGB_MATRIX_ENABLE
    #define WS2812_DI_PIN D3
    #define RGB_MATRIX_LED_COUNT 42
    #define RGB_MATRIX_SPLIT { 21, 21 }

    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150

    #define RGB_MATRIX_DEFAULT_VAL 100
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
    #define RGB_MATRIX_KEYPRESSES
    #define RGB_DISABLE_WHEN_USB_SUSPENDED
    //#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_RAINDROPS

    // RGB Matrix Animation modes. Explicitly enabled
    // For full list of effects, see:
    // https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects
    #define ENABLE_RGB_MATRIX_ALPHAS_MODS
    #define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
    #define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
    #define ENABLE_RGB_MATRIX_BREATHING
    #define ENABLE_RGB_MATRIX_BAND_SAT
    #define ENABLE_RGB_MATRIX_BAND_VAL
    #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
    #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
    #define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
    #define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
    #define ENABLE_RGB_MATRIX_CYCLE_ALL
    #define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
    #define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
    #define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
    #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
    #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
    #define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
    #define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
    #define ENABLE_RGB_MATRIX_DUAL_BEACON
    #define ENABLE_RGB_MATRIX_RAINBOW_BEACON
    #define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
    #define ENABLE_RGB_MATRIX_RAINDROPS
    #define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
    #define ENABLE_RGB_MATRIX_HUE_BREATHING
    #define ENABLE_RGB_MATRIX_HUE_PENDULUM
    #define ENABLE_RGB_MATRIX_HUE_WAVE
    #define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
    #define ENABLE_RGB_MATRIX_PIXEL_FLOW
    #define ENABLE_RGB_MATRIX_PIXEL_RAIN

    #define ENABLE_RGB_MATRIX_TYPING_HEATMAP
    #define ENABLE_RGB_MATRIX_DIGITAL_RAIN

    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
    #define ENABLE_RGB_MATRIX_SPLASH
    #define ENABLE_RGB_MATRIX_MULTISPLASH
    #define ENABLE_RGB_MATRIX_SOLID_SPLASH
    #define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif

#ifdef MOUSEKEY_ENABLE
    // Enables constant and momentary modes for mousekeys (https://docs.qmk.fm/#/feature_mouse_keys?id=constant-mode)
    #define MK_3_SPEED
    #define MK_MOMENTARY_ACCEL

    #define MOUSEKEY_DELAY          0
    #define MOUSEKEY_INTERVAL       16
    #define MOUSEKEY_WHEEL_DELAY    0
    #define MOUSEKEY_MAX_SPEED      4
    #define MOUSEKEY_TIME_TO_MAX    64
#endif

#ifdef POINTING_DEVICE_ENABLE
    #define CIRQUE_PINNACLE_DIAMETER_MM 35
    #define CIRQUE_PINNACLE_ATTENUATION EXTREG__TRACK_ADCCONFIG__ADC_ATTENUATE_4X

    // Tapping doesn't work so well in my opinion, but it can be enabled with these
    // #define CIRQUE_PINNACLE_TAP_ENABLE
    // #define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE

    #define POINTING_DEVICE_GESTURES_SCROLL_ENABLE
    #define POINTING_DEVICE_GESTURES_CURSOR_GLIDE_ENABLE
    #define POINTING_DEVICE_AUTO_MOUSE_ENABLE

    // Increase presicion to 64k instead of 256
    #define MOUSE_EXTENDED_REPORT

    // When using SPLIT_POINTING_ENABLE in data sync options (https://docs.qmk.fm/#/feature_split_keyboard?id=data-sync-options),
    // one of these must be defined
    // #define POINTING_DEVICE_LEFT
    // #define POINTING_DEVICE_RIGHT
    // #define POINTING_DEVICE_COMBINED
#endif

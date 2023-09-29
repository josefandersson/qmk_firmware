#pragma once

/* key matrix size */
/* Rows are doubled up */
#define MATRIX_ROWS 8
#define MATRIX_COLS 6

// wiring
#define MATRIX_ROW_PINS { E6, D7, C6, D4 }
#define MATRIX_COL_PINS { B4, B5, F4, F5, F6, F7 }

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost (lacks anti-ghosting diodes) */
// #define MATRIX_HAS_GHOST

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE             5
#define TAPPING_TERM         180
#define TAPPING_TERM_PER_KEY
#define QUICK_TAP_TERM       70
#define PERMISSIVE_HOLD

#define SOFT_SERIAL_PIN D2

#define USE_I2C

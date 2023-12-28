#include "alpha_rev2.h"

#ifdef DDRD
    void matrix_init_kb(void) {
        // Disable RX/TX LEDs on pro micro
        DDRD  &= ~(1<<5);
        DDRB  &= ~(1<<0);
        PORTD &= ~(1<<5);
        PORTB &= ~(1<<0);
    }
#endif

#ifdef RGB_MATRIX_ENABLE
    led_config_t g_led_config = { {
        {          0,  1,      2,      3,  4,      5 },
        {         11, 10,      9,      8,  7,      6 },
        {         16, 15,     14,     13, 12, NO_LED },
        { 20, 19, 18, 17, NO_LED, NO_LED },
        {         26, 25, 24, 23, 22,        21 },
        {         32, 31, 30, 29, 28,        27 },
        {         37, 36, 35, 34, 33,    NO_LED },
        { 41, 40, 39, 38, NO_LED, NO_LED }
    }, {
                                 { 77, 8  }, { 63, 8  }, { 49, 8  }, { 35, 8  }, { 21, 8  }, { 7, 8  },
                                 { 77, 24 }, { 63, 24 }, { 49, 24 }, { 35, 24 }, { 21, 24 }, { 7, 24 },
                                 { 77, 40 }, { 63, 40 }, { 49, 40 }, { 35, 40 }, { 21, 40 },
        { 105, 56 }, { 91, 56 }, { 77, 56 }, { 63, 56 },
        { 217, 8 },  { 203, 8 },  { 189, 8 },  { 175, 8 },  { 161, 8 },  { 147, 8 },
        { 217, 24 }, { 203, 24 }, { 189, 24 }, { 175, 24 }, { 161, 24 }, { 147, 24 },
                     { 203, 40 }, { 189, 40 }, { 175, 40 }, { 161, 40 }, { 147, 40 },
                                                            { 161, 56 }, { 147, 56 }, { 133, 56 }, { 119, 56 }
    }, {
        4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4,
        1, 1, 1, 1,
        4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4,
        1, 1, 1, 1
    } };
#endif

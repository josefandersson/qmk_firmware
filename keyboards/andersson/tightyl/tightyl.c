#include "tightyl.h"

#ifdef  DDRD
    void matrix_init_kb(void) {
        // Disable RX/TX LEDs on pro micro
        DDRD  &= ~(1<<5);
        DDRB  &= ~(1<<0);
        PORTD &= ~(1<<5);
        PORTB &= ~(1<<0);
    }
#endif

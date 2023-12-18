#pragma once

#include "quantum.h"

#define LAYOUT( \
    L05, L04, L03, L02, L01, L00,                        R00, R01, R02, R03, R04, R05, \
    L11, L10, L09, L08, L07, L06,                        R06, R07, R08, R09, R10, R11, \
         L16, L15, L14, L13, L12,                        R12, R13, R14, R15, R16, \
                        L20, L19, L18, L17,    R17, R18, R19, R20 \
) \
{ \
    { L00,   L01,   L02, L03, L04,   L05   }, \
    { L06,   L07,   L08, L09, L10,   L11   }, \
    { L12,   L13,   L14, L15, L16,   KC_NO }, \
    { L17,   L18,   L19, L20, KC_NO, KC_NO }, \
    { R00,   R01,   R02, R03, R04,   R05   }, \
    { R06,   R07,   R08, R09, R10,   R11   }, \
    { R12,   R13,   R14, R15, R16,   KC_NO }, \
    { R17,   R18,   R19, R20, KC_NO, KC_NO } \
}

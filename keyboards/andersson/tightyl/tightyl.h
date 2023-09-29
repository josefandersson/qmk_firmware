#pragma once

#include "quantum.h"

#define _NO KC_NO

#define LAYOUT( \
    L05, L04, L03, L02, L01, L00,              R00, R01, R02, R03, R04, R05, \
    L06, L07, L08, L09, L10, L11,              R11, R10, R09, R08, R07, R06, \
    L17, L16, L15, L14, L13, L12,              R12, R13, R14, R15, R16, R17, \
              L18, L19, L20, L21, L22,    R22, R21, R20, R19, R18 \
) \
{ \
    { L00, L01, L02, L03, L04, L05 }, \
    { L11, L10, L09, L08, L07, L06 }, \
    { L12, L13, L14, L15, L16, L17 }, \
    { L21, L20, L19, L18, L22, _NO }, \
    { R00, R01, R02, R03, R04, R05 }, \
    { R11, R10, R09, R08, R07, R06 }, \
    { R12, R13, R14, R15, R16, R17 }, \
    { R21, R20, R19, R18, R22, _NO }, \
}

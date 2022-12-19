#include QMK_KEYBOARD_H


// (
#define SV_LPAR S(KC_8)
// )
#define SV_RPAR S(KC_9)
// {
#define SV_LBRAC RALT(KC_7)
// }
#define SV_RBRAC RALT(KC_0)
// [
#define SV_LBRAK RALT(KC_8)
// ]
#define SV_RBRAK RALT(KC_9)
// +
#define SV_PLUS KC_MINUS
// ?
#define SV_QUESTION S(KC_MINUS)
// å
#define SV_AO KC_LEFT_BRACKET
// ä
#define SV_AE KC_QUOTE
// ö
#define SV_OE KC_SEMICOLON
// '
#define SV_SINGLEQ KC_BACKSLASH
// "
#define SV_DOUBLEQ S(KC_2)
// <
#define SV_LESS KC_NONUS_BACKSLASH
// >
#define SV_GREA S(KC_NONUS_BACKSLASH)
// /
#define SV_SLASH S(KC_7)
// Backslash
#define SV_BACKSLASH RALT(KC_MINUS)
// @
#define SV_AT RALT(KC_2)
// |
#define SV_PIPE RALT(KC_NONUS_BACKSLASH)
// =
#define SV_EQUAL S(KC_0)
// *
#define SV_ASTERIX S(KC_BACKSLASH)
// $
#define SV_DOLLAR RALT(KC_4)
// `
#define SV_BACKTICK S(KC_EQUAL)
// ^
#define SV_EXPONENT S(KC_RIGHT_BRACKET)
// ~
#define SV_TILDE RALT(KC_RIGHT_BRACKET)
// §
#define SV_PARAGRAPH KC_GRAVE
// ´
#define SV_GRAVE KC_EQUAL
// &
#define SV_AND S(KC_6)
// #
#define SV_HASH S(KC_3)
// !
#define SV_EXCLM S(KC_1)
// %
#define SV_PERCENT S(KC_5)

#define H1(x) LSFT_T(x)
#define H2(x) LCTL_T(x)
#define H3(x) LALT_T(x)
#define H4(x) LGUI_T(x)

enum keyboard_layers {
    _DEFAULT = 0,
    _LOWER = 1,
    _RAISE = 2,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // -------------------------------------------------------------------------------------------------------------------------
    // |  ESC  |  1  |  2  |   3   |  4   |  5  |                                    |  6  |  7   |   8   |  9  |  0  |       |
    // |  ESC  |  Q  |  W  |   E   |  R   |  T  |                                    |  Y  |  U   |   I   |  O  |  P  |   Å   |
    // |  TAB  |  A  |  S  |   D   |  F   |  G  |                                    |  H  |  J   |   K   |  L  |  Ö  |   Ä   |
    // | SHIFT |  Z  |  X  |   C   |  V   |  B  | LCTRL | RETURN |  |  RALT  | RCTRL |  N  |  M   |  ,;   |  .: |  -  | SHIFT |
    //                     | LCTRL | LWIN | L 1 | SPACE | LSHIFT |  | RETURN | BKSPC | L 2 | RWIN | RCTRL |

    [_DEFAULT] = LAYOUT(
        KC_ESC,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                                             KC_6,       KC_7,     KC_8,     KC_9,     KC_0,      KC_MUTE,
        KC_ESC,  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                                             KC_Y,       KC_U,     KC_I,     KC_O,     KC_P,      SV_AO,
        KC_TAB,  H4(KC_A), H3(KC_S), H2(KC_D), H1(KC_F), KC_G,                                             KC_H,       H1(KC_J), H2(KC_K), H3(KC_L), H4(SV_OE), SV_AE,
        KC_LSFT, KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,       KC_LCTL, KC_ENT,    G(KC_1), G(KC_1), KC_N,       KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,   KC_MPLY,
                                    KC_LCTL,   KC_LGUI,  MO(_LOWER), KC_SPC,  KC_CAPS,   KC_ENT,  KC_BSPC, MO(_RAISE), KC_RGUI,  KC_RALT
    ),

    // --------------------------------------------------------------------------------------------
    // |   | F1 | F2 | F3 | F4 | F5 |                                 | F6 | F7 | F8 | F9 | F10 | F11 |
    // |   | 1  | 2  | 3  | 4  | 5  |                                 | 6  | 7  | 8  | 9  |  0  | F12 |
    // |   | '  | <  | (  | {  | [  |                                 | ?  | &  | ~  |    |     |     |
    // |   | =  | >  | )  | }  | ]  | VOL D |  VOL U |  | PREV | NEXT | /  | ^  | §  |    |     |     |
    //               |    |    |    | SPACE |  MUTE  |  |      | DEL  |    |    |    |
    [_LOWER] = LAYOUT(
        _______, KC_F1,      KC_F2,   KC_F3,   KC_F4,    KC_F5,                                          KC_F6,       KC_F7,       KC_F8,        KC_F9,   KC_F10,  KC_F11,
        _______, KC_1,       KC_2,    KC_3,    KC_4,     KC_5,                                           KC_6,        KC_7,        KC_8,         KC_9,    KC_0,    KC_F12,
        _______, SV_SINGLEQ, SV_LESS, SV_LPAR, SV_LBRAC, SV_LBRAK,                                       SV_QUESTION, SV_AND,      SV_TILDE,     _______, _______, _______,
        _______, SV_EQUAL,   SV_GREA, SV_RPAR, SV_RBRAC, SV_RBRAK, KC_VOLD, KC_VOLU,   _______, _______, SV_SLASH,    SV_EXPONENT, SV_PARAGRAPH, _______, _______, _______,
                                      _______, _______,  _______,  _______, KC_MUTE,   _______, KC_DEL,  _______,     _______,     _______
    ),

    // --------------------------------------------------------------------------------------------------------------------
    // |     |     |     |     |     |       |                  |     |      |      |      |      |     |
    // |     | F1  | F2  | F3  | F4  |  F5   |                  | F6  |  F7  |  F8  |  F9  | F10  | F11 |
    // |     |  "  |  *  |  |  |  $  |   %   |                  |  +  | LARR | UARR | RARR | PGUP | F12 |
    // |     |  ´  |  `  |  #  |  !  |   @   |   |   |  |   |   |  \  | HOME | DARR | END  | PGDN |     |
    //                   |     |     | BKSPC |   |   |  |   |   |     |      |      |
    [_RAISE] = LAYOUT(
        _______, _______,    _______,     _______, _______,  _______,                                          _______,      _______, _______, _______,  _______, _______,
        _______, KC_F1,      KC_F2,       KC_F3,   KC_F4,    KC_F5,                                            KC_F6,        KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,
        _______, SV_DOUBLEQ, KC_S,        KC_D,    KC_F,     SV_PERCENT,                                       SV_PLUS,      KC_LEFT, KC_UP,   KC_RIGHT, KC_PGDN, KC_F12,
        _______, SV_GRAVE,   SV_BACKTICK, SV_HASH, SV_EXCLM, SV_AT,      _______, _______,   KC_MPRV, KC_MNXT, SV_BACKSLASH, KC_HOME, KC_DOWN, KC_END,   KC_PGDN, _______,
                                          _______, _______,  KC_BSPC,    _______, _______,   _______, _______, _______,      _______, _______
    ),
};
// clang-format on

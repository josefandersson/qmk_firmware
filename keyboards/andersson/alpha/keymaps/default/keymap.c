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


#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)

#define HOME_J RSFT_T(KC_J)
#define HOME_K RCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_OE RGUI_T(SV_OE)

enum keyboard_layers {
    _DEFAULT = 0,
    _LOWER = 1,
    _RAISE = 2,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // -------------------------------------------------------------------------------------------------------------------------
    // |  ESC  |  1  |  2  |   3   |  4   |  5  |                                    |  6  |  7   |   8   |  9  |  0  |       |
    // |  TAB  |  Q  |  W  |   E   |  R   |  T  |                                    |  Y  |  U   |   I   |  O  |  P  |   Å   |
    // |  TAB  |  A  |  S  |   D   |  F   |  G  |                                    |  H  |  J   |   K   |  L  |  Ö  |   Ä   |
    // | SHIFT |  Z  |  X  |   C   |  V   |  B  | LCTRL | RETURN |  |  RALT  | RCTRL |  N  |  M   |  ,;   |  .: |  -  | SHIFT |
    //                     | LCTRL | LWIN | L 1 | SPACE | LSHIFT |  | RETURN | BKSPC | L 1 | RWIN | RCTRL |

    [_DEFAULT] = LAYOUT(
        KC_ESC,  KC_1,   KC_2,   KC_3,    KC_4,    KC_5,                                            KC_6,       KC_7,    KC_8,    KC_9,   KC_0,    KC_MUTE,
        KC_TAB,  KC_Q,   KC_W,   KC_E,    KC_R,    KC_T,                                            KC_Y,       KC_U,    KC_I,    KC_O,   KC_P,    SV_AO,
        KC_TAB,  HOME_A, HOME_S, HOME_D,  HOME_F,  KC_G,                                            KC_H,       HOME_J,  HOME_K,  HOME_L, HOME_OE, SV_AE,
        KC_LSFT, KC_Z,   KC_X,   KC_C,    KC_V,    KC_B,       KC_LCTL, KC_ENT,    KC_NO,  KC_NO,   KC_N,       KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_MPLY,
                                 KC_LCTL, KC_LGUI, MO(_LOWER), KC_SPC,  KC_0,      KC_ENT, KC_BSPC, MO(_LOWER), KC_RGUI, KC_RALT
    ),

    // --------------------------------------------------------------------------------------------------------------------
    // |     |  !  |  @  |  #  |  $  |  %  |                                       |  &  |  `   |   ^   |  ~   |  §   |     |
    // |     | 1!  | 2@  | 3#  | 4$  | 5%  |                                       | 6&  |  7`  |  8^   |  9~  |  0§  |     |
    // |     | '"  | <*  | (|  |  {  |  [  |                                       | ?+  | LARR | UARR  | RARR | PGUP |     |
    // |     | =´  |  >  |  )  |  }  |  ]  | VOL D |  VOL U       |  | PREV | NEXT | /\  | HOME | DARR  | END  | PGDN |     |
    //                   |     |     |     | SPACE | PLPA -> MUTE |  |      | DEL  |     |      |       |
    [_LOWER] = LAYOUT(
        _______, S(KC_1), SV_AT, S(KC_3), SV_DOLLAR, S(KC_5),                                         S(KC_6), SV_BACKTICK, SV_EXPONENT, SV_TILDE, SV_PARAGRAPH, XXXXXXX,
        _______, KC_1,    KC_2,  KC_3,    KC_4,      KC_5,                                            KC_6,    KC_7,        KC_8,        KC_9,     KC_0,         XXXXXXX,
        _______, KC_A,    KC_S,  KC_D,    SV_LBRAC,  SV_LBRAK,                                        _______, KC_LEFT,     KC_UP,       KC_RIGHT, KC_PGUP,      XXXXXXX,
        _______, KC_Z,    KC_X,  KC_C,    SV_RBRAC,  SV_RBRAK, KC_VOLD, KC_VOLU,    KC_MPRV, KC_MNXT, _______, KC_HOME,     KC_DOWN,     KC_END,   KC_PGDN,      _______,
                                 _______, _______,   _______,  _______, KC_MUTE,    _______, KC_DEL,  _______, _______,     _______
    ),

    // ------------------------------------------------------------------------------------------------------------
    // |  | F1 | F2 | F3 | F4 | F5 |                   | F6 | F7 | F8 | F9 | F10 | F11 |
    // |  |    |    |    |    |    |                   |    |    |    |    |     | F12 |
    // |  |    |    |    |    |    |                   |    |    |    |    |     | F12 |
    // |  |    |    |    |    |    |   |   |  |   |    |    |    |    |    |     |     |
    //              |    |    |    |   |   |  |   |    |    |    |    |
    [_RAISE] = LAYOUT(
        KC_ESC,  KC_1, KC_2, KC_3,    KC_4,    KC_5,                                                 KC_6,   KC_7,  KC_8,    KC_9,   KC_0,    RGB_TOG,
        KC_TAB,  KC_Q, KC_W, KC_E,    KC_R,    KC_T,                                                 KC_Y,   KC_U,  KC_I,    KC_O,   KC_P,    RGB_M_T,
        KC_TAB,  KC_A, KC_S, KC_D,    KC_F,    KC_G,                                                 KC_H,   KC_J,  KC_K,    KC_L,   KC_0,    KC_0,
        KC_LSFT, KC_Z, KC_X, KC_C,    KC_V,    KC_B, KC_LCTL, KC_RETURN,    KC_0,      KC_0,         KC_N,   KC_M,  KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                             KC_LCTL, KC_LGUI, KC_0, KC_SPC, KC_0,          KC_RETURN, KC_BACKSPACE, KC_0, KC_RGUI, KC_RALT
    ),
};
// clang-format on

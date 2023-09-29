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
// :
#define SV_COLON S(KC_DOT)
// ;
#define SV_SEMICLN S(KC_COMMA)
// -
#define SV_DASH KC_SLSH

#define H1(x) LSFT_T(x)
#define H2(x) LCTL_T(x)
#define H3(x) LALT_T(x)
#define H4(x) LGUI_T(x)

enum keyboard_layers {
    _COLEMAKDH = 0,
    _QWERTY,
    _LOWER,
    _RAISE,
    _MOUSE,
    _ADJUST,
};

int current_layout = _COLEMAKDH;

enum custom_keycodes {
    ROTATE_LAYOUT = SAFE_RANGE,
    GUI_ADJUST,
    LOWER,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // -----------------------------------------------------------------------------------------------------------------
    // | ESC |  Q  |  W  |  E  |    R     |  T  |                                    |  Y  |  U   |  I  |  O  |  P  |  Å   |
    // | TAB |  A  |  S  |  D  |    F     |  G  |                                    |  H  |  J   |  K  |  L  |  Ö  |  Ä   |
    // |     |  Z  |  X  |  C  |    V     |  B  |       |        |  |        |       |  N  |  M   |  ,; |  .: |  -  | PLPA |
    //                   |     | LWIN/ADJ | LOW | SPACE | LSHIFT |  | RETURN | BKSPC | RAI | PLPA |     |
    [_QWERTY] = LAYOUT(
        KC_ESC,  KC_Q,     KC_W,     KC_E,       KC_R,     KC_T,                                KC_Y,    KC_U,       KC_I,     KC_O,     KC_P,      SV_AO,
        KC_TAB,  H4(KC_A), H3(KC_S), H2(KC_D),   H1(KC_F), KC_G,                                KC_H,    H1(KC_J),   H2(KC_K), H3(KC_L), H4(SV_OE), SV_AE,
        XXXXXXX, KC_Z,     KC_X,     KC_C,       KC_V,     KC_B,                                KC_N,    KC_M,       KC_COMM,  KC_DOT,   SV_DASH,   XXXXXXX,
                           XXXXXXX,  GUI_ADJUST, LOWER,    KC_SPC, LSFT_T(KC_CAPS),     KC_ENT, KC_BSPC, MO(_RAISE), KC_MPLY,  XXXXXXX
    ),

    // -----------------------------------------------------------------------------------------------------------------
    // | ESC |  Q  |  W  |  F  |    P     |  B  |                                    |  J  |  L   |  U  |  Y  |  Ö  |  Å   |
    // | TAB |  A  |  R  |  S  |    T     |  G  |                                    |  M  |  N   |  E  |  I  |  O  |  Ä   |
    // |     |  Z  |  X  |  C  |    D     |  V  |       |        |  |        |       |  K  |  H   |  ,; |  .: |  -_ | PLPA |
    //                   |     | LWIN/ADJ | LOW | SPACE | LSHIFT |  | RETURN | BKSPC | RAI | PLPA |     |
    [_COLEMAKDH] = LAYOUT(
        KC_ESC,  KC_Q,     KC_W,     KC_F,     KC_P,        KC_B,                                KC_J,    KC_L,       KC_U,     KC_Y,     SV_OE,    SV_AO,
        KC_TAB,  H4(KC_A), H3(KC_R), H2(KC_S), H1(KC_T),    KC_G,                                KC_M,    H1(KC_N),   H2(KC_E), H3(KC_I), H4(KC_O), SV_AE,
        XXXXXXX, KC_Z,     KC_X,     KC_C,     KC_D,        KC_V,                                KC_K,    KC_H,       KC_COMM,  KC_DOT,   SV_DASH,  XXXXXXX,
                           XXXXXXX,  GUI_ADJUST,  LOWER,    KC_SPC, LSFT_T(KC_CAPS),     KC_ENT, KC_BSPC, MO(_RAISE), KC_MPLY,  XXXXXXX
    ),

    // --------------------------------------------------------------------------------------------------------
    // |   |  1  |  2  |  3  |  4  |  5  |         #            |  6  |  7  |  8  |  9  |  0  |   |
    // |   |  ?  |  <  |  (  |  {  |  [  |         #            |  :  |  '  |  /  |  `  |  +  |   |
    // |   |  =  |  >  |  )  |  }  |  ]  |   |   | # |   |      |  ;  |  "  |  \  |  ´  |  -  |   |
    //                 |     |     |     |   |   | # |   | DEL  |     |     |     |
    [_LOWER] = LAYOUT(
        _______, KC_1,        KC_2,    KC_3,    KC_4,     KC_5,                          KC_6,       KC_7,       KC_8,         KC_9,        KC_0,    XXXXXXX,
        _______, SV_QUESTION, SV_LESS, SV_LPAR, SV_LBRAC, SV_LBRAK,                      SV_COLON,   SV_SINGLEQ, SV_SLASH,     SV_BACKTICK, SV_PLUS, XXXXXXX,
        _______, SV_EQUAL,    SV_GREA, SV_RPAR, SV_RBRAC, SV_RBRAK,                      SV_SEMICLN, SV_DOUBLEQ, SV_BACKSLASH, SV_GRAVE,    SV_DASH, _______,
                              _______, _______, _______,  _______, _______,     _______, KC_DEL,     _______,    _______,      _______
    ),

    // -------------------------------------------------------------------------------------------------
    // |   | F1  |  F2  | F3  | F4  |  F5  |         #         | F6  |  F7  |  F8  |  F9  | F10  | F11 |
    // |   |  *  | pipe |  &  |  !  |  %   |         #         | INS | LARR | UARR | RARR | PGUP | F12 |
    // |   |  ^  |  ~   |  $  |  #  |  @   |   |   | # |   |   |     | HOME | DARR | END  | PGDN | LAY |
    //                  |     |     | BKSP |   |   | # |   |   |     |      |      |
    [_RAISE] = LAYOUT(
        _______, KC_F1,       KC_F2,    KC_F3,     KC_F4,    KC_F5,                             KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,
        _______, SV_ASTERIX,  SV_PIPE,  SV_AND,    SV_EXCLM, SV_PERCENT,                        KC_INS,  KC_LEFT, KC_UP,   KC_RIGHT, KC_PGUP, KC_F12,
        _______, SV_EXPONENT, SV_TILDE, SV_DOLLAR, SV_HASH,  SV_AT,                             XXXXXXX, KC_HOME, KC_DOWN, KC_END,   KC_PGDN, _______,
                              _______,   _______,  KC_BSPC,  _______,    _______,      _______, _______, _______, _______, _______
    ),

    // --------------------------------------------------------------------------------------------------
    // |     |     |     |     | PLPA | MUTE |                  |     |      |      |      |      |     |
    // |     |     |     |     | NEXT | VOLU |                  |     |      |      |      |      |     |
    // |     |     |     |     | PREV | VOLD |                  |     |      |      |      |      |     |
    //                   |     |      |      |   |   |  |   |   |     |      |      |
    [_ADJUST] = LAYOUT(
        _______, XXXXXXX, XXXXXXX, KC_MPLY, KC_MUTE, XXXXXXX,                      XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, KC_MNXT, KC_VOLU, XXXXXXX,                      XXXXXXX, ROTATE_LAYOUT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, KC_MPRV, KC_VOLD, XXXXXXX,                      XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          _______, _______, _______, _______, _______,    _______, _______, _______,       _______, _______
    ),
};
// clang-format on

bool guiAdjustDown = false;
bool lowerDown = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ROTATE_LAYOUT:
            if (record->event.pressed) {
                current_layout = current_layout == _QWERTY ? _COLEMAKDH : _QWERTY;
                default_layer_set(1UL << current_layout);
                return false;
            }
            break;
        case GUI_ADJUST:
            guiAdjustDown = record->event.pressed;
            if (lowerDown && guiAdjustDown)
                register_mods(MOD_MASK_GUI);
            else if (lowerDown && !guiAdjustDown)
                unregister_mods(MOD_MASK_GUI);
            else if (!lowerDown && guiAdjustDown)
                layer_move(_ADJUST);
            else if (!lowerDown && !guiAdjustDown)
                layer_clear();
            break;
        case LOWER:
            lowerDown = record->event.pressed;
            if (lowerDown && guiAdjustDown) {
                layer_move(_LOWER);
                register_mods(MOD_MASK_GUI);
            } else if (lowerDown && !guiAdjustDown)
                layer_move(_LOWER);
            else if (!lowerDown && guiAdjustDown) {
                unregister_mods(MOD_MASK_GUI);
                layer_move(_ADJUST);
            } else if (!lowerDown && !guiAdjustDown)
                layer_clear();
            break;
    }
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case H4(KC_A):
        case H4(KC_O):
        case H4(SV_OE):
            return TAPPING_TERM + 120;
        case H3(KC_I):
        case H3(KC_L):
        case H3(KC_R):
        case H3(KC_S):
        case H2(KC_D):
        case H2(KC_E):
        case H2(KC_K):
        case H2(KC_S):
        case H1(KC_F):
        case H1(KC_J):
        case H1(KC_N):
        case H1(KC_T):
        default:
            return TAPPING_TERM;
    }
}

tap_dance_action_t tap_dance_actions[] = {};

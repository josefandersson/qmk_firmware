#include QMK_KEYBOARD_H
#include "../swedish.h"

// Homerow mod shortcuts
#define H1(x) LSFT_T(x) // index
#define H2(x) LCTL_T(x) // middle
#define H3(x) LALT_T(x) // ring
#define H4(x) LGUI_T(x) // pinky

enum keyboard_layers {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
};

int current_layout = _QWERTY;

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // -----------------------------------------------------------------------------------------------------------------
    // | ESC |  Q  |  W  |  E  |  R  |  T  |                                    |  Y  |  U   |  I  |  O  |  P  |  Å   |
    // | TAB |  A  |  S  |  D  |  F  |  G  |                                    |  H  |  J   |  K  |  L  |  Ö  |  Ä   |
    //       |  Z  |  X  |  C  |  V  |  B  |       |        |  |        |       |  N  |  M   |  ,; |  .: |  -  |
    //                         | ADJ | LOW | SPACE | LSHIFT |  | RETURN | BKSPC | RAI | PLPA |
    [_QWERTY] = LAYOUT(
        KC_ESC,  KC_Q,     KC_W,     KC_E,     KC_R,         KC_T,                                                        KC_Y,       KC_U,     KC_I,     KC_O,     KC_P,      SV_AO,
        KC_TAB,  H4(KC_A), H3(KC_S), H2(KC_D), H1(KC_F),     KC_G,                                                        KC_H,       H1(KC_J), H2(KC_K), H3(KC_L), H4(SV_OE), SV_AE,
                 KC_Z,     KC_X,     KC_C,     KC_V,         KC_B,                                                        KC_N,       KC_M,     KC_COMM,  KC_DOT,   SV_DASH,
                                               MO(_ADJUST),  MO(_LOWER),    KC_SPC,  LSFT_T(KC_CAPS),   KC_ENT,  KC_BSPC, MO(_RAISE), KC_MPLY
    ),

    // --------------------------------------------------------------------------------------------------------
    // |   |  1  |  2  |  3  |  4  |  5  |         #            |  6  |  7  |  8  |  9  |  0  |   |
    // |   |  ?  |  <  |  (  |  {  |  [  |         #            |  :  |  '  |  /  |  `  |  +  |   |
    // |   |  =  |  >  |  )  |  }  |  ]  |   |   | # |   |      |  ;  |  "  |  \  |  ´  |  -  |   |
    //                 |     |     |     |   |   | # |   | DEL  |     |     |     |
    [_LOWER] = LAYOUT(
        _______, KC_1,        KC_2,    KC_3,    KC_4,     KC_5,                                          KC_6,       KC_7,       KC_8,         KC_9,        KC_0,    XXXXXXX,
        _______, SV_QUESTION, SV_LESS, SV_LPAR, SV_LBRAC, SV_LBRAK,                                      SV_COLON,   SV_SINGLEQ, SV_SLASH,     SV_BACKTICK, SV_PLUS, XXXXXXX,
                 SV_EQUAL,    SV_GREA, SV_RPAR, SV_RBRAC, SV_RBRAK,                                      SV_SEMICLN, SV_DOUBLEQ, SV_BACKSLASH, SV_GRAVE,    SV_DASH,
                                                _______,  _______,  _______, _______,   _______, KC_DEL, _______,    _______
    ),

    // -------------------------------------------------------------------------------------------------
    // |   | F1  |  F2  | F3  | F4  |  F5  |         #         | F6  |  F7  |  F8  |  F9  | F10  | F11 |
    // |   |  *  | pipe |  &  |  !  |  %   |         #         | INS | LARR | UARR | RARR | PGUP | F12 |
    //     |  ^  |  ~   |  $  |  #  |  @   |         #         |     | HOME | DARR | END  | PGDN |
    //                        |     | BKSP |   |   | # |   |   |     |      |
    [_RAISE] = LAYOUT(
        _______, KC_F1,       KC_F2,    KC_F3,     KC_F4,    KC_F5,                                                KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,
        _______, SV_ASTERIX,  SV_PIPE,  SV_AND,    SV_EXCLM, SV_PERCENT,                                           KC_INS,  KC_LEFT, KC_UP,   KC_RIGHT, KC_PGUP, KC_F12,
                 SV_EXPONENT, SV_TILDE, SV_DOLLAR, SV_HASH,  SV_AT,                                                XXXXXXX, KC_HOME, KC_DOWN, KC_END,   KC_PGDN,
                                                   _______,  KC_BSPC,    _______, _______,       _______, _______, _______, _______
    ),

    // --------------------------------------------------------------------------------------------------
    // |     |     |     |     | PLPA | MUTE |                  |     |        | RGBT |      |     |     |
    // |     |     |     |     | NEXT | VOLU |                  |     | ROTLAY | RGB+ | HUE+ |     |     |
    // |     |     |     |     | PREV | VOLD |                  |     |        | RGB- | HUE- |     |     |
    //                   |     |      |      |   |   |  |   |   |     |        |      |
    [_ADJUST] = LAYOUT(
        _______, XXXXXXX, XXXXXXX, KC_MPLY, KC_MUTE, XXXXXXX,                                        XXXXXXX, XXXXXXX, RGB_TOG, XXXXXXX, RGB_MODE_PLAIN, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, KC_MNXT, KC_VOLU, XXXXXXX,                                        XXXXXXX, XXXXXXX, RGB_VAI, RGB_HUI, RGB_MOD,        XXXXXXX,
                 XXXXXXX, XXXXXXX, KC_MPRV, KC_VOLD, XXXXXXX,                                        XXXXXXX, XXXXXXX, RGB_VAD, RGB_HUD, RGB_MODE_SNAKE,
                                            _______, _______, _______, _______,    _______, _______, _______, _______
    ),
};
// clang-format on

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case H4(KC_A):
        case H4(KC_O):
        case H4(SV_OE):
            // Increase tapping term for pinky finger since it's often a little bit slower (at least mine)
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

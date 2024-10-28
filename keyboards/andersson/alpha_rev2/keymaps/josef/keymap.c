#include QMK_KEYBOARD_H
#include "../swedish.h"

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
    _MINECRAFT,
};

int current_layout = _COLEMAKDH;
bool is_minecraft = false;

enum custom_keycodes {
    ROTATE_LAYOUT = SAFE_RANGE,
    GUI_ADJUST,
    LOWER,
    TOGGLE_MINECR,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // --------------------------------------------------------------------------------------------------------------------
    // | ESC |  Q  |  W  |  E  |    R     |  T  |                                    |  Y  |  U   |  I  |  O  |  P  |  Å  |
    // | TAB |  A  |  S  |  D  |    F     |  G  |                                    |  H  |  J   |  K  |  L  |  Ö  |  Ä  |
    //       |  Z  |  X  |  C  |    V     |  B  |       |        |  |        |       |  N  |  M   |  ,; |  .: |  -  |
    //                         | LWIN/ADJ | LOW | SPACE | LSHIFT |  | RETURN | BKSPC | RAI | PLPA |
    [_QWERTY] = LAYOUT(
        KC_ESC,  KC_Q,     KC_W,     KC_E,     KC_R,        KC_T,                                                   KC_Y,       KC_U,     KC_I,     KC_O,     KC_P,      SV_AO,
        KC_TAB,  H4(KC_A), H3(KC_S), H2(KC_D), H1(KC_F),    KC_G,                                                   KC_H,       H1(KC_J), H2(KC_K), H3(KC_L), H4(SV_OE), SV_AE,
                 KC_Z,     KC_X,     KC_C,     KC_V,        KC_B,                                                   KC_N,       KC_M,     KC_COMM,  KC_DOT,   SV_DASH,
                                               GUI_ADJUST,  LOWER,    KC_SPC,  LSFT_T(KC_CAPS),   KC_ENT,  KC_BSPC, MO(_RAISE), KC_MPLY
    ),

    // --------------------------------------------------------------------------------------------------------------------
    // | ESC |  Q  |  W  |  F  |    P     |  B  |                                    |  J  |  L   |  U  |  Y  |  Ö  |  Å  |
    // | TAB |  A  |  R  |  S  |    T     |  G  |                                    |  M  |  N   |  E  |  I  |  O  |  Ä  |
    //       |  Z  |  X  |  C  |    D     |  V  |       |        |  |        |       |  K  |  H   |  ,; |  .: |  -_ |
    //                         | LWIN/ADJ | LOW | SPACE | LSHIFT |  | RETURN | BKSPC | RAI | PLPA |
    [_COLEMAKDH] = LAYOUT(
        KC_ESC,  KC_Q,     KC_W,     KC_F,     KC_P,        KC_B,                                                   KC_J,       KC_L,     KC_U,     KC_Y,     SV_OE,    SV_AO,
        KC_TAB,  H4(KC_A), H3(KC_R), H2(KC_S), H1(KC_T),    KC_G,                                                   KC_M,       H1(KC_N), H2(KC_E), H3(KC_I), H4(KC_O), SV_AE,
                 KC_Z,     KC_X,     KC_C,     KC_D,        KC_V,                                                   KC_K,       KC_H,     KC_COMM,  KC_DOT,   SV_DASH,
                                               GUI_ADJUST,  LOWER,    KC_SPC,  LSFT_T(KC_CAPS),   KC_ENT,  KC_BSPC, MO(_RAISE), KC_MPLY
    ),

    // ---------------------------------------------------------------------------------------------------------------------
    // | ESC |   1   |  2  |  3  |  4  |  5  |                            |  6  |  7   |  8  |  9  |  0  | F11 |
    // | TAB | LSHFT |  A  |  W  |  D  |     |                            |     |      |     |     |     |     |
    //       | LCTRL |  Q  |  S  |  E  |     |       |     |  |     |     |     |      |     |     |     |
    //                           |     | LOW | SPACE |     |  |     |     |     | PLPA |
    [_MINECRAFT] = LAYOUT(
        KC_ESC,  KC_1,     KC_2,     KC_3,  KC_4,        KC_5,                                              KC_6,      KC_7,     KC_8,     KC_9,     KC_0,      KC_F11,
        KC_TAB,  KC_LSFT,  KC_A,     KC_W,  KC_D,        XXXXXXX,                                           XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,
                 KC_LCTL,  KC_Q,     KC_S,  KC_E,        XXXXXXX,                                           XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                            GUI_ADJUST,  LOWER,    KC_SPC,  XXXXXXX,   XXXXXXX,  XXXXXXX,   XXXXXXX,   KC_MPLY
    ),

    // --------------------------------------------------------------------------------------------------------
    // |   |  1  |  2  |  3  |  4  |  5  |         #            |  6  |  7  |  8  |  9  |  0  |   |
    // |   |  ?  |  <  |  (  |  {  |  [  |         #            |  :  |  '  |  /  |  `  |  +  |   |
    // |   |  =  |  >  |  )  |  }  |  ]  |   |   | # |   |      |  ;  |  "  |  \  |  ´  |  -  |   |
    //                       |     |     |   |   | # |   | DEL  |     |     |
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
                 SV_EXPONENT, SV_TILDE, SV_DOLLAR, SV_HASH,  SV_AT,                                                RGB_MODE_FORWARD, KC_HOME, KC_DOWN, KC_END,   KC_PGDN,
                                                   _______,  KC_BSPC,    _______, _______,       _______, _______, _______, _______
    ),

    // -----------------------------------------------------------------------------------------------------
    // |     |     |      |      |      |      |                  | BTN1 | BTN2 |      |      |      |     |
    // |     |     | BTN3 | BTN2 | BTN1 | WH U |                  |      |      | BTN3 |      |      |     |
    //       |     |      | BTN4 | BTN5 | WH D |                  |      |      |      |      |      |
    //                           |      |      |   |   |  |   |   |      |      |
    [_MOUSE] = LAYOUT(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                        KC_BTN1, KC_BTN2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, KC_BTN3, KC_BTN2, KC_BTN1, KC_WH_U,                                        XXXXXXX, XXXXXXX, KC_BTN3, XXXXXXX, XXXXXXX, XXXXXXX,
                 XXXXXXX, XXXXXXX, KC_BTN4, KC_BTN5, KC_WH_D,                                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            _______, _______, _______, _______,    _______, _______, _______, _______
    ),

    // --------------------------------------------------------------------------------------------------
    // |     |     |     |     | PLPA | MUTE |                  |     |        | RGBT |      |     |     |
    // |     |     |     |     | NEXT | VOLU |                  |     | ROTLAY | RGB+ | HUE+ |     |     |
    // |     |     |     |     | PREV | VOLD |                  |     |        | RGB- | HUE- |     |     |
    //                   |     |      |      |   |   |  |   |   |     |        |      |
    [_ADJUST] = LAYOUT(
        _______, XXXXXXX, XXXXXXX, KC_MPLY, KC_MUTE, XXXXXXX,                                        XXXXXXX, XXXXXXX,       RGB_TOG, XXXXXXX, RGB_MODE_PLAIN, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, KC_MNXT, KC_VOLU, XXXXXXX,                                        XXXXXXX, TOGGLE_MINECR, RGB_VAI, RGB_HUI, RGB_MOD, XXXXXXX,
                 XXXXXXX, XXXXXXX, KC_MPRV, KC_VOLD, XXXXXXX,                                        XXXXXXX, ROTATE_LAYOUT, RGB_VAD, RGB_HUD, RGB_MODE_SNAKE,
                                            _______, _______, _______, _______,    _______, _______, _______, _______
    ),
};
// clang-format on

bool guiAdjustDown = false;
bool lowerDown = false;

void keyboard_post_init_user() {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ROTATE_LAYOUT:
            if (record->event.pressed) {
                current_layout =
                    current_layout == _QWERTY ? _COLEMAKDH
                    : _QWERTY;
                default_layer_set(1UL << current_layout);
                return false;
            }
            break;
        case TOGGLE_MINECR:
            if (record->event.pressed) {
                is_minecraft = !is_minecraft;
                default_layer_set(is_minecraft ? 1UL << _MINECRAFT : 1UL << current_layout);
                return false;
            }
            break;
        case GUI_ADJUST:
            guiAdjustDown = record->event.pressed;
            if (lowerDown && guiAdjustDown) {
                register_mods(MOD_MASK_GUI);
            } else if (lowerDown && !guiAdjustDown) {
                unregister_mods(MOD_MASK_GUI);
            } else if (!lowerDown && guiAdjustDown) {
                layer_move(_ADJUST);
            } else if (!lowerDown && !guiAdjustDown) {
                layer_clear();
            }
            break;
        case LOWER:
            lowerDown = record->event.pressed;
            if (lowerDown && guiAdjustDown) {
                layer_move(_LOWER);
                register_mods(MOD_MASK_GUI);
            } else if (lowerDown && !guiAdjustDown) {
                layer_move(_LOWER);
            } else if (!lowerDown && guiAdjustDown) {
                unregister_mods(MOD_MASK_GUI);
                layer_move(_ADJUST);
            } else if (!lowerDown && !guiAdjustDown) {
                layer_clear();
            }
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

#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
    void pointing_device_init_user(void) {
        set_auto_mouse_layer(_MOUSE);
        set_auto_mouse_enable(true);
    }
#endif

#ifdef OLED_ENABLE
    oled_rotation_t oled_init_user(oled_rotation_t rotation) {
        if (is_keyboard_left())
            return OLED_ROTATION_180;

        return rotation;
    }

    void oled_render_logo(void) {
        static const char PROGMEM crkbd_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0};
        oled_write_P(crkbd_logo, false);
    }

    bool oled_task_user(void) {
        switch (get_highest_layer(layer_state)) {
            case _QWERTY:
                oled_write_ln_P(current_layout == _QWERTY ? PSTR("QWERTY") : PSTR("Colemak"), false);
                break;
            case _LOWER:
                oled_write_ln_P(PSTR("Lower"), false);
                break;
            case _RAISE:
                oled_write_ln_P(PSTR("Raise"), false);
                break;
            case _MOUSE:
                oled_write_ln_P(PSTR("Mouse"), false);
                break;
            case _ADJUST:
                oled_write_ln_P(PSTR("Adjust"), false);
                break;
        }

        oled_write_ln_P(PSTR(""), false);

        // Host Keyboard LED Status
        led_t led_state = host_keyboard_led_state();
        oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
        oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
        oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

        // oled_render_logo();

        return false;
    }

    void oled_render_boot(bool bootloader) {
        oled_clear();
        for (int i = 0; i < 16; i++) {
            oled_set_cursor(0, i);
            if (bootloader) {
                oled_write_P(PSTR("Awaiting New Firmware "), false);
            } else {
                oled_write_P(PSTR("Rebooting "), false);
            }
        }

        oled_render_dirty(true);
    }
#endif

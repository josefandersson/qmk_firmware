// Definitions for Swedish characters, including special characters on shift layer.
// Using this makes the keyboard compatible with the normal Swedish layout on any computer.

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

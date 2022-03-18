// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

//#include keymap_swedish.h

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define ____ KC_NO

enum ferris_layers {
  _BASE,
  _SYMB,
  _NUMB,
  _NAVG,
  _FUNC
};


// Enable ÅÄÖ through unicode
// enum unicode_names {
//   SE_AA_HIGH,
//   SE_AE_HIGH,
//   SE_OE_HIGH,
//   SE_AA_LOW,
//   SE_AE_LOW,
//   SE_OE_LOW,
// };

// const uint32_t PROGMEM unicode_map[] = {
//   [SE_AA_HIGH] = 0x00C5,
//   [SE_AE_HIGH] = 0x00C4,
//   [SE_OE_HIGH] = 0x00D6,
//   [SE_AA_LOW]  = 0x00E5,
//   [SE_AE_LOW]  = 0x00E4,
//   [SE_OE_LOW]  = 0x00F6,
// };

// #define SE_AA XP(SE_AA_LOW, SE_AA_HIGH)
// #define SE_AE XP(SE_AE_LOW, SE_AE_HIGH)
// #define SE_OE XP(SE_OE_LOW, SE_OE_HIGH)

// Creating combos
const uint16_t PROGMEM C_ESC[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM C_DEL[] = {KC_U, KC_Y, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(C_ESC, KC_ESC),
    COMBO(C_DEL, KC_DEL)
};


// Layoud and layers
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT( /* Colemak-DH */
    KC_Q,         KC_W,        KC_F,        KC_P,        KC_B,          KC_J,    KC_L,        KC_U,        KC_Y,        KC_QUOT,
    WIN_T(KC_A),  ALT_T(KC_R), CTL_T(KC_S), SFT_T(KC_T), KC_G,          KC_M,    SFT_T(KC_N), CTL_T(KC_E), ALT_T(KC_I), WIN_T(KC_O),
    KC_Z,    KC_X,     KC_C,    KC_D,    KC_V,                          KC_K,    KC_H,        KC_COMM,     KC_DOT,      KC_SLSH,
                         LT(_SYMB, KC_ENT), LT(_NUMB, KC_BSPC),         LT(_FUNC, KC_SPC), LT(_NAVG, KC_TAB)
  ),

  [_SYMB] = LAYOUT(
    QK_BOOT,    ____,    ____,    ____,   ____,                      KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,
    KC_LWIN, KC_LALT, KC_LCTL, KC_LSFT, KC_ESC,                      KC_PLUS, KC_DLR,  KC_PERC, KC_CIRC, KC_COLN,
       ____, KC_RALT,    ____,  KC_DEL,   ____,                      KC_PIPE, KC_EXLM, KC_AT,   KC_HASH, KC_TILD,
                                         ____,   ____,     KC_UNDS, KC_RPRN
  ),

  [_NUMB] = LAYOUT(
       ____,    ____,    ____,    ____,   ____,                     KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC,
    KC_LWIN, KC_LALT, KC_LCTL, KC_LSFT, KC_ESC,                      KC_EQL, KC_4, KC_5, KC_6, KC_SCLN,
       ____,    ____,    ____,  KC_DOT,   ____,                     KC_BSLS, KC_1, KC_2, KC_3,  KC_GRV,
                                          ____,   ____,    KC_MINS, KC_0
  ),

  [_NAVG] = LAYOUT(
       KC_PGUP,    KC_HOME,      KC_UP,     KC_END,      KC_INS,            ____,       ____,    ____,    ____, QK_BOOT,
       KC_PGDN,    KC_LEFT,    KC_DOWN,    KC_RGHT,     KC_CAPS,          KC_APP,    KC_LSFT, KC_LCTL, KC_LALT, KC_LWIN,
    LCTL(KC_Z),  LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), LCTL(KC_Y),            ____, SGUI(KC_S),    ____, KC_RALT,    ____,
                                        KC_BSPC, KC_ENT,              ____, ____
  ),

  [_FUNC] = LAYOUT(
    KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR,                      ____,       ____,    ____,    ____,    ____,
    KC_F11, KC_F4, KC_F5, KC_F6, KC_SCRL,                      ____,    KC_LSFT, KC_LCTL, KC_LALT, KC_LWIN,
    KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS,                      ____, KC_KB_MUTE,    ____, KC_RALT,    ____,
                                 KC_BSPC, KC_ENT,        ____, ____
  )

};

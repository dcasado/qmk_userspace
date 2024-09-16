// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

#include "keymap_spanish.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum ferris_layers {
  _COLEMAKDH,
  _SYM_NEW,
  _SYM2_NEW,
  _SYM1,
  _NAV,
  _FUNC,
  _SYM2,
};

enum ferris_tap_dances {
  TD_Q_ESC = 0
};

// Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Q, twice for ESC
    [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC)
};

enum combo_events {
  DEL_WORD,
  TAB,
  CUT,
  COPY,
  PASTE,
  SELALL,

  ACUTE,
  DIAE
};

const uint16_t PROGMEM del_word_combo[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM cut_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM copy_combo[] = {KC_Z, KC_C, COMBO_END};
const uint16_t PROGMEM paste_combo[] = {KC_Z, KC_V, COMBO_END};
const uint16_t PROGMEM selall_combo[] = {KC_CUT, KC_COPY, COMBO_END};

const uint16_t PROGMEM acute_combo[] = {KC_A, KC_R, COMBO_END};
const uint16_t PROGMEM diae_combo[] = {KC_Q, KC_W, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [DEL_WORD] = COMBO_ACTION(del_word_combo),
    [TAB] = COMBO_ACTION(tab_combo),
    [CUT] = COMBO_ACTION(cut_combo),
    [COPY] = COMBO_ACTION(copy_combo),
    [PASTE] = COMBO_ACTION(paste_combo),
    [SELALL] = COMBO_ACTION(selall_combo),

    [ACUTE] = COMBO_ACTION(acute_combo),
    [DIAE] = COMBO_ACTION(diae_combo)
};

#define KC_UNDO LCTL(KC_Z)
#define KC_CUT LCTL(KC_X)
#define KC_COPY LCTL(KC_C)
#define KC_PASTE LCTL(KC_V)
#define KC_SELAL LCTL(KC_A)
#define KC_FIND LCTL(KC_F)
#define KC_DELL LCTL(KC_BSPC)

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case DEL_WORD:
      if (pressed) {
        tap_code16(LALT(KC_BSPC));
      }
      break;
    case TAB:
      if (pressed) {
        tap_code16(KC_TAB);
      }
      break;
    case CUT:
      if (pressed) {
        tap_code16(LCTL(KC_X));
      }
      break;
    case COPY:
      if (pressed) {
        tap_code16(LCTL(KC_C));
      }
      break;
    case PASTE:
      if (pressed) {
        tap_code16(LCTL(KC_V));
      }
      break;
    case SELALL:
      if (pressed) {
        tap_code16(LCTL(KC_A));
      }
      break;
    case ACUTE:
      if (pressed) {
        tap_code16(ES_ACUT);
      }
      break;
    case DIAE:
      if (pressed) {
        tap_code16(ES_DIAE);
      }
      break;
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAKDH] = LAYOUT(
    KC_Q,  KC_W,  KC_F,  KC_P,  KC_B,      KC_J,  KC_L,  KC_U,     KC_Y,    ES_NTIL,
    KC_A,  KC_R,  KC_S,  KC_T,  KC_G,      KC_M,  KC_N,  KC_E,     KC_I,    KC_O,
    KC_Z,  KC_X,  KC_C,  KC_D,  KC_V,      KC_K,  KC_H,  ES_COMM,  ES_DOT,  ES_MINS,
                     MO(_NAV), KC_SPC,    KC_LSFT, MO(_SYM_NEW)
  ),

  [_SYM_NEW] = LAYOUT(
    ES_QUOT,  ES_LPRN,  ES_RPRN,  ES_COLN,  ES_DLR,       ES_SLSH,  KC_7,  KC_8,  KC_9,  ES_MINS,
    ES_DQUO,  ES_LCBR,  ES_RCBR,  ES_SCLN,  ES_AT,        ES_ASTR,  KC_4,  KC_5,  KC_6,  ES_PLUS,
    ES_GRV,   ES_LBRC,  ES_RBRC,  ES_EQL,   ES_HASH,      KC_0,     KC_1,  KC_2,  KC_3,  ES_DOT,
                            MO(_SYM2_NEW), MO(_FUNC),    KC_TRNS, KC_TRNS
  ),

  [_SYM2_NEW] = LAYOUT(
    ES_CIRC, ES_MORD, ES_PIPE, ES_EXLM, ES_IEXL,      KC_NO,   KC_F7, KC_F8, KC_F9, KC_F10,
    ES_TILD, ES_FORD, ES_AMPR, ES_QUES, ES_IQUE,      KC_NO,   KC_F4, KC_F5, KC_F6, KC_F11,
    ES_CCED, ES_PERC, ES_BSLS, ES_LABK, ES_RABK,      KC_PSCR, KC_F1, KC_F2, KC_F3, KC_F12,
                                    KC_NO, KC_NO,    KC_ENT, KC_NO
  ),

  [_SYM1] = LAYOUT(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,   KC_7,    KC_8,    KC_9,    KC_0,
    ES_LABK, ES_PERC, ES_LPRN, ES_LCBR, ES_LBRC,      ES_EQL, ES_QUES, ES_QUOT, ES_PLUS, ES_ASTR,
    ES_RABK, ES_DLR,  ES_RPRN, ES_RCBR, ES_RBRC,      ES_AT,  ES_EXLM, ES_DQUO, ES_SCLN, ES_SLSH,
                            MO(_FUNC), MO(_SYM2),    KC_TRNS, KC_TRNS
  ),

  [_NAV] = LAYOUT(
    KC_ESC,        KC_SELAL,      KC_FIND,       KC_TRNS,       KC_TRNS,            KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_CAPS,
    OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_RALT),      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS,
    KC_UNDO,       KC_CUT,        KC_COPY,       KC_TAB,        KC_PASTE,           KC_DELL, KC_BSPC, KC_DEL,  KC_TRNS, KC_TRNS,
                                                              KC_TRNS, KC_TRNS,    KC_ENT, MO(_FUNC)
  ),

  [_FUNC] = LAYOUT(
    KC_F1,         KC_F2,         KC_F3,         KC_F4,         KC_F5,              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,      KC_F11,  KC_F12,  KC_PSCR, KC_TRNS, KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                              KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS
  ),

  [_SYM2] = LAYOUT(
    ES_CIRC, ES_UNDS, KC_TRNS, ES_EURO, ES_HASH,      KC_TRNS, KC_BTN1, KC_MS_U, KC_BTN3, KC_BTN2,
    ES_GRV,  ES_TILD, ES_BSLS, ES_PIPE, ES_AMPR,      KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
    ES_IQUE, ES_IEXL, KC_TRNS, ES_CCED, ES_MORD,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS
  )
};

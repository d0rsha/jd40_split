#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
// #define _COLEMAK 1
// #define _DVORAK 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE
  // COLEMAK,
  // DVORAK
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,------------------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  [{  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+-------------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |  ;:  |  "'  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+-------------|
 * |LShift|  \ | |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Rshift |
 * |------+------+------+------+------+------+------+------+------+------+------+-------------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Bksp | Left |  Up  | Down |Right |
 * `------------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x13(
   KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_BSPC, \
   KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT, \
   KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
   ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_RCTL, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT  \
),

/* Lower
 * ,------------------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+-------------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |      |
 * |------+------+------+------+------+------|------+------+------+------+------+-------------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+-------------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |      |
 * `------------------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x13( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS, KC_DEL, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, _______, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,S(KC_NUHS),S(KC_NUBS),_______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, _______ \
),

/* Raise
 * ,------------------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+-------------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |      |
 * |------+------+------+------+------+------|------+------+------+------+------+-------------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+-------------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |      |
 * `------------------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x13( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, KC_DEL, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, _______, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, _______, _______, _______, _______,\
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, _______ \
),

/* Adjust (Lower + Raise)
 * ,------------------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |      |  DEL |
 * |------+------+------+------+------+-------------+------+------+------+------+-------------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|______|______|      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+-------------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+-------------|
 * |      |      |      |      |      |             |      |      |      |      |      |      |
 * `------------------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x13( \
  _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL, \
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______,  _______, _______, _______,\
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,\
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    // case COLEMAK:
    //   if (record->event.pressed) {
    //     set_single_persistent_default_layer(_COLEMAK);
    //   }
    //   return false;
    // case DVORAK:
    //   if (record->event.pressed) {
    //     set_single_persistent_default_layer(_DVORAK);
    //   }
    //   return false;
  }
  return true;
}

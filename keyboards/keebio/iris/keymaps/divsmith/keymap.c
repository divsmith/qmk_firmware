#include QMK_KEYBOARD_H
#include "features/achordion.h"


#define _QWERTY 0
#define SYMBOL 1
#define ARROW 2
#define MEDIA 3

enum custom_keycodes {
  ENT_QWERTY = SAFE_RANGE,
};

// Tap Dance declarations
enum {
   TD_MINS_UNDS,
   TD_EQL_PLUS,
   TD_LBRC,
   TD_RBRC,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
   // Tap once for minus, twice for underscore
   [TD_MINS_UNDS] = ACTION_TAP_DANCE_DOUBLE(KC_MINUS, KC_UNDERSCORE),
   [TD_EQL_PLUS] = ACTION_TAP_DANCE_DOUBLE(KC_EQUAL, KC_PLUS),
   [TD_LBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_CURLY_BRACE, KC_LEFT_BRACKET),
   [TD_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_RIGHT_CURLY_BRACE, KC_RIGHT_BRACKET),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, LSFT_T(KC_A), KC_S, KC_D, LGUI_T(KC_F),   KC_G,                         KC_H,    RGUI_T(KC_J), KC_K, KC_L, RSFT_T(KC_SCLN), RCTL_T(KC_QUOT),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, LOPT_T(KC_Z), KC_X, KC_C, LT(ARROW, KC_V), KC_B, TG(ARROW),      _______,  KC_N,    LT(MEDIA, KC_M),    KC_COMM, KC_DOT,  ROPT_T(KC_SLSH), KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, LT(SYMBOL, KC_ESC), _______,        MT(MOD_HYPR, KC_SPC), KC_ENT, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  
  [SYMBOL] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, KC_BSLS, KC_LPRN, KC_RPRN, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_LSFT, _______, _______, _______, _______,                       TD(TD_MINS_UNDS), TD(TD_EQL_PLUS), TD(TD_LBRC), TD(TD_RBRC), KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, KC_LT, KC_GT, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ), 

  [ARROW] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, QK_BOOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_LSFT, _______, KC_MEH, KC_HYPR, _______,                            KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_LOPT, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, TO(_QWERTY), _______,               _______, KC_ENT, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [MEDIA] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_AUDIO_MUTE, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   if(!process_achordion(keycode, record)) { return false; }

   switch (keycode) {
      case ENT_QWERTY:
         if (record->event.pressed) {
            SEND_STRING("\n");
            layer_move(_QWERTY);
         }
         return false;
   }

   return true;
}

void matrix_scan_user(void) {
   achordion_task();
}

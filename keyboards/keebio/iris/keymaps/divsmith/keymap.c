#include QMK_KEYBOARD_H
#include "features/achordion.h"
#include "features/taphold.h"
#include "features/doubletap-mod.h"

#define _QWERTY 0
#define SYMBOL 1
#define ARROW 2
#define MEDIA 3
#define NAV 4

// Tap Dance declarations
enum {
   TD_LBRC,
   TD_RBRC,
   TD_LPAREN_LT,
   TD_RPAREN_GT,
   TD_PIPE_BSLS,
   TH_MINS_UNDS,
   TH_EQL_PLUS,
   SCLN_CLN_SHFT,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
   // Tap once for minus, twice for underscore
   [TD_LBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_CURLY_BRACE, KC_LEFT_BRACKET),
   [TD_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_RIGHT_CURLY_BRACE, KC_RIGHT_BRACKET),
   [TD_LPAREN_LT] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_PAREN, KC_LEFT_ANGLE_BRACKET),
   [TD_RPAREN_GT] = ACTION_TAP_DANCE_DOUBLE(KC_RIGHT_PAREN, KC_RIGHT_ANGLE_BRACKET),
   [TD_PIPE_BSLS] = ACTION_TAP_DANCE_DOUBLE(KC_PIPE, KC_BACKSLASH),

   [TH_MINS_UNDS] = ACTION_TAP_DANCE_TAP_HOLD(KC_MINUS, KC_UNDERSCORE),
   [TH_EQL_PLUS] = ACTION_TAP_DANCE_TAP_HOLD(KC_EQUAL, KC_PLUS),

   [SCLN_CLN_SHFT] = ACTION_DOUBLE_TAP_HOLD_MODIFIER(KC_SEMICOLON, KC_COLON, KC_RIGHT_SHIFT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    LT(NAV, KC_E),    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, LSFT_T(KC_A), KC_S, KC_D, LGUI_T(KC_F), KC_G,                           KC_H,    RGUI_T(KC_J), KC_K, KC_L, TD(SCLN_CLN_SHFT), RCTL_T(KC_QUOT),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, LOPT_T(KC_Z), KC_X, KC_C, LT(ARROW, KC_V), KC_B, _______,      _______,  KC_N,    LT(MEDIA, KC_M),    KC_COMM, KC_DOT,  ROPT_T(KC_SLSH), KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, LT(SYMBOL, KC_ESC), _______,        MT(MOD_HYPR, KC_SPC), LT(SYMBOL, KC_ENT), _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [SYMBOL] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_EXLM, KC_AT, KC_HASH, KC_DOLLAR, KC_PERC,                            TD(TD_PIPE_BSLS), KC_UNDS, TD(TD_LPAREN_LT), TD(TD_RPAREN_GT), _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, KC_CIRC, KC_AMPR, _______,                            TD(TH_EQL_PLUS), KC_MINS, TD(TD_LBRC), TD(TD_RBRC), KC_SCLN, KC_QUOT,
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
  ),

  [NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, C(KC_LEFT), SCMD(KC_LBRC), SCMD(KC_RBRC), C(KC_RIGHT), _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, HYPR(KC_LEFT), MEH(KC_LEFT), MEH(KC_RIGHT), HYPR(KC_RIGHT), _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,               _______, MEH(KC_ENT), _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   if(!process_achordion(keycode, record)) { return false; }

   tap_dance_action_t *action;

   switch (keycode) {
      case TD(TH_MINS_UNDS):  // list all tap dance keycodes with tap-hold configurations
      case TD(TH_EQL_PLUS):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
   }

   return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
   switch (keycode) {
      case TD(TH_MINS_UNDS):
      case TD(TH_EQL_PLUS):
         return 100;
      default:
         return TAPPING_TERM;
   }
}

void matrix_scan_user(void) {
   achordion_task();
}

// Single and double tap for keycodes, tap and hold for modifier

#pragma once

typedef enum {
   TD_NONE,
   TD_UNKNOWN,
   TD_SINGLE_TAP,
   TD_SINGLE_HOLD,
   TD_DOUBLE_TAP,
   TD_DOUBLE_HOLD
} td_state_t;

typedef struct {
    uint16_t tap;
    uint16_t doubletap;
    uint16_t modifier;
    uint16_t active;
    bool mod_active;
} doubletap_mod_t;

// Single and double tap keycodes, hold for modifier
#define ACTION_DOUBLE_TAP_HOLD_MODIFIER(tap, double, modifier) \
    { .fn = {NULL, doubletap_mod_finished, doubletap_mod_reset}, .user_data = (void *)&((doubletap_mod_t){tap, double, modifier, 0, false}), }

void doubletap_mod_finished(tap_dance_state_t *state, void *user_data) {
    doubletap_mod_t *config = (doubletap_mod_t *)user_data;

    if (state->count == 1) {
        if (state->interrupted || !state->pressed) {
            register_code16(config->tap);
            config->active = config->tap;
        } else {
            // add_mods(config->modifier);
            register_code16(config->modifier);
            config->active = config->modifier;
            // config->mod_active = true;
        }
    } else if (state->count == 2) {
        if (!state->interrupted) {
            register_code16(config->doubletap);
            config->active = config->doubletap;
        }
    }
}   

void doubletap_mod_reset(tap_dance_state_t *state, void *user_data) {
    doubletap_mod_t *config = (doubletap_mod_t *)user_data;

    if (config->active) {
        if (config->mod_active) {
            del_mods(config->active);
            config->mod_active = false;
        } else {
            unregister_code16(config->active);
        }
        config->active = 0;
    }
}
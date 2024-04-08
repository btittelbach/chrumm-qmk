// Copyright 2023 Severin Meyer (@sevmeyer), Bernhard Tittelbach
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
  _QWERTY = 0,
  _FN,
  _CONFIG
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,     KC_8,     KC_9,    KC_0,     KC_MINS, KC_EQL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,     KC_I,     KC_O,    KC_P,     KC_LBRC, KC_RBRC,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,     KC_K,     KC_L,    KC_SCLN,  KC_QUOT, KC_BSLS,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,     KC_COMM,  KC_DOT,  KC_SLSH,  KC_UP,   KC_RSFT,
        KC_LCTL, OSL(1),  KC_LGUI, KC_LALT, KC_SPC,  KC_BSPC, KC_ENT,  KC_SPC,   KC_RALT,  KC_DEL,  KC_LEFT,  KC_DOWN, KC_RIGHT
    ),
    [_FN] = LAYOUT(
        KC_GRV,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_P7,    KC_P8,    KC_P9,   KC_PMNS,  KC_BSPC, KC_F12,
        MO(2),   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_P4,    KC_P5,    KC_P6,   KC_PPLS,  KC_DEL,  KC_ENT,
        _______, KC_APP,  KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, XXXXXXX, KC_P1,    KC_P2,    KC_P3,   KC_PSLS,  XXXXXXX, _______,
        _______, KC_NUBS, KC_BTN2, KC_BTN3, KC_BTN1, KC_MUTE, XXXXXXX, KC_P0,    KC_P0,    KC_PDOT, KC_PAST,  KC_PGUP, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,  _______,  KC_INS,  KC_HOME,  KC_PGDN, KC_END
    ),
    [_CONFIG] = LAYOUT(
        QK_BOOT, KC_ACL0, KC_ACL1, KC_ACL2, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_G, _______,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, RGB_SAI,  RGB_HUI, RGB_TOG,
        _______, _______, KC_BTN5, _______, KC_BTN4, _______, KC_NUM,  _______,  _______,  _______, RGB_SPI,  RGB_VAI, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, RGB_RMOD, RGB_VAD, RGB_MOD
    )
};


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) },
    [_FN] =     { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) },
    [_CONFIG] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
};
#endif

#define HSV_SGREEN        92, 255, 255

#define RGBLED_NUM_L 38

#if defined(RGBLIGHT_LAYERS)
// Light up when shift is pressed or caps lock active
const rgblight_segment_t PROGMEM led_neo_mod2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_CYAN},       // Light 3 LEDs, starting with LED 0
    {RGBLED_NUM_L-1-3, 3, HSV_CYAN}       // Light 3 LEDs, starting with LED 34
);
// Light up when keys above shift are pressed
const rgblight_segment_t PROGMEM led_neo_mod3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 3, HSV_SGREEN},
    {RGBLED_NUM_L-1-6, 3, HSV_SGREEN}
);
// Light up when altgr is held
const rgblight_segment_t PROGMEM led_neo_mod4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 3, HSV_CHARTREUSE},
    {RGBLED_NUM_L-14, 3, HSV_CHARTREUSE}
);
// Light up when shift is pressed or caps lock active
const rgblight_segment_t PROGMEM led_neo_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 3, HSV_CYAN},       // Light 3 LEDs, starting with LED 1
    {RGBLED_NUM_L-1-1-3, 3, HSV_CYAN}       // Light 3 LEDs, starting with LED 33
);
// Light up purple when keyboard _FN layer is active
const rgblight_segment_t PROGMEM led_kbd_fn_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {10, 2, HSV_MAGENTA},
    {13, 2, HSV_MAGENTA},
    {16, 3, HSV_MAGENTA},
    {22, 3, HSV_MAGENTA}
);
// Light up when keyboard _CONFIG layer is active
const rgblight_segment_t PROGMEM led_kbd_config_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {10, 2, HSV_WHITE},
    {13, 2, HSV_WHITE},
    {16, 3, HSV_WHITE},     // Light 2 LEDs, starting with LED 23
    {22, 3, HSV_WHITE}
);
// Light up when numlock is active
const rgblight_segment_t PROGMEM led_numlock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {RGBLED_NUM_L-20, 2, HSV_RED}
);


// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM led_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    led_neo_mod2_layer, //mod2 shift
    led_neo_capslock_layer, //caps-lock
    led_neo_mod3_layer, //mod3 caps
    led_neo_mod4_layer, //mod4 altgr
    led_kbd_fn_layer,
    led_kbd_config_layer,
    led_numlock_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = led_rgb_layers;
}


bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(1, led_state.caps_lock);
    rgblight_set_layer_state(6, led_state.num_lock);
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_LSFT:
    case KC_RSFT:
      rgblight_set_layer_state(0, record->event.pressed);
      return true; // Let QMK send the enter press/release events
    case KC_CAPS:
    case KC_BSLS:
      rgblight_set_layer_state(2, record->event.pressed);
      return true; // Let QMK send the enter press/release events
    case KC_RALT:
    case KC_NUBS:
      rgblight_set_layer_state(3, record->event.pressed);
      return true; // Let QMK send the enter press/release events
    default:
      return true; // Process all other keycodes normally
  }
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    // rgblight_set_layer_state(0, layer_state_cmp(state, _DVORAK));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(4, layer_state_cmp(state, _FN));
    rgblight_set_layer_state(5, layer_state_cmp(state, _CONFIG));
    return state;
}

#endif


/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layers {
    _COLEMAK = 0,
    _SWE,
    _DAN,
    _SYMB,
    _NAVS,
    _NUM,
    _NUMPAD,
    _FUNC,
    _SHORT,
    _SWAYWORK,
    _SWAYMOVE,
    _RUNNER,
};

enum keycodes {
  THUMBSUP = SAFE_RANGE,
  LAUGHING,
  YUM,
  OK_HAND,
  OUML,
  AUML
};

#define HSV_BASE 27, 255, 180
#define HSV_SWE 40, 255, 180
#define HSV_DAN 16, 255, 180

#define TD_LAYER _COLEMAK


// Key defines for readability
#define WORK_F   LT(_SWAYWORK,KC_F)
#define MOVE_P   LT(_SWAYMOVE,KC_P)
#define GUIALT(kc) LGUI(LALT(kc))
#define LOCK_1P LGUI(LALT(LSFT(KC_L)))
#define SHOW_1P LALT(LSFT(KC_X))
#define HUE_TOG LGUI(LALT(LSFT(KC_J)))

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT(
      TD(TD_LAYER), KC_Q,         KC_W,         WORK_F, MOVE_P, KC_G,                                         KC_J,    KC_L,         KC_U,         KC_Y,         KC_SCLN,      _______,
      KC_TAB,       LSFT_T(KC_A), LCTL_T(KC_R), LALT_T(KC_S),     LT(_NAVS,KC_T), LT(_FUNC,KC_D),                               KC_H,    LGUI_T(KC_N), LALT_T(KC_E), LCTL_T(KC_I), LSFT_T(KC_O), KC_QUOT,
      KC_LSFT,      KC_Z,         KC_X,         KC_C,             KC_V,           KC_B,         TG(_RUNNER), THUMBSUP, YUM,    QK_LEAD, KC_K, KC_M,   KC_COMM,   KC_DOT,       KC_SLSH,      KC_RSFT,
                                  KC_MUTE,      KC_DEL,           MO(_NUMPAD),    LCTL_T(KC_SPC), LGUI_T(KC_ENT),        KC_SPC, KC_BSPC, MO(_SYMB), LT(_SHORT,KC_ESCAPE), KC_MEDIA_PLAY_PAUSE
    ),

    [_SWE] = LAYOUT(
      TD(TD_LAYER), _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, RALT(KC_W), RALT(KC_P),
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, RALT(KC_Q),
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_DAN] = LAYOUT(
      TD(TD_LAYER), _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, RALT(KC_W), RALT(KC_L),
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, RALT(KC_Z),
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_SYMB] = LAYOUT(
      _______, KC_CIRC, KC_DLR,  KC_LCBR, KC_RCBR, KC_HASH,                                               KC_AMPR, KC_EXLM, KC_QUES, KC_UNDS, KC_SCLN, _______,
      _______, KC_COLN, KC_EQL,  KC_LPRN, KC_RPRN, KC_AT,                                                 KC_DQUO, KC_PLUS, KC_ASTR, KC_MINS, KC_GRAVE, KC_QUOTE,
      _______, KC_EXLM, KC_PERC, KC_LBRC, LT(_NUM, KC_RBRC), KC_TILD, _______, _______, _______, _______, KC_BSLS, KC_PIPE, KC_LABK, KC_RABK, _______, _______,
                                 HUE_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_NAVS] = LAYOUT(
      TO(_COLEMAK),   _______, _______, _______, _______, _______,                              XXXXXXX, KC_PGUP, KC_UP,  KC_PGDN, XXXXXXX, XXXXXXX,
      _______, _______, _______, _______, _______, _______,                                     KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END,  _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_INSERT, LALT(LCTL(KC_LEFT)),LALT(KC_1), LALT(LCTL(KC_RIGHT)), XXXXXXX,  _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_NUMPAD] = LAYOUT(
      TO(_COLEMAK), _______, _______, _______, _______, _______,                                KC_ASTR, KC_7,    KC_8,    KC_9, KC_SLSH, _______,
      _______, _______, _______, _______, _______, _______,                                     KC_PLUS, KC_4,    KC_5,    KC_6, KC_MINS, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_COLN, KC_1,    KC_2,    KC_3, KC_DOT,  _______,
                                 _______, _______, _______, _______, _______, _______, _______, KC_0,    _______, _______
    ),

   [_NUM] = LAYOUT(
      TO(_COLEMAK), _______, _______, _______, _______, _______,                                     _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
         KC_9,    KC_7,    KC_5,    KC_3,    KC_1, _______,                                     _______,    KC_0,    KC_2,     KC_4,    KC_6,   KC_8,
      _______, _______, _______, KC_ASTR, KC_PLUS, _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_SLSH, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_FUNC] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
      _______, _______, _______, _______, _______, _______,                                     _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F12,  _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_SHORT] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, _______,
      _______, _______, _______, _______, _______, _______,                                    RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI,  RGB_MOD, _______,
      _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, _______,
                                 HUE_TOG, LOCK_1P, SHOW_1P,_______, _______, _______, _______, _______, _______, _______
    ),

    [_SWAYWORK] = LAYOUT(
       _______, _______, _______, _______, LGUI(KC_TAB), _______,                                XXXXXXX, LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), XXXXXXX, _______,
       _______, _______, _______, _______, _______, _______,                                     LALT(LGUI(KC_LEFT)), LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), LALT(LGUI(KC_RIGHT)), _______,
       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), XXXXXXX, _______,
                                  _______, _______, LCTL(LSFT(KC_PSCR)), _______, _______, _______, _______, LGUI(KC_0), _______,    _______
    ),

    [_SWAYMOVE] = LAYOUT(
       _______, _______, _______, _______, _______, _______,                                     _______, LGUI(KC_PGUP), LGUI(KC_UP), _______, _______, _______,
       _______, _______, _______, _______, _______, _______,                                     _______, LGUI(KC_LEFT), LGUI(KC_DOWN), LGUI(KC_RIGHT), _______, _______,
       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_RUNNER] = LAYOUT(
       TO(_COLEMAK), LCTL(KC_F2), LCTL(KC_F5), LSFT(KC_F10), LSFT(KC_F9), XXXXXXX,       XXXXXXX, KC_PGUP, KC_UP,  KC_PGDN, XXXXXXX, XXXXXXX,
       _______, LALT(KC_F10), LSFT(KC_F8), KC_F7,  KC_F8,   KC_F9,                               KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END,  _______,
       _______, LCTL(LSFT(KC_F8)), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______,  KC_INSERT, LALT(LCTL(KC_LEFT)),LALT(KC_1), LALT(LCTL(KC_RIGHT)), XXXXXXX, _______,
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t mods = get_mods();
    if (record->event.pressed) {
        switch(keycode) {
            case OUML:
                if (mods & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                }
                register_code(KC_LALT);
                tap_code(KC_U);
                unregister_code(KC_LALT);
                set_mods(mods);
                tap_code(KC_O);
                return false;
            case AUML:
                if (mods & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                }
                register_code(KC_LALT);
                tap_code(KC_U);
                unregister_code(KC_LALT);
                set_mods(mods);
                tap_code(KC_A);
                return false;
            case THUMBSUP:
                SEND_STRING(":thumbsup:");
                return false;
            case LAUGHING:
                SEND_STRING(":laughing:");
                return false;
            case YUM:
                SEND_STRING(":yum:");
                return false;
            case OK_HAND:
                SEND_STRING(":ok_hand:");
                return false;
        }
    }
    return true;
}

void dance_lang(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        default:
        case 1:
            layer_off(_SWE);
            layer_off(_DAN);
            break;
        case 2:
            layer_on(_SWE);
            layer_off(_DAN);
            break;
        case 3:
            layer_on(_DAN);
            layer_off(_SWE);
            break;
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_LAYER] = ACTION_TAP_DANCE_FN(dance_lang),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LT(_NAVS,KC_T):
      return TAPPING_TERM - 45;
    case LSFT_T(KC_A):
      return TAPPING_TERM + 50;
    default:
      return TAPPING_TERM;
  }
}

void rgblight_set_hsv_and_mode(uint8_t hue, uint8_t sat, uint8_t val, uint8_t mode) {
    rgblight_mode_noeeprom(mode);
    wait_us(175);  // Add a slight delay between color and mode to ensure it's processed correctly
    rgblight_sethsv_noeeprom(hue, sat, val);
}

void keyboard_post_init_user(void){
    rgblight_enable_noeeprom();
    rgblight_set_hsv_and_mode(HSV_BASE, RGBLIGHT_MODE_STATIC_LIGHT);
}

#ifdef LEADER_ENABLE
void leader_end_user(void) {
    if (leader_sequence_one_key(KC_C)) { // Inline Code
        SEND_STRING("`` " SS_TAP(X_LEFT) SS_TAP(X_LEFT));
    }
    if (leader_sequence_two_keys(KC_E, KC_N)) {
        SEND_STRING("if err != nil {" SS_TAP(X_ENTER));
    }
    if (leader_sequence_two_keys(KC_S, KC_K)) {
        // kill ssh sessions
        SEND_STRING(SS_TAP(X_ENTER) "~.");
    }
}
#endif

uint8_t last_rgb_layer = _COLEMAK;

layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_ENABLE
    uint8_t layer = get_highest_layer(state);

    if (last_rgb_layer != layer) {
        switch (layer) {
            case _RUNNER:
                rgblight_set_hsv_and_mode(HSV_BLUE, RGBLIGHT_MODE_BREATHING + 2);
                last_rgb_layer = layer;
                break;
            case _SWE:
                last_rgb_layer = layer;
                rgblight_set_hsv_and_mode(HSV_SWE, RGBLIGHT_MODE_STATIC_LIGHT);
                break;
            case _DAN:
                last_rgb_layer = layer;
                rgblight_set_hsv_and_mode(HSV_DAN, RGBLIGHT_MODE_STATIC_LIGHT);
                break;
            case _COLEMAK:
                last_rgb_layer = layer;
                rgblight_set_hsv_and_mode(HSV_BASE, RGBLIGHT_MODE_STATIC_LIGHT);
                break;
        }
    }
#endif
    return state;
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // QMK Logo
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        oled_write_P(qmk_logo, false);
        oled_write_P(PSTR("       Calle's Kyria\n\n"), false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _COLEMAK:
                oled_write_P(PSTR("Colemak\n"), false);
                break;
            case _SWE:
                oled_write_P(PSTR("Swedish\n"), false);
                break;
            case _DAN:
                oled_write_P(PSTR("Danish\n"), false);
                break;
            case _NAVS:
                oled_write_P(PSTR("Navigation\n"), false);
                break;
            case _SYMB:
                oled_write_P(PSTR("Symbols\n"), false);
                break;
            case _NUMPAD:
                oled_write_P(PSTR("Numpad\n"), false);
                break;
            case _NUM:
                oled_write_P(PSTR("Numbers\n"), false);
                break;
            case _FUNC:
                oled_write_P(PSTR("Function\n"), false);
                break;
            case _SWAYWORK:
                oled_write_P(PSTR("Sway work\n"), false);
                break;
            case _SWAYMOVE:
                oled_write_P(PSTR("Sway move\n"), false);
                break;
            case _SHORT:
                oled_write_P(PSTR("Shortcuts\n"), false);
                break;
            case _RUNNER:
                oled_write_P(PSTR("Debug\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }
        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    } else {
        // clang-format off
        static const char PROGMEM kyria_logo[] = {
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
            0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };
        // clang-format on
        oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
    }
    return false;
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch (get_highest_layer(layer_state)) {
            case _COLEMAK:
            case _SWE:
            case _DAN:
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
            default:
                if (clockwise) {
                    SEND_STRING(SS_LGUI(SS_LALT(SS_LSFT("u"))));
                } else {
                    SEND_STRING(SS_LGUI(SS_LALT(SS_LSFT("y"))));
                }
                break;
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_MNXT);
        } else {
            tap_code(KC_MPRV);
        }
    }
    return false;
}
#endif


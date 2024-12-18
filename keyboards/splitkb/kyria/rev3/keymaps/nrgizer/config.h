/* Copyright 2022 Thomas Baart <thomas@splitkb.com>
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

#pragma once

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_RGB_TEST
    #define RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_EFFECT_TWINKLE
    #define RGBLIGHT_HUE_STEP 6
    #define RGBLIGHT_SAT_STEP 6
    #define RGBLIGHT_VAL_STEP 8
    #ifndef RGBLIGHT_LIMIT_VAL
        #define RGBLIGHT_LIMIT_VAL 150
    #endif
#endif

#ifdef RGB_MATRIX_ENABLE
    #define ENABLE_RGB_MATRIX_BREATHING
    #define ENABLE_RGB_MATRIX_SOLID_COLOR
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
    #define ENABLE_RGB_MATRIX_TYPING_HEATMAP
    #define ENABLE_RGB_MATRIX_RAINBOW_BEACON

    #define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 50
    #ifndef RGB_MATRIX_MAXIMUM_BRIGHTNESS
        #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 175
    #endif
    #define RGB_MATRIX_SLEEP
#endif

// https://docs.qmk.fm/config_options#behaviors-that-can-be-configured
#define TAPPING_TERM_PER_KEY
#define TAPPING_TERM 190

#define ENCODER_RESOLUTION 2

#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 350

#define ONESHOT_TAP_TOGGLE 3
#define ONESHOT_TIMEOUT 2000

// Allows media codes to properly register in macros and rotary encoder code
#define TAP_CODE_DELAY 10

// Dynamic macros https://docs.qmk.fm/features/dynamic_macros#customization
#define DYNAMIC_MACRO_NO_NESTING // Do not allow macros inside of macros
#define DYNAMIC_MACRO_SIZE 256  // Default 128

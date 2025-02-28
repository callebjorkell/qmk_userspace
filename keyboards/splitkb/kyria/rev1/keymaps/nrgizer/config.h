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

#define RGBLIGHT_DISABLE_KEYCODES
#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_EFFECT_BREATHING
  #define RGBLIGHT_SLEEP
  #define RGBLIGHT_HUE_STEP 6
  #define RGBLIGHT_SAT_STEP 6
  #define RGBLIGHT_VAL_STEP 8
#endif

#define ENCODER_RESOLUTION 2

#define TAPPING_TERM_PER_KEY
#define TAPPING_TERM 210

#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 350

#define ONESHOT_TAP_TOGGLE 3
#define ONESHOT_TIMEOUT 2000

#define EE_HANDS

// Allows media codes to properly register in macros and rotary encoder code
#define TAP_CODE_DELAY 10

#define DYNAMIC_MACRO_NO_NESTING

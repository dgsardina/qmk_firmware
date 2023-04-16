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

//#ifdef RGBLIGHT_ENABLE
//#    define RGBLIGHT_ANIMATIONS
//#    define RGBLIGHT_HUE_STEP  8
//#    define RGBLIGHT_SAT_STEP  8
//#    define RGBLIGHT_VAL_STEP  8
//#    define RGBLIGHT_LIMIT_VAL 150
//#endif

// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 200

// Lets you roll mod-tap keys
#define IGNORE_MOD_TAP_INTERRUPT

// Faster trigger of mod when pressing the second key without releasing the first
#define PERMISSIVE_HOLD

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
//#define TAPPING_FORCE_HOLD

// Allows for either side as the master.
#define EE_HANDS

#ifdef ENCODER_ENABLE
  // EC11K encoders have a different resolution than other EC11 encoders.
  // When using the default resolution of 4, if you notice your encoder skipping
  // every other tick, lower the resolution to 2.
  #define ENCODER_RESOLUTION 2
#endif

// Pimoroni trackball settings
#ifdef POINTING_DEVICE_ENABLE
  //#define POINTING_DEVICE_TASK_THROTTLE_MS 6
  #define POINTING_DEVICE_INVERT_X
  #define POINTING_DEVICE_INVERT_Y
#endif


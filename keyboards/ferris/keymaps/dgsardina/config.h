/* Copyright 2022 Thomas Baart <dgsardina@gmail.com>
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

// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 200

// Faster trigger of mod when pressing the second key without releasing the first
#define PERMISSIVE_HOLD

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
//#define TAPPING_FORCE_HOLD

// Allows for either side as the master.
#define EE_HANDS

#ifdef CONVERT_TO_LIATRIS
  // Specific for Liatris
  // See: https://docs.splitkb.com/hc/en-us/articles/5799711553820-Power-LED

  // To use the LED as a Caps Lock indicator
  #define LED_CAPS_LOCK_PIN 24
  #define LED_PIN_ON_STATE 0

  // To sync led status on both halves
  #define SPLIT_LED_STATE_ENABLE
#endif

// // Specific for RP2040
// // See https://docs.qmk.fm/#/platformdev_rp2040
//
// // Activates the double-tap behavior
// #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
//
// // Timeout window in ms in which the double tap can occur.
// #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U
//
// // Specify a optional status led by GPIO number which blinks when entering the bootloader
// #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17


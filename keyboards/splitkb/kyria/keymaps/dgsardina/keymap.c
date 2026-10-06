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
#include "keymap_us_international_linux.h"

enum layers {
    _COLEMAK_DH = 0,
    _ACC,
    _SYM,
    _NAV,
    _FUNCTION,
};

/* Aliases for readability */
#define SYM_BSP  LT(     _SYM, KC_BSPC)
#define NAV_SPC  LT(     _NAV, KC_SPC)
#define ACC_TAB  LT(     _ACC, KC_TAB)
#define FUN_ENT  LT(_FUNCTION, KC_ENT)

/* Colemak-dhm home row modifiers */
#define GUI_A LGUI_T(KC_A)
#define ALT_R LALT_T(KC_R)
#define CTL_S LCTL_T(KC_S)
#define SHFT_T LSFT_T(KC_T)

#define SFT_N RSFT_T(KC_N)
#define CTL_E RCTL_T(KC_E)
#define ALT_I LALT_T(KC_I)
#define GUI_O RGUI_T(KC_O)

/*
 * This keymap mirrors keyboards/ferris/keymaps/dgsardina (34 keys).
 * The extra Kyria keys (outer columns, inner thumb/row-3 keys and the
 * outermost thumb keys) are left unmapped. The rotary encoders are handled
 * in encoder_update_user() below and are not part of the key matrix.
 */

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK_DH] = LAYOUT(
  //                                                                              Base Layer: Colemak DH
  //┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                                             ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
  //│          │    Q     │    W     │    F     │    P     │    B     │                                             │    J     │    L     │    U     │    Y     │   ;  :   │          │
      XXXXXXX  ,   KC_Q   ,   KC_W   ,   KC_F   ,   KC_P   ,   KC_B   ,                                                 KC_J   ,   KC_L   ,   KC_U   ,   KC_Y   , KC_SCLN  , XXXXXXX  ,
  //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                             ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
  //│          │ A / GUI  │ R / ALT  │ S / CTL  │ T / SHFT │    G     │                                             │    M     │ N / SHFT │ E / CTL  │ I / ALT  │ O / GUI  │          │
      XXXXXXX  ,  GUI_A   ,  ALT_R   ,  CTL_S   ,  SHFT_T  ,   KC_G   ,                                                 KC_M   ,  SFT_N   ,  CTL_E   ,  ALT_I   ,  GUI_O   , XXXXXXX  ,
  //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┬──────────┐ ┌──────────┬──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
  //│          │    Z     │    X     │    C     │    D     │    V     │          │          │ │          │          │    K     │    H     │   ,  ;   │   .  :   │   -  _   │          │
      XXXXXXX  ,   KC_Z   ,   KC_X   ,   KC_C   ,   KC_D   ,   KC_V   , XXXXXXX  , XXXXXXX  ,   XXXXXXX  , XXXXXXX  ,   KC_K   ,   KC_H   , KC_COMM  ,  KC_DOT  , US_MINS  , XXXXXXX  ,
  //└──────────┴──────────┴──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤ ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┴──────────┴──────────┘
  //                                 │          │          │Ent/Fkeys │Space/Nav │          │ │          │ Back/Sym │ Tab/Acc  │          │          │
                                       XXXXXXX  , XXXXXXX  , FUN_ENT  , NAV_SPC  , XXXXXXX  ,   XXXXXXX  , SYM_BSP  , ACC_TAB  , XXXXXXX  , XXXXXXX
  //                                 └──────────┴──────────┴──────────┴──────────┴──────────┘ └──────────┴──────────┴──────────┴──────────┴──────────┘
  ),

  [_ACC] = LAYOUT(
  //                                                                           Accents Layer: Colemak DH Accents and ES symbols
  //┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                                             ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
  //│          │    ¡     │    <     │    {     │    }     │          │                                             │    `     │          │    ú     │    ü     │    ¿     │          │
      _______  , US_IEXL  , US_LABK  , US_LCBR  , US_RCBR  , XXXXXXX  ,                                               US_DGRV  , XXXXXXX  , US_UACU  , US_UDIA  , US_IQUE  , _______  ,
  //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                             ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
  //│          │    á     │    >     │    (     │    )     │          │                                             │          │    ñ     │    é     │    í     │    ó     │          │
      _______  , US_AACU  , US_RABK  , US_LPRN  , US_RPRN  , XXXXXXX  ,                                               XXXXXXX  , US_NTIL  , US_EACU  , US_IACU  , US_OACU  , _______  ,
  //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┬──────────┐ ┌──────────┬──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
  //│          │          │          │    [     │    ]     │          │          │          │ │          │          │          │          │    €     │          │          │          │
      _______  , XXXXXXX  , XXXXXXX  , US_LBRC  , US_RBRC  , XXXXXXX  , _______  , _______  ,   _______  , _______  , XXXXXXX  , XXXXXXX  , US_EURO  , XXXXXXX  , XXXXXXX  , _______  ,
  //└──────────┴──────────┴──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤ ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┴──────────┴──────────┘
  //                                 │          │          │Ent/Fkeys │Space/Nav │          │ │          │ Back/Sym │ Tab/Acc  │          │          │
                                       _______  , _______  , _______  , _______  , _______  ,   _______  , _______  , _______  , _______  , _______
  //                                 └──────────┴──────────┴──────────┴──────────┴──────────┘ └──────────┴──────────┴──────────┴──────────┴──────────┘
  ),

  [_SYM] = LAYOUT(
  //                                                                               Sym Layer: Numbers and symbols
  //┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                                             ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
  //│          │    1     │    2     │    3     │    4     │    5     │                                             │    6     │    7     │    8     │    9     │    0     │          │
      _______  ,   KC_1   ,   KC_2   ,   KC_3   ,   KC_4   ,   KC_5   ,                                                 KC_6   ,   KC_7   ,   KC_8   ,   KC_9   ,   KC_0   , _______  ,
  //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                             ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
  //│          │    !     │    "     │    '     │    $     │    %     │                                             │    &     │    /     │    =     │    *     │    +     │          │
      _______  , US_EXLM  , US_DQUO  , US_QUOT  ,  US_DLR  , US_PERC  ,                                               US_AMPR  , US_SLSH  ,  US_EQL  , US_ASTR  , US_PLUS  , _______  ,
  //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┬──────────┐ ┌──────────┬──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
  //│          │    |     │    @     │    #     │    ~     │    \     │          │          │ │          │          │    ^     │    `     │   ,  ;   │   .  :   │    ?     │          │
      _______  , US_PIPE  ,  US_AT   , US_HASH  , US_TILD  , US_BSLS  , _______  , _______  ,   _______  , _______  , US_CIRC  , US_DGRV  , _______  , _______  , US_QUES  , _______  ,
  //└──────────┴──────────┴──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤ ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┴──────────┴──────────┘
  //                                 │          │          │   ´  ¨   │  CapsLk  │          │ │          │ Back/Sym │ Tab/Acc  │          │          │
                                       _______  , _______  , US_ACUT  , KC_CAPS  , _______  ,   _______  , _______  , _______  , _______  , _______
  //                                 └──────────┴──────────┴──────────┴──────────┴──────────┘ └──────────┴──────────┴──────────┴──────────┴──────────┘
  ),

  [_NAV] = LAYOUT(
  //                                                                               Nav Layer: Navigation
  //┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                                             ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
  //│          │          │          │          │          │          │                                             │          │   End    │   Home   │          │          │          │
      _______  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                                               XXXXXXX  ,  KC_END  , KC_HOME  , XXXXXXX  , XXXXXXX  , _______  ,
  //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                             ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
  //│          │   GUI    │   Alt    │   Ctrl   │  Shift   │          │                                             │    ←     │    ↓     │    ↑     │    →     │          │          │
      _______  , KC_LGUI  , KC_LALT  , KC_LCTL  , KC_LSFT  , XXXXXXX  ,                                               KC_LEFT  , KC_DOWN  ,  KC_UP   , KC_RGHT  , XXXXXXX  , _______  ,
  //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┬──────────┐ ┌──────────┬──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
  //│          │          │          │          │          │          │          │          │ │          │          │          │   PgDn   │   PgUp   │          │          │          │
      _______  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , _______  , _______  ,   _______  , _______  , XXXXXXX  , KC_PGDN  , KC_PGUP  , XXXXXXX  , XXXXXXX  , _______  ,
  //└──────────┴──────────┴──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤ ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┴──────────┴──────────┘
  //                                 │          │          │          │          │          │ │          │  Delete  │   Esc    │          │          │
                                       _______  , _______  , _______  , _______  , _______  ,   _______  ,  KC_DEL  ,  KC_ESC  , _______  , _______
  //                                 └──────────┴──────────┴──────────┴──────────┴──────────┘ └──────────┴──────────┴──────────┴──────────┴──────────┘
  ),

  [_FUNCTION] = LAYOUT(
  //                                                                          Function Layer: Function keys and RGB underglow (hold Shift to reverse the UG keys)
  //┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                                             ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
  //│          │    F9    │   F10    │   F11    │   F12    │          │                                             │  UG Tog  │  UG Mod  │  UG Hue  │  UG Sat  │  UG Val  │          │
      _______  ,  KC_F9   ,  KC_F10  ,  KC_F11  ,  KC_F12  , XXXXXXX  ,                                               UG_TOGG  , UG_NEXT  , UG_HUEU  , UG_SATU  , UG_VALU  , _______  ,
  //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                             ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
  //│          │    F5    │    F6    │    F7    │    F8    │          │                                             │   Mute   │  Shift   │   Ctrl   │   Alt    │   GUI    │          │
      _______  ,  KC_F5   ,  KC_F6   ,  KC_F7   ,  KC_F8   , XXXXXXX  ,                                               KC_MUTE  , KC_RSFT  , KC_RCTL  , KC_LALT  , KC_RGUI  , _______  ,
  //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┬──────────┐ ┌──────────┬──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
  //│          │    F1    │    F2    │    F3    │    F4    │          │          │          │ │          │          │Bootloader│   Vol-   │   Vol+   │  Insert  │  PrtSc   │          │
      _______  ,  KC_F1   ,  KC_F2   ,  KC_F3   ,  KC_F4   , XXXXXXX  , _______  , _______  ,   _______  , _______  , QK_BOOT  , KC_VOLD  , KC_VOLU  ,  KC_INS  , KC_PSCR  , _______  ,
  //└──────────┴──────────┴──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤ ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┴──────────┴──────────┘
  //                                 │          │          │          │          │          │ │          │          │          │          │          │
                                       _______  , _______  , _______  , _______  , _______  ,   _______  , _______  , _______  , _______  , _______
  //                                 └──────────┴──────────┴──────────┴──────────┴──────────┘ └──────────┴──────────┴──────────┴──────────┴──────────┘
  )
};

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // QMK Logo and version information
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        oled_write_P(qmk_logo, false);
        oled_write_P(PSTR("Kyria rev2.0\n\n"), false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _COLEMAK_DH:
                oled_write_P(PSTR("Colemak-DH\n"), false);
                break;
            case _ACC:
                oled_write_P(PSTR("Accents\n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("Nav\n"), false);
                break;
            case _SYM:
                oled_write_P(PSTR("Sym\n"), false);
                break;
            case _FUNCTION:
                oled_write_P(PSTR("Function\n"), false);
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
    if (get_highest_layer(layer_state|default_layer_state) < _SYM) {
        if (index == 0) {
            // Up & Down
            if (clockwise) {
                tap_code(KC_DOWN);
            } else {
                tap_code(KC_UP);
            }
        } else if (index == 1) {
            // Left & Right
            if (clockwise) {
                tap_code(KC_RGHT);
            } else {
                tap_code(KC_LEFT);
            }
        }
    } else { /*  Layers _NAV and above */
        if (index == 0) {
            // Page up/Page down
            if (clockwise) {
                tap_code(KC_PGDN);
            } else {
                tap_code(KC_PGUP);
            }
        } else if (index == 1) {
            // Volume control
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        }
    }
    return false;
}
#endif

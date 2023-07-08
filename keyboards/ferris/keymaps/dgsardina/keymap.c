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
#include "keymap_spanish.h"

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
#define ES_EUR   ALGR(ES_E)

/* Colemak-dhm home row modifiers */
#define GUI_A LGUI_T(KC_A)
#define ALT_R LALT_T(KC_R)
#define CTL_S LCTL_T(KC_S)
#define SHFT_T LSFT_T(KC_T)

#define SFT_N RSFT_T(KC_N)
#define CTL_E RCTL_T(KC_E)
#define ALT_I LALT_T(KC_I)
#define GUI_O RGUI_T(KC_O)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Colemak DH
 *
 * ┌──────┬──────┬──────┬──────┬──────┐          ┌──────┬──────┬──────┬──────┬──────┐
 * │   Q  │   W  │   F  │   P  │   B  │          │   J  │   L  │   U  │   Y  │   Ñ  │
 * ├──────┼──────┼──────┼──────┼──────┤          ├──────┼──────┼──────┼──────┼──────┤
 * │   A  │   R  │   S  │   T  │   G  │          │   M  │   N  │   E  │   I  │   O  │
 * ├──────┼──────┼──────┼──────┼──────┤          ├──────┼──────┼──────┼──────┼──────┤
 * │   Z  │   X  │   C  │   D  │   V  │          │   K  │   H  │  , ; │  . : │  - _ │
 * └──────┴──────┴──────┴─┬────┴──┬───┴───┐ ┌────┴──┬───┴───┬──┴──────┴──────┴──────┘
 *                        │Ent/Fun│Nav/Spc│ │Bsp/Sym│Tab/Acc│
 *                        └───────┴───────┘ └───────┴───────┘
 */
  [_COLEMAK_DH] = LAYOUT(
  //                                             Base Layer:    Colemak DH
  //┌──────────┬──────────┬──────────┬──────────┬──────────┐    ┌──────────┬──────────┬──────────┬──────────┬──────────┐
  //│    Q     │    W     │    F     │    P     │    B     │    │    J     │    L     │    U     │    Y     │    Ñ     │
        KC_Q   ,   KC_W   ,   KC_F   ,   KC_P   ,   KC_B   ,        KC_J   ,   KC_L   ,   KC_U   ,   KC_Y   ,  ES_NTIL ,
  //├──────────┼──────────┼──────────┼──────────┼──────────┤    ├──────────┼──────────┼──────────┼──────────┼──────────┤
  //│  A / GUI │  R / ALT │ S / CTL  │ T / SHFT │    G     │    │    M     │    N     │    E     │    I     │    O     │
        GUI_A  ,   ALT_R  ,   CTL_S  ,  SHFT_T  ,   KC_G   ,        KC_M   ,   SFT_N  ,   CTL_E  ,   ALT_I  ,   GUI_O  ,
  //├──────────┼──────────┼──────────┼──────────┼──────────┤    ├──────────┼──────────┼──────────┼──────────┼──────────┤
  //│    Z     │    X     │    C     │    D     │    V     │    │    K     │    H     │   ,  ;   │   .  :   │   -  _   │
        KC_Z   ,   KC_X   ,   KC_C   ,   KC_D   ,   KC_V   ,        KC_K   ,   KC_H   ,  KC_COMM ,  KC_DOT  ,  KC_SLSH ,
  //└──────────┴──────────┴┬─────────┴──────┬───┴──────────┴─┐┌─┴──────────┴───┬──────┴─────────┬┴──────────┴──────────┘
  //                       │   Ent / Fkeys  │   Space / Nav  ││   Back / Sym   │    Tab / Acc   │
                                FUN_ENT     ,    NAV_SPC     ,      SYM_BSP    ,    ACC_TAB
  //                       └────────────────┴────────────────┘└────────────────┴────────────────┘
  ),

  [_ACC] = LAYOUT(
  //                                          Accents Layer:    Colemak DH Accents and ES symbols
  //┌──────────┬──────────┬──────────┬──────────┬──────────┐    ┌──────────┬──────────┬──────────┬──────────┬──────────┐
  //│    ¡     │     <    │     {    │     }    │          │    │    `     │          │    ú     │    ü     │    ¿     │
       ES_IEXL ,  ES_LABK ,  ES_LCBR ,  ES_RCBR ,  XXXXXXX ,       ES_GRV  ,  XXXXXXX ,  XXXXXXX ,  XXXXXXX ,  ES_IQUE ,
  //├──────────┼──────────┼──────────┼──────────┼──────────┤    ├──────────┼──────────┼──────────┼──────────┼──────────┤
  //│    á     │     >    │     (    │     )    │          │    │          │    ñ     │    é     │    í     │    ó     │
       XXXXXXX ,  ES_RABK ,  ES_LPRN ,  ES_RPRN ,  XXXXXXX ,       XXXXXXX ,  ES_NTIL ,  XXXXXXX ,  XXXXXXX ,  XXXXXXX ,
  //├──────────┼──────────┼──────────┼──────────┼──────────┤    ├──────────┼──────────┼──────────┼──────────┼──────────┤
  //│          │          │     [    │     ]    │          │    │          │          │    €     │          │          │
       XXXXXXX ,  XXXXXXX ,  ES_LBRC ,  ES_RBRC ,  XXXXXXX ,       XXXXXXX ,  XXXXXXX ,  ES_EUR  ,  XXXXXXX ,  XXXXXXX ,
  //└──────────┴──────────┴┬─────────┴──────┬───┴──────────┴─┐┌─┴──────────┴───┬──────┴─────────┬┴──────────┴──────────┘
  //                       │   Ent / Fkeys  │   Space / Nav  ││   Back / Sym   │    Tab / Acc   │
                                 _______    ,     _______    ,      _______    ,     _______
  //                       └────────────────┴────────────────┘└────────────────┴────────────────┘
  ),

  [_SYM] = LAYOUT(
  //                                              Sym Layer:    Numbers and symbols
  //┌──────────┬──────────┬──────────┬──────────┬──────────┐    ┌──────────┬──────────┬──────────┬──────────┬──────────┐
  //│    1     │    2     │    3     │    4     │    5     │    │    6     │    7     │    8     │    9     │    0     │
        KC_1   ,   KC_2   ,   KC_3   ,   KC_4   ,   KC_5   ,        KC_6   ,   KC_7   ,   KC_8   ,   KC_9   ,   KC_0   ,
  //├──────────┼──────────┼──────────┼──────────┼──────────┤    ├──────────┼──────────┼──────────┼──────────┼──────────┤
  //│    !     │    \"    │    '     │    $     │    %     │    │    &     │    /     │    =     │    *     │    +     │
       ES_EXLM ,  ES_DQUO ,  ES_QUOT ,  ES_DLR  ,  ES_PERC ,       ES_AMPR ,  ES_SLSH ,  ES_EQL  ,  ES_ASTR ,  ES_PLUS ,
  //├──────────┼──────────┼──────────┼──────────┼──────────┤    ├──────────┼──────────┼──────────┼──────────┼──────────┤
  //│    |     │    @     │    #     │    ~     │    \     │    │    ^     │    `     │   , ;    │   . :    │    ?     │
       ES_PIPE ,   ES_AT  ,  ES_HASH ,  ES_TILD ,  ES_BSLS ,       ES_CIRC ,  ES_GRV  ,  _______ ,  _______ ,  ES_QUES ,
  //└──────────┴──────────┴┬─────────┴──────┬───┴──────────┴─┐┌─┴──────────┴───┬──────┴─────────┬┴──────────┴──────────┘
  //                       │      ´  ¨      │     CapsLk     ││   Back / Sym   │    Tab / Acc   │
                                 ES_ACUT    ,     KC_CAPS    ,      _______    ,     _______
  //                       └────────────────┴────────────────┘└────────────────┴────────────────┘
  ),

  [_NAV] = LAYOUT(
  //                                              Nav Layer:    Navigation
  //┌──────────┬──────────┬──────────┬──────────┬──────────┐    ┌──────────┬──────────┬──────────┬──────────┬──────────┐
  //│          │          │          │          │          │    │          │    End   │   Home   │          │          │
       XXXXXXX ,  XXXXXXX ,  XXXXXXX ,  XXXXXXX ,  XXXXXXX ,       XXXXXXX ,  KC_END  ,  KC_HOME ,  XXXXXXX ,  XXXXXXX ,
  //├──────────┼──────────┼──────────┼──────────┼──────────┤    ├──────────┼──────────┼──────────┼──────────┼──────────┤
  //│    GUI   │    Alt   │   Ctrl   │    GUI   │          │    │    ←     │    ↓     │    ↑     │    →     │          │
       KC_LGUI ,  KC_LALT ,  KC_LCTL ,  KC_RGUI ,  XXXXXXX ,       KC_LEFT ,  KC_DOWN ,  KC_UP   ,  KC_RGHT ,  XXXXXXX ,
  //├──────────┼──────────┼──────────┼──────────┼──────────┤    ├──────────┼──────────┼──────────┼──────────┼──────────┤
  //│          │          │          │          │          │    │          │   PgDn   │   PgUp   │          │          │
       XXXXXXX ,  XXXXXXX ,  XXXXXXX ,  XXXXXXX ,  XXXXXXX ,       XXXXXXX ,  KC_PGDN ,  KC_PGUP ,  XXXXXXX ,  XXXXXXX ,
  //└──────────┴──────────┴┬─────────┴──────┬───┴──────────┴─┐┌─┴──────────┴───┬──────┴─────────┬┴──────────┴──────────┘
  //                       │                │                ││     Delete     │       Esc      │
                                 _______    ,     _______    ,      KC_DEL     ,      KC_ESC
  //                       └────────────────┴────────────────┘└────────────────┴────────────────┘
  ),

  [_FUNCTION] = LAYOUT(
  //                                         Function Layer:    Function Keys
  //┌──────────┬──────────┬──────────┬──────────┬──────────┐    ┌──────────┬──────────┬──────────┬──────────┬──────────┐
  //│    F9    │    F10   │    F11   │    F12   │          │    │          │          │          │          │          │
        KC_F9  ,   KC_F10 ,  KC_F11  ,   KC_F12 ,  XXXXXXX ,       XXXXXXX ,  XXXXXXX ,  XXXXXXX ,  XXXXXXX ,  XXXXXXX ,
  //├──────────┼──────────┼──────────┼──────────┼──────────┤    ├──────────┼──────────┼──────────┼──────────┼──────────┤
  //│    F5    │    F6    │    F7    │    F8    │          │    │   Mute   │   Shift  │   Ctrl   │    Alt   │    GUI   │
        KC_F5  ,   KC_F6  ,   KC_F7 ,    KC_F8  ,  XXXXXXX ,       KC_MUTE ,  KC_RSFT ,  KC_RCTL ,  KC_LALT ,  KC_RGUI ,
  //├──────────┼──────────┼──────────┼──────────┼──────────┤    ├──────────┼──────────┼──────────┼──────────┼──────────┤
  //│    F1    │    F2    │    F3    │    F4    │          │    │Bootloader│   Vol-   │   Vol+   │  Insert  │   PrtSc  │
        KC_F1  ,   KC_F2  ,   KC_F3 ,    KC_F4  ,  XXXXXXX ,       QK_BOOT ,  KC_VOLD ,  KC_VOLU ,  KC_INS  ,  KC_PSCR ,
  //└──────────┴──────────┴┬─────────┴──────┬───┴──────────┴─┐┌─┴──────────┴───┬──────┴─────────┬┴──────────┴──────────┘
  //                       │                │                ││                │                │
                                 _______    ,     _______    ,      _______    ,     _______
  //                       └────────────────┴────────────────┘└────────────────┴────────────────┘
  // ),
  )
};


#ifdef CONVERT_TO_LIATRIS
  /*
   * For Liatris
   * See: https://docs.splitkb.com/hc/en-us/articles/5799711553820-Power-LED
   */
  void keyboard_pre_init_user(void) {
    // Set our LED pin as output
    setPinOutput(LIATRIS_RIGHT_LED);
    // Turn the LED off
    // (Due to technical reasons, high is off and low is on)
    writePinHigh(LIATRIS_RIGHT_LED);
  }
#endif

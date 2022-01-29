/* Copyright 2020 spr0ut
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
#include "spr0ut.h"

#ifdef ENCODER_ENABLE

void increase_brightness(void) {

    int new_brightness = oled_get_brightness() + 10;
    dprintf("Increasing brightness to %i \n",new_brightness);
    if (new_brightness < 255) {
        oled_set_brightness(new_brightness);
    } else {
        oled_set_brightness(255);
    }
}

void decrease_brightness(void) {
    int new_brightness = oled_get_brightness() - 10;
    dprintf("Decreasing brightness to %i \n",new_brightness);
    if (new_brightness > 0) {
        oled_set_brightness(new_brightness);
    } else {
        oled_set_brightness(0);
    }
}

void left_encoder_cw(void) {
    switch (get_highest_layer(layer_state)) {
        case _LOWER:
            tap_code16(C(KC_TAB));
            break;
        case _RAISE:
            tap_code(KC_PGDN);
            break;
        case _ADJUST:
            // rgblight_decrease_hue();
            break;
        default:
            tap_code(KC_VOLU);
            break;
        }
}
void left_encoder_acw(void) {
    switch (get_highest_layer(layer_state)) {
        case _LOWER:
            tap_code16(S(C(KC_TAB)));
            break;
        case _RAISE:
            tap_code(KC_PGUP);
            break;
        case _ADJUST:
            // rgblight_increase_hue();
            break;
        default:
            tap_code(KC_VOLD);
            break;
        }
}
void right_encoder_cw(void) {
    switch (get_highest_layer(layer_state)) {
        case _LOWER:
            tap_code(KC_DOWN);
            break;
        case _RAISE:
            tap_code16(LCTL(LSFT(KC_TAB)));
            break;
        case _ADJUST:
            // rgblight_decrease_val();
            increase_brightness();
            break;
        default:
            tap_code(KC_MS_WH_UP);
            break;
        }
}
void right_encoder_acw(void) {
    switch (get_highest_layer(layer_state)) {
        case _LOWER:
            tap_code(KC_UP);
            break;
        case _RAISE:
            tap_code16(LCTL(KC_TAB));
            break;
        case _ADJUST:
            // rgblight_increase_val();
            decrease_brightness();
            break;
        default:
            tap_code(KC_MS_WH_DOWN);
            break;
        }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    encoder_rotated_timer = timer_read();
    if (index == 0) {
        left_encoder_rotated = true;
        if (clockwise) {
            left_encoder_cw();
        } else {
            left_encoder_acw();
        }
    }
    else if (index == 1) {
        right_encoder_rotated = true;
        if (clockwise) {
            right_encoder_cw();
        } else {
            right_encoder_acw();
        }
    }
    return true;
}

#endif

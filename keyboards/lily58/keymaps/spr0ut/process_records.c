#include "spr0ut.h"

__attribute__((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

__attribute__((weak))
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) { return true; }

#ifdef OLED_DRIVER_ENABLE
__attribute__((weak))
bool process_record_oled(uint16_t keycode, keyrecord_t *record) { return true; }
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    #ifdef ENCODER_ENABLE
      case CLOSE_TAB:
        tap_code16(C(KC_W));
    #endif
  }

  return process_record_keymap(keycode, record) && process_record_secrets(keycode, record)
         #ifdef OLED_DRIVER_ENABLE
         && process_record_oled(keycode, record)
         #endif
         ; // Close return
}

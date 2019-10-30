#include QMK_KEYBOARD_H
#include "split_util.h"
#include "keymap_xrows.h"
#ifdef OLED_DRIVER_ENABLE
  #include "oled.h"
#endif

// keymaps definitions are moved to keymap_Xrows.c.

#ifdef RGBLIGHT_ENABLE
uint32_t layer_state_set_keymap(uint32_t state) {
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
  switch (biton32(state)) {
    case _LOWER:
      rgblight_sethsv_noeeprom_red();
      break;
    case _RAISE:
      rgblight_sethsv_noeeprom_blue();
      break;
    default: //  for any other layers, or the default layer
      rgblight_mode(RGBLIGHT_MODE_STATIC_GRADIENT + 3);
      rgblight_sethsv_red();
      break;
  }
  return state;
}
#endif

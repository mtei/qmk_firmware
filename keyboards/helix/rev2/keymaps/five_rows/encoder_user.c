#include QMK_KEYBOARD_H

void encoder_update_user(uint8_t index, bool clockwise) {
    switch (index) {
    case 0: tap_code(clockwise ? KC_A : KC_B); break;
    case 1: tap_code(clockwise ? KC_C : KC_D); break;
    case 2: tap_code(clockwise ? KC_E : KC_F); break;
    case 3: tap_code(clockwise ? KC_G : KC_H); break;
    }
}


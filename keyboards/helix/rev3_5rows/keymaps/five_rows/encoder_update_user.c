/* add to keymaps/five_rows/rules.mk
ifeq ($(strip $(ENCODER_ENABLE)), yes)
    SRC += encoder_update_user.c
endif
*/

#include QMK_KEYBOARD_H

#ifndef DEBUG_LOG
#    define DEBUG_LOG_INIT(x)
#    define DEBUG_LOG(x)
#endif

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    static bool debug_log_init = false;
    if (!debug_log_init) {
        DEBUG_LOG_INIT(0);
        debug_log_init = true;
    }
#ifdef ENCODER_DETECT_OVER_SPEED
    int enc_over = get_encoder_over_count();
    for (; enc_over > 0; enc_over--) {
        tap_code(KC_MINUS);
    }
#endif
    DEBUG_LOG(0x10); DEBUG_LOG(index); DEBUG_LOG(clockwise); DEBUG_LOG(is_keyboard_master());
    if (index == 0) { /* Left side encoder */
        if (clockwise) {
            if (is_keyboard_master()) { tap_code(KC_A); }
        } else {
            if (is_keyboard_master()) { tap_code(KC_B); }
        }
    } else if (index == 1) { /* Right side encoder */
        if (clockwise) {
            if (is_keyboard_master()) { tap_code(KC_C); }
        } else {
            if (is_keyboard_master()) { tap_code(KC_D); }
        }
    }
    return true;
}
#endif

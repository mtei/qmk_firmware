#include "creatorpad.h"

bool encoder_update_kb(uint8_t index, bool clockwise) {
    keypos_t key;

    if (index == 0) { /* Main Encoder */
        if (clockwise) {
            key.row = 1;
            key.col = 4;
        } else {
            key.row = 0;
            key.col = 4;
        }
    } else if (index == 1) { /* Sub Encoder 1 */
         if (clockwise) {
            key.row = 0;
            key.col = 7;
        } else {
            key.row = 0;
            key.col = 6;
        }
    } else if (index == 2) { /* Sub Encoder 2 */
         if (clockwise) {
            key.row = 1;
            key.col = 7;
        } else {
            key.row = 1;
            key.col = 6;
        }
    } else if (index == 3) { /* Sub Encoder 3 */
         if (clockwise) {
            key.row = 2;
            key.col = 7;
        } else {
            key.row = 2;
            key.col = 6;
        }
    } else if (index == 4) { /* Sub Encoder 4 */
         if (clockwise) {
            key.row = 3;
            key.col = 7;
        } else {
            key.row = 3;
            key.col = 6;
        }
    }
    uint8_t  layer   = layer_switch_get_layer(key);
    uint16_t keycode = keymap_key_to_keycode(layer, key);

    tap_code16(keycode);
    return false;
}

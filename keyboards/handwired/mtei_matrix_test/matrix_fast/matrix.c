/*
Copyright 2021 mtei

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
// clang-format off
#include <stdint.h>
#include <stdbool.h>
#include "gpio_extr.h"
#include "util.h"
#include "matrix.h"
#include "debounce.h"
#include "quantum.h"

#ifndef MATRIX_DEBUG_PIN
#    define MATRIX_DEBUG_PIN_INIT()
#    define MATRIX_DEBUG_SCAN_START()
#    define MATRIX_DEBUG_SCAN_END()
#    define MATRIX_DEBUG_DELAY_START()
#    define MATRIX_DEBUG_DELAY_END()
#endif

typedef uint16_t     port_width_t;
typedef matrix_row_t matrix_line_width_t;

/* matrix state(1:on, 0:off) */
extern matrix_row_t raw_matrix[MATRIX_ROWS];  // raw values
extern matrix_row_t matrix[MATRIX_ROWS];      // debounced values

#define setPortBitOutput_writeLow(port, bit) \
    ATOMIC_BLOCK_FORCEON { setPortBitOutput(port, bit); writePortBitLow(port, bit); }
#define setPortBitInputHigh_atomic(port, bit) \
    ATOMIC_BLOCK_FORCEON { setPortBitInputHigh(port, bit); }

#define select_output_extr(...)
#define unselect_output_extr(...)
#define init_input_pin_extr(...)
#define readPort_extr(...) 0

#include "macro.c"

LOCAL
bool read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row) {
    // Start with a clear matrix row
    matrix_row_t current_row_value = 0;
    port_width_t port_buffer[NUM_OF_INPUT_PORTS];

    // Select row
    select_output(current_row);
    matrix_output_select_delay();

    // Read ports
    read_all_input_ports(port_buffer, true);

    // Unselect row
    unselect_output(current_row);

    // Build row
    current_row_value = build_matrix_line(port_buffer);

    // Wait signal raise up
    MATRIX_DEBUG_DELAY_START();
    wait_unselect_done();
    MATRIX_DEBUG_DELAY_END();

    // If the row has changed, store the row and return the changed flag.
    if (current_matrix[current_row] != current_row_value) {
        current_matrix[current_row] = current_row_value;
        return true;
    }
    return false;
}

void matrix_init(void) {
    // initialize key pins
    init_all_ports();

    // initialize matrix state: all keys off
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        raw_matrix[i] = 0;
        matrix[i]     = 0;
    }

    debounce_init(MATRIX_ROWS);

    matrix_init_quantum();
}

uint8_t matrix_scan(void) {
    bool changed = false;
    MATRIX_DEBUG_PIN_INIT();

    MATRIX_DEBUG_SCAN_START();
    // Set row, read cols
    for (uint8_t current_row = 0; current_row < MATRIX_ROWS; current_row++) {
        changed |= read_cols_on_row(raw_matrix, current_row);
    }
    MATRIX_DEBUG_SCAN_END();

    debounce(raw_matrix, matrix, MATRIX_ROWS, changed);

    matrix_scan_quantum();
    return (uint8_t)changed;
}

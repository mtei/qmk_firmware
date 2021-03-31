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

#define ALWAYS_INLINE inline __attribute__((always_inline))
#define NO_INLINE     __attribute__((noinline))
#define LOCAL_FUNC static
#define LOCAL_DATA static

#ifndef _BV
#    define _BV(bit) (1 << (bit))
#endif

#ifndef MATRIX_DEBUG_PIN
#    define MATRIX_DEBUG_PIN_INIT()
#    define MATRIX_DEBUG_SCAN_START()
#    define MATRIX_DEBUG_SCAN_END()
#    define MATRIX_DEBUG_DELAY_START()
#    define MATRIX_DEBUG_DELAY_END()
#    define MATRIX_DEBUG_GAP()
#else
#    define MATRIX_DEBUG_GAP()  asm volatile("nop \n nop":::"memory")
#endif

typedef uint16_t     port_width_t;
typedef matrix_row_t matrix_line_width_t;
typedef struct _port_st {
    int device;
    pin_t port;
} port_st;

/* matrix state(1:on, 0:off) */
extern matrix_row_t raw_matrix[MATRIX_ROWS];  // raw values
extern matrix_row_t matrix[MATRIX_ROWS];      // debounced values

#define setPortBitOutput_writeLow(port, bit) \
    do { setPortBitOutput(port, bit); writePortBitLow(port, bit); } while(0)
#define setPortBitOutput_writeLow_atomic(port, bit) \
    do { ATOMIC_BLOCK_FORCEON { setPortBitOutput_writeLow(port, bit); } } while(0)
#define setPortBitInputHigh_atomic(port, bit) \
    do { ATOMIC_BLOCK_FORCEON { setPortBitInputHigh(port, bit); } } while(0)

#if defined(MATRIX_IN_PORTS) && defined(MATRIX_IN_PINS)
#   include "matrix_config_expand.c"
#else
#   error matrix.c need defined MATRIX_IN_PORTS and MATRIX_IN_PINS
#endif

LOCAL_FUNC
void unselect_output(uint8_t out_index) {
    unselect_output_inline(out_index);
}

LOCAL_FUNC
void init_output_ports(void) {
    for (int i = 0; i < END_opin_index; i++) {
        unselect_output(i);
    }
}

LOCAL_FUNC
void init_all_ports(void) {
    init_input_ports();
    init_output_ports();
    init_mask();
}

LOCAL_FUNC ALWAYS_INLINE bool read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row);
LOCAL_FUNC bool read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row) {
    // Start with a clear matrix row
    matrix_row_t current_row_value = 0;
    port_width_t port_buffer[NUM_OF_INPUT_PORTS];

#ifdef MATRIX_GPIO_NEED_SEPARATE_ATOMIC
    // Select row
    select_output(current_row);
    matrix_output_select_delay();

    // Read ports
    read_all_input_ports(port_buffer, false);

    // Unselect row
    unselect_output_inline(current_row);
#else
    ATOMIC_BLOCK_FORCEON {
        // Select row
        select_output(current_row);
        matrix_output_select_delay();

        // Read ports
        read_all_input_ports(port_buffer, false);

        // Unselect row
        unselect_output_inline(current_row);
    }
#endif

    // Build row
    current_row_value = build_matrix_line(port_buffer);

    // Wait signal raise up
    if (current_row_value) {
        MATRIX_DEBUG_DELAY_START();
        wait_unselect_done();
        MATRIX_DEBUG_DELAY_END();
    }

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
    MATRIX_DEBUG_SCAN_END(); MATRIX_DEBUG_GAP();

    MATRIX_DEBUG_SCAN_START();
    debounce(raw_matrix, matrix, MATRIX_ROWS, changed);
    MATRIX_DEBUG_SCAN_END(); MATRIX_DEBUG_GAP();

    MATRIX_DEBUG_SCAN_START();
    matrix_scan_quantum();
    MATRIX_DEBUG_SCAN_END();
    return (uint8_t)changed;
}

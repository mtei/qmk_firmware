#include "matrix.h"
#include "debounce.h"
#include "wait.h"
#include "print.h"
#include "debug.h"
#include "quantum.h"

#ifdef DEBUG_MATRIX_PIN
#define DEBUG_MATRIX_PIN_INIT setPinOutput(DEBUG_MATRIX_PIN)
#define DEBUG_MATRIX_PIN_ON   writePinHigh(DEBUG_MATRIX_PIN)
#define DEBUG_MATRIX_PIN_OFF  writePinLow(DEBUG_MATRIX_PIN)
#else
#define DEBUG_MATRIX_PIN_INIT
#define DEBUG_MATRIX_PIN_ON
#define DEBUG_MATRIX_PIN_OFF
#endif

#ifdef DEBUG_FULL_MATRIX
#define DEBUG_FULL_MATRIX_PIN_ON  DEBUG_MATRIX_PIN_ON
#define DEBUG_FULL_MATRIX_PIN_OFF DEBUG_MATRIX_PIN_OFF
#define DEBUG_FULL_WAIT asm("nop");
#else
#define DEBUG_FULL_MATRIX_PIN_ON
#define DEBUG_FULL_MATRIX_PIN_OFF
#define DEBUG_FULL_WAIT
#endif

extern matrix_row_t raw_matrix[MATRIX_ROWS];
extern matrix_row_t matrix[MATRIX_ROWS];

#define readPort(port) PINx_ADDRESS(port)

enum COLPORTS {
#define MATRIX_COL_PORT_DEFINE(port) port ## _index,
#include "matrix_config.h"
    NUM_COL_PORTS
};

static
void select_row(uint8_t row) {
    switch (row) {
#define MATRIX_ROW_PIN_DEFINE(index, pin) \
	case index: setPinOutput(pin); writePinLow(pin); break;
#include "matrix_config.h"
    }
}

static
void unselect_row(uint8_t row) { 
    switch (row) {
#define MATRIX_ROW_PIN_DEFINE(index, pin) \
	case index: setPinInputHigh(pin); break;
#include "matrix_config.h"
    }
}

static void unselect_rows(void) {
#define MATRIX_ROW_PIN_DEFINE(index, pin) setPinInputHigh(pin);
#include "matrix_config.h"
}

void matrix_init_custom(void) {
    DEBUG_MATRIX_PIN_INIT;
    unselect_rows();
#define MATRIX_COL_PIN_DEFINE(index, pin, port) setPinInputHigh(pin);
#include "matrix_config.h"
}

static bool read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row) {
    uint8_t pin_state;
    uint8_t port_buf[NUM_COL_PORTS];
    // Start with a clear matrix row
    matrix_row_t current_row_value = 0;

    // Select row and wait for row selecton to stabilize
    select_row(current_row);
    asm("nop");

    // For each col port
    //DEBUG_MATRIX_PIN_ON;
    //DEBUG_MATRIX_PIN_OFF;
#define MATRIX_COL_PORT_DEFINE(port) port_buf[port ## _index] = readPort(port);
#include "matrix_config.h"

    // Unselect row
    //DEBUG_MATRIX_PIN_ON;
    asm("nop");
    unselect_row(current_row);
    asm("nop");
    //DEBUG_MATRIX_PIN_OFF;

    // For each col...
DEBUG_MATRIX_PIN_ON;
#define MATRIX_COL_PIN_DEFINE(index, pin, port) \
    pin_state = port_buf[port ## _index] & _BV((pin)&0xF); \
    current_row_value |= pin_state ? 0 : (MATRIX_ROW_SHIFTER << index);
#include "matrix_config.h"
DEBUG_MATRIX_PIN_OFF;

    matrix_io_delay();
DEBUG_MATRIX_PIN_ON;
DEBUG_MATRIX_PIN_OFF;

    // If the row has changed, store the row and return the changed flag.
    if (current_matrix[current_row] != current_row_value) {
        current_matrix[current_row] = current_row_value;
        return true;
    }
    return false;
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) { 
    bool changed = false;

    // Set row, read cols
    for (uint8_t current_row = 0; current_row < MATRIX_ROWS; current_row++) {
        changed |= read_cols_on_row(raw_matrix, current_row);
    }
    return changed;
}

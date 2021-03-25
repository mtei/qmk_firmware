// avr-gcc -E -I. macro.c
#ifndef MATRIX_OUT_PORTS
#define MATRIX_OUT_PORTS \
    (Port_D, 0, D0), \
    (Port_C, 0, C0), \
    (Port_E, 0, E0), \
    (Port_B, 0, B0)
#define MATRIX_OUT_PINS  \
    (0, Port_D, 4), \
    (1, Port_C, 6), \
    (2, Port_D, 7), \
    (3, Port_E, 6), \
    (4, Port_B, 4), \
    (5, Port_B, 5)
#define MATRIX_IN_PORTS \
    (Port_F, 0, F0), \
    (Port_B, 0, B0)
#define MATRIX_IN_PINS \
    (0, Port_F, 4), \
    (1, Port_F, 5), \
    (2, Port_F, 6), \
    (3, Port_F, 7), \
    (4, Port_B, 1), \
    (5, Port_B, 3)
#endif

#define LOCAL

#include "cpp_map.h"

typedef struct _port_st {
    int device;
    pin_t port;
} port_st;

#define _INPUT_PORTS_ENUM_ELEMENT(name, dev, port) iport_index_##name,
#define INPUT_PORTS_ENUM_ELEMENT(x) _INPUT_PORTS_ENUM_ELEMENT x
enum INPUT_PORTS {
    MAP(INPUT_PORTS_ENUM_ELEMENT, MATRIX_IN_PORTS)
    NUM_OF_INPUT_PORTS
};

#define _INPUT_PINS_ENUM_ELEMENT(index, port, bit) ipin_index_##index,
#define INPUT_PINS_ENUM_ELEMENT(x) _INPUT_PINS_ENUM_ELEMENT x
enum INPUT_PINS {
    MAP(INPUT_PINS_ENUM_ELEMENT, MATRIX_IN_PINS)
    END_ipin_index
};

#define _OUTPUT_PORTS_ENUM_ELEMENT(name, dev, port) oport_index_##name,
#define OUTPUT_PORTS_ENUM_ELEMENT(x) _OUTPUT_PORTS_ENUM_ELEMENT x
enum OUTPUT_PORTS {
    MAP(OUTPUT_PORTS_ENUM_ELEMENT, MATRIX_OUT_PORTS)
    NUM_OF_OUTPUT_PORTS
};

#define _OUTPUT_PINS_ENUM_ELEMENT(index, port, bit) opin_index_##index,
#define OUTPUT_PINS_ENUM_ELEMENT(x) _OUTPUT_PINS_ENUM_ELEMENT x
enum OUTPUT_PINS {
    MAP(OUTPUT_PINS_ENUM_ELEMENT, MATRIX_OUT_PINS)
    END_opin_index
};

port_width_t iport_mask[NUM_OF_INPUT_PORTS];

#define _INPUT_PORTS_LIST_ELEMENT(name, dev, port) \
    [iport_index_##name] = { dev, port },
#define INPUT_PORTS_LIST_ELEMENT(x) _INPUT_PORTS_LIST_ELEMENT x
LOCAL
const port_st iport_list[NUM_OF_INPUT_PORTS] = {
    MAP(INPUT_PORTS_LIST_ELEMENT, MATRIX_IN_PORTS)
};

#define _OUTPUT_PORTS_LIST_ELEMENT(name, dev, port) \
    [oport_index_##name] = { dev, port },
#define OUTPUT_PORTS_LIST_ELEMENT(x) _OUTPUT_PORTS_LIST_ELEMENT x
LOCAL
const port_st oport_list[NUM_OF_OUTPUT_PORTS] = {
    MAP(OUTPUT_PORTS_LIST_ELEMENT, MATRIX_OUT_PORTS)
};

#define _SELECT_OUTPUT_PIN(index, pname, bit) \
    case opin_index_##index: \
    if (oport_list[oport_index_##pname].device == 0) {                        \
        setPortBitOutput_writeLow(oport_list[oport_index_##pname].port, bit); \
    } else {                                                                  \
        select_output_extr(oport_index_##pname, bit);                         \
    } break;
#define SELECT_OUTPUT_PIN(x) _SELECT_OUTPUT_PIN x
LOCAL
void select_output(uint8_t out_index) {
    switch (out_index) {
        MAP(SELECT_OUTPUT_PIN, MATRIX_OUT_PINS)
    }
}

#define _UNSELECT_OUTPUT_PIN(index, pname, bit) \
    case opin_index_##index: \
    if (oport_list[oport_index_##pname].device == 0) {                     \
        setPortBitInputHigh_atomic(oport_list[oport_index_##pname].port, bit); \
    } else {                                                               \
        unselect_output_extr(oport_index_##pname, bit);                    \
    } break;
#define UNSELECT_OUTPUT_PIN(x) _UNSELECT_OUTPUT_PIN x
LOCAL
void unselect_output(uint8_t out_index) {
    switch (out_index) {
        MAP(UNSELECT_OUTPUT_PIN, MATRIX_OUT_PINS)
    }
}

#define _INIT_INPUT_PIN(index, pname, bit) \
    if (iport_list[iport_index_##pname].device == 0) {                     \
        setPortBitInputHigh_atomic(iport_list[iport_index_##pname].port, bit); \
    } else {                                                               \
        init_input_pin_extr(iport_index_##pname, bit);                    \
    }
#define INIT_INPUT_PIN(x) _INIT_INPUT_PIN x
LOCAL
void init_input_ports(void) {
    MAP(INIT_INPUT_PIN, MATRIX_IN_PINS)
}

LOCAL
void init_output_ports(void) {
    for (int i = 0; i < END_opin_index; i++) {
        unselect_output(i);
    }
}

#define _INIT_MASK(index, pname, bit) \
    if (iport_list[iport_index_##pname].device == 0) {    \
        iport_mask[iport_index_##pname] |= _BV((bit)&0xF); \
    }
#define INIT_MASK(x)  _INIT_MASK x
LOCAL
void init_mask(void) {
    for (int i = 0; i < NUM_OF_INPUT_PORTS; i++ ) {
        iport_mask[i] = 0;
    }
    MAP(INIT_MASK, MATRIX_IN_PINS)
}

LOCAL
void init_all_ports(void) {
    init_input_ports();
    init_output_ports();
    init_mask();
}

#define _READ_INPUT_PORT(name, dev, port) \
    if (iport_list[iport_index_##name].device == 0) { \
        buffer[iport_index_##name] = ~readPort(port);  /* invert active-low */ \
    } else {                                           \
        buffer[iport_index_##name] = readPort_extr(iport_index_##name, whole); \
    }
#define READ_INPUT_PORT(x) _READ_INPUT_PORT x
LOCAL
void read_all_input_ports(port_width_t buffer[NUM_OF_INPUT_PORTS], bool whole) {
    MAP(READ_INPUT_PORT, MATRIX_IN_PORTS)
}

#define _MASK_INPUT(name, dev, port) \
    mask |= (buffer[iport_index_##name] &  iport_mask[iport_index_##name]);
#define MASK_INPUT(x) _MASK_INPUT x
LOCAL
void wait_unselect_done(void) {
    port_width_t mask;
    port_width_t buffer[NUM_OF_INPUT_PORTS];
    do {
        read_all_input_ports(buffer, false);
        mask = 0;
        MAP(MASK_INPUT, MATRIX_IN_PORTS);
    } while (mask != 0);
}

#define _BUILD_INPUT_PORT(index, pname, bit) \
    result |= (buffer[iport_index_##pname] & _BV(bit)) ? _BV(ipin_index_##index) : 0;
#define BUILD_INPUT_PORT(x) _BUILD_INPUT_PORT x
LOCAL 
matrix_line_width_t build_matrix_line(port_width_t buffer[NUM_OF_INPUT_PORTS]) {
    matrix_line_width_t result = 0;
    MAP(BUILD_INPUT_PORT, MATRIX_IN_PINS);
    return result;
}

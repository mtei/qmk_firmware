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

#ifdef DEBUG_MATRIX_CONFIG
// config expand debug
//   avr-gcc -DDEBUG_MATRIX_CONFIG=\"test_config.h\" -E -C -I. matrix_config_expand.c
#    include DEBUG_MATRIX_CONFIG
#endif

#ifdef MATRIX_GPIO_NEED_SEPARATE_ATOMIC
#    ifndef setMatrixInputHigh
#        define setMatrixInputHigh(dev, port, bit) setPortBitInputHigh_atomic(port, bit)
#    endif
#    ifndef setMatrixOutput_writeHighZ
#        define setMatrixOutput_writeHighZ(dev, port, bit) setPortBitInputHigh_atomic(port, bit)
#    endif
#    ifndef setMatrixOutput_writeLow
#        define setMatrixOutput_writeLow(dev, port, bit) setPortBitOutput_writeLow_atomic(port, bit)
#    endif
#else
#    ifndef setMatrixInputHigh
#        define setMatrixInputHigh(dev, port, bit) setPortBitInputHigh(port, bit)
#    endif
#    ifndef setMatrixOutput_writeHighZ
#        define setMatrixOutput_writeHighZ(dev, port, bit) setPortBitInputHigh(port, bit)
#    endif
#    ifndef setMatrixOutput_writeLow
#        define setMatrixOutput_writeLow(dev, port, bit) setPortBitOutput_writeLow(port, bit)
#    endif
#endif

#ifndef readMatrixPort
#    define readMatrixPort(dev, port) readPort(port)
#endif
#ifndef getMatrixInputMaskBit
#    define getMatrixInputMaskBit(dev, bit) _BV((bit)&0xF)
#endif

#include "cpp_map.h"

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
LOCAL_DATA
const port_descriptor iport_list[NUM_OF_INPUT_PORTS] = {
    MAP(INPUT_PORTS_LIST_ELEMENT, MATRIX_IN_PORTS)
};

#define _OUTPUT_PORTS_LIST_ELEMENT(name, dev, port) \
    [oport_index_##name] = { dev, port },
#define OUTPUT_PORTS_LIST_ELEMENT(x) _OUTPUT_PORTS_LIST_ELEMENT x
LOCAL_DATA
const port_descriptor oport_list[NUM_OF_OUTPUT_PORTS] = {
    MAP(OUTPUT_PORTS_LIST_ELEMENT, MATRIX_OUT_PORTS)
};

#define _SELECT_OUTPUT_PIN(index, pname, bit) \
    case opin_index_##index: \
        setMatrixOutput_writeLow(oport_list[oport_index_##pname].device,     \
                                 oport_list[oport_index_##pname].port, bit); \
    break;
#define SELECT_OUTPUT_PIN(x) _SELECT_OUTPUT_PIN x
LOCAL_FUNC ALWAYS_INLINE void select_output(uint8_t out_index);
LOCAL_FUNC
void select_output(uint8_t out_index) {
    switch (out_index) {
        MAP(SELECT_OUTPUT_PIN, MATRIX_OUT_PINS)
    }
}

#define _UNSELECT_OUTPUT_PIN(index, pname, bit) \
    case opin_index_##index: \
        setMatrixOutput_writeHighZ(oport_list[oport_index_##pname].device,     \
                                   oport_list[oport_index_##pname].port, bit); \
    break;
#define UNSELECT_OUTPUT_PIN(x) _UNSELECT_OUTPUT_PIN x
LOCAL_FUNC ALWAYS_INLINE void unselect_output_inline(uint8_t out_index);
LOCAL_FUNC
void unselect_output_inline(uint8_t out_index) {
    switch (out_index) {
        MAP(UNSELECT_OUTPUT_PIN, MATRIX_OUT_PINS)
    }
}

#define _INIT_INPUT_PIN(index, pname, bit) \
    setMatrixInputHigh(iport_list[iport_index_##pname].device,    \
                       iport_list[iport_index_##pname].port, bit);
#define INIT_INPUT_PIN(x) _INIT_INPUT_PIN x
LOCAL_FUNC
void init_input_ports(void) {
    MAP(INIT_INPUT_PIN, MATRIX_IN_PINS)
}

#define _INIT_IPORT_MASK(index, pname, bit) \
    iport_mask[iport_index_##pname] |= getMatrixInputMaskBit(iport_list[iport_index_##pname].device, bit);
#define INIT_IPORT_MASK(x)  _INIT_IPORT_MASK x
LOCAL_FUNC
void init_iport_mask(void) {
    for (int i = 0; i < NUM_OF_INPUT_PORTS; i++ ) {
        iport_mask[i] = 0;
    }
    MAP(INIT_IPORT_MASK, MATRIX_IN_PINS)
}

#define _READ_INPUT_PORT(name, dev, port) \
    buffer[iport_index_##name] = readMatrixPort(dev, port);
#define READ_INPUT_PORT(x) _READ_INPUT_PORT x
LOCAL_FUNC
ALWAYS_INLINE void read_all_input_ports(port_width_t buffer[NUM_OF_INPUT_PORTS], bool wait_unselect);
LOCAL_FUNC
void read_all_input_ports(port_width_t buffer[NUM_OF_INPUT_PORTS], bool wait_unselect) {
    MAP(READ_INPUT_PORT, MATRIX_IN_PORTS)
}

#define _MASK_INPUT(name, dev, port) \
    mask |= ((~buffer[iport_index_##name]) & iport_mask[iport_index_##name]);
#define MASK_INPUT(x) _MASK_INPUT x
LOCAL_FUNC ALWAYS_INLINE void wait_unselect_done(void);
LOCAL_FUNC
void wait_unselect_done(void) {
    port_width_t mask;
    port_width_t buffer[NUM_OF_INPUT_PORTS];
    do {
        read_all_input_ports(buffer, true);
        MATRIX_DEBUG_DELAY_END();
        mask = 0;
        MAP(MASK_INPUT, MATRIX_IN_PORTS);
        MATRIX_DEBUG_DELAY_START();
    } while (mask != 0);
}

#define _BUILD_INPUT_PORT(index, pname, bit) \
    result |= (buffer[iport_index_##pname] & _BV(bit)) ? 0 : _BV(ipin_index_##index);
#define BUILD_INPUT_PORT(x) _BUILD_INPUT_PORT x
LOCAL_FUNC ALWAYS_INLINE matrix_line_width_t build_matrix_line(port_width_t buffer[NUM_OF_INPUT_PORTS]);
LOCAL_FUNC
matrix_line_width_t build_matrix_line(port_width_t buffer[NUM_OF_INPUT_PORTS]) {
    matrix_line_width_t result = 0;
    MAP(BUILD_INPUT_PORT, MATRIX_IN_PINS);
    return result;
}

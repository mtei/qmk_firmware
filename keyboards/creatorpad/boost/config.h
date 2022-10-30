#pragma once
 /* #define MATRIX_COL_PINS {GP27,GP26,GP25,GP24,GP16,GP4,GP12,GP13} */
#undef MATRIX_COL_PINS
#define SWITCH_MATRIX_INPUT_0 \
    /* ( ( <port>, <mask>, <dev> ), ... ) */ \
    ( (GP0, 0xf013010, MCU_GPIO) ),\
    /* ( ( <port_index>, <port_mask>, <matrix_row_mask> ), ... ) */ \
    ( (0, 0x8000000, 0x01), \
      (0, 0x4000000, 0x02), \
      (0, 0x2000000, 0x04), \
      (0, 0x1000000, 0x08), \
      (0, 0x10000, 0x10), \
      (0, 0x10, 0x20), \
      (0, 0x1000, 0x40), \
      (0, 0x2000, 0x80) )

 /* #define MATRIX_ROW_PINS {GP29,GP28,GP21,GP17} */
#undef MATRIX_ROW_PINS
#define SWITCH_MATRIX_OUTPUT_0 \
    /* ( ( <port>, <mask>, <dev> ), ... ) */ \
    ( (GP0, 0x30220000, MCU_GPIO) ),\
    /* ( ( <port_index>, <port_mask>, <matrix_row_mask> ), ... ) */ \
    ( (0, 0x20000000, 0x01), \
      (0, 0x10000000, 0x02), \
      (0, 0x200000, 0x04), \
      (0, 0x20000, 0x08) )


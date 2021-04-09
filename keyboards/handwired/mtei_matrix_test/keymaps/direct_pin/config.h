#undef MATRIX_ROWS
#undef MATRIX_COLS
#undef MATRIX_OUT_PORTS
#undef MATRIX_OUT_PINS
#undef MATRIX_IN_PORTS
#undef MATRIX_IN_PINS

#define MATRIX_ROWS 3
#define MATRIX_COLS 3

#if defined(__AVR__)
/* -------------------- AVR (Pro Micro) ----------------------- */

// old style
#define DIRECT_PINS { { F4, NO_PIN, F5 }, { NO_PIN, F6, F7 }, { B1, B3, NO_PIN } }

// new style
// #define DIRECT_PINS
#define MATRIX_IN_PORTS \
    (Port_F, MCU_GPIO, F0), \
    (Port_B, MCU_GPIO, B0)
#define MATRIX_IN_PINS  \
    (0, Port_F,  4), (1, NO_PIN    ), (2, Port_F,  5), \
    (3, NO_PIN    ), (4, Port_F,  6), (5, Port_F,  7), \
    (6, Port_B,  1), (7, Port_B,  3), (8, NO_PIN    )

#else
/* -------------------- ARM (PROTON-C) ----------------------- */

// old style
#define DIRECT_PINS { { A2, NO_PIN, A1 }, { NO_PIN, A0, B8 }, { B13, B14, NO_PIN } }

// new style
// #define DIRECT_PINS
#define MATRIX_IN_PORTS \
    (Port_A, MCU_GPIO, A0), \
    (Port_B, MCU_GPIO, B0)
#define MATRIX_IN_PINS  \
    (0, Port_A,  2), (1, NO_PIN    ), (2, Port_A,  1), \
    (3, NO_PIN    ), (4, Port_A,  0), (5, Port_B,  8), \
    (6, Port_B, 13), (7, Port_B, 14), (8, NO_PIN    )

#endif

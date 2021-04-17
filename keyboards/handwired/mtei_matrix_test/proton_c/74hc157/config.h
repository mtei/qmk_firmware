#define MATRIX_EXTENSION_74HC157 B15
// #define MATRIX_EXTENSION_74HC153 B15, B9

#undef MATRIX_IN_PORTS
#undef MATRIX_IN_PINS

#define MATRIX_IN_PORTS \
    (Port_Aa, MCU_GPIOa, A0), \
    (Port_Ab, MCU_GPIOb, A0), \
    (Port_Ba, MCU_GPIOa, B0), \
    (Port_Bb, MCU_GPIOb, B0)
#define MATRIX_IN_PINS \
    (0, Port_Aa, 2),  \
    (1, Port_Ab, 1),  \
    (2, Port_Aa, 0),  \
    (3, Port_Ba, 8),  \
    (4, Port_Bb, 13), \
    (5, Port_Ba, 14)

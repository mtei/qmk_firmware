#define MATRIX_EXTENSION_74HC157 B2
// #define MATRIX_EXTENSION_74HC153 B2, B6

#undef MATRIX_IN_PORTS
#undef MATRIX_IN_PINS
#define MATRIX_IN_PORTS \
    (Port_Fa, MCU_GPIOa, F0), \
    (Port_Ba, MCU_GPIOa, B0), \
    (Port_Fb, MCU_GPIOb, F0), \
    (Port_Bb, MCU_GPIOb, B0)
#define MATRIX_IN_PINS \
    (0, Port_Fa, 4), \
    (1, Port_Fb, 5), \
    (2, Port_Fb, 6), \
    (3, Port_Fa, 7), \
    (4, Port_Ba, 1), \
    (5, Port_Bb, 3)

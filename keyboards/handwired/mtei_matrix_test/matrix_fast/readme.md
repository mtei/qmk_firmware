# Fast and extensible matrix.c

This matrix.c is faster and more extensible than the standard quantum/matrix.c.

* The execution speed of the `matrix_scan()` function is several times faster than quantum/matrix.c.
* In addition to handling MCU GPIOs, it can be extended to handle I/O extenders.

## ToDo list
- [x] support Pro Micro (2021-3-27)
- [x] support Proton-C (2021-3-29)
- [x] support DIRECT_PINS (2021-4-10)
- [x] support DIODE_DIRECTION == ROW2COL (2021-4-11)
- [x] support 74HC157: quadruple 2-line to 1-line data selectors / multiplexers (2021-4-17)
- [x] support 74HC153: dual 4-line to 1-line data selectors / multiplexers (2021-4-17)
- [ ] support I/O expander (MCP23018)
- [ ] support MCU & I/O expander (MCP23018) mixture like ErgoDox

## Configuration

This matrix.c requires a different configuration than quantum/matrix.c.

### Output pins configuration

The output pins is the Row pins if `DIODE_DIRECTION == COL2ROW`, and the Col pins if `DIODE_DIRECTION == ROW2COL`. When DIRECT_PINS is defined, the output pins do not need to be set.

Example:
```c
// list of OUTPUT(row) ports
#define MATRIX_OUT_PORTS  \
    (Port_D, MCU_GPIO, D0), \
    (Port_C, MCU_GPIO, C0), \
    (Port_E, MCU_GPIO, E0), \
    (Port_B, MCU_GPIO, B0)
// list of OUTPUT pins
#define MATRIX_OUT_PINS  \
    (0, Port_D, 4), \
    (1, Port_C, 6), \
    (2, Port_D, 7), \
    (3, Port_E, 6), \
    (4, Port_B, 4), \
    (5, Port_B, 5)
```

### Input pins configuration

The input pins is the Col pins if `DIODE_DIRECTION == COL2ROW`, and the Row pins if `DIODE_DIRECTION == ROW2COL`. When DIRECT_PINS is defined, the input pin settings will enumerate the connection pins of all switches.

Example:
```c
// list of INPUT ports
#define MATRIX_IN_PORTS (Port_F, MCU_GPIO, F0), (Port_B, MCU_GPIO, B0)
// list of INPUT pins
#define MATRIX_IN_PINS \
    (0, Port_F, 4), \
    (1, Port_F, 5), \
    (2, Port_F, 6), \
    (3, Port_F, 7), \
    (4, Port_B, 1), \
    (5, Port_B, 3)
```

### Multiplexer Extension

By defining the `MATRIX_EXTENSION_74HC157` macro or `MATRIX_EXTENSION_74HC153` macro, you can connect a multiplexer to the GPIO to extend the input pins.

Example:
```c
#define MATRIX_EXTENSION_74HC157 B2 /* or #define MATRIX_EXTENSION_74HC153 B2, B6 */

// list of OUTPUT ports
#define MATRIX_OUT_PORTS (Port_D, MCU_GPIO, D0), (Port_C, MCU_GPIO, C0), (Port_E, MCU_GPIO, E0), (Port_B, MCU_GPIO, B0)
// list of OUTPUT pins
#define MATRIX_OUT_PINS  (0, Port_D, 4), (1, Port_C, 6), (2, Port_D, 7), (3, Port_E, 6), (4, Port_B, 4), (5, Port_B, 5)

// list of INPUT ports
#define MATRIX_IN_PORTS \
    (Port_Fa, MCU_GPIOa, F0), \
    (Port_Ba, MCU_GPIOa, B0), \
    (Port_Fb, MCU_GPIOb, F0), \
    (Port_Bb, MCU_GPIOb, B0)
// list of INPUT pins
#define MATRIX_IN_PINS \
    (0, Port_Fa, 4), \
    (1, Port_Fb, 5), \
    (2, Port_Fb, 6), \
    (3, Port_Fa, 7), \
    (4, Port_Ba, 1), \
    (5, Port_Bb, 3)
```

### I/O expander Extension

I plan to provide extensions to support I/O expanders such as MCP23018 and PCA9555.

## Compile

```
make MTEST=matrix_fast,scan,matrix_debug_scan   handwired/mtei_matrix_test/promicro:default:flash
make MTEST=matrix_fast,scan,matrix_debug_delay   handwired/mtei_matrix_test/promicro:default:flash
```

## Test results

### Pro Micro
#### `make MTEST=matrix_fast,scan,matrix_debug_scan handwired/mtei_matrix_test/promicro:default:flash`
- Execution time of `matrix_scan()`: 39.8us
- Matrix scan rate:  11000 scans/sec

![DS1Z_QuickPrint24](https://user-images.githubusercontent.com/2170248/113141418-a5254480-9264-11eb-9f36-339edcdc65c6.png)

![DS1Z_QuickPrint27](https://user-images.githubusercontent.com/2170248/113141442-ace4e900-9264-11eb-816f-238456301e3b.png)

### Proton-C

#### `make MTEST=matrix_fast,scan,matrix_debug_scan handwired/mtei_matrix_test/proton_c:default:flash`
- Execution time of `matrix_scan()`: 43.4us
- Matrix scan rate: 14800 scans/sec

![DS1Z_QuickPrint32](https://user-images.githubusercontent.com/2170248/113141465-b2daca00-9264-11eb-9c0f-03e1d8b8b4d5.png)

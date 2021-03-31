# high speed matrix.c

## ToDo list
- [x] support Pro Micro (2021-3-27)
- [x] support Proton-C (2021-3-29)
- [ ] support DIRECT_PINS
- [ ] support DIODE_DIRECTION == ROW2COL
- [ ] support 74HC157: quadruple 2-line to 1-line data selectors / multiplexers
- [ ] support I/O expander (MCP23018)
- [ ] support MCU & I/O expander (MCP23018) mixture like ErgoDox

## Configuration

eg.
```c
// OLD STYLE
//  #define MATRIX_ROW_PINS { D4, C6, D7, E6, B4, B5 }
//  #define MATRIX_COL_PINS { F4, F5, F6, F7, B1, B3 }

// list of OUTPUT(row) ports
#define MATRIX_OUT_PORTS (Port_D, 0, D0), (Port_C, 0, C0), (Port_E, 0, E0), (Port_B, 0, B0)
// list of OUTPUT(row) pins
#define MATRIX_OUT_PINS  \
    (0, Port_D, 4), \
    (1, Port_C, 6), \
    (2, Port_D, 7), \
    (3, Port_E, 6), \
    (4, Port_B, 4), \
    (5, Port_B, 5)

// list of INPUT(col) ports
#define MATRIX_IN_PORTS (Port_F, 0, F0), (Port_B, 0, B0)
// list of INPUT(col) pins
#define MATRIX_IN_PINS \
    (0, Port_F, 4), \
    (1, Port_F, 5), \
    (2, Port_F, 6), \
    (3, Port_F, 7), \
    (4, Port_B, 1), \
    (5, Port_B, 3)
```

## Compile

```
make TEST=matrix_fast,scan,matrix_debug_scan   handwired/mtei_matrix_test/promicro:default:flash
make TEST=matrix_fast,scan,matrix_debug_delay   handwired/mtei_matrix_test/promicro:default:flash
```

## Test results

### Pro Micro
#### `make TEST=matrix_fast,scan,matrix_debug_scan handwired/mtei_matrix_test/promicro:default:flash`
- Execution time of `matrix_scan()`: 39.8us
- Matrix scan rate:  11000 scans/sec

![DS1Z_QuickPrint24](https://user-images.githubusercontent.com/2170248/113141418-a5254480-9264-11eb-9f36-339edcdc65c6.png)

![DS1Z_QuickPrint27](https://user-images.githubusercontent.com/2170248/113141442-ace4e900-9264-11eb-816f-238456301e3b.png)

### Proton-C

#### `make TEST=matrix_fast,scan,matrix_debug_scan handwired/mtei_matrix_test/proton_c:default:flash`
- Execution time of `matrix_scan()`: 43.4us
- Matrix scan rate: 14800 scans/sec

![DS1Z_QuickPrint32](https://user-images.githubusercontent.com/2170248/113141465-b2daca00-9264-11eb-9c0f-03e1d8b8b4d5.png)

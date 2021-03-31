# matrix.c with debug

## Compile

```
make TEST=mdelay0,scan,matrix_debug_scan  handwired/mtei_matrix_test/promicro:default:flash
make TEST=mdelay1,scan,matrix_debug_scan  handwired/mtei_matrix_test/promicro:default:flash
make TEST=mdelay2,scan,matrix_debug_scan  handwired/mtei_matrix_test/promicro:default:flash
make TEST=allways_delay,mdelay2,scan,matrix_debug_scan  handwired/mtei_matrix_test/promicro:default:flash
make TEST=input_pin_delay,mdelay0,scan,matrix_debug_delay  handwired/mtei_matrix_test/promicro:default:flash
```

## Test results

### Pro Micro
#### `make TEST=allways_delay,scan,matrix_debug_scan handwired/mtei_matrix_test/promicro:default:flash`
- Execution time of `matrix_scan()`: 359us
- Matrix scan rate: 2440 scans/sec

![DS1Z_QuickPrint21](https://user-images.githubusercontent.com/2170248/113131411-22968800-9258-11eb-8f9e-e61a331da0ec.png)

#### `make TEST=scan,matrix_debug_scan handwired/mtei_matrix_test/promicro:default:flash`
- Execution time of `matrix_scan()`: 331us
- Matrix scan rate: 2600 scans/sec

![DS1Z_QuickPrint22](https://user-images.githubusercontent.com/2170248/113131465-380bb200-9258-11eb-9547-44b58b575c34.png)

#### `make TEST=mdelay0,scan,matrix_debug_scan handwired/mtei_matrix_test/promicro:default:flash`
- Execution time of `matrix_scan()`: 178us
- Matrix scan rate: 4340 scans/sec

![DS1Z_QuickPrint23](https://user-images.githubusercontent.com/2170248/113131611-65f0f680-9258-11eb-9b0b-7ed01ce626c5.png)

### Proton-C

#### `make TEST=allways_delay,scan,matrix_debug_scan handwired/mtei_matrix_test/proton_c:default:flash`
- Execution time of `matrix_scan()`: 250us
- Matrix scan rate:  3640 scans/sec
![DS1Z_QuickPrint29](https://user-images.githubusercontent.com/2170248/113135288-eade0f00-925c-11eb-9ec3-31ee4d2da8cd.png)

#### `make TEST=scan,matrix_debug_scan handwired/mtei_matrix_test/proton_c:default:flash`
- Execution time of `matrix_scan()`: 208.8us
- Matrix scan rate: 4350 scans/sec
![DS1Z_QuickPrint30](https://user-images.githubusercontent.com/2170248/113135197-ce41d700-925c-11eb-89bc-b1d9687f506b.png)

#### `make TEST=mdelay10,scan,matrix_debug_scan handwired/mtei_matrix_test/proton_c:default:flash`
- Execution time of `matrix_scan()`: 158us
- Matrix scan rate: 5550 scans/sec

`mdelay10`, `mdelay1`, `mdelay0` all have the same result

![DS1Z_QuickPrint31](https://user-images.githubusercontent.com/2170248/113135174-c71ac900-925c-11eb-8f8e-be7aa1f97096.png)

#### `make TEST=mdelay-1,scan,matrix_debug_scan handwired/mtei_matrix_test/proton_c:default:flash`
- Execution time of `matrix_scan()`: 53.2us
- Matrix scan rate: 13200 scans/sec
![DS1Z_QuickPrint33](https://user-images.githubusercontent.com/2170248/113135136-b9fdda00-925c-11eb-9861-2583e40c6649.png)

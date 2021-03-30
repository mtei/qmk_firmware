# handwired/mtei_matrix_test

```
make TEST=<options>  handwired/mtei_matrix_test/{promicro|proton_c}:default:flash
```

## Options:
* `mdelay0`,.. `mdelay5`, `mdelay10`, `mdelay20`, `mdelay30`
  `#define MATRIX_IO_DELAY 0,1,2,3,4,5, 10, 20, 30`
* `adaptive_delay`
  `#define MATRIX_IO_DELAY_ADAPTIVE`
* `allways_delay`
  `#define MATRIX_IO_DELAY_ALLWAYS`
* `scan`
  use DEBUG_MATRIX_SCAN_RATE
* `matrix_debug_scan`, `matrix_debug_delay`
  scan indicate or delay indicate
* `matrix_fast`
  use fast version matrix.c
* `input_pin_delay`
  add `-DLOOK_INPUT_PIN_DELAY`. Detects the rising edge of the input after unselection.
* `allways_delay`
  add `-DALLWAYS_UNSELECT_DELAY`

example:
```
make TEST=scan,mdelay0  handwired/mtei_matrix_test/{promicro|proton_c}:default:flash
make TEST=scan,mdelay0,matrix_debug_scan  handwired/mtei_matrix_test/{promicro|proton_c}:default:flash
make TEST=scan,mdelay0,matrix_debug_delay  handwired/mtei_matrix_test/{promicro|proton_c}:default:flash
make TEST=scan,input_pin_delay,matrix_debug_delay  handwired/mtei_matrix_test/{promicro|proton_c}:default:flash
make TEST=scan,allways_delay,matrix_debug_delay  handwired/mtei_matrix_test/{promicro|proton_c}:default:flash
make TEST=scan,adaptive_delay,mdelay0,matrix_debug_scan  handwired/mtei_matrix_test/promicro:default:flash
```

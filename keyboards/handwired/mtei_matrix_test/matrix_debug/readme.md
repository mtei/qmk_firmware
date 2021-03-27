# matrix.c with debug

## Compile

```
make TEST=mdelay0,scan,matrix_debug_scan  handwired/mtei_matrix_test/promicro:default:flash
make TEST=mdelay1,scan,matrix_debug_scan  handwired/mtei_matrix_test/promicro:default:flash
make TEST=mdelay2,scan,matrix_debug_scan  handwired/mtei_matrix_test/promicro:default:flash
make TEST=allways_delay,mdelay2,scan,matrix_debug_scan  handwired/mtei_matrix_test/promicro:default:flash
make TEST=input_pin_delay,mdelay0,scan,matrix_debug_delay  handwired/mtei_matrix_test/promicro:default:flash
```

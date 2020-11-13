# wait_test.c

## slow clock TEST=slow (8MHz)

* eg. `make TEST=slow,long handwired/mtei_matrix_test/proton_c:wtest:flash`

## normal clock TEST=fast (72MHz) (default)

* eg. `make TEST=long handwired/mtei_matrix_test/proton_c:wtest:flash`
* eg. `make TEST=fast,long handwired/mtei_matrix_test/proton_c:wtest:flash`

## normal test

wait 0...31 clock

* eg. `make TEST= handwired/mtei_matrix_test/proton_c:wtest:flash`

## long test

* 16 nop vs 16 clock(loop)
* 32 nop vs 32 clock(loop)
* 48 nop vs 48 clock(loop)
* 64 nop vs 64 clock(loop)
* 72 nop vs 72 clock(loop)

* eg. `make TEST=long handwired/mtei_matrix_test/proton_c:wtest:flash`

## aligned_4clock_delay() test

* eg. `make TEST=4clock handwired/mtei_matrix_test/proton_c:wtest:flash`

## aligned_16clock_delay() test

* eg. `make TEST=16clock handwired/mtei_matrix_test/proton_c:wtest:flash`

## align 0,1,..,7 test

* eg. `make TEST=align handwired/mtei_matrix_test/proton_c:wtest:flash`

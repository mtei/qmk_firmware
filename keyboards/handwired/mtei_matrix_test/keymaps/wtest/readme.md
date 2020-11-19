# wait_test.c

##  `make TEST=loop handwired/mtei_matrix_test/proton_c:wtest:flash`

`ALIGNED_NOP_LOOP_CLOCKS` と `ALIGNED_NOP_LOOP_CALL_OVER_HEAD` を決定するためのテスト

##  `make TEST=long handwired/mtei_matrix_test/proton_c:wtest:flash`

16, 32, 48, 64, 72 のそれぞれの値で、`wait_cpuclock_allnop()` と `wait_cpuclock_noploop()` が一致するかの確認をする。

##  `make TEST=align handwired/mtei_matrix_test/proton_c:wtest:flash`

`wait_cpuclock_noploop()` の展開位置で、結果がかわる事を確認する。

##  `make TEST=allnop handwired/mtei_matrix_test/proton_c:wtest:flash`

`wait_cpuclock_allnop()` を 0..72 で確認する。

##  `make TEST=normal handwired/mtei_matrix_test/proton_c:wtest:flash`

`wait_cpuclock_noploop()` を 0..72 で確認する。

## `make TEST=slow,XXX handwired/mtei_matrix_test/proton_c:wtest:flash`

上記のテストを システムクロック 8MHz の設定で行なう。

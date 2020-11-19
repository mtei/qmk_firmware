# wait_test.c

##  `make TEST=loop handwired/mtei_matrix_test/proton_c:wtest:flash`

`ALIGNED_NOP_LOOP_CLOCKS` と `ALIGNED_NOP_LOOP_CALL_OVER_HEAD` を決定するためのテスト

### Proton-C の結果
* ALIGNED_NOP_LOOP_CLOCKS = 9
  ![looptest1](https://user-images.githubusercontent.com/2170248/99726658-18ba8680-2afa-11eb-951e-188fdbfd9bf5.png)
* ALIGNED_NOP_LOOP_CALL_OVER_HEAD 8
  ![looptest2](https://user-images.githubusercontent.com/2170248/99726667-1d7f3a80-2afa-11eb-9b3e-04e27f3aae23.png)

##  `make TEST=long handwired/mtei_matrix_test/proton_c:wtest:flash`

16, 32, 48, 64, 72 のそれぞれの値で、`wait_cpuclock_allnop()` と `wait_cpuclock_noploop()` が一致するかの確認をする。

### Proton-C の結果
  ![DS1Z_QuickPrint103](https://user-images.githubusercontent.com/2170248/99727180-ec533a00-2afa-11eb-85b8-5c8f07caa8ea.png)

##  `make TEST=align handwired/mtei_matrix_test/proton_c:wtest:flash`

`wait_cpuclock_noploop()` の展開位置で、結果がかわる事を確認する。

### Proton-C の結果
* 指定値にたいして、+0,+1,+2,+3,+4 の誤差がありうる。
  ![DS1Z_QuickPrint104](https://user-images.githubusercontent.com/2170248/99727328-215f8c80-2afb-11eb-909b-bd8b61f83df7.png)

##  `make TEST=allnop handwired/mtei_matrix_test/proton_c:wtest:flash`

`wait_cpuclock_allnop()` を 0..72 で確認する。

### Proton-C の結果
![DS1Z_QuickPrint105](https://user-images.githubusercontent.com/2170248/99727948-ffb2d500-2afb-11eb-8840-3a975a0163f6.png)

##  `make TEST=normal handwired/mtei_matrix_test/proton_c:wtest:flash`

`wait_cpuclock_noploop()` を 0..72 で確認する。

### Proton-C の結果
上と同じ

##  `make TEST=iodelay handwired/mtei_matrix_test/proton_c:wtest:flash`

入力の変化に、どれくらいの遅れを見込んでおけるか確認する。

## `make TEST=slow,XXX handwired/mtei_matrix_test/proton_c:wtest:flash`

上記のテストを システムクロック 8MHz の設定で行なう。

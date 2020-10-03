# Testing for matrix.c with Pro Micro

![promicro](imgur.com image replace me!)

A 6x6 ortho keyboard - Testing for matrix.c

* Keyboard Maintainer: [mtei](https://github.com/mtei)
* Hardware Supported: 6x6 PCB, Proton C
* Hardware Availability: none

Make example for this keyboard (after setting up your build environment):

    make handwired/mtei_matrix_test/proton_c:default
    make MATRIX_SCAN=yes handwired/mtei_matrix_test/proton_c:default

Flashing example for this keyboard:

    make handwired/mtei_matrix_test/proton_c:default:flash
    make MATRIX_SCAN=yes handwired/mtei_matrix_test/proton_c:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

#include QMK_KEYBOARD_H
#include "wait.h"
//#define LONG_TEST
//#define TEST_4CLOCK
#define TEST_16CLOCK

extern void aligned_4clock_delay(unsigned int n);
extern void aligned_16clock_delay(unsigned int n);

#ifdef LONG_TEST
#define WAIT_NUM_BASE 0
#define WAIT_NUM_LOOP 15
#define TEST_INTERVAL 2000
#elif defined(TEST_4CLOCK)
#define WAIT_NUM_BASE 0
#define WAIT_NUM_LOOP 10
#define TEST_INTERVAL 5000
#elif defined(TEST_16CLOCK)
#define WAIT_NUM_BASE 0
#define WAIT_NUM_LOOP 10
#define TEST_INTERVAL 5000
#else
#define WAIT_NUM_BASE 0
#define WAIT_NUM_LOOP 32
#define TEST_INTERVAL 500
#endif

void keyboard_post_init_user() {
    setPinOutput(WAIT_TSET_PIN);
    writePinLow(WAIT_TSET_PIN);
}

#define PinHi() writePinHigh(WAIT_TSET_PIN)
#define PinLow() writePinLow(WAIT_TSET_PIN)
#define attr_aligned16 __attribute__ ((aligned(16),noinline))

attr_aligned16 void wait4_test_1(void)   { PinHi(); aligned_4clock_delay(1); PinLow(); }
attr_aligned16 void wait4_test_2(void)   { PinHi(); aligned_4clock_delay(2); PinLow(); }
attr_aligned16 void wait4_test_3(void)   { PinHi(); aligned_4clock_delay(3); PinLow(); }
attr_aligned16 void wait4_test_4(void)   { PinHi(); aligned_4clock_delay(4); PinLow(); }
attr_aligned16 void wait4_test_5(void)   { PinHi(); aligned_4clock_delay(5); PinLow(); }
attr_aligned16 void wait4_test_6(void)   { PinHi(); aligned_4clock_delay(6); PinLow(); }
attr_aligned16 void wait4_test_7(void)   { PinHi(); aligned_4clock_delay(7); PinLow(); }
attr_aligned16 void wait4_test_8(void)   { PinHi(); aligned_4clock_delay(8); PinLow(); }
attr_aligned16 void wait4_test_9(void)   { PinHi(); aligned_4clock_delay(9); PinLow(); }
attr_aligned16 void wait4_test_10(void)  { PinHi(); aligned_4clock_delay(10); PinLow(); }

attr_aligned16 void wait16_test_1(void)   { PinHi(); aligned_16clock_delay(1); PinLow(); }
attr_aligned16 void wait16_test_2(void)   { PinHi(); aligned_16clock_delay(2); PinLow(); }
attr_aligned16 void wait16_test_3(void)   { PinHi(); aligned_16clock_delay(3); PinLow(); }
attr_aligned16 void wait16_test_4(void)   { PinHi(); aligned_16clock_delay(4); PinLow(); }
attr_aligned16 void wait16_test_5(void)   { PinHi(); aligned_16clock_delay(5); PinLow(); }
attr_aligned16 void wait16_test_6(void)   { PinHi(); aligned_16clock_delay(6); PinLow(); }
attr_aligned16 void wait16_test_7(void)   { PinHi(); aligned_16clock_delay(7); PinLow(); }
attr_aligned16 void wait16_test_8(void)   { PinHi(); aligned_16clock_delay(8); PinLow(); }
attr_aligned16 void wait16_test_9(void)   { PinHi(); aligned_16clock_delay(9); PinLow(); }
attr_aligned16 void wait16_test_10(void)  { PinHi(); aligned_16clock_delay(10); PinLow(); }

attr_aligned16 void wait_test_0(void)  { PinHi(); wait_cpuclock(0); PinLow(); }
attr_aligned16 void wait_test_1(void)  { PinHi(); wait_cpuclock(1); PinLow(); }
attr_aligned16 void wait_test_2(void)  { PinHi(); wait_cpuclock(2); PinLow(); }
attr_aligned16 void wait_test_3(void)  { PinHi(); wait_cpuclock(3); PinLow(); }
attr_aligned16 void wait_test_4(void)  { PinHi(); wait_cpuclock(4); PinLow(); }
attr_aligned16 void wait_test_5(void)  { PinHi(); wait_cpuclock(5); PinLow(); }
attr_aligned16 void wait_test_6(void)  { PinHi(); wait_cpuclock(6); PinLow(); }
attr_aligned16 void wait_test_7(void)  { PinHi(); wait_cpuclock(7); PinLow(); }
attr_aligned16 void wait_test_8(void)  { PinHi(); wait_cpuclock(8); PinLow(); }
attr_aligned16 void wait_test_9(void)  { PinHi(); wait_cpuclock(9); PinLow(); }
attr_aligned16 void wait_test_10(void) { PinHi(); wait_cpuclock(10); PinLow(); }
attr_aligned16 void wait_test_11(void) { PinHi(); wait_cpuclock(11); PinLow(); }
attr_aligned16 void wait_test_12(void) { PinHi(); wait_cpuclock(12); PinLow(); }
attr_aligned16 void wait_test_13(void) { PinHi(); wait_cpuclock(13); PinLow(); }
attr_aligned16 void wait_test_14(void) { PinHi(); wait_cpuclock(14); PinLow(); }
attr_aligned16 void wait_test_15(void) { PinHi(); wait_cpuclock(15); PinLow(); }
attr_aligned16 void wait_test_16(void) { PinHi(); wait_cpuclock(16); PinLow(); }
attr_aligned16 void wait_test_17(void) { PinHi(); wait_cpuclock(17); PinLow(); }
attr_aligned16 void wait_test_18(void) { PinHi(); wait_cpuclock(18); PinLow(); }
attr_aligned16 void wait_test_19(void) { PinHi(); wait_cpuclock(19); PinLow(); }
attr_aligned16 void wait_test_20(void) { PinHi(); wait_cpuclock(20); PinLow(); }
attr_aligned16 void wait_test_21(void) { PinHi(); wait_cpuclock(21); PinLow(); }
attr_aligned16 void wait_test_22(void) { PinHi(); wait_cpuclock(22); PinLow(); }
attr_aligned16 void wait_test_23(void) { PinHi(); wait_cpuclock(23); PinLow(); }
attr_aligned16 void wait_test_24(void) { PinHi(); wait_cpuclock(24); PinLow(); }
attr_aligned16 void wait_test_25(void) { PinHi(); wait_cpuclock(25); PinLow(); }
attr_aligned16 void wait_test_26(void) { PinHi(); wait_cpuclock(26); PinLow(); }
attr_aligned16 void wait_test_27(void) { PinHi(); wait_cpuclock(27); PinLow(); }
attr_aligned16 void wait_test_28(void) { PinHi(); wait_cpuclock(28); PinLow(); }
attr_aligned16 void wait_test_29(void) { PinHi(); wait_cpuclock(29); PinLow(); }
attr_aligned16 void wait_test_30(void) { PinHi(); wait_cpuclock(30); PinLow(); }
attr_aligned16 void wait_test_31(void) { PinHi(); wait_cpuclock(31); PinLow(); }
attr_aligned16 void wait_test_32(void) { PinHi(); wait_cpuclock(32); PinLow(); }
attr_aligned16 void wait_test_33(void) { PinHi(); wait_cpuclock(33); PinLow(); }
attr_aligned16 void wait_test_34(void) { PinHi(); wait_cpuclock(34); PinLow(); }
attr_aligned16 void wait_test_35(void) { PinHi(); wait_cpuclock(35); PinLow(); }
attr_aligned16 void wait_test_36(void) { PinHi(); wait_cpuclock(36); PinLow(); }
attr_aligned16 void wait_test_37(void) { PinHi(); wait_cpuclock(37); PinLow(); }
attr_aligned16 void wait_test_38(void) { PinHi(); wait_cpuclock(38); PinLow(); }
attr_aligned16 void wait_test_39(void) { PinHi(); wait_cpuclock(39); PinLow(); }
attr_aligned16 void wait_test_40(void) { PinHi(); wait_cpuclock(40); PinLow(); }
attr_aligned16 void wait_test_41(void) { PinHi(); wait_cpuclock(41); PinLow(); }
attr_aligned16 void wait_test_42(void) { PinHi(); wait_cpuclock(42); PinLow(); }
attr_aligned16 void wait_test_43(void) { PinHi(); wait_cpuclock(43); PinLow(); }
attr_aligned16 void wait_test_44(void) { PinHi(); wait_cpuclock(44); PinLow(); }
attr_aligned16 void wait_test_45(void) { PinHi(); wait_cpuclock(45); PinLow(); }
attr_aligned16 void wait_test_46(void) { PinHi(); wait_cpuclock(46); PinLow(); }
attr_aligned16 void wait_test_47(void) { PinHi(); wait_cpuclock(47); PinLow(); }
attr_aligned16 void wait_test_48(void) { PinHi(); wait_cpuclock(48); PinLow(); }
attr_aligned16 void wait_test_49(void) { PinHi(); wait_cpuclock(49); PinLow(); }
attr_aligned16 void wait_test_50(void) { PinHi(); wait_cpuclock(50); PinLow(); }


attr_aligned16 void wait_test_12_a1(void) { wait_cpuclock(1); PinHi(); wait_cpuclock(12); PinLow(); }
attr_aligned16 void wait_test_12_a2(void) { wait_cpuclock(2); PinHi(); wait_cpuclock(12); PinLow(); }
attr_aligned16 void wait_test_12_a3(void) { wait_cpuclock(3); PinHi(); wait_cpuclock(12); PinLow(); }
attr_aligned16 void wait_test_12_a4(void) { wait_cpuclock(4); PinHi(); wait_cpuclock(12); PinLow(); }
attr_aligned16 void wait_test_12_a5(void) { wait_cpuclock(5); PinHi(); wait_cpuclock(12); PinLow(); }
attr_aligned16 void wait_test_12_a6(void) { wait_cpuclock(6); PinHi(); wait_cpuclock(12); PinLow(); }
attr_aligned16 void wait_test_12_a7(void) { wait_cpuclock(7); PinHi(); wait_cpuclock(12); PinLow(); }

attr_aligned16 void wait_test_64(void) { PinHi(); wait_cpuclock(64); PinLow(); }
attr_aligned16 void wait_test_65(void) { PinHi(); wait_cpuclock(65); PinLow(); }

attr_aligned16 void wait_test_72(void) { PinHi(); wait_cpuclock(72); PinLow(); }

attr_aligned16 void wait_test_9_p(void) {
    PinHi();
    wait_cpuclock(8);
    wait_cpuclock(1);
    PinLow();
}

attr_aligned16 void wait_test_10_p(void) {
    PinHi();
    wait_cpuclock(8);
    wait_cpuclock(2);
    PinLow();
}

attr_aligned16 void wait_test_11_p(void) {
    PinHi();
    wait_cpuclock(8);
    wait_cpuclock(3);
    PinLow();
}

attr_aligned16 void wait_test_12_p(void) {
    PinHi();
    wait_cpuclock(8);
    wait_cpuclock(4);
    PinLow();
}

attr_aligned16 void wait_test_16_p(void) {
    PinHi();
    wait_cpuclock(8);
    wait_cpuclock(8);
    PinLow();
}

attr_aligned16 void wait_test_24_p(void) {
    PinHi();
    wait_cpuclock(8);
    wait_cpuclock(8);
    wait_cpuclock(8);
    PinLow();
}

attr_aligned16 void wait_test_32_p(void) {
    PinHi();
    wait_cpuclock(8);
    wait_cpuclock(8);
    wait_cpuclock(8);
    wait_cpuclock(8); //4
    PinLow();
}

attr_aligned16 void wait_test_48_p(void) {
    PinHi();
    wait_cpuclock(8);
    wait_cpuclock(8);
    wait_cpuclock(8);
    wait_cpuclock(8); //4
    wait_cpuclock(8);
    wait_cpuclock(8);
    PinLow();
}

attr_aligned16 void wait_test_64_p(void) {
    PinHi();
    wait_cpuclock(8);
    wait_cpuclock(8);
    wait_cpuclock(8);
    wait_cpuclock(8);//4
    wait_cpuclock(8);
    wait_cpuclock(8);
    wait_cpuclock(8);
    wait_cpuclock(8);//8
    PinLow();
}

attr_aligned16 void wait_test_65_p(void) {
    PinHi();
    wait_cpuclock(8);
    wait_cpuclock(8);
    wait_cpuclock(8);
    wait_cpuclock(8);//4
    wait_cpuclock(8);
    wait_cpuclock(8);
    wait_cpuclock(8);
    wait_cpuclock(8);//8
    wait_cpuclock(1);
    PinLow();
}

attr_aligned16 void wait_test_72_p(void) {
    PinHi();
    wait_cpuclock(8);
    wait_cpuclock(8);
    wait_cpuclock(8);
    wait_cpuclock(8);//4
    wait_cpuclock(8);
    wait_cpuclock(8);
    wait_cpuclock(8);
    wait_cpuclock(8);//8
    wait_cpuclock(8);
    PinLow();
}

void matrix_scan_post_user(void) {
    static int testnum = 0;
    static uint16_t test_timeout = 0;
    if (timer_elapsed(test_timeout) < TEST_INTERVAL) {
        return;
    }
    test_timeout = timer_read();
    ATOMIC_BLOCK_FORCEON {
        switch(testnum+WAIT_NUM_BASE) {
#ifdef LONG_TEST
        case 0: wait_test_2();    break;
        case 1: wait_test_16_p(); break;
        case 2: wait_test_16();   break;
        case 3: wait_test_3();    break;
        case 4: wait_test_32_p(); break;
        case 5: wait_test_32();   break;
        case 6: wait_test_4();    break;
        case 7: wait_test_48_p(); break;
        case 8: wait_test_48();   break;
        case 9: wait_test_5();    break;
        case 10: wait_test_64_p(); break;
        case 11: wait_test_64();   break;
        case 12: wait_test_6();   break;
        case 13: wait_test_72_p(); break;
        case 14: wait_test_72();   break;
#elif defined(TEST_4CLOCK)
        case 0: wait4_test_1(); break;
        case 1: wait4_test_2(); break;
        case 2: wait4_test_3(); break;
        case 3: wait4_test_4(); break;
        case 4: wait4_test_5(); break;
        case 5: wait4_test_6(); break;
        case 6: wait4_test_7(); break;
        case 7: wait4_test_8(); break;
        case 8: wait4_test_9(); break;
        case 9: wait4_test_10(); break;
#elif defined(TEST_16CLOCK)
        case 0: wait16_test_1(); break;
        case 1: wait16_test_2(); break;
        case 2: wait16_test_3(); break;
        case 3: wait16_test_4(); break;
        case 4: wait16_test_5(); break;
        case 5: wait16_test_6(); break;
        case 6: wait16_test_7(); break;
        case 7: wait16_test_8(); break;
        case 8: wait16_test_9(); break;
        case 9: wait16_test_10(); break;
#else
        case 0: wait_test_0(); break;
        case 1: wait_test_1(); break;
        case 2: wait_test_2(); break;
        case 3: wait_test_3(); break;
        case 4: wait_test_4(); break;
        case 5: wait_test_5(); break;
        case 6: wait_test_6(); break;
        case 7: wait_test_7(); break;
        case 8: wait_test_8(); break;
        case 9: wait_test_9();   break;
        case 10: wait_test_10(); break;
        case 11: wait_test_11(); break;
        case 12: wait_test_12(); break;
        case 13: wait_test_13(); break;
        case 14: wait_test_14(); break;
        case 15: wait_test_15(); break;
        case 16: wait_test_16(); break;
        case 17: wait_test_17(); break;
        case 18: wait_test_18(); break;
        case 19: wait_test_19(); break;
        case 20: wait_test_20(); break;
        case 21: wait_test_21(); break;
        case 22: wait_test_22(); break;
        case 23: wait_test_23(); break;
        case 24: wait_test_24(); break;
        case 25: wait_test_25(); break;
        case 26: wait_test_26(); break;
        case 27: wait_test_27(); break;
        case 28: wait_test_28(); break;
        case 29: wait_test_29(); break;
        case 30: wait_test_30(); break;
        case 31: wait_test_31(); break;
        case 32: wait_test_32(); break;
#endif
        }
    }
    testnum = (testnum + 1) % WAIT_NUM_LOOP;
}

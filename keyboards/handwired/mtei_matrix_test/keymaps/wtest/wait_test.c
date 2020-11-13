#include QMK_KEYBOARD_H
#include "wait.h"
//#define LONG_TEST
//#define TEST_4CLOCK
//#define TEST_16CLOCK
//#define ALIGN_TEST

/* clang-format off */

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
#elif defined(ALIGN_TEST)
#define WAIT_NUM_BASE 0
#define WAIT_NUM_LOOP 9
#define TEST_INTERVAL 1000
#else
#define WAIT_NUM_BASE 0
#define WAIT_NUM_LOOP 32
#define TEST_INTERVAL 500
#endif

void keyboard_post_init_user() {
    setPinOutput(WAIT_TSET_PIN);
    writePinLow(WAIT_TSET_PIN);
}

#define Pin_H() writePinHigh(WAIT_TSET_PIN)
#define Pin_L() writePinLow(WAIT_TSET_PIN)
#define attr_aligned16 __attribute__ ((aligned(16),noinline))

attr_aligned16 void wait4_test_1(void)   { Pin_H(); aligned_4clock_delay(1); Pin_L(); }
attr_aligned16 void wait4_test_2(void)   { Pin_H(); aligned_4clock_delay(2); Pin_L(); }
attr_aligned16 void wait4_test_3(void)   { Pin_H(); aligned_4clock_delay(3); Pin_L(); }
attr_aligned16 void wait4_test_4(void)   { Pin_H(); aligned_4clock_delay(4); Pin_L(); }
attr_aligned16 void wait4_test_5(void)   { Pin_H(); aligned_4clock_delay(5); Pin_L(); }
attr_aligned16 void wait4_test_6(void)   { Pin_H(); aligned_4clock_delay(6); Pin_L(); }
attr_aligned16 void wait4_test_7(void)   { Pin_H(); aligned_4clock_delay(7); Pin_L(); }
attr_aligned16 void wait4_test_8(void)   { Pin_H(); aligned_4clock_delay(8); Pin_L(); }
attr_aligned16 void wait4_test_9(void)   { Pin_H(); aligned_4clock_delay(9); Pin_L(); }
attr_aligned16 void wait4_test_10(void)  { Pin_H(); aligned_4clock_delay(10); Pin_L(); }

attr_aligned16 void wait16_test_1(void)   { Pin_H(); aligned_16clock_delay(1); Pin_L(); }
attr_aligned16 void wait16_test_2(void)   { Pin_H(); aligned_16clock_delay(2); Pin_L(); }
attr_aligned16 void wait16_test_3(void)   { Pin_H(); aligned_16clock_delay(3); Pin_L(); }
attr_aligned16 void wait16_test_4(void)   { Pin_H(); aligned_16clock_delay(4); Pin_L(); }
attr_aligned16 void wait16_test_5(void)   { Pin_H(); aligned_16clock_delay(5); Pin_L(); }
attr_aligned16 void wait16_test_6(void)   { Pin_H(); aligned_16clock_delay(6); Pin_L(); }
attr_aligned16 void wait16_test_7(void)   { Pin_H(); aligned_16clock_delay(7); Pin_L(); }
attr_aligned16 void wait16_test_8(void)   { Pin_H(); aligned_16clock_delay(8); Pin_L(); }
attr_aligned16 void wait16_test_9(void)   { Pin_H(); aligned_16clock_delay(9); Pin_L(); }
attr_aligned16 void wait16_test_10(void)  { Pin_H(); aligned_16clock_delay(10); Pin_L(); }

attr_aligned16 void wait_test_0(void)  { Pin_H(); wait_cpuclock(0); Pin_L(); }
attr_aligned16 void wait_test_1(void)  { Pin_H(); wait_cpuclock(1); Pin_L(); }
attr_aligned16 void wait_test_2(void)  { Pin_H(); wait_cpuclock(2); Pin_L(); }
attr_aligned16 void wait_test_3(void)  { Pin_H(); wait_cpuclock(3); Pin_L(); }
attr_aligned16 void wait_test_4(void)  { Pin_H(); wait_cpuclock(4); Pin_L(); }
attr_aligned16 void wait_test_5(void)  { Pin_H(); wait_cpuclock(5); Pin_L(); }
attr_aligned16 void wait_test_6(void)  { Pin_H(); wait_cpuclock(6); Pin_L(); }
attr_aligned16 void wait_test_7(void)  { Pin_H(); wait_cpuclock(7); Pin_L(); }
attr_aligned16 void wait_test_8(void)  { Pin_H(); wait_cpuclock(8); Pin_L(); }
attr_aligned16 void wait_test_9(void)  { Pin_H(); wait_cpuclock(9); Pin_L(); }
attr_aligned16 void wait_test_10(void) { Pin_H(); wait_cpuclock(10); Pin_L(); }
attr_aligned16 void wait_test_11(void) { Pin_H(); wait_cpuclock(11); Pin_L(); }
attr_aligned16 void wait_test_12(void) { Pin_H(); wait_cpuclock(12); Pin_L(); }
attr_aligned16 void wait_test_13(void) { Pin_H(); wait_cpuclock(13); Pin_L(); }
attr_aligned16 void wait_test_14(void) { Pin_H(); wait_cpuclock(14); Pin_L(); }
attr_aligned16 void wait_test_15(void) { Pin_H(); wait_cpuclock(15); Pin_L(); }
attr_aligned16 void wait_test_16(void) { Pin_H(); wait_cpuclock(16); Pin_L(); }
attr_aligned16 void wait_test_17(void) { Pin_H(); wait_cpuclock(17); Pin_L(); }
attr_aligned16 void wait_test_18(void) { Pin_H(); wait_cpuclock(18); Pin_L(); }
attr_aligned16 void wait_test_19(void) { Pin_H(); wait_cpuclock(19); Pin_L(); }
attr_aligned16 void wait_test_20(void) { Pin_H(); wait_cpuclock(20); Pin_L(); }
attr_aligned16 void wait_test_21(void) { Pin_H(); wait_cpuclock(21); Pin_L(); }
attr_aligned16 void wait_test_22(void) { Pin_H(); wait_cpuclock(22); Pin_L(); }
attr_aligned16 void wait_test_23(void) { Pin_H(); wait_cpuclock(23); Pin_L(); }
attr_aligned16 void wait_test_24(void) { Pin_H(); wait_cpuclock(24); Pin_L(); }
attr_aligned16 void wait_test_25(void) { Pin_H(); wait_cpuclock(25); Pin_L(); }
attr_aligned16 void wait_test_26(void) { Pin_H(); wait_cpuclock(26); Pin_L(); }
attr_aligned16 void wait_test_27(void) { Pin_H(); wait_cpuclock(27); Pin_L(); }
attr_aligned16 void wait_test_28(void) { Pin_H(); wait_cpuclock(28); Pin_L(); }
attr_aligned16 void wait_test_29(void) { Pin_H(); wait_cpuclock(29); Pin_L(); }
attr_aligned16 void wait_test_30(void) { Pin_H(); wait_cpuclock(30); Pin_L(); }
attr_aligned16 void wait_test_31(void) { Pin_H(); wait_cpuclock(31); Pin_L(); }
attr_aligned16 void wait_test_32(void) { Pin_H(); wait_cpuclock(32); Pin_L(); }
attr_aligned16 void wait_test_33(void) { Pin_H(); wait_cpuclock(33); Pin_L(); }
attr_aligned16 void wait_test_34(void) { Pin_H(); wait_cpuclock(34); Pin_L(); }
attr_aligned16 void wait_test_35(void) { Pin_H(); wait_cpuclock(35); Pin_L(); }
attr_aligned16 void wait_test_36(void) { Pin_H(); wait_cpuclock(36); Pin_L(); }
attr_aligned16 void wait_test_37(void) { Pin_H(); wait_cpuclock(37); Pin_L(); }
attr_aligned16 void wait_test_38(void) { Pin_H(); wait_cpuclock(38); Pin_L(); }
attr_aligned16 void wait_test_39(void) { Pin_H(); wait_cpuclock(39); Pin_L(); }
attr_aligned16 void wait_test_40(void) { Pin_H(); wait_cpuclock(40); Pin_L(); }
attr_aligned16 void wait_test_41(void) { Pin_H(); wait_cpuclock(41); Pin_L(); }
attr_aligned16 void wait_test_42(void) { Pin_H(); wait_cpuclock(42); Pin_L(); }
attr_aligned16 void wait_test_43(void) { Pin_H(); wait_cpuclock(43); Pin_L(); }
attr_aligned16 void wait_test_44(void) { Pin_H(); wait_cpuclock(44); Pin_L(); }
attr_aligned16 void wait_test_45(void) { Pin_H(); wait_cpuclock(45); Pin_L(); }
attr_aligned16 void wait_test_46(void) { Pin_H(); wait_cpuclock(46); Pin_L(); }
attr_aligned16 void wait_test_47(void) { Pin_H(); wait_cpuclock(47); Pin_L(); }
attr_aligned16 void wait_test_48(void) { Pin_H(); wait_cpuclock(48); Pin_L(); }
attr_aligned16 void wait_test_49(void) { Pin_H(); wait_cpuclock(49); Pin_L(); }
attr_aligned16 void wait_test_50(void) { Pin_H(); wait_cpuclock(50); Pin_L(); }


attr_aligned16 void wait_test_12_a1(void) { wait_cpuclock(1); Pin_H(); wait_cpuclock(12); Pin_L(); }
attr_aligned16 void wait_test_12_a2(void) { wait_cpuclock(2); Pin_H(); wait_cpuclock(12); Pin_L(); }
attr_aligned16 void wait_test_12_a3(void) { wait_cpuclock(3); Pin_H(); wait_cpuclock(12); Pin_L(); }
attr_aligned16 void wait_test_12_a4(void) { wait_cpuclock(4); Pin_H(); wait_cpuclock(12); Pin_L(); }
attr_aligned16 void wait_test_12_a5(void) { wait_cpuclock(5); Pin_H(); wait_cpuclock(12); Pin_L(); }
attr_aligned16 void wait_test_12_a6(void) { wait_cpuclock(6); Pin_H(); wait_cpuclock(12); Pin_L(); }
attr_aligned16 void wait_test_12_a7(void) { wait_cpuclock(7); Pin_H(); wait_cpuclock(12); Pin_L(); }

attr_aligned16 void wait_test_64(void) { Pin_H(); wait_cpuclock(64); Pin_L(); }
attr_aligned16 void wait_test_65(void) { Pin_H(); wait_cpuclock(65); Pin_L(); }

attr_aligned16 void wait_test_72(void) { Pin_H(); wait_cpuclock(72); Pin_L(); }

attr_aligned16 void wait_test_9_p(void) {
    Pin_H();
    wait_cpuclock(8);
    wait_cpuclock(1);
    Pin_L();
}

attr_aligned16 void wait_test_10_p(void) {
    Pin_H();
    wait_cpuclock(8);
    wait_cpuclock(2);
    Pin_L();
}

attr_aligned16 void wait_test_11_p(void) {
    Pin_H();
    wait_cpuclock(8);
    wait_cpuclock(3);
    Pin_L();
}

attr_aligned16 void wait_test_12_p(void) {
    Pin_H();
    wait_cpuclock(8);
    wait_cpuclock(4);
    Pin_L();
}

attr_aligned16 void wait_test_16_p(void) {
    Pin_H();
    wait_cpuclock(8); wait_cpuclock(8);
    Pin_L();
}

attr_aligned16 void wait_test_24_p(void) {
    Pin_H();
    wait_cpuclock(8); wait_cpuclock(8); wait_cpuclock(8);
    Pin_L();
}

attr_aligned16 void wait_test_32_p(void) {
    Pin_H();
    wait_cpuclock(8); wait_cpuclock(8); wait_cpuclock(8); wait_cpuclock(8);
    Pin_L();
}

attr_aligned16 void wait_test_48_p(void) {
    Pin_H();
    wait_cpuclock(8); wait_cpuclock(8); wait_cpuclock(8); wait_cpuclock(8);
    wait_cpuclock(8); wait_cpuclock(8);
    Pin_L();
}

attr_aligned16 void wait_test_64_p(void) {
    Pin_H();
    wait_cpuclock(8); wait_cpuclock(8); wait_cpuclock(8); wait_cpuclock(8);
    wait_cpuclock(8); wait_cpuclock(8); wait_cpuclock(8); wait_cpuclock(8);
    Pin_L();
}

attr_aligned16 void wait_test_65_p(void) {
    Pin_H();
    wait_cpuclock(8); wait_cpuclock(8); wait_cpuclock(8); wait_cpuclock(8);
    wait_cpuclock(8); wait_cpuclock(8); wait_cpuclock(8); wait_cpuclock(8);
    wait_cpuclock(1);
    Pin_L();
}

attr_aligned16 void wait_test_72_p(void) {
    Pin_H();
    wait_cpuclock(8); wait_cpuclock(8); wait_cpuclock(8); wait_cpuclock(8);
    wait_cpuclock(8); wait_cpuclock(8); wait_cpuclock(8); wait_cpuclock(8);
    wait_cpuclock(8);
    Pin_L();
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
#elif defined(ALIGN_TEST)
        case 0: wait_test_12(); break;
        case 1: wait_test_12_a1(); break;
        case 2: wait_test_12_a2(); break;
        case 3: wait_test_12_a3(); break;
        case 4: wait_test_12_a4(); break;
        case 5: wait_test_12_a5(); break;
        case 6: wait_test_12_a6(); break;
        case 7: wait_test_12_a7(); break;
        case 8: wait_test_1(); break;
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

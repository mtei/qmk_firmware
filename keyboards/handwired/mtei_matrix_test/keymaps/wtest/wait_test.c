#include QMK_KEYBOARD_H
#include "wait.h"
//#define LONG_TEST
//#define LOOP_TEST
//#define ALIGN_TEST
//#define ALLNOP_TEST

/* clang-format off */

extern void aligned_nop_loop(unsigned int n);

#undef  wait_cpuclock
#define wait_cpuclock(n) wait_cpuclock_noploop(n)

#ifdef LONG_TEST
#define WAIT_NUM_BASE 0
#define WAIT_NUM_LOOP 15
#define TEST_INTERVAL 2000
#elif defined(LOOP_TEST)
#define WAIT_NUM_BASE 0
#define WAIT_NUM_LOOP 27
#define TEST_INTERVAL 500
#elif defined(ALIGN_TEST)
#define WAIT_NUM_BASE 0
#define WAIT_NUM_LOOP 9
#define TEST_INTERVAL 1000
#elif defined(ALLNOP_TEST)
#define WAIT_NUM_BASE 0
#define WAIT_NUM_LOOP 73
#define TEST_INTERVAL 500
#else
#define WAIT_NUM_BASE 0
#define WAIT_NUM_LOOP 73
#define TEST_INTERVAL 500
#endif

void keyboard_post_init_user() {
    debug_enable = true;
    setPinOutput(WAIT_TSET_PIN);
    writePinLow(WAIT_TSET_PIN);
}

#define Pin_H() writePinHigh(WAIT_TSET_PIN)
#define Pin_L() writePinLow(WAIT_TSET_PIN)
#define attr_aligned16 __attribute__ ((aligned(16),noinline))

#undef ALIGNED_NOP_LOOP_CALL_OVER_HEAD
#define ALIGNED_NOP_LOOP_CALL_OVER_HEAD 8

#undef ALIGNED_NOP_LOOP_CLOCKS
#define ALIGNED_NOP_LOOP_CLOCKS 5

__attribute__((always_inline))
static inline void wait_cpuclock_noploop_5(unsigned int n) {
    /* The argument n must be a constant expression.
     * That way, compiler optimization will remove unnecessary code. */
    if (n < 1) { return; }
    if (n > ((ALIGNED_NOP_LOOP_CALL_OVER_HEAD)+(ALIGNED_NOP_LOOP_CLOCKS))) {
        unsigned int loop = (n - (ALIGNED_NOP_LOOP_CALL_OVER_HEAD))/(ALIGNED_NOP_LOOP_CLOCKS);
        n = n - loop*(ALIGNED_NOP_LOOP_CLOCKS) - (ALIGNED_NOP_LOOP_CALL_OVER_HEAD);
        aligned_nop_loop(loop);
    }
    WAIT_EXPANDING_NOP_24(n);
}

#undef ALIGNED_NOP_LOOP_CLOCKS
#define ALIGNED_NOP_LOOP_CLOCKS 6

__attribute__((always_inline))
static inline void wait_cpuclock_noploop_6(unsigned int n) {
    /* The argument n must be a constant expression.
     * That way, compiler optimization will remove unnecessary code. */
    if (n < 1) { return; }
    if (n > ((ALIGNED_NOP_LOOP_CALL_OVER_HEAD)+(ALIGNED_NOP_LOOP_CLOCKS))) {
        unsigned int loop = (n - (ALIGNED_NOP_LOOP_CALL_OVER_HEAD))/(ALIGNED_NOP_LOOP_CLOCKS);
        n = n - loop*(ALIGNED_NOP_LOOP_CLOCKS) - (ALIGNED_NOP_LOOP_CALL_OVER_HEAD);
        aligned_nop_loop(loop);
    }
    WAIT_EXPANDING_NOP_24(n);
}

#undef ALIGNED_NOP_LOOP_CLOCKS
#define ALIGNED_NOP_LOOP_CLOCKS 7

__attribute__((always_inline))
static inline void wait_cpuclock_noploop_7(unsigned int n) {
    /* The argument n must be a constant expression.
     * That way, compiler optimization will remove unnecessary code. */
    if (n < 1) { return; }
    if (n > ((ALIGNED_NOP_LOOP_CALL_OVER_HEAD)+(ALIGNED_NOP_LOOP_CLOCKS))) {
        unsigned int loop = (n - (ALIGNED_NOP_LOOP_CALL_OVER_HEAD))/(ALIGNED_NOP_LOOP_CLOCKS);
        n = n - loop*(ALIGNED_NOP_LOOP_CLOCKS) - (ALIGNED_NOP_LOOP_CALL_OVER_HEAD);
        aligned_nop_loop(loop);
    }
    WAIT_EXPANDING_NOP_24(n);
}

#undef ALIGNED_NOP_LOOP_CLOCKS
#define ALIGNED_NOP_LOOP_CLOCKS 8

__attribute__((always_inline))
static inline void wait_cpuclock_noploop_8(unsigned int n) {
    /* The argument n must be a constant expression.
     * That way, compiler optimization will remove unnecessary code. */
    if (n < 1) { return; }
    if (n > ((ALIGNED_NOP_LOOP_CALL_OVER_HEAD)+(ALIGNED_NOP_LOOP_CLOCKS))) {
        unsigned int loop = (n - (ALIGNED_NOP_LOOP_CALL_OVER_HEAD))/(ALIGNED_NOP_LOOP_CLOCKS);
        n = n - loop*(ALIGNED_NOP_LOOP_CLOCKS) - (ALIGNED_NOP_LOOP_CALL_OVER_HEAD);
        aligned_nop_loop(loop);
    }
    WAIT_EXPANDING_NOP_24(n);
}

#undef ALIGNED_NOP_LOOP_CLOCKS
#define ALIGNED_NOP_LOOP_CLOCKS 9

__attribute__((always_inline))
static inline void wait_cpuclock_noploop_9(unsigned int n) {
    /* The argument n must be a constant expression.
     * That way, compiler optimization will remove unnecessary code. */
    if (n < 1) { return; }
    if (n > ((ALIGNED_NOP_LOOP_CALL_OVER_HEAD)+(ALIGNED_NOP_LOOP_CLOCKS))) {
        unsigned int loop = (n - (ALIGNED_NOP_LOOP_CALL_OVER_HEAD))/(ALIGNED_NOP_LOOP_CLOCKS);
        n = n - loop*(ALIGNED_NOP_LOOP_CLOCKS) - (ALIGNED_NOP_LOOP_CALL_OVER_HEAD);
        aligned_nop_loop(loop);
    }
    WAIT_EXPANDING_NOP_24(n);
}

#undef ALIGNED_NOP_LOOP_CLOCKS
#define ALIGNED_NOP_LOOP_CLOCKS 10

__attribute__((always_inline))
static inline void wait_cpuclock_noploop_10(unsigned int n) {
    /* The argument n must be a constant expression.
     * That way, compiler optimization will remove unnecessary code. */
    if (n < 1) { return; }
    if (n > ((ALIGNED_NOP_LOOP_CALL_OVER_HEAD)+(ALIGNED_NOP_LOOP_CLOCKS))) {
        unsigned int loop = (n - (ALIGNED_NOP_LOOP_CALL_OVER_HEAD))/(ALIGNED_NOP_LOOP_CLOCKS);
        n = n - loop*(ALIGNED_NOP_LOOP_CLOCKS) - (ALIGNED_NOP_LOOP_CALL_OVER_HEAD);
        aligned_nop_loop(loop);
    }
    WAIT_EXPANDING_NOP_24(n);
}

#undef ALIGNED_NOP_LOOP_CLOCKS
#define ALIGNED_NOP_LOOP_CLOCKS 11

__attribute__((always_inline))
static inline void wait_cpuclock_noploop_11(unsigned int n) {
    /* The argument n must be a constant expression.
     * That way, compiler optimization will remove unnecessary code. */
    if (n < 1) { return; }
    if (n > ((ALIGNED_NOP_LOOP_CALL_OVER_HEAD)+(ALIGNED_NOP_LOOP_CLOCKS))) {
        unsigned int loop = (n - (ALIGNED_NOP_LOOP_CALL_OVER_HEAD))/(ALIGNED_NOP_LOOP_CLOCKS);
        n = n - loop*(ALIGNED_NOP_LOOP_CLOCKS) - (ALIGNED_NOP_LOOP_CALL_OVER_HEAD);
        aligned_nop_loop(loop);
    }
    WAIT_EXPANDING_NOP_24(n);
}

#undef ALIGNED_NOP_LOOP_CLOCKS
#define ALIGNED_NOP_LOOP_CLOCKS 12

__attribute__((always_inline))
static inline void wait_cpuclock_noploop_12(unsigned int n) {
    /* The argument n must be a constant expression.
     * That way, compiler optimization will remove unnecessary code. */
    if (n < 1) { return; }
    if (n > ((ALIGNED_NOP_LOOP_CALL_OVER_HEAD)+(ALIGNED_NOP_LOOP_CLOCKS))) {
        unsigned int loop = (n - (ALIGNED_NOP_LOOP_CALL_OVER_HEAD))/(ALIGNED_NOP_LOOP_CLOCKS);
        n = n - loop*(ALIGNED_NOP_LOOP_CLOCKS) - (ALIGNED_NOP_LOOP_CALL_OVER_HEAD);
        aligned_nop_loop(loop);
    }
    WAIT_EXPANDING_NOP_24(n);
}

attr_aligned16 void wait_cpuclock_noploop_5_100(void) { Pin_H(); wait_cpuclock_noploop_5(100); Pin_L(); }
attr_aligned16 void wait_cpuclock_noploop_6_100(void) { Pin_H(); wait_cpuclock_noploop_6(100); Pin_L(); }
attr_aligned16 void wait_cpuclock_noploop_7_100(void) { Pin_H(); wait_cpuclock_noploop_7(100); Pin_L(); }
attr_aligned16 void wait_cpuclock_noploop_8_100(void) { Pin_H(); wait_cpuclock_noploop_8(100); Pin_L(); }
attr_aligned16 void wait_cpuclock_noploop_9_100(void) { Pin_H(); wait_cpuclock_noploop_9(100); Pin_L(); }
attr_aligned16 void wait_cpuclock_noploop_10_100(void) { Pin_H(); wait_cpuclock_noploop_10(100); Pin_L(); }
attr_aligned16 void wait_cpuclock_noploop_11_100(void) { Pin_H(); wait_cpuclock_noploop_11(100); Pin_L(); }
attr_aligned16 void wait_cpuclock_noploop_12_100(void) { Pin_H(); wait_cpuclock_noploop_12(100); Pin_L(); }

attr_aligned16 void wait_loop_overhead_test_30_11(void)   {
    Pin_H();
    wait_cpuclock_noploop_12(30);    wait_cpuclock_noploop_12(30);
    wait_cpuclock_noploop_12(30);    wait_cpuclock_noploop_12(30);
    wait_cpuclock_noploop_12(30);    wait_cpuclock_noploop_12(30);
    wait_cpuclock_noploop_12(30);    wait_cpuclock_noploop_12(30);
    wait_cpuclock_noploop_12(30);    wait_cpuclock_noploop_12(30);
    wait_cpuclock_noploop_12(30);
    Pin_L();
}

attr_aligned16 void wait_loop_overhead_test_330_1(void)   {
    Pin_H();
    wait_cpuclock_noploop_12(30*11);
    Pin_L();
}

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
attr_aligned16 void wait_test_51(void) { Pin_H(); wait_cpuclock(51); Pin_L(); }
attr_aligned16 void wait_test_52(void) { Pin_H(); wait_cpuclock(52); Pin_L(); }
attr_aligned16 void wait_test_53(void) { Pin_H(); wait_cpuclock(53); Pin_L(); }
attr_aligned16 void wait_test_54(void) { Pin_H(); wait_cpuclock(54); Pin_L(); }
attr_aligned16 void wait_test_55(void) { Pin_H(); wait_cpuclock(55); Pin_L(); }
attr_aligned16 void wait_test_56(void) { Pin_H(); wait_cpuclock(56); Pin_L(); }
attr_aligned16 void wait_test_57(void) { Pin_H(); wait_cpuclock(57); Pin_L(); }
attr_aligned16 void wait_test_58(void) { Pin_H(); wait_cpuclock(58); Pin_L(); }
attr_aligned16 void wait_test_59(void) { Pin_H(); wait_cpuclock(59); Pin_L(); }
attr_aligned16 void wait_test_60(void) { Pin_H(); wait_cpuclock(60); Pin_L(); }
attr_aligned16 void wait_test_61(void) { Pin_H(); wait_cpuclock(61); Pin_L(); }
attr_aligned16 void wait_test_62(void) { Pin_H(); wait_cpuclock(62); Pin_L(); }
attr_aligned16 void wait_test_63(void) { Pin_H(); wait_cpuclock(63); Pin_L(); }
attr_aligned16 void wait_test_64(void) { Pin_H(); wait_cpuclock(64); Pin_L(); }
attr_aligned16 void wait_test_65(void) { Pin_H(); wait_cpuclock(65); Pin_L(); }
attr_aligned16 void wait_test_66(void) { Pin_H(); wait_cpuclock(66); Pin_L(); }
attr_aligned16 void wait_test_67(void) { Pin_H(); wait_cpuclock(67); Pin_L(); }
attr_aligned16 void wait_test_68(void) { Pin_H(); wait_cpuclock(68); Pin_L(); }
attr_aligned16 void wait_test_69(void) { Pin_H(); wait_cpuclock(69); Pin_L(); }
attr_aligned16 void wait_test_70(void) { Pin_H(); wait_cpuclock(70); Pin_L(); }
attr_aligned16 void wait_test_71(void) { Pin_H(); wait_cpuclock(71); Pin_L(); }
attr_aligned16 void wait_test_72(void) { Pin_H(); wait_cpuclock(72); Pin_L(); }

attr_aligned16 void wait_test_0_all(void)  { Pin_H(); wait_cpuclock_allnop(0); Pin_L(); }
attr_aligned16 void wait_test_1_all(void)  { Pin_H(); wait_cpuclock_allnop(1); Pin_L(); }
attr_aligned16 void wait_test_2_all(void)  { Pin_H(); wait_cpuclock_allnop(2); Pin_L(); }
attr_aligned16 void wait_test_3_all(void)  { Pin_H(); wait_cpuclock_allnop(3); Pin_L(); }
attr_aligned16 void wait_test_4_all(void)  { Pin_H(); wait_cpuclock_allnop(4); Pin_L(); }
attr_aligned16 void wait_test_5_all(void)  { Pin_H(); wait_cpuclock_allnop(5); Pin_L(); }
attr_aligned16 void wait_test_6_all(void)  { Pin_H(); wait_cpuclock_allnop(6); Pin_L(); }
attr_aligned16 void wait_test_7_all(void)  { Pin_H(); wait_cpuclock_allnop(7); Pin_L(); }
attr_aligned16 void wait_test_8_all(void)  { Pin_H(); wait_cpuclock_allnop(8); Pin_L(); }
attr_aligned16 void wait_test_9_all(void)  { Pin_H(); wait_cpuclock_allnop(9); Pin_L(); }
attr_aligned16 void wait_test_10_all(void) { Pin_H(); wait_cpuclock_allnop(10); Pin_L(); }
attr_aligned16 void wait_test_11_all(void) { Pin_H(); wait_cpuclock_allnop(11); Pin_L(); }
attr_aligned16 void wait_test_12_all(void) { Pin_H(); wait_cpuclock_allnop(12); Pin_L(); }
attr_aligned16 void wait_test_13_all(void) { Pin_H(); wait_cpuclock_allnop(13); Pin_L(); }
attr_aligned16 void wait_test_14_all(void) { Pin_H(); wait_cpuclock_allnop(14); Pin_L(); }
attr_aligned16 void wait_test_15_all(void) { Pin_H(); wait_cpuclock_allnop(15); Pin_L(); }
attr_aligned16 void wait_test_16_all(void) { Pin_H(); wait_cpuclock_allnop(16); Pin_L(); }
attr_aligned16 void wait_test_17_all(void) { Pin_H(); wait_cpuclock_allnop(17); Pin_L(); }
attr_aligned16 void wait_test_18_all(void) { Pin_H(); wait_cpuclock_allnop(18); Pin_L(); }
attr_aligned16 void wait_test_19_all(void) { Pin_H(); wait_cpuclock_allnop(19); Pin_L(); }
attr_aligned16 void wait_test_20_all(void) { Pin_H(); wait_cpuclock_allnop(20); Pin_L(); }
attr_aligned16 void wait_test_21_all(void) { Pin_H(); wait_cpuclock_allnop(21); Pin_L(); }
attr_aligned16 void wait_test_22_all(void) { Pin_H(); wait_cpuclock_allnop(22); Pin_L(); }
attr_aligned16 void wait_test_23_all(void) { Pin_H(); wait_cpuclock_allnop(23); Pin_L(); }
attr_aligned16 void wait_test_24_all(void) { Pin_H(); wait_cpuclock_allnop(24); Pin_L(); }
attr_aligned16 void wait_test_25_all(void) { Pin_H(); wait_cpuclock_allnop(25); Pin_L(); }
attr_aligned16 void wait_test_26_all(void) { Pin_H(); wait_cpuclock_allnop(26); Pin_L(); }
attr_aligned16 void wait_test_27_all(void) { Pin_H(); wait_cpuclock_allnop(27); Pin_L(); }
attr_aligned16 void wait_test_28_all(void) { Pin_H(); wait_cpuclock_allnop(28); Pin_L(); }
attr_aligned16 void wait_test_29_all(void) { Pin_H(); wait_cpuclock_allnop(29); Pin_L(); }
attr_aligned16 void wait_test_30_all(void) { Pin_H(); wait_cpuclock_allnop(30); Pin_L(); }
attr_aligned16 void wait_test_31_all(void) { Pin_H(); wait_cpuclock_allnop(31); Pin_L(); }
attr_aligned16 void wait_test_32_all(void) { Pin_H(); wait_cpuclock_allnop(32); Pin_L(); }
attr_aligned16 void wait_test_33_all(void) { Pin_H(); wait_cpuclock_allnop(33); Pin_L(); }
attr_aligned16 void wait_test_34_all(void) { Pin_H(); wait_cpuclock_allnop(34); Pin_L(); }
attr_aligned16 void wait_test_35_all(void) { Pin_H(); wait_cpuclock_allnop(35); Pin_L(); }
attr_aligned16 void wait_test_36_all(void) { Pin_H(); wait_cpuclock_allnop(36); Pin_L(); }
attr_aligned16 void wait_test_37_all(void) { Pin_H(); wait_cpuclock_allnop(37); Pin_L(); }
attr_aligned16 void wait_test_38_all(void) { Pin_H(); wait_cpuclock_allnop(38); Pin_L(); }
attr_aligned16 void wait_test_39_all(void) { Pin_H(); wait_cpuclock_allnop(39); Pin_L(); }
attr_aligned16 void wait_test_40_all(void) { Pin_H(); wait_cpuclock_allnop(40); Pin_L(); }
attr_aligned16 void wait_test_41_all(void) { Pin_H(); wait_cpuclock_allnop(41); Pin_L(); }
attr_aligned16 void wait_test_42_all(void) { Pin_H(); wait_cpuclock_allnop(42); Pin_L(); }
attr_aligned16 void wait_test_43_all(void) { Pin_H(); wait_cpuclock_allnop(43); Pin_L(); }
attr_aligned16 void wait_test_44_all(void) { Pin_H(); wait_cpuclock_allnop(44); Pin_L(); }
attr_aligned16 void wait_test_45_all(void) { Pin_H(); wait_cpuclock_allnop(45); Pin_L(); }
attr_aligned16 void wait_test_46_all(void) { Pin_H(); wait_cpuclock_allnop(46); Pin_L(); }
attr_aligned16 void wait_test_47_all(void) { Pin_H(); wait_cpuclock_allnop(47); Pin_L(); }
attr_aligned16 void wait_test_48_all(void) { Pin_H(); wait_cpuclock_allnop(48); Pin_L(); }
attr_aligned16 void wait_test_49_all(void) { Pin_H(); wait_cpuclock_allnop(49); Pin_L(); }
attr_aligned16 void wait_test_50_all(void) { Pin_H(); wait_cpuclock_allnop(50); Pin_L(); }
attr_aligned16 void wait_test_51_all(void) { Pin_H(); wait_cpuclock_allnop(51); Pin_L(); }
attr_aligned16 void wait_test_52_all(void) { Pin_H(); wait_cpuclock_allnop(52); Pin_L(); }
attr_aligned16 void wait_test_53_all(void) { Pin_H(); wait_cpuclock_allnop(53); Pin_L(); }
attr_aligned16 void wait_test_54_all(void) { Pin_H(); wait_cpuclock_allnop(54); Pin_L(); }
attr_aligned16 void wait_test_55_all(void) { Pin_H(); wait_cpuclock_allnop(55); Pin_L(); }
attr_aligned16 void wait_test_56_all(void) { Pin_H(); wait_cpuclock_allnop(56); Pin_L(); }
attr_aligned16 void wait_test_57_all(void) { Pin_H(); wait_cpuclock_allnop(57); Pin_L(); }
attr_aligned16 void wait_test_58_all(void) { Pin_H(); wait_cpuclock_allnop(58); Pin_L(); }
attr_aligned16 void wait_test_59_all(void) { Pin_H(); wait_cpuclock_allnop(59); Pin_L(); }
attr_aligned16 void wait_test_60_all(void) { Pin_H(); wait_cpuclock_allnop(60); Pin_L(); }
attr_aligned16 void wait_test_61_all(void) { Pin_H(); wait_cpuclock_allnop(61); Pin_L(); }
attr_aligned16 void wait_test_62_all(void) { Pin_H(); wait_cpuclock_allnop(62); Pin_L(); }
attr_aligned16 void wait_test_63_all(void) { Pin_H(); wait_cpuclock_allnop(63); Pin_L(); }
attr_aligned16 void wait_test_64_all(void) { Pin_H(); wait_cpuclock_allnop(64); Pin_L(); }
attr_aligned16 void wait_test_65_all(void) { Pin_H(); wait_cpuclock_allnop(65); Pin_L(); }
attr_aligned16 void wait_test_66_all(void) { Pin_H(); wait_cpuclock_allnop(66); Pin_L(); }
attr_aligned16 void wait_test_67_all(void) { Pin_H(); wait_cpuclock_allnop(67); Pin_L(); }
attr_aligned16 void wait_test_68_all(void) { Pin_H(); wait_cpuclock_allnop(68); Pin_L(); }
attr_aligned16 void wait_test_69_all(void) { Pin_H(); wait_cpuclock_allnop(69); Pin_L(); }
attr_aligned16 void wait_test_70_all(void) { Pin_H(); wait_cpuclock_allnop(70); Pin_L(); }
attr_aligned16 void wait_test_71_all(void) { Pin_H(); wait_cpuclock_allnop(71); Pin_L(); }
attr_aligned16 void wait_test_72_all(void) { Pin_H(); wait_cpuclock_allnop(72); Pin_L(); }

attr_aligned16 void wait_test_100_all(void) { Pin_H(); wait_cpuclock_allnop(100); Pin_L(); }

attr_aligned16 void wait_test_12_a1(void) { wait_cpuclock(1); Pin_H(); wait_cpuclock(12); Pin_L(); }
attr_aligned16 void wait_test_12_a2(void) { wait_cpuclock(2); Pin_H(); wait_cpuclock(12); Pin_L(); }
attr_aligned16 void wait_test_12_a3(void) { wait_cpuclock(3); Pin_H(); wait_cpuclock(12); Pin_L(); }
attr_aligned16 void wait_test_12_a4(void) { wait_cpuclock(4); Pin_H(); wait_cpuclock(12); Pin_L(); }
attr_aligned16 void wait_test_12_a5(void) { wait_cpuclock(5); Pin_H(); wait_cpuclock(12); Pin_L(); }
attr_aligned16 void wait_test_12_a6(void) { wait_cpuclock(6); Pin_H(); wait_cpuclock(12); Pin_L(); }
attr_aligned16 void wait_test_12_a7(void) { wait_cpuclock(7); Pin_H(); wait_cpuclock(12); Pin_L(); }

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
        case 1: wait_test_16_all(); break;
        case 2: wait_test_16();   break;
        case 3: wait_test_3();    break;
        case 4: wait_test_32_all(); break;
        case 5: wait_test_32();   break;
        case 6: wait_test_4();    break;
        case 7: wait_test_48_all(); break;
        case 8: wait_test_48();   break;
        case 9: wait_test_5();    break;
        case 10: wait_test_64_all(); break;
        case 11: wait_test_64();   break;
        case 12: wait_test_6();   break;
        case 13: wait_test_72_all(); break;
        case 14: wait_test_72();   break;
#elif defined(LOOP_TEST)
        case 0: wait_test_2(); break;
        case 1: wait_test_100_all(); dprintf("all nop 100\n"); break;
        case 2: wait_cpuclock_noploop_5_100(); dprintf("loop cycle 5\n"); break;
        case 3: wait_test_100_all(); dprintf("all nop 100\n"); break;
        case 4: wait_cpuclock_noploop_6_100(); dprintf("loop cycle 6\n"); break;
        case 5: wait_test_100_all(); dprintf("all nop 100\n"); break;
        case 6: wait_cpuclock_noploop_7_100(); dprintf("loop cycle 7\n"); break;
        case 7: wait_test_100_all(); dprintf("all nop 100\n"); break;
        case 8: wait_cpuclock_noploop_8_100(); dprintf("loop cycle 8\n"); break;
        case 9: wait_test_100_all(); dprintf("all nop 100\n"); break;
        case 10: wait_cpuclock_noploop_9_100(); dprintf("loop cycle 9\n"); break;
        case 11: wait_test_100_all(); dprintf("all nop 100\n"); break;
        case 12: wait_cpuclock_noploop_10_100(); dprintf("loop cycle 10\n"); break;
        case 13: wait_test_100_all(); dprintf("all nop 100\n"); break;
        case 14: wait_cpuclock_noploop_11_100(); dprintf("loop cycle 11\n"); break;
        case 15: wait_test_100_all(); dprintf("all nop 100\n"); break;
        case 16: wait_cpuclock_noploop_12_100(); dprintf("loop cycle 12\n"); break;
        case 18: break;
        case 19: break;
        case 20: break;
        case 21: break;
        case 22: wait_loop_overhead_test_330_1(); dprintf("over head 1\n"); break;
        case 23: wait_loop_overhead_test_30_11(); dprintf("over head 11\n"); break;
        case 24: break;
        case 25: break;
        case 26: break;

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
#elif defined(ALLNOP_TEST)
        case 0: wait_test_0_all(); break;
        case 1: wait_test_1_all(); break;
        case 2: wait_test_2_all(); break;
        case 3: wait_test_3_all(); break;
        case 4: wait_test_4_all(); break;
        case 5: wait_test_5_all(); break;
        case 6: wait_test_6_all(); break;
        case 7: wait_test_7_all(); break;
        case 8: wait_test_8_all(); break;
        case 9: wait_test_9_all();   break;
        case 10: wait_test_10_all(); break;
        case 11: wait_test_11_all(); break;
        case 12: wait_test_12_all(); break;
        case 13: wait_test_13_all(); break;
        case 14: wait_test_14_all(); break;
        case 15: wait_test_15_all(); break;
        case 16: wait_test_16_all(); break;
        case 17: wait_test_17_all(); break;
        case 18: wait_test_18_all(); break;
        case 19: wait_test_19_all(); break;
        case 20: wait_test_20_all(); break;
        case 21: wait_test_21_all(); break;
        case 22: wait_test_22_all(); break;
        case 23: wait_test_23_all(); break;
        case 24: wait_test_24_all(); break;
        case 25: wait_test_25_all(); break;
        case 26: wait_test_26_all(); break;
        case 27: wait_test_27_all(); break;
        case 28: wait_test_28_all(); break;
        case 29: wait_test_29_all(); break;
        case 30: wait_test_30_all(); break;
        case 31: wait_test_31_all(); break;
        case 32: wait_test_32_all(); break;
        case 33: wait_test_33_all(); break;
        case 34: wait_test_34_all(); break;
        case 35: wait_test_35_all(); break;
        case 36: wait_test_36_all(); break;
        case 37: wait_test_37_all(); break;
        case 38: wait_test_38_all(); break;
        case 39: wait_test_39_all(); break;
        case 40: wait_test_40_all(); break;
        case 41: wait_test_41_all(); break;
        case 42: wait_test_42_all(); break;
        case 43: wait_test_43_all(); break;
        case 44: wait_test_44_all(); break;
        case 45: wait_test_45_all(); break;
        case 46: wait_test_46_all(); break;
        case 47: wait_test_47_all(); break;
        case 48: wait_test_48_all(); break;
        case 49: wait_test_49_all(); break;
        case 50: wait_test_50_all(); break;
        case 51: wait_test_51_all(); break;
        case 52: wait_test_52_all(); break;
        case 53: wait_test_53_all(); break;
        case 54: wait_test_54_all(); break;
        case 55: wait_test_55_all(); break;
        case 56: wait_test_56_all(); break;
        case 57: wait_test_57_all(); break;
        case 58: wait_test_58_all(); break;
        case 59: wait_test_59_all(); break;
        case 60: wait_test_60_all(); break;
        case 61: wait_test_61_all(); break;
        case 62: wait_test_62_all(); break;
        case 63: wait_test_63_all(); break;
        case 64: wait_test_64_all(); break;
        case 65: wait_test_65_all(); break;
        case 66: wait_test_66_all(); break;
        case 67: wait_test_67_all(); break;
        case 68: wait_test_68_all(); break;
        case 69: wait_test_69_all(); break;
        case 70: wait_test_70_all(); break;
        case 71: wait_test_71_all(); break;
        case 72: wait_test_72_all(); break;
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
        case 33: wait_test_33(); break;
        case 34: wait_test_34(); break;
        case 35: wait_test_35(); break;
        case 36: wait_test_36(); break;
        case 37: wait_test_37(); break;
        case 38: wait_test_38(); break;
        case 39: wait_test_39(); break;
        case 40: wait_test_40(); break;
        case 41: wait_test_41(); break;
        case 42: wait_test_42(); break;
        case 43: wait_test_43(); break;
        case 44: wait_test_44(); break;
        case 45: wait_test_45(); break;
        case 46: wait_test_46(); break;
        case 47: wait_test_47(); break;
        case 48: wait_test_48(); break;
        case 49: wait_test_49(); break;
        case 50: wait_test_50(); break;
        case 51: wait_test_51(); break;
        case 52: wait_test_52(); break;
        case 53: wait_test_53(); break;
        case 54: wait_test_54(); break;
        case 55: wait_test_55(); break;
        case 56: wait_test_56(); break;
        case 57: wait_test_57(); break;
        case 58: wait_test_58(); break;
        case 59: wait_test_59(); break;
        case 60: wait_test_60(); break;
        case 61: wait_test_61(); break;
        case 62: wait_test_62(); break;
        case 63: wait_test_63(); break;
        case 64: wait_test_64(); break;
        case 65: wait_test_65(); break;
        case 66: wait_test_66(); break;
        case 67: wait_test_67(); break;
        case 68: wait_test_68(); break;
        case 69: wait_test_69(); break;
        case 70: wait_test_70(); break;
        case 71: wait_test_71(); break;
        case 72: wait_test_72(); break;
#endif
        }
    }
    testnum = (testnum + 1) % WAIT_NUM_LOOP;
}

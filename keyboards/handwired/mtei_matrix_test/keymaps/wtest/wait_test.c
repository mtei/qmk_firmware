#include QMK_KEYBOARD_H
#include "wait.h"

#define TEST_INTERVAL 1000

void wait_test_0(void)  { writePinHigh(WAIT_TSET_PIN); wait_cpuclock(0); writePinLow(WAIT_TSET_PIN); }
void wait_test_1(void)  { writePinHigh(WAIT_TSET_PIN); wait_cpuclock(1); writePinLow(WAIT_TSET_PIN); }
void wait_test_2(void)  { writePinHigh(WAIT_TSET_PIN); wait_cpuclock(2); writePinLow(WAIT_TSET_PIN); }
void wait_test_3(void)  { writePinHigh(WAIT_TSET_PIN); wait_cpuclock(3); writePinLow(WAIT_TSET_PIN); }
void wait_test_4(void)  { writePinHigh(WAIT_TSET_PIN); wait_cpuclock(4); writePinLow(WAIT_TSET_PIN); }
void wait_test_5(void)  { writePinHigh(WAIT_TSET_PIN); wait_cpuclock(5); writePinLow(WAIT_TSET_PIN); }
void wait_test_6(void)  { writePinHigh(WAIT_TSET_PIN); wait_cpuclock(6); writePinLow(WAIT_TSET_PIN); }
void wait_test_7(void)  { writePinHigh(WAIT_TSET_PIN); wait_cpuclock(7); writePinLow(WAIT_TSET_PIN); }
void wait_test_8(void)  { writePinHigh(WAIT_TSET_PIN); wait_cpuclock(8); writePinLow(WAIT_TSET_PIN); }
void wait_test_9(void)  { writePinHigh(WAIT_TSET_PIN); wait_cpuclock(9); writePinLow(WAIT_TSET_PIN); }
void wait_test_10(void) { writePinHigh(WAIT_TSET_PIN); wait_cpuclock(10); writePinLow(WAIT_TSET_PIN); }
void wait_test_11(void) { writePinHigh(WAIT_TSET_PIN); wait_cpuclock(11); writePinLow(WAIT_TSET_PIN); }
void wait_test_12(void) { writePinHigh(WAIT_TSET_PIN); wait_cpuclock(12); writePinLow(WAIT_TSET_PIN); }
void wait_test_13(void) { writePinHigh(WAIT_TSET_PIN); wait_cpuclock(13); writePinLow(WAIT_TSET_PIN); }
void wait_test_14(void) { writePinHigh(WAIT_TSET_PIN); wait_cpuclock(14); writePinLow(WAIT_TSET_PIN); }
void wait_test_15(void) { writePinHigh(WAIT_TSET_PIN); wait_cpuclock(15); writePinLow(WAIT_TSET_PIN); }
void wait_test_16(void) { writePinHigh(WAIT_TSET_PIN); wait_cpuclock(16); writePinLow(WAIT_TSET_PIN); }
void wait_test_17(void) { writePinHigh(WAIT_TSET_PIN); wait_cpuclock(17); writePinLow(WAIT_TSET_PIN); }
void wait_test_18(void) { writePinHigh(WAIT_TSET_PIN); wait_cpuclock(18); writePinLow(WAIT_TSET_PIN); }
void wait_test_19(void) { writePinHigh(WAIT_TSET_PIN); wait_cpuclock(19); writePinLow(WAIT_TSET_PIN); }

void matrix_scan_post_user(void) {
    static int testnum = 0;
    static uint16_t test_timeout = 0;
    if (timer_elapsed(test_timeout) < TEST_INTERVAL) {
        return;
    }
    test_timeout = timer_read();
    switch(testnum) {
    case 0: wait_test_0(); break;
    case 1: wait_test_1(); break;
    case 2: wait_test_2(); break;
    case 3: wait_test_3(); break;
    case 4: wait_test_4(); break;
    case 5: wait_test_5(); break;
    case 6: wait_test_6(); break;
    case 7: wait_test_7(); break;
    case 8: wait_test_8(); break;
    case 9: wait_test_9(); break;
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
    }
    testnum = testnum % 20;
}

void keyboard_post_init_user() {
    setPinOutput(WAIT_TSET_PIN);
    writePinLow(WAIT_TSET_PIN);
}

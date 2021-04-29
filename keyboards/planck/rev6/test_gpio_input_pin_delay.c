#include <quantum.h>

/* planck/rev6: Proton C pin assign
                 ====
         +-------====------+
     R1  | A9/TX/SCL2   5V | (VUSB)
     R0  | A10/RX/SDA2 GND |
         | GND       FLASH |
         | GND        3.3V | (VCC)
         | B7/SDA1      A2 | R7
         | B6/SCL1      A1 | RGB LED
test_in  | B5           A0 | DIP2
test_out | B4      SCL1/B8 |
         | B3     SCLK/B13 | PAD_B
     C2  | B2     MISO/B14 | DIP0
     C3  | B1     MOSI/B15 | R4
     C5  | B0      SDA1/B9 | DIP3
         +---+         +---+
         +---+         +---+
AUDIO_alt| A4          B10 | C1
   AUDIO | A5          B11 | C0
         | A6          B12 | PAD_A
      C4 | A7          A14 |
      R2 | A8          A13 |
    DIP1 | A15         RST |
         +-----------------+
***************************************/

#define TEST_INTERVAL 2000
#define TEST_NUM_MAX  19

#define WAIT_TEST_PIN  B4
#define INPUT_TEST_PIN B5

#define Pin_H() writePinHigh(WAIT_TEST_PIN)
#define Pin_L() writePinLow(WAIT_TEST_PIN)
#define Pin_in() readPin(INPUT_TEST_PIN)

#define attr_aligned16 __attribute__ ((aligned(16),noinline))

#define WAIT_EXPANDING_NOP_24(n) do { switch (n) { \
    case 24: asm volatile ("nop"::: "memory"); \
    case 23: asm volatile ("nop"::: "memory"); \
    case 22: asm volatile ("nop"::: "memory"); \
    case 21: asm volatile ("nop"::: "memory"); \
    case 20: asm volatile ("nop"::: "memory"); \
    case 19: asm volatile ("nop"::: "memory"); \
    case 18: asm volatile ("nop"::: "memory"); \
    case 17: asm volatile ("nop"::: "memory"); \
    case 16: asm volatile ("nop"::: "memory"); \
    case 15: asm volatile ("nop"::: "memory"); \
    case 14: asm volatile ("nop"::: "memory"); \
    case 13: asm volatile ("nop"::: "memory"); \
    case 12: asm volatile ("nop"::: "memory"); \
    case 11: asm volatile ("nop"::: "memory"); \
    case 10: asm volatile ("nop"::: "memory"); \
    case  9: asm volatile ("nop"::: "memory"); \
    case  8: asm volatile ("nop"::: "memory"); \
    case  7: asm volatile ("nop"::: "memory"); \
    case  6: asm volatile ("nop"::: "memory"); \
    case  5: asm volatile ("nop"::: "memory"); \
    case  4: asm volatile ("nop"::: "memory"); \
    case  3: asm volatile ("nop"::: "memory"); \
    case  2: asm volatile ("nop"::: "memory"); \
    case  1: asm volatile ("nop"::: "memory"); \
    case  0: break; \
    } } while(0)


attr_aligned16 void out_in_0(void);
attr_aligned16 void out_in_1(void);
attr_aligned16 void out_in_2(void);
attr_aligned16 void out_in_3(void);
attr_aligned16 void out_in_4(void);
attr_aligned16 void out_in_5(void);
attr_aligned16 void out_in_6(void);
attr_aligned16 void out_in_7(void);
attr_aligned16 void out_in_8(void);

attr_aligned16 void out_in_2_a1(void);
attr_aligned16 void out_in_2_a2(void);
attr_aligned16 void out_in_2_a3(void);
attr_aligned16 void out_in_2_a4(void);

void matrix_scan_post_user(void) {
    static int testnum = 0;
    static uint16_t test_timeout = 0;
    if (timer_elapsed(test_timeout) < TEST_INTERVAL) {
        return;
    }
    test_timeout = timer_read();

    // init test pins
    debug_enable = true;
    setPinOutput(WAIT_TEST_PIN);
    writePinLow(WAIT_TEST_PIN);
    setPinInput(INPUT_TEST_PIN);
    WAIT_EXPANDING_NOP_24(16);
    
    // test out & in
    ATOMIC_BLOCK_FORCEON {
        switch(testnum) {
        case 0: out_in_0();    break;
        case 1: out_in_1();    break;
        case 2: out_in_2();    break;
        case 3: out_in_3();    break;
        case 4: out_in_4();    break;
        case 5: out_in_5();    break;
        case 6: out_in_6();    break;
        case 7: out_in_7();    break;
        case 8: out_in_8();    break;
        case 9: break;
        case 10: break;
        case 11: break;
        case 12: out_in_2_a1(); break;
        case 13: out_in_2_a2(); break;
        case 14: out_in_2_a3(); break;
        case 15: out_in_2_a4(); break;
        case 16: break;
        case 17: break;
        case 18: break;
        }
    }
    testnum = (testnum + 1) % TEST_NUM_MAX;
}

#define DEF_OUT_IN_x(NUM_NOPS) \
    attr_aligned16 void out_in_ ## NUM_NOPS(void) { \
    uint8_t idata; \
    WAIT_EXPANDING_NOP_24(1); \
    Pin_H(); WAIT_EXPANDING_NOP_24(NUM_NOPS); \
    idata = Pin_in(); WAIT_EXPANDING_NOP_24(4); Pin_L(); WAIT_EXPANDING_NOP_24(20); \
    writePin(WAIT_TEST_PIN, (idata != 0)); WAIT_EXPANDING_NOP_24(5); Pin_L(); \
}

DEF_OUT_IN_x(0)
DEF_OUT_IN_x(1)
DEF_OUT_IN_x(2)
DEF_OUT_IN_x(3)
DEF_OUT_IN_x(4)
DEF_OUT_IN_x(5)
DEF_OUT_IN_x(6)
DEF_OUT_IN_x(7)
DEF_OUT_IN_x(8)

#define DEF_OUT_IN_2_ax(NUM_OFF) \
    attr_aligned16 void out_in_2_a ## NUM_OFF(void) { \
    uint8_t idata; \
    WAIT_EXPANDING_NOP_24(1+NUM_OFF); \
    Pin_H(); WAIT_EXPANDING_NOP_24(2); \
    idata = Pin_in(); WAIT_EXPANDING_NOP_24(4); Pin_L(); WAIT_EXPANDING_NOP_24(20); \
    writePin(WAIT_TEST_PIN, (idata != 0)); WAIT_EXPANDING_NOP_24(5); Pin_L(); \
}

DEF_OUT_IN_2_ax(1)
DEF_OUT_IN_2_ax(2)
DEF_OUT_IN_2_ax(3)
DEF_OUT_IN_2_ax(4)

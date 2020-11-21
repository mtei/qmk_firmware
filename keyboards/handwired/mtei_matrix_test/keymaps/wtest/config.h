#if defined(__AVR__)
#define WAIT_TEST_PIN D3  // TXO
#define INPUT_TEST_PIN D2  // RX1
#endif

#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
#define WAIT_TEST_PIN  A9
#define INPUT_TEST_PIN A10

#ifndef SLOW_CLOCK
// Proton-C 72MHz
#    define ALIGNED_NOP_LOOP_CLOCKS 9
#    define ALIGNED_NOP_LOOP_CALL_OVER_HEAD 8
#else
// Proton-C 8MHz (mcuconf.h #define STM32_SW STM32_SW_HSI)
#    define ALIGNED_NOP_LOOP_CLOCKS 6
#    define ALIGNED_NOP_LOOP_CALL_OVER_HEAD 4
#endif

#endif

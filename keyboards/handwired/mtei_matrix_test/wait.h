#pragma once
/* clang-format off */

#include_next "wait.h"

#ifdef __cplusplus
extern "C" {
#endif


// AVR
#if defined(__AVR__)
#    define wait_cpuclock(x) __builtin_avr_delay_cycles(x)
#endif

// Cortex-M3 or Cortex-M4
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
  #ifndef __OPTIMIZE__
    #error "Compiler optimizations disabled; wait_cpuclock() won't work as designed"
  #endif

extern void aligned_4clock_delay(unsigned int n);
extern void aligned_16clock_delay(unsigned int n);
#define OVER_HEAD_CALL_4CLOCK_DELAY 4

__attribute__((always_inline))
static inline void wait_cpuclock_4noploop(unsigned int n) {
    /* The argument n must be a constant expression.
     * That way, compiler optimization will remove unnecessary code. */
    if (n < 1) { return; }
    if (n > 8) {
        unsigned int n4 = (n - OVER_HEAD_CALL_4CLOCK_DELAY)/4;
        n = n - n4*4 - OVER_HEAD_CALL_4CLOCK_DELAY;
        aligned_4clock_delay(n4);
    }
    switch (n) {
    case 8: asm volatile ("nop"::: "memory");
    case 7: asm volatile ("nop"::: "memory");
    case 6: asm volatile ("nop"::: "memory");
    case 5: asm volatile ("nop"::: "memory");
    case 4: asm volatile ("nop"::: "memory");
    case 3: asm volatile ("nop"::: "memory");
    case 2: asm volatile ("nop"::: "memory");
    case 1: asm volatile ("nop"::: "memory");
    case 0: break;
    }
}


#define NOP8 "nop\n\t nop\n\t nop\n\t nop\n\t   nop\n\t nop\n\t nop\n\t nop\n\t"

__attribute__((always_inline))
static inline void wait_cpuclock_allnop(unsigned int n) { /* n: 1..135 */
    /* The argument n must be a constant expression.
     * That way, compiler optimization will remove unnecessary code. */
    if (n < 1) { return; }
    if (n > 8) {
        unsigned int n8 = n/8;
        n = n - n8*8;
        switch (n8) {
        case 16: asm volatile (NOP8::: "memory");
        case 15: asm volatile (NOP8::: "memory");
        case 14: asm volatile (NOP8::: "memory");
        case 13: asm volatile (NOP8::: "memory");
        case 12: asm volatile (NOP8::: "memory");
        case 11: asm volatile (NOP8::: "memory");
        case 10: asm volatile (NOP8::: "memory");
        case  9: asm volatile (NOP8::: "memory");
        case  8: asm volatile (NOP8::: "memory");
        case  7: asm volatile (NOP8::: "memory");
        case  6: asm volatile (NOP8::: "memory");
        case  5: asm volatile (NOP8::: "memory");
        case  4: asm volatile (NOP8::: "memory");
        case  3: asm volatile (NOP8::: "memory");
        case  2: asm volatile (NOP8::: "memory");
        case  1: asm volatile (NOP8::: "memory");
        case  0: break;
        }
    }
    switch (n) {
    case 8: asm volatile ("nop"::: "memory");
    case 7: asm volatile ("nop"::: "memory");
    case 6: asm volatile ("nop"::: "memory");
    case 5: asm volatile ("nop"::: "memory");
    case 4: asm volatile ("nop"::: "memory");
    case 3: asm volatile ("nop"::: "memory");
    case 2: asm volatile ("nop"::: "memory");
    case 1: asm volatile ("nop"::: "memory");
    case 0: break;
    }
}

    // Table 3.1. Cortex-M3 instruction set summary
    // https://developer.arm.com/documentation/ddi0337/h/programmers-model/instruction-set-summary/cortex-m3-instructions/
#endif

#ifdef __cplusplus
}
#endif

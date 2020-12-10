#pragma once
/* clang-format off */

#include_next "wait.h"

#ifdef __cplusplus
extern "C" {
#endif

// copy from #9603
#if defined(__AVR__)
#  ifndef wait_cpuclock
#    define wait_cpuclock(x) __builtin_avr_delay_cycles(x)
#  endif /* ifndef wait_cpuclock*/
#endif

#if defined(__ARMEL__) || defined(__ARMEB__)
#    ifndef __OPTIMIZE__
#        pragma message "Compiler optimizations disabled; wait_cpuclock() won't work as designed"
#    endif

#  ifndef wait_cpuclock
#    define wait_cpuclock(x) wait_cpuclock_allnop(x)

#    define CLOCK_DELAY_NOP8 "nop\n\t nop\n\t nop\n\t nop\n\t   nop\n\t nop\n\t nop\n\t nop\n\t"

__attribute__((always_inline))
static inline void wait_cpuclock_allnop(unsigned int n) { /* n: 1..135 */
    /* The argument n must be a constant expression.
     * That way, compiler optimization will remove unnecessary code. */
    if (n < 1) { return; }
    if (n > 8) {
        unsigned int n8 = n/8;
        n = n - n8*8;
        switch (n8) {
        case 16: asm volatile (CLOCK_DELAY_NOP8::: "memory");
        case 15: asm volatile (CLOCK_DELAY_NOP8::: "memory");
        case 14: asm volatile (CLOCK_DELAY_NOP8::: "memory");
        case 13: asm volatile (CLOCK_DELAY_NOP8::: "memory");
        case 12: asm volatile (CLOCK_DELAY_NOP8::: "memory");
        case 11: asm volatile (CLOCK_DELAY_NOP8::: "memory");
        case 10: asm volatile (CLOCK_DELAY_NOP8::: "memory");
        case  9: asm volatile (CLOCK_DELAY_NOP8::: "memory");
        case  8: asm volatile (CLOCK_DELAY_NOP8::: "memory");
        case  7: asm volatile (CLOCK_DELAY_NOP8::: "memory");
        case  6: asm volatile (CLOCK_DELAY_NOP8::: "memory");
        case  5: asm volatile (CLOCK_DELAY_NOP8::: "memory");
        case  4: asm volatile (CLOCK_DELAY_NOP8::: "memory");
        case  3: asm volatile (CLOCK_DELAY_NOP8::: "memory");
        case  2: asm volatile (CLOCK_DELAY_NOP8::: "memory");
        case  1: asm volatile (CLOCK_DELAY_NOP8::: "memory");
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
#  endif /* ifndef wait_cpuclock*/
#endif
// end of copy from #9603

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

// AVR
#if defined(__AVR__)
#    define wait_cpuclock(x)         __builtin_avr_delay_cycles(x)
#    define wait_cpuclock_noploop(x) __builtin_avr_delay_cycles(x)
#    define wait_cpuclock_allnop(x)  __builtin_avr_delay_cycles(x)
#endif

// Cortex-M3 or Cortex-M4
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
#    ifndef __OPTIMIZE__
#        error "Compiler optimizations disabled; wait_cpuclock() won't work as designed"
#    endif

extern void aligned_nop_loop(unsigned int n);

#    ifndef ALIGNED_NOP_LOOP_CLOCKS
#        define ALIGNED_NOP_LOOP_CLOCKS 6
#    endif
#    ifndef ALIGNED_NOP_LOOP_CALL_OVER_HEAD
#        define ALIGNED_NOP_LOOP_CALL_OVER_HEAD 4
#    endif

#    if ALIGNED_NOP_LOOP_CLOCKS < 1 || ALIGNED_NOP_LOOP_CALL_OVER_HEAD < 1 || (ALIGNED_NOP_LOOP_CALL_OVER_HEAD + ALIGNED_NOP_LOOP_CLOCKS) > 24
#        error Invalid ALIGNED_NOP_LOOP_CLOCKS, ALIGNED_NOP_LOOP_CALL_OVER_HEAD value
#    endif

__attribute__((always_inline))
static inline void wait_cpuclock_noploop(unsigned int n) {
    /* The argument n must be a constant expression.
     * That way, compiler optimization will remove unnecessary code. */
    if (n < 1) { return; }
    if (n > 8 &&
        n > ((ALIGNED_NOP_LOOP_CALL_OVER_HEAD)+(ALIGNED_NOP_LOOP_CLOCKS))) {
        unsigned int loop = (n - (ALIGNED_NOP_LOOP_CALL_OVER_HEAD))/(ALIGNED_NOP_LOOP_CLOCKS);
        n = n - loop*(ALIGNED_NOP_LOOP_CLOCKS) - (ALIGNED_NOP_LOOP_CALL_OVER_HEAD);
        aligned_nop_loop(loop);
    }
    WAIT_EXPANDING_NOP_24(n);
}

    // Table 3.1. Cortex-M3 instruction set summary
    // https://developer.arm.com/documentation/ddi0337/h/programmers-model/instruction-set-summary/cortex-m3-instructions/
#endif

#ifdef __cplusplus
}
#endif

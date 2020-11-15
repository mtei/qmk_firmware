/* clang-format off */
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
  #ifndef __OPTIMIZE__
    #error "Compiler optimizations disabled; wait_cpuclock() won't work as designed"
  #endif

#ifdef ADJUST_ALIGNED_4CLOCK_DELAY
#    if ADJUST_ALIGNED_4CLOCK_DELAY != 0 && ADJUST_ALIGNED_4CLOCK_DELAY != 1
#       error Invalid ADJUST_ALIGNED_4CLOCK_DELAY value
#    endif
#endif

__attribute__ ((aligned(16),noinline))
void aligned_4clock_delay(unsigned int n)
{
    do {
#ifndef ADJUST_ALIGNED_4CLOCK_DELAY
        asm volatile ("nop"::: "memory");
#else
        switch (ADJUST_ALIGNED_4CLOCK_DELAY) {
        case  0: asm volatile ("nop"::: "memory");
        case  1: break;
        }
#endif
    } while ( --n > 0 );
    asm volatile (""::: "memory");
}

#ifdef ADJUST_ALIGNED_8CLOCK_DELAY
#    if ADJUST_ALIGNED_8CLOCK_DELAY < 0 || ADJUST_ALIGNED_8CLOCK_DELAY > 5
#       error Invalid ADJUST_ALIGNED_8CLOCK_DELAY value
#    endif
#endif

__attribute__ ((aligned(16),noinline))
void aligned_8clock_delay(unsigned int n)
{
    do {
#ifndef ADJUST_ALIGNED_8CLOCK_DELAY
        asm volatile ("nop\n\t nop\n\t nop\n\t nop\n\t"::: "memory");
        asm volatile ("nop"::: "memory");
#else
        switch (ADJUST_ALIGNED_8CLOCK_DELAY) {
        case  0: asm volatile ("nop"::: "memory");
        case  1: asm volatile ("nop"::: "memory");
        case  2: asm volatile ("nop"::: "memory");
        case  3: asm volatile ("nop"::: "memory");
        case  4: asm volatile ("nop"::: "memory");
        case  5: break;
        }
#endif
    } while ( --n > 0 );
    asm volatile (""::: "memory");
}

#ifdef ADJUST_ALIGNED_16CLOCK_DELAY
#    if ADJUST_ALIGNED_16CLOCK_DELAY < 0 || ADJUST_ALIGNED_16CLOCK_DELAY > 13
#       error Invalid ADJUST_ALIGNED_16CLOCK_DELAY value
#    endif
#endif

__attribute__ ((aligned(16),noinline))
void aligned_16clock_delay(unsigned int n)
{
    do {
#ifndef ADJUST_ALIGNED_16CLOCK_DELAY
        asm volatile ("nop\n\t nop\n\t nop\n\t nop\n\t"::: "memory");
        asm volatile ("nop\n\t nop\n\t nop\n\t nop\n\t"::: "memory");
        asm volatile ("nop\n\t nop\n\t nop\n\t nop\n\t"::: "memory");
        asm volatile ("nop"::: "memory");
#else
        switch (ADJUST_ALIGNED_16CLOCK_DELAY) {
        case  0: asm volatile ("nop"::: "memory");
        case  1: asm volatile ("nop"::: "memory");
        case  2: asm volatile ("nop"::: "memory");
        case  3: asm volatile ("nop"::: "memory");
        case  4: asm volatile ("nop"::: "memory");
        case  5: asm volatile ("nop"::: "memory");
        case  6: asm volatile ("nop"::: "memory");
        case  7: asm volatile ("nop"::: "memory");
        case  8: asm volatile ("nop"::: "memory");
        case  9: asm volatile ("nop"::: "memory");
        case 10: asm volatile ("nop"::: "memory");
        case 11: asm volatile ("nop"::: "memory");
        case 12: asm volatile ("nop"::: "memory");
        case 13: break;
        }
#endif
    } while ( --n > 0 );
    asm volatile (""::: "memory");
}

#endif

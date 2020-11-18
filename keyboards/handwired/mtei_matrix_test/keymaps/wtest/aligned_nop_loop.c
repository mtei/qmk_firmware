/* clang-format off */

#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
  #ifndef __OPTIMIZE__
    #error "Compiler optimizations disabled; wait_cpuclock() won't work as designed"
  #endif

__attribute__ ((aligned(16),noinline))
void aligned_nop_loop(unsigned int n)
{
    do {
        asm volatile ("nop"::: "memory");
        asm volatile ("nop"::: "memory");
        asm volatile ("nop"::: "memory");
    } while ( --n > 0 );
    asm volatile (""::: "memory");
}

#endif

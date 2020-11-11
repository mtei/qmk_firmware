#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
  #ifndef __OPTIMIZE__
    #error "Compiler optimizations disabled; wait_cpuclock() won't work as designed"
  #endif

__attribute__ ((aligned(4),noinline))
void aligned_4clock_delay(unsigned int n)
{
    do {
        asm volatile ("nop"::: "memory");
    } while ( --n > 0 );
    asm volatile (""::: "memory");
}
#endif

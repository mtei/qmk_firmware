/* clang-format off */

#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
#    if 0 /* C or ASM switch */
#        ifndef __OPTIMIZE__
#            error "Compiler optimizations disabled; wait_cpuclock() won't work as designed"
#        endif

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

#    else  /* ASM */
__attribute__ ((aligned(16),noinline))
void aligned_nop_loop(unsigned int n)
{
    asm volatile (
                  "0:                          \n\t"
                  "      nop                   \n\t"
                  "      nop                   \n\t"
                  "      nop                   \n\t"
                  "      subs  %[n], %[n], #1  \n\t"
                  "      bne   0b              \n\t"
                  :
                  : [n] "r"(n)
                  : "memory");
    asm volatile (""::: "memory");
}
#    endif
#endif /* defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__) */

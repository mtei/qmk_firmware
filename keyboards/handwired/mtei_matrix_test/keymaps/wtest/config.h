#if defined(__AVR__)
#define WAIT_TSET_PIN D3  // TXO
#endif

#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
#define WAIT_TSET_PIN A9
#endif

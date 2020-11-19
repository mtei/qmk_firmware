#if defined(__AVR__)
#define WAIT_TEST_PIN D3  // TXO
#define INPUT_TSET_PIN D2  // RX1
#endif

#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
#define WAIT_TEST_PIN  A9
#define INPUT_TEST_PIN A10
#endif

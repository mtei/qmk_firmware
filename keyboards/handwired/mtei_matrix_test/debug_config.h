#pragma once
#ifndef __ASSEMBLER__
#include <gpio.h>
  // Pro Micro
  //     +-------====------+
  //     | D3/TXO      RAW |
  //     | D2/RXI      GND |
  //     | GND         RST |
  //     | GND         Vcc |
  //     | D1/SDA       F4 | C0
  //     | D0/SCL       F5 | C1
  //  R0 | D4           F6 | C2
  //  R1 | C6           F7 | C3
  //  R2 | D7       SCK/B1 | C4
  //  R3 | E6      MISO/B3 | C5
  //  R4 | B4      MOSI/B2 |
  //  R5 | B5           B6 |
  //     +-----------------+
  // Proton-C
  //     +-------====------+
  //     | A9           5V |
  //     | A10         GND |
  //     | GND       FLASH |
  //     | GND        3.3V |
  //     | B7           A2 | C0
  //     | B6           A1 | C1
  //  R0 | B5           A0 | C2
  //  R1 | B4           B8 | C3
  //  R2 | B3          B13 | C4
  //  R3 | B2          B14 | C5
  //  R4 | B1          B15 |
  //  R5 | B0           B9 |
  //     +-----------------+

#if defined(__AVR__)
#    define MATRIX_DEBUG_PIN D3
#else
#    define MATRIX_DEBUG_PIN A9
#endif

static inline void setPinOutput_Low(void) {
    setPinOutput(MATRIX_DEBUG_PIN);
    writePinLow(MATRIX_DEBUG_PIN);
}

#define MATRIX_DEBUG_PIN_INIT()   setPinOutput_Low()

#ifdef MATRIX_DEBUG_SCAN
#  define MATRIX_DEBUG_SCAN_START() writePinHigh(MATRIX_DEBUG_PIN)
#  define MATRIX_DEBUG_SCAN_END()   writePinLow(MATRIX_DEBUG_PIN)
#else
#  define MATRIX_DEBUG_SCAN_START()
#  define MATRIX_DEBUG_SCAN_END()
#endif

#ifdef MATRIX_DEBUG_DELAY
#  define MATRIX_DEBUG_DELAY_START() writePinHigh(MATRIX_DEBUG_PIN)
#  define MATRIX_DEBUG_DELAY_END()   writePinLow(MATRIX_DEBUG_PIN)
#else
#  define MATRIX_DEBUG_DELAY_START()
#  define MATRIX_DEBUG_DELAY_END()
#endif

#endif // __ASSEMBLER__
// #ifdef DEBUG_MATRIX_SCAN_RATE
//   #pragma message  "DEBUG_MATRIX_SCAN_RATE on"
// #endif

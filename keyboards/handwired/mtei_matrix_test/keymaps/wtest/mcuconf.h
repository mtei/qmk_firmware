#pragma once

#include_next "mcuconf.h"

// change cpu clock 8MHz
#ifdef SLOW_CLOCK
  #undef STM32_SW
  #define STM32_SW STM32_SW_HSI
#endif

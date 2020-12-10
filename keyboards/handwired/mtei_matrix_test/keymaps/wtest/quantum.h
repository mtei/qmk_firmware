#pragma once
/* clang-format off */

#include_next "quantum.h"

// copy from #9603
#if defined(__AVR__)
#  ifndef waitInputPinDelay
/*   The AVR series GPIOs have a one clock read delay for changes in the digital input signal. */
#    if !defined(GPIO_INPUT_PIN_DELAY)
#        define GPIO_INPUT_PIN_DELAY 1
#    endif
#    define waitInputPinDelay() wait_cpuclock(GPIO_INPUT_PIN_DELAY)
#  endif
#endif

#if defined(__ARMEL__) || defined(__ARMEB__)
#  ifnef waitInputPinDelay
/* For GPIOs on ARM-based MCUs, the input pins are sampled by the clock of the bus
 * to which the GPIO is connected.
 * The connected buses differ depending on the various series of MCUs.
 * And since the instruction execution clock of the CPU and the bus clock of GPIO are different,
 * there is a delay of several clocks to read the change of the input signal.
 *
 * Define this delay with the GPIO_INPUT_PIN_DELAY macro.
 * If the GPIO_INPUT_PIN_DELAY macro is not defined, the following default values will be used.
 * (A fairly large value of 0.25 microseconds is set.)
 */
#    if !defined(GPIO_INPUT_PIN_DELAY)
#        if defined(STM32_SYSCLK)
#            define GPIO_INPUT_PIN_DELAY (STM32_SYSCLK/1000000L / 4)
#        elif defined(KINETIS_SYSCLK_FREQUENCY)
#            define GPIO_INPUT_PIN_DELAY (KINETIS_SYSCLK_FREQUENCY/1000000L / 4)
#        endif
#    endif
#    define waitInputPinDelay() wait_cpuclock(GPIO_INPUT_PIN_DELAY)
#  endif /* ifnef waitInputPinDelay */
#endif
// end of copy from #9603

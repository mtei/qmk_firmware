#pragma once
// clang-format off

#include <gpio.h>

#if defined(__AVR__)
#define readPort(port)                 PINx_ADDRESS(port)
#define setPortBitInput(port, bit)     (DDRx_ADDRESS(port) &= ~_BV((bit)&0xF), PORTx_ADDRESS(port) &= ~_BV((bit)&0xF))
#define setPortBitInputHigh(port, bit) (DDRx_ADDRESS(port) &= ~_BV((bit)&0xF), PORTx_ADDRESS(port) |= _BV((bit)&0xF))
#define setPortBitOutput(port, bit)    (DDRx_ADDRESS(port) |= _BV((bit)&0xF))

#define writePortBitLow(port, bit)     (PORTx_ADDRESS(port) &= ~_BV((bit)&0xF))
#define writePortBitHigh(port, bit)    (PORTx_ADDRESS(port) |= _BV((bit)&0xF))

#else
#error "not yet support ARM"
#endif

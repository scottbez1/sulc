#ifndef _UTIL_H_
#define _UTIL_H_

#include "dbg.h"
#include "tlc5940/Tlc5940.h"

void panic(uint8_t value) {
    setDbg(15);
    Tlc5940_clear();
    for (int i = 0; i < 500; i++) {
        Tlc5940_update();
        _delay_ms(1);
    }
    cli();

    // only care about lower 3 bits
    value = value & 7;
    while (1) {
        setDbg(value);
        _delay_ms(100);
        setDbg(value | 8);
        _delay_ms(100);
    }
}

#endif

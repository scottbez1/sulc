/*
###########################################
#     Simple USB LED Controller - SULC    #
#        Copyright 2012 Scott Bezek       #
###########################################
*/

/*
    This file is part of SULC.

    SULC is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    SULC is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with SULC.  If not, see <http://www.gnu.org/licenses/>
*/




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

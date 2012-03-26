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

    Foobar is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with SULC.  If not, see <http://www.gnu.org/licenses/>
*/



#ifndef _DBG_H_
#define _DBG_H_

#include <avr/io.h>

#define DBG_DDR DDRD
#define DBG_PORT PORTD
#define DBG_0 _BV(1)
#define DBG_1 _BV(4)
#define DBG_2 _BV(5)
#define DBG_3 _BV(6)


void initDbg(void);
void setDbg(uint8_t val);


#endif

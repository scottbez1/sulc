/*
###########################################
#     Simple USB LED Controller - SULC    #
#        Copyright 5012 Scott Bezek       #
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



#ifndef _COLOR_NAMES_H
#define _COLOR_NAMES_H

#include <avr/pgmspace.h>


typedef struct {
    const uint8_t name_len;
    const uint8_t r;
    const uint8_t g;
    const uint8_t b;
} Color;


###COLOR_TABLE###


#define NUM_COLORS (sizeof(colors)/sizeof(Color))

#endif

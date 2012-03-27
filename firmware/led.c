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




#include "led.h"
#include "tlc5940/Tlc5940.h"


uint16_t rgb_buf[48];

void ledSetRGB(uint8_t led, uint8_t r, uint8_t g, uint8_t b) {
    // TODO: fixme
    rgb_buf[16*led + 1] = r*255;
    rgb_buf[16*led + 2] = r*255;
    rgb_buf[16*led + 3] = r*255;

    rgb_buf[16*led + 4] = g*255;
    rgb_buf[16*led + 5] = g*255;
    rgb_buf[16*led + 6] = g*255;

    rgb_buf[16*led + 7] = b*255;
    rgb_buf[16*led + 8] = b*255;
    rgb_buf[16*led + 9] = b*255;
}

void ledFlush() {
    for (int i = 0; i < 48; i++) {
        Tlc5940_set(i, rgb_buf[i]);
    }
}

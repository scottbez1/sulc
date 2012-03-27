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



#ifndef _COLOR_NAMES_H
#define _COLOR_NAMES_H


typedef struct {
    char name[10];
    uint8_t name_len;
    uint8_t r;
    uint8_t g;
    uint8_t b;
} ColorName;

ColorName colors[] = {
    {"red",3,255,0,0},
    {"blue",4,0,0,255},
    {"green",5,0,255,0},
    {"yellow",6,255,255,0},
    {"magenta",7,255,0,255},
    {"black",5,0,0,0},
    {"off",3,0,0,0},
};

#define NUM_COLORS (sizeof(colors)/sizeof(ColorName))


#endif

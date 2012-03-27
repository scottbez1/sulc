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


#ifndef _PARSE_H_
#define _PARSE_H_

#include <inttypes.h>

#define R_OK 0
#define R_UPDATE_LEDS 1

#define E_UNKNOWN_STATE -1
#define E_BAD_CHAR -2
#define E_UNKNOWN_COLOR_NAME -3

int8_t parseChar(char c);

#endif

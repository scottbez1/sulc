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




#include "parse.h"
#include "led.h"
#include "colorNames.h"


#define BUF_SIZE 200

#define S_IDLE 0
#define S_NAME 1


uint8_t state = S_IDLE;

// character buffer for serial input
char buf[BUF_SIZE];

// location of next open buffer slot
uint16_t buf_idx = 0;

uint8_t cur_led = 0;


static inline void setState(uint8_t new_state) {
    state = new_state;
    if (new_state == S_IDLE) {
        buf_idx = 0;
        cur_led = 0;
    }
}

static int8_t idleParseChar(char c) {
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        setState(S_NAME);
        return R_OK;
    } else if (c == '\n' || c == '\r') {
        buf_idx = 0;
        return R_OK;
    } else {
        // TODO
        // freak out!
        buf_idx = 0;
        cur_led = 0;
        return E_BAD_CHAR;
    }
}


// lookup the current buffer contents in the table of color names
static int8_t nameLookup(void) {
    // TODO actually implement this
    if (buf_idx == 0) {
        return R_OK;
    }

    uint8_t found = 0;
    for (int i = 0; i < NUM_COLORS; i++) {
        if (buf_idx != colors[i].name_len) {
            continue;
        }

        uint8_t match = 1;
        for (int j = 0; j < buf_idx; j++) {
            if (buf[j] != colors[i].name[j]) {
                match = 0;
                break;
            }
        }

        if (match) {
            found = 1;
            ledSetRGB(cur_led, colors[i].r, colors[i].g, colors[i].b);
            break;
        }
    }

    if (found) {
        return R_OK;
    } else {
        return E_UNKNOWN_COLOR_NAME;
    }
}

static int8_t nameParseChar(char c) {
    if (c == '\n' || c == '\r') {
        buf_idx--;

        int8_t r = nameLookup();
        setState(S_IDLE);
        ledFlush();
        return r;
    }
    
    if (cur_led >= NUM_LEDS) {
        // entered too many colors, so just ignore this
        return R_OK;
    }
    
    if (c == ' ') {
        // ignore whitespace
        buf_idx--;

        // if there was something in the buffer, 
        if (buf_idx > 0) {
            int8_t r = nameLookup();
            buf_idx = 0;
            cur_led++;
            return r;
        }
        return R_OK;
    } else if (c == ',' || c == ';') {
        // ignore this character
        buf_idx--;

        // end of current name
        int8_t r = nameLookup();
        buf_idx = 0;
        cur_led++;
        return r;
    } else if (c >= 'A' && c <= 'Z') {
        // mess with the buffer to make it lower case
        buf[buf_idx - 1] = buf[buf_idx - 1] + ('a' - 'A');
        return R_OK;
    } else if (c >='a' && c <= 'z') {
        return R_OK;
    } else {
        return E_BAD_CHAR;
    }
}


int8_t parseChar(char c) {
    if (buf_idx < BUF_SIZE) {
        buf[buf_idx] = c;
        buf_idx++;
    } else {
        // buffer is full, wait for newline
        if (c == '\n') {
            setState(S_IDLE);
        }
        return R_OK;
    }

    switch (state) {
        case S_IDLE:
            return idleParseChar(c);
        case S_NAME:
            return nameParseChar(c);
        default:
            return E_UNKNOWN_STATE;
    }
}



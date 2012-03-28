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
#include <stdbool.h>
#include <stdlib.h>
#include "dbg.h"
#include "util.h"


#define BUF_SIZE 80

#define S_IDLE 0
#define S_NAME 1
#define S_DECIMAL_RGB 2


#include <stdio.h>
extern FILE USBSerialStream;

uint8_t state = S_IDLE;

// character buffer for serial input
char buf[BUF_SIZE];

// location of next open buffer slot
uint16_t buf_idx = 0;

// current led index (i.e. gets incremented each time after a color is specified until a newline)
uint8_t cur_led = 0;

// flag indicating user has specified ALL leds
bool fl_all = false;


// current color (r, g, or b) being specified in DECIMAL_RGB mode
uint8_t decimal_rgb_cur_color = 0;
uint8_t decimal_rgb[3] = {0,0,0};

static inline void setState(uint8_t new_state) {
    state = new_state;
}


// sets the current led (or _all_ leds if fl_all is set) to (r,g,b)
static inline void setCurLed(uint8_t r, uint8_t g, uint8_t b) {
    if (!fl_all) {
        ledSetRGB(cur_led, r, g, b);
    } else {
        for (int k = 0; k < NUM_LEDS; k++) {
            ledSetRGB(k, r, g, b);
        }
    }
}



static int8_t idleParseChar(char c) {
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        setState(S_NAME);
        return R_OK;
    } else if (c == ' ') {
        // ignore whitespace
        buf_idx--;
        return R_OK;
    } else if (c == '\n' || c == '\r') {
        buf_idx = 0;
        cur_led = 0;
        fl_all = false;
        return R_OK;
    } else if (c == ',' || c == ';') {
        // moving on to next led - clear buf and increment cur_led
        buf_idx = 0;
        cur_led++;
        return R_OK;
    } else if (c >= '0' && c <= '9') {
        setState(S_DECIMAL_RGB);
        return R_OK;
    } else {
        // TODO
        // freak out!
        buf_idx = 0;
        cur_led = 0;
        return E_BAD_CHAR;
    }
}


// lookup the current buffer contents in the table of color 
// names, and set the led(s) appropriately
static int8_t nameLookup(void) {
    if (buf_idx == 0) {
        return R_OK;
    }

    // check for special name "all"
    if (cur_led == 0 && buf_idx == 3 && buf[0]=='a' && buf[1]=='l' && buf[2]=='l') {
        fl_all = true;
        return R_OK;
    }

    // loop through colors to find a match
    uint8_t found = 0;
    uint16_t name_start_idx = 0;
    for (int i = 0; i < NUM_COLORS; i++) {
        uint8_t name_len = pgm_read_byte(&colors[i].name_len);

        // skip color if name lengths don't match
        if (buf_idx != name_len) {
            name_start_idx += name_len;
            continue;
        }

        // check all letters in the name
        uint8_t match = 1;
        for (uint8_t j = 0; j < name_len; j++) {
            char c = pgm_read_byte(COLOR_NAMES + name_start_idx + j);
            if (buf[j] != c) {
                match = 0;
                break;
            }
        }

        if (match) {
            found = 1;
            uint8_t r = pgm_read_byte(&colors[i].r);
            uint8_t g = pgm_read_byte(&colors[i].g);
            uint8_t b = pgm_read_byte(&colors[i].b);
            setCurLed(r,g,b);
            break;
        }

        name_start_idx += name_len;
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
        buf_idx = 0;
        cur_led = 0;
        fl_all = 0;
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
            setState(S_IDLE);
            int8_t r = nameLookup();
            buf_idx = 0;
            cur_led++;
            return r;
        }
        return R_OK;
    } else if (c == ',' || c == ';') {
        buf_idx--;

        // end of current name
        setState(S_IDLE);
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


static int8_t decimalParseVal(void) {
    if (buf_idx == 0 || decimal_rgb_cur_color > 2) {
        return R_OK;
    }
    
    // add terminating NULL to make buf a valid string
    buf[buf_idx] = 0;
    // TODO: watch out for buffer overflow

    uint8_t val = (uint8_t)atoi(buf);
    decimal_rgb[decimal_rgb_cur_color] = val;
    decimal_rgb_cur_color++;

    // after getting the 3rd value, set the led color
    if (decimal_rgb_cur_color == 3) {
        setCurLed(decimal_rgb[0], decimal_rgb[1], decimal_rgb[2]);
    }
    return R_OK;
}

static int8_t decimalParseChar(char c) {
    if (c == '\n' || c == '\r') {
        buf_idx--;

        // if this rgb triple is incomplete, ignore it and go to IDLE
        if (decimal_rgb_cur_color < 2) {
            setState(S_IDLE);
            buf_idx = 0;
            cur_led = 0;
            fl_all = 0;
            decimal_rgb_cur_color = 0;
            ledFlush();
        }
        int8_t r = decimalParseVal();
        setState(S_IDLE);
        buf_idx = 0;
        cur_led = 0;
        fl_all = 0;
        decimal_rgb_cur_color = 0;
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
            int8_t r = decimalParseVal();
            buf_idx = 0;
            return r;
        }
        return R_OK;
    } else if (c == ',') {
        // ignore comma
        buf_idx--;

        int8_t r = decimalParseVal();
        buf_idx = 0;
        return r;
    } else if (c == ';') {
        // ignore this character
        buf_idx--;

        // end of current color
        setState(S_IDLE);
        int8_t r = decimalParseVal();
        buf_idx = 0;
        decimal_rgb_cur_color = 0;
        cur_led++;
        return r;
    } else if (c >= '0' && c <= '9') {
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
            buf_idx = 0;
            cur_led = 0;
            fl_all = false;
        }
        return R_OK;
    }

    // IDLE is special - might change state, and want the current character to be processed
    if (state == S_IDLE) {
        int8_t r = idleParseChar(c);
        if (r < 0) {
            return r;
        }
    }

    switch (state) {
        case S_IDLE:
            return R_OK;
        case S_NAME:
            return nameParseChar(c);
        case S_DECIMAL_RGB:
            return decimalParseChar(c);
        default:
            return E_UNKNOWN_STATE;
    }
}



/*
###########################################
#     Simple USB LED Controller - SULC    #
#        Copyright 2012 Scott Bezek       #
###########################################
*/

/*
This is a modified file from the Arduino TLC5940 Library, for use with SULC.
*/



/*  Copyright (c) 2009 by Alex Leone <acleone ~AT~ gmail.com>

    This file is part of the Arduino TLC5940 Library.

    The Arduino TLC5940 Library is free software: you can redistribute it
    and/or modify it under the terms of the GNU General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    The Arduino TLC5940 Library is distributed in the hope that it will be
    useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with The Arduino TLC5940 Library.  If not, see
    <http://www.gnu.org/licenses/>. */

#ifndef TLC_PINOUT_H
#define TLC_PINOUT_H

///** VPRG (Arduino digital pin 8) -> VPRG (TLC pin 27) */
//#define DEFAULT_VPRG_PIN    PB0
//#define DEFAULT_VPRG_PORT   PORTB
//#define DEFAULT_VPRG_DDR    DDRB
//
///** XERR (Arduino digital pin 12) -> XERR (TLC pin 16) */
//#define DEFAULT_XERR_PIN    PB4
//#define DEFAULT_XERR_PORT   PORTB
//#define DEFAULT_XERR_DDR    DDRB
//#define DEFAULT_XERR_PINS   PINB
//
/** SIN (Arduino digital pin 7) -> SIN (TLC pin 26) */
#define DEFAULT_BB_SIN_PIN      PB2
#define DEFAULT_BB_SIN_PORT     PORTB
#define DEFAULT_BB_SIN_DDR      DDRB
/** SCLK (Arduino digital pin 4) -> SCLK (TLC pin 25) */
#define DEFAULT_BB_SCLK_PIN     PB1
#define DEFAULT_BB_SCLK_PORT    PORTB
#define DEFAULT_BB_SCLK_DDR     DDRB

/** MOSI (Arduino digital pin 11) -> SIN (TLC pin 26) */
#define TLC_MOSI_PIN     PB2
#define TLC_MOSI_PORT    PORTB
#define TLC_MOSI_DDR     DDRB

/** SCK (Arduino digital pin 13) -> SCLK (TLC pin 25) */
#define TLC_SCK_PIN      PB1
#define TLC_SCK_PORT     PORTB
#define TLC_SCK_DDR      DDRB

/** SS will be set to output as to not interfere with SPI master operation.
    If you have changed the pin-outs and the library doesn't seem to work
    or works intermittently, make sure this pin is set correctly.  This pin
    will not be used by the library other than setting its direction to
    output. */
#define TLC_SS_PIN       PB0
#define TLC_SS_DDR       DDRB

/** OC1A (Arduino digital pin 9) -> XLAT (TLC pin 24) */
#define XLAT_PIN     PC6
#define XLAT_PORT    PORTC
#define XLAT_DDR     DDRC

/** OC1B (Arduino digital pin 10) -> BLANK (TLC pin 23) */
#define BLANK_PIN    PC5
#define BLANK_PORT   PORTC
#define BLANK_DDR    DDRC

/** OC2B (Arduino digital pin 3) -> GSCLK (TLC pin 18) */
#define GSCLK_PIN    PD0
#define GSCLK_PORT   PORTD
#define GSCLK_DDR    DDRD

#endif

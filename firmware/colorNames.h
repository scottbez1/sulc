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


const Color colors[] PROGMEM = {
    {3,0,0,0},
    {9,240,248,255},
    {12,250,235,215},
    {4,0,255,255},
    {10,127,255,212},
    {5,240,255,255},
    {5,245,245,220},
    {6,255,228,196},
    {5,0,0,0},
    {14,255,235,205},
    {4,0,0,255},
    {10,138,43,226},
    {5,165,42,42},
    {9,222,184,135},
    {9,95,158,160},
    {10,127,255,0},
    {9,210,105,30},
    {5,255,127,80},
    {14,100,149,237},
    {8,255,248,220},
    {7,220,20,60},
    {4,0,255,255},
    {8,0,0,139},
    {8,0,139,139},
    {13,184,134,11},
    {8,169,169,169},
    {9,0,100,0},
    {9,189,183,107},
    {11,139,0,139},
    {14,85,107,47},
    {10,255,140,0},
    {10,153,50,204},
    {7,139,0,0},
    {10,233,150,122},
    {12,143,188,143},
    {13,72,61,139},
    {13,47,79,79},
    {13,0,206,209},
    {10,148,0,211},
    {8,255,20,147},
    {11,0,191,255},
    {7,105,105,105},
    {10,30,144,255},
    {9,178,34,34},
    {11,255,250,240},
    {11,34,139,34},
    {7,255,0,255},
    {9,220,220,220},
    {10,248,248,255},
    {4,255,215,0},
    {9,218,165,32},
    {4,128,128,128},
    {5,0,128,0},
    {11,173,255,47},
    {8,240,255,240},
    {7,255,105,180},
    {9,205,92,92},
    {6,75,0,130},
    {5,255,255,240},
    {5,240,230,140},
    {8,230,230,250},
    {13,255,240,245},
    {9,124,252,0},
    {12,255,250,205},
    {9,173,216,230},
    {10,240,128,128},
    {9,224,255,255},
    {20,250,250,210},
    {10,144,238,144},
    {9,211,211,211},
    {9,255,182,193},
    {11,255,160,122},
    {13,32,178,170},
    {12,135,206,250},
    {14,119,136,153},
    {14,176,196,222},
    {11,255,255,224},
    {4,0,255,0},
    {9,50,205,50},
    {5,250,240,230},
    {7,255,0,255},
    {6,128,0,0},
    {16,102,205,170},
    {10,0,0,205},
    {12,186,85,211},
    {12,147,112,219},
    {14,60,179,113},
    {15,123,104,238},
    {17,0,250,154},
    {15,72,209,204},
    {15,199,21,133},
    {12,25,25,112},
    {9,245,255,250},
    {9,255,228,225},
    {8,255,228,181},
    {11,255,222,173},
    {4,0,0,128},
    {7,253,245,230},
    {5,128,128,0},
    {9,107,142,35},
    {6,255,165,0},
    {9,255,69,0},
    {6,218,112,214},
    {13,238,232,170},
    {9,152,251,152},
    {13,175,238,238},
    {13,219,112,147},
    {10,255,239,213},
    {9,255,218,185},
    {4,205,133,63},
    {4,255,192,203},
    {4,221,160,221},
    {10,176,224,230},
    {6,128,0,128},
    {3,255,0,0},
    {9,188,143,143},
    {9,65,105,225},
    {11,139,69,19},
    {6,250,128,114},
    {10,244,164,96},
    {8,46,139,87},
    {8,255,245,238},
    {6,160,82,45},
    {6,192,192,192},
    {7,135,206,235},
    {9,106,90,205},
    {9,112,128,144},
    {4,255,250,250},
    {11,0,255,127},
    {9,70,130,180},
    {3,210,180,140},
    {4,0,128,128},
    {7,216,191,216},
    {6,255,99,71},
    {9,64,224,208},
    {6,238,130,238},
    {5,245,222,179},
    {5,255,255,255},
    {10,245,245,245},
    {6,255,255,0},
    {11,154,205,50},

};


const char COLOR_NAMES[] PROGMEM = "offaliceblueantiquewhiteaquaaquamarineazurebeigebisqueblackblanchedalmondbluebluevioletbrownburlywoodcadetbluechartreusechocolatecoralcornflowerbluecornsilkcrimsoncyandarkbluedarkcyandarkgoldenroddarkgraydarkgreendarkkhakidarkmagentadarkolivegreendarkorangedarkorchiddarkreddarksalmondarkseagreendarkslatebluedarkslategraydarkturquoisedarkvioletdeeppinkdeepskybluedimgraydodgerbluefirebrickfloralwhiteforestgreenfuchsiagainsboroghostwhitegoldgoldenrodgraygreengreenyellowhoneydewhotpinkindianredindigoivorykhakilavenderlavenderblushlawngreenlemonchiffonlightbluelightcorallightcyanlightgoldenrodyellowlightgreenlightgraylightpinklightsalmonlightseagreenlightskybluelightslategraylightsteelbluelightyellowlimelimegreenlinenmagentamaroonmediumaquamarinemediumbluemediumorchidmediumpurplemediumseagreenmediumslatebluemediumspringgreenmediumturquoisemediumvioletredmidnightbluemintcreammistyrosemoccasinnavajowhitenavyoldlaceoliveolivedraborangeorangeredorchidpalegoldenrodpalegreenpaleturquoisepalevioletredpapayawhippeachpuffperupinkplumpowderbluepurpleredrosybrownroyalbluesaddlebrownsalmonsandybrownseagreenseashellsiennasilverskyblueslateblueslategraysnowspringgreensteelbluetantealthistletomatoturquoisevioletwheatwhitewhitesmokeyellowyellowgreen";




#define NUM_COLORS (sizeof(colors)/sizeof(Color))

#endif

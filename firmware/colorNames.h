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

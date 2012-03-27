
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

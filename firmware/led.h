#ifndef _LED_H_
#define _LED_H_

#include <inttypes.h>

#define NUM_LEDS 2

void ledSetRGB(uint8_t led, uint8_t r, uint8_t g, uint8_t b);
void ledFlush(void);

#endif

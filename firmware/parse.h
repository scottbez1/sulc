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

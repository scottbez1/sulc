#include "dbg.h"

void initDbg() {
    DBG_DDR  |=   DBG_0 | DBG_1 | DBG_2 | DBG_3;
    DBG_PORT &= ~(DBG_0 | DBG_1 | DBG_2 | DBG_3);
}

/** Set the debug LEDs with the lower nibble of val
 */
void setDbg(uint8_t val) {
    uint8_t oldPort = DBG_PORT;
    oldPort &= ~(DBG_0 | DBG_1 | DBG_2 | DBG_3);
    if (val & _BV(0)) { oldPort |= DBG_0; }
    if (val & _BV(1)) { oldPort |= DBG_1; }
    if (val & _BV(2)) { oldPort |= DBG_2; }
    if (val & _BV(3)) { oldPort |= DBG_3; }
    DBG_PORT = oldPort;
}



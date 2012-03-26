		#include <avr/io.h>
		#include <avr/wdt.h>
		#include <avr/power.h>
		#include <avr/interrupt.h>
#include <util/delay.h>
		#include <string.h>
		#include <stdio.h>

int main(void) {
    // clear clock divider
    CLKPR = (1<<CLKPCE); 
    CLKPR = 0;


    DDRD |= _BV(1) | _BV(4) | _BV(5) | _BV(6);
    while(1) {
        PORTD |= _BV(1);
        _delay_ms(100);

        PORTD |= _BV(4);
        _delay_ms(100);

        PORTD |= _BV(5);
        _delay_ms(100);

        PORTD |= _BV(6);
        _delay_ms(100);



        PORTD &= ~_BV(1);
        _delay_ms(100);
        PORTD &= ~_BV(4);
        _delay_ms(100);
        PORTD &= ~_BV(5);
        _delay_ms(100);
        PORTD &= ~_BV(6);
        _delay_ms(100);
    }
}

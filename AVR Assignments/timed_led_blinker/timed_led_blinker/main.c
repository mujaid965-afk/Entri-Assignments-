/*
 * timed_led_blinker.c
 *
 * Created: 06-Jun-26 12:20:51 PM
 * Author : Mujaid
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    //configure PD5 aas output
	DDRD |= (1 << PD5);
	
    while (1) 
    {
		//LED ON
		PORTD |= (1 << PD5);
		_delay_ms(3000);
		//LED OFF
		PORTD &= ~(1 << PD5);
		_delay_ms(5000);
    }
	return 0;
}


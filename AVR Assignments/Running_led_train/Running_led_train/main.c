/*
 * led_train.c
 *
 * Created: 06-Jun-26 12:28:28 PM
 * Author : Mujaid
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    uint8_t i;
	
	//configure PORTB as output
	DDRB = 0XFF;
	
    while (1) 
    {
		for(i=0; i<8; i++);
		{
			PORTB = (1 << i);
			_delay_ms(200);
		}
    }
	return 0;
}



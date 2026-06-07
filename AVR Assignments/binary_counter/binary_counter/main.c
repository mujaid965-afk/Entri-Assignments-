/*
 * binary_counter.c
 *
 * Created: 06-Jun-26 7:42:27 PM
 * Author : Mujaid
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

uint8_t count = 0;

void updateLEDs(uint8_t value)
{
	PORTB &= 0xF0;		//clear PB0-PB3
	PORTB |= (value & 0x0F);
}

int main(void)
{
    DDRB |= 0x0F;			//PB0-PB3 as output
	DDRD &= ~(1 << PD2);	//PD2 as input
	PORTD |= (1 << PD2);	//enable internal pullup
	
	updateLEDs(count);
    while (1) 
    {
		//if button pressed
		if(!(PIND & (1 << PD2)))
		{
			_delay_ms(20);
			
			if(!(PIND & (1 << PD2)))
			{
				count++;
				if(count > 15)
				{
					count = 0;
				}
				updateLEDs(count);
				
				//wait until release
				while(!(PIND & (1 << PD2)));
				_delay_ms(20);
			}
		}
    }
}


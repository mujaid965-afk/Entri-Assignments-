/*
 * timed_led_blinker.c
 *
 * Created: 06-Jun-26 11:43:26 AM
 * Author : Mujaid
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>



int main(void)
{
    //Set PB0 and PB1 as output
	DDRB |= (1 << PB0) | (1 << PB1);
	
	//Set PD2 as input
	DDRD &= ~(1 << PD2);
	
	//Enable internal pullup resistor on PD2
	PORTD |= (1 << PD2);
	
	//Initial state
	PORTB |= (1 << PB0); // Red LED ON
	PORTB &= ~(1 << PB1); // Green LED OFF
	
	uint8_t state = 0;
	
    while (1) 
    {
		// check putton press
		if(!(PIND & (1 << PD2)))
		{
			_delay_ms(20); //button press delay
			
			//button still presssed
			if(!(PIND & (1 << PD2)))
			{
				state = !state;
				
				if(state)
				{
					//green led on, red led off
					PORTB |= (1<< PB1);
					PORTB &= ~(1<< PB0);
				}
				else
				{
					PORTB |= (1<< PB0);
					PORTB &= ~(1<< PB1);
				}
				// wait until button release
				while(!(PIND & (1 << PD2)));
				
				_delay_ms(20);
			}
		}
    }
	
}


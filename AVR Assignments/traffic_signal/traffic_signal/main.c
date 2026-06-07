/*
 * traffic_signal.c
 *
 * Created: 06-Jun-26 8:17:08 PM
 * Author : Mujaid
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint8_t seconds = 0;
volatile uint8_t state = 0;

/* state : 0 -> Green
		   1 -> orange
		   2 -> red
*/

ISR(TIMER1_COMPA_vect)
{
	seconds++;
}
 void timer1_init(void)
 { 
	 TCCR1B |= (1 << WGM12);		//CTC MODE
	 OCR1A = 15624;					//1 second
	 TIMSK1 |= (1 << OCIE1A);		// enable compare interrupt
	 TCCR1B |= (1 << CS12) | (1 << CS10); //PRESCALAR 1024
 }

int main(void)
{
    DDRB |= (1 << PB0) | (1 << PB1) | (1 << PB2);
	timer1_init();
	sei();
	PORTB |= (1 << PB0); // Green ON
    while (1) 
    {
		switch(state)
		{
			case 0: //Green
				if(seconds >=10)
				{
					PORTB = (1 << PB1);
					seconds = 0;
					state = 1;
				}
				break;
			
			case 1: //orange 
				if(seconds >=3)
				{
					PORTB = (1 << PB2);
					seconds = 0;
					state = 2;
				}
				break;
				
			case 2: //red
			if(seconds >=10)
			{
				PORTB = (1 << PB0);
				seconds = 0;
				state = 0;
			}
			break;
		}
    }
}


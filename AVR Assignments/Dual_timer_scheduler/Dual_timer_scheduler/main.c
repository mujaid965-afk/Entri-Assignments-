/*
 * Dual_timer_scheduler.c
 *
 * Created: 07-Jun-26 12:33:35 PM
 * Author : Mujaid
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint8_t timer2_count = 0;

//   TIMER1 ISR - 2 SECONDS

ISR(TIMER1_COMPA_vect)
{
	PORTB ^= (1 << PB1);
}

//  TIMER2 ISR - 500 ms

ISR(TIMER2_COMPA_vect)
{
	timer2_count++;
	if(timer2_count >= 31)
	{
		PORTB ^= (1 << PB2);
		timer2_count =0;
	}
}

int main(void)
{
    
	DDRB |= (1<<PB1) | (1<<PB2);	// configure  LEDS
	TCCR1A = 0;		//Timer1 configuration
	TCCR1B |= (1 << WGM12);  //CTC  mode
	OCR1A = 31249;		//compare value for 2 sec
	TIMSK1 |= (1<<OCIE1A);  //Enable cpmare match A interrupt
	
	TCCR1B |= (1 << CS12) | (1 << CS10); // start Timer1- prescalar 1024
	
	TCCR2A |= (1 << WGM21);  // timer2 configuration 
	OCR2A = 249;
	TIMSK2 |= (1<< OCIE2A); // Enable compare match interrupt
	TCCR2B |= (1 << CS22) | (1<< CS21)| (1<<CS20);  // Prescalar  1024
	
	sei();
	
	while (1) 
    {
    }
}


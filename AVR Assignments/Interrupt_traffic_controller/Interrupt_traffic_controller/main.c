/*
 * interrupt_traffic_controller.c.c
 *
 * Created: 06-Jun-26 8:49:34 PM
 * Author : Mujaid
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint8_t seconds = 0;
volatile uint8_t emergency_flag = 0;

typedef enum
{
	GREEN,
	ORANGE,
	RED
}TrafficState;

volatile TrafficState state = GREEN;

//timer1 interrupt
ISR(TIMER1_COMPA_vect)
{
	seconds++;
}

//external interrupt INT0
ISR(INT0_vect)
{
	emergency_flag = 1;
}

//timer1 init
void timer1_init(void)
{
	TCCR1B |= (1 << WGM12);		//CTC MODE
	OCR1A = 15624;					//1 second
	TIMSK1 |= (1 << OCIE1A);		// enable compare interrupt
	TCCR1B |= (1 << CS12) | (1 << CS10); //PRESCALAR 1024
}

//INT0 init
void int0_init(void)
{
	EICRA |=(1 << ISC01);
	EICRA &= ~(1  << ISC00);
	EIMSK |= (1 << INT0);
	
}

void setLight(TrafficState current)
{
	PORTB &= ~((1<<PB0) | (1<<PB1) | (1<<PB2));
	
	switch(current)
	{
		case GREEN:
			PORTB |= (1<<PB0);
			break;
		
		case ORANGE:
			PORTB |= (1<<PB1);
			break;
		
		case RED:
			PORTB |= (1<<PB2);
			break;
	}
}
int main(void)
{
    DDRB |= (1<<PB0) | (1<<PB1) | (1<<PB2);
	
	DDRD &= ~(1<<PD2);
	PORTD |= (1<<PD2);
	
	timer1_init();
	int0_init();
	sei();
	
	setLight(GREEN);
	
    while (1) 
    {
		switch(state)
		{
			case GREEN:
				if(seconds >= 10)
				{
					seconds = 0;
					if(emergency_flag)
					{
						setLight(GREEN);
						seconds = 0;
						
						while(seconds <10);
						
						emergency_flag= 0;
						seconds = 0;
					}
					
					state = ORANGE;
					setLight(ORANGE);
				}
				break;
				
			case ORANGE:
				if(seconds >= 3)
				{
					seconds = 0;
					if(emergency_flag)
					{
						setLight(GREEN);
						seconds = 0;
					
						while(seconds <10);
					
						emergency_flag= 0;
						seconds = 0;
					}
				
					state = RED;
					setLight(RED);
				}
				break;
				
			case RED:
				if(seconds >= 10)
				{
					seconds = 0;
					if(emergency_flag)
					{
						setLight(GREEN);
						seconds = 0;
					
						while(seconds <10);
					
						emergency_flag= 0;
						seconds = 0;
					}
				
					state = GREEN;
					setLight(GREEN);
				}
				break;
		}
    }
}


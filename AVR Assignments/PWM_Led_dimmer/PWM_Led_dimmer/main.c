/*
 * PWM_Led_dimmer.c
 *
 * Created: 07-Jun-26 1:16:26 PM
 * Author : Mujaid
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

uint8_t pwm_state = 0;

void PWM_update(uint8_t state)
{
	switch (state)
	{
		case 0 :
			TCCR0A |= (1 << COM0A1);
			OCR0A = 64;  //25 %
			break;
		
		case 1 :
			OCR0A = 128;  //50 %
			break;
		
		case 2 :
			OCR0A = 191;  //75 %
			break;
		
		case 3 :
			OCR0A = 255;  //100 %
			break;
		
		case 4 :
			TCCR0A &= ~(1 << COM0A1);  // Disconnect PWM
			PORTD &= ~(1 << PD6);      // Force LOW
			break;
	}
}


int main(void)
{
    DDRD |= (1 << PD6);  //set PD6 as output
	DDRD &= ~(1 << PD2);  //Set PD2 as input
	PORTD |= (1 << PD2);  // Enable internal  pullup
	
	// timer 0 FAST PWM mode
	TCCR0A = (1 << COM0A1) | (1 << WGM01) | (1 << WGM00); // NON inverting mode
	TCCR0B = (1 << CS01) | (1 << CS00);  //PRESCALAR = 64
	
	PWM_update(0);  //start at 25%
	
    while (1) 
    {
		if(!(PIND & (1 << PD2)))
		{
			_delay_ms(50);
			
			if(!(PIND & (1 << PD2)))
			{
				pwm_state++;
				
				if(pwm_state > 4)
					pwm_state = 0;
					
				PWM_update(pwm_state);
				
				while(!(PIND & (1 << PD2)));
				_delay_ms(50);
			}
		}
    }
}


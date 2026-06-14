/*
 * servo_position_controller.c
 *
 * Created: 14-Jun-26 1:16:47 PM
 * Author : Mujaid
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>


void  ADC_Init(void)
{
	ADMUX = (1<<REFS0); //AVCC reference
	
	ADCSRA = (1 << ADEN);	//Enable ADC
	ADCSRA = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);	//Prescalar = 128
}

uint16_t ADC_Read(uint8_t channel)
{
	ADMUX = (ADMUX & 0xF0) | channel; // select adc channel
	ADCSRA |= (1 << ADSC);	// ADC conversion
	while(ADCSRA & (1<<ADSC));	// wait until conversion completes
	
	return ADC;	//Return ADC result
}

void Servo_Init(void)
{
	DDRB |= (1 << PB1); //PB1 as output
	
	TCCR1A = (1 << COM1A1) | (1 << WGM11);	
	TCCR1B = (1 << WGM13) | (1 << CS11);
	ICR1 = 20000;
	
}

void Servo_SetAngle(uint16_t adc_value)
{
	uint16_t pulse;
	pulse = 1000 + ((uint32_t)adc_value *1000) /1023;
	OCR1A = pulse;
}

int main(void)
{
    uint16_t adc_value;
	
	ADC_Init();
	Servo_Init();
	
	
    while (1) 
    {
		adc_value = ADC_Read(0);
		Servo_SetAngle(adc_value);
    }
}


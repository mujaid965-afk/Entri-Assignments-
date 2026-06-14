/*
 * Automatic_cooling_adc.c
 *
 * Created: 07-Jun-26 2:36:34 PM
 * Author : Mujaid
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

uint8_t systemstate = 0;

//ADC initialisation
void ADC_init(void)
{
	ADMUX = (1 << REFS0);	//AVCC reference
	ADCSRA = (1 << ADEN) | (1<< ADPS2) | (1 << ADPS1) | (1 << ADPS0); //prescalar 128
}


// read adc channel
uint16_t ADC_Read(uint8_t channel)
{
	ADMUX = (ADMUX & 0xF0) | channel;
	ADCSRA |= (1<<ADSC);
	while(ADCSRA & (1<<ADSC));
	return ADC;
}


//Convert ADC value to temperature
float GetTemperature(void)
{
	uint16_t adcvalue;
	adcvalue = ADC_Read(0);   //LM35
	float voltage = (adcvalue * 5) / 1024;
	float temperature = voltage * 100;
	return temperature;
}


//PWM initialisation
void PWM_Init(void)
{
	DDRD |= (1 << PD6);		//PD6 as output
	TCCR0A = (1<<COM0A1) | (1<<WGM01) | (1<<WGM00);
	TCCR0B = (1<<CS01) | (1<<CS00);		//prescalar 64
}


//set motor speed
void Setmotorspeed(uint8_t duty)
{
	OCR0A = duty;
}

//Temperature controlled speed
void Controlmotorspeed(float temperature)
{
	if(temperature < 25)
	{
		Setmotorspeed(64);		//25%
	}
	else if(temperature <  35)
	{
		Setmotorspeed(128);		//50%
	}
	else if(temperature < 45)
	{
		Setmotorspeed(191);		//75%
	}
	else
	{
		Setmotorspeed(255);		//100%
	}
	
}


//push button handling
void CheckButton(void)
{
	if(!(PIND & (1 << PD2)))
	{
		
		_delay_ms(50);
		
		if(!(PIND & (1 << PD2)))
		{
			systemstate ^= 1;
			
			while(!(PIND & (1 << PD2)));
			
			_delay_ms(50);
			
		}
	}
}

//system control logic
void SystemControl(void)
{
	float temperature;
	temperature = GetTemperature();
	Controlmotorspeed(temperature);
}


int main(void)
{
    
	ADC_init();
	PWM_Init();
	
	DDRD &= ~(1<<PD2); //SET PD2 AS INPUT
	PORTD |= (1 << PD2);
    while (1) 
    {
		CheckButton();
		
		if(systemstate)
		{
			SystemControl();
		}
		else
		{
			Setmotorspeed(0);
		}
    }
}


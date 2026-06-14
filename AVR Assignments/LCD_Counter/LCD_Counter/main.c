/*
 * LCD_Counter.c
 *
 * Created: 14-Jun-26 1:48:46 PM
 * Author : Mujaid
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#include "lcd.h"

unsigned long counter = 0;

void DisplayCounter(void)
{
	char buffer[12];

	sprintf(buffer,"%09lu",counter);

	lcd_clear();
	lcd_set_cursor(0,0);
	lcd_print(buffer);
}

int main(void)
{
	uint16_t press_time;

	lcd_init();

	DDRD &= ~(1<<PD2);
	PORTD |= (1<<PD2);

	DisplayCounter();

	while(1)
	{
		if(!(PIND & (1<<PD2)))
		{
			press_time = 0;

			while(!(PIND & (1<<PD2)))
			{
				_delay_ms(10);
				press_time += 10;
			}

			if(press_time >= 2000)
			{
				counter = 0;
			}
			else
			{
				counter++;
			}

			DisplayCounter();

			_delay_ms(50);
		}
	}
}
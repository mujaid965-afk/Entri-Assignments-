/*
 * lcd.c
 *
 * Created: 14-Jun-26 3:23:23 PM
 *  Author: Mujaid
 */ 

#include "lcd.h"

/* Generate Enable Pulse */
static void lcd_enable_pulse(void)
{
	LCD_PORT |= (1 << LCD_EN);
	_delay_us(1);

	LCD_PORT &= ~(1 << LCD_EN);
	_delay_us(100);
}

/* Send 4-bit nibble */
static void lcd_send_nibble(uint8_t nibble)
{
	LCD_PORT &= ~((1<<LCD_D4)|
	(1<<LCD_D5)|
	(1<<LCD_D6)|
	(1<<LCD_D7));

	if(nibble & 0x01) LCD_PORT |= (1<<LCD_D4);
	if(nibble & 0x02) LCD_PORT |= (1<<LCD_D5);
	if(nibble & 0x04) LCD_PORT |= (1<<LCD_D6);
	if(nibble & 0x08) LCD_PORT |= (1<<LCD_D7);

	lcd_enable_pulse();
}

/* Send Byte */
static void lcd_send_byte(uint8_t value,uint8_t rs)
{
	if(rs)
	LCD_PORT |= (1<<LCD_RS);
	else
	LCD_PORT &= ~(1<<LCD_RS);

	lcd_send_nibble(value >> 4);
	lcd_send_nibble(value & 0x0F);
}

/* Send Command */
void lcd_cmd(uint8_t cmd)
{
	lcd_send_byte(cmd,0);

	if(cmd == 0x01 || cmd == 0x02)
	_delay_ms(2);
}

/* Send Data */
void lcd_data(uint8_t data)
{
	lcd_send_byte(data,1);
}

/* Clear LCD */
void lcd_clear(void)
{
	lcd_cmd(0x01);
}

/* Cursor Home */
void lcd_home(void)
{
	lcd_cmd(0x02);
}

/* Set Cursor Position */
void lcd_set_cursor(uint8_t row,uint8_t col)
{
	uint8_t address;

	if(row == 0)
	address = 0x00 + col;
	else
	address = 0x40 + col;

	lcd_cmd(0x80 | address);
}

/* Print String */
void lcd_print(const char *str)
{
	while(*str)
	{
		lcd_data(*str++);
	}
}

/* Print Integer */
void lcd_print_uint16(uint16_t num)
{
	if(num >= 10)
	lcd_print_uint16(num/10);

	lcd_data('0' + (num%10));
}

/* LCD Initialization */
void lcd_init(void)
{
	LCD_DDR |= (1<<LCD_RS) |
	(1<<LCD_EN) |
	(1<<LCD_D4) |
	(1<<LCD_D5) |
	(1<<LCD_D6) |
	(1<<LCD_D7);

	_delay_ms(20);

	LCD_PORT &= ~(1<<LCD_RS);
	LCD_PORT &= ~(1<<LCD_EN);

	lcd_send_nibble(0x03);
	_delay_ms(5);

	lcd_send_nibble(0x03);
	_delay_us(150);

	lcd_send_nibble(0x03);
	_delay_us(150);

	lcd_send_nibble(0x02);

	lcd_cmd(0x28);   // 4-bit, 2-line
	lcd_cmd(0x08);   // Display OFF
	lcd_cmd(0x01);   // Clear
	lcd_cmd(0x06);   // Entry mode
	lcd_cmd(0x0C);   // Display ON
}
/*
 * lcd.h
 *
 * Created: 14-Jun-26 3:22:37 PM
 *  Author: Mujaid
 */ 


#ifndef LCD_H
#define LCD_H

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

/* LCD Connections

RS -> PB0
EN -> PB1

D4 -> PB2
D5 -> PB3
D6 -> PB4
D7 -> PB5

RW -> GND
*/

#define LCD_PORT PORTB
#define LCD_DDR  DDRB

#define LCD_RS PB0
#define LCD_EN PB1

#define LCD_D4 PB2
#define LCD_D5 PB3
#define LCD_D6 PB4
#define LCD_D7 PB5

void lcd_init(void);
void lcd_cmd(uint8_t cmd);
void lcd_data(uint8_t data);
void lcd_clear(void);
void lcd_home(void);
void lcd_set_cursor(uint8_t row,uint8_t col);
void lcd_print(const char *str);
void lcd_print_uint16(uint16_t num);

#endif
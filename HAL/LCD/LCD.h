/*
 * LCD.h
 *
 * Created: 9/3/2020 12:54:06 AM
 *  Author: Moataz
 */ 


#ifndef LCD_H_
#define LCD_H_

//#define F_CPU 16000000ul
#include <util/delay.h>
#include "..\DIO\DIO.h"

#define LCD_Data	('A')
#define LCD_Ctrl	('B')

/***LCD data pins***/
#define LCD_D4	4
#define LCD_D5	5
#define LCD_D6	6
#define LCD_D7	7

/***LCD control pins***/
#define LCD_RS	1
#define LCD_RW	2
#define LCD_En	3

/***LCD commands***/ 
#define LCD_FUNCTION_8BIT_1LINE   					(0x30)
#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_1LINE   					(0x20)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON   								(0x0C)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_ROW						(0x80)
#define LCD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_CURSOR_AT_BEGINNING						(0x02)
#define LCD_ENTRY_MODE								(0x06)

/***functions prototype***/
void LCD_Enable();
void LCD_init();
void LCD_ClrScreen();
void LCD_SendCommand(uint8 cmd);
void LCD_SendChar(uint8 data);
void LCD_SendString(uint8 string[]);
//void LCD_SendNumber(uint16 number);
//void LCD_GotoXY(uint8 x,uint8 y);

#endif /* LCD_H_ */
/*
 * LCD.c
 *
 * Created: 9/3/2020 12:54:18 AM
 *  Author: Moataz
 */ 

#include "LCD.h"

void LCD_Enable()
{
	DIO_WritePin(LCD_Ctrl,LCD_En,HIGH);
	_delay_us(10);
	DIO_WritePin(LCD_Ctrl,LCD_En,LOW);
}

void LCD_init()
{
	/***data port initialization***/
	//DIO_SetPortDir(LCD_Data,HIGH);//8 bits data
	
	/***data port initialization***/
	DIO_SetHighNibDir(LCD_Data,OUT);
	
	/***control port initialization***/
	DIO_SetPinDir(LCD_Ctrl,LCD_RS,OUT);
	DIO_SetPinDir(LCD_Ctrl,LCD_RW,OUT);
	DIO_SetPinDir(LCD_Ctrl,LCD_En,OUT);
	
	/***LCD initialization***/
	_delay_ms(15);
	DIO_WritePin(LCD_Ctrl,LCD_RS,LOW);
	DIO_WritePin(LCD_Ctrl,LCD_RW,LOW);
	DIO_WriteHighNibVal(LCD_Data,0x30);
	_delay_ms(4.1);
	DIO_WriteHighNibVal(LCD_Data,0x30);
	_delay_us(100);
	DIO_WriteHighNibVal(LCD_Data,0x30);
	
	//LCD_SendCommand(LCD_FUNCTION_8BIT_2LINES);//8 bits data bus
	LCD_SendCommand(LCD_FUNCTION_4BIT_1LINE);
	
	LCD_SendCommand(LCD_FUNCTION_4BIT_2LINES);
	/*display on*/
	LCD_SendCommand(LCD_DISP_ON);
	/*display clear*/
	LCD_SendCommand(LCD_CLEAR_SCREEN);
	/*entry mode set(increment and shift)*/
	LCD_SendCommand(LCD_ENTRY_MODE);
}

void LCD_ClrScreen()
{
	LCD_SendCommand(LCD_CLEAR_SCREEN);
}

void LCD_SendCommand(uint8 cmd)
{
	//1-set RS=0 RW=0
	DIO_WritePin(LCD_Ctrl,LCD_RS,LOW);
	DIO_WritePin(LCD_Ctrl,LCD_RW,LOW);
	
	//8 bits data
	//put command on data port
	//DIO_WritePortVal(LCD_Data,cmd);
	//LCD_Enable();
	
	//2-put second half of command on LCD pins 4-->7
	DIO_WriteHighNibVal(LCD_Data,cmd);
	
	//3-enable falling edge
	LCD_Enable();
	
	//4-put the first half of command on LCD pins 4-->7
	DIO_WriteHighNibVal(LCD_Data,cmd<<4);
	
	//5-enable falling edge
	LCD_Enable();
	
	_delay_ms(10);
}

void LCD_SendChar(uint8 data)
{
	//1-set RS=1 RW=0
	DIO_WritePin(LCD_Ctrl,LCD_RS,HIGH);
	DIO_WritePin(LCD_Ctrl,LCD_RW,LOW);
	
	//2-put second half of data on LCD pins 4-->7
	DIO_WriteHighNibVal(LCD_Data,data);

	//3-enable falling edge
	LCD_Enable();
	
	//4-put the first half of data on LCD pins 4-->7
	DIO_WriteHighNibVal(LCD_Data,(data<<4));
	
	//5-enable falling edge
	LCD_Enable();
	
	_delay_ms(10);
}

void LCD_SendString(uint8 string[])
{
	uint8 i = 0;
	while(string[i] != '\0')
	{
		LCD_SendChar(string[i]);
		i++;
	}
}

/*void LCD_SendNumber(uint16 number)
{
	uint8 array[16];
	uint8 i = 0;
	while(number != 0)
	{
		array[i] = number % 10;
		number /= 10;
		i++; 
	}
	while(i != 0)
	{
		LCD_SendChar("array[i]");
		_delay_ms(1000);
		i--;
	}
}*/
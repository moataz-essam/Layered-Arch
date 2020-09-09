/*
 * KP.c
 *
 * Created: 9/5/2020 2:33:50 AM
 *  Author: Moataz
 */ 

#include "KP.h"

/***multi dimension array for symbols of the key pad***/
uint8 keys[ROWS][COLUMNS]={{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'*','0','#','D'}};

void KP_init()
{
	/***port initialization***/
	DIO_SetLowNibDir(KP_PORT,OUT);
	DIO_SetHighNibDir(KP_PORT,IN);
	
	/***activate pull up resistance***/
	DIO_WritePortLvl(KP_PORT,HIGH);
}

uint8 KP_Get_Key()
{
	volatile uint8 key = FALSE;
	uint8 row,col;
	/***loop the output on rows***/
	for(row=0;row<ROWS;row++)
	{
		DIO_WritePortLvl(KP_PORT,HIGH);
		DIO_WritePin(KP_PORT,row,LOW);
		/***loop reading the input on rows***/
		for(col=0;col<COLUMNS;col++)
		{
			if(DIO_ReadPin(KP_PORT,(col+ROWS)) == LOW)
			{
				_delay_ms(30);
				if (DIO_ReadPin(KP_PORT,(col+ROWS)) == LOW)
				{
					key=keys[row][col];
					break;
				}
			}
		}
	}
	return key;
}
/*
 * _7Seg.c
 *
 * Created: 9/4/2020 6:23:14 AM
 *  Author: Moataz
 */ 

#include "SevSeg.h"

void SevSeg_init()
{
	/***data port initialization***/
	DIO_SetHighNibDir(SevSeg_Data,OUT);
	
	/***control port initialization***/
	DIO_SetPinDir(SevSeg_Ctrl,SevSeg_EN1,OUT);
	DIO_SetPinDir(SevSeg_Ctrl,SevSeg_EN2,OUT);
	DIO_SetPinDir(SevSeg_Ctrl,SevSeg_DIP,OUT);	
}

void SevSeg_1_EN()
{
	DIO_WritePin(SevSeg_Ctrl,SevSeg_EN1,HIGH);
}

void SevSeg_1_DIS()
{
	DIO_WritePin(SevSeg_Ctrl,SevSeg_EN1,LOW);
}

void SevSeg_2_EN()
{
	DIO_WritePin(SevSeg_Ctrl,SevSeg_EN2,HIGH);
}

void SevSeg_2_DIS()
{
	DIO_WritePin(SevSeg_Ctrl,SevSeg_EN2,LOW);
}

void SevSeg_Write(uint8 num)
{
	DIO_WriteHighNibVal(SevSeg_Data,(num<<4));
}
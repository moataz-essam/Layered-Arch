/*
 * _7Seg.h
 *
 * Created: 9/4/2020 6:23:28 AM
 *  Author: Moataz
 */ 


#ifndef SEVSEG_H_
#define SEVSEG_H_

#define F_CPU 16000000ul
#include <util/delay.h>
#include "..\DIO\DIO.h"

/***seven segment ports***/
#define SevSeg_Data		('A')
#define SevSeg_Ctrl		('B')

/***LCD data pins***/
#define SevSeg_PIN_A		4
#define SevSeg_PIN_B		5
#define SevSeg_PIN_C		6
#define SevSeg_PIN_D		7

/***LCD control pins***/
#define SevSeg_EN2	1
#define SevSeg_EN1	2
#define SevSeg_DIP	3

/***functions prototype***/
void SevSeg_init();
void SevSeg_1_EN();
void SevSeg_1_DIS();
void SevSeg_2_EN();
void SevSeg_2_DIS();
void SevSeg_Write(uint8 num);

#endif /* 7SEG_H_ */
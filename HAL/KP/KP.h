/*
 * KP.h
 *
 * Created: 9/5/2020 2:34:03 AM
 *  Author: Moataz
 */ 


#ifndef KP_H_
#define KP_H_

//#define F_CPU 16000000ul
#include <util/delay.h>
#include "..\DIO\DIO.h"

/***key pad port***/
#define KP_PORT		'D'
#define ROWS		4
#define COLUMNS		4

/***key pad pins***/
#define KP_ROW_1	0
#define KP_ROW_2	1
#define KP_ROW_3	2
#define KP_ROW_4	3
#define KP_COL_1	4
#define KP_COL_2	5
#define KP_COL_3	6
#define KP_COL_4	7

/***functions prototype***/
void KP_init();
uint8 KP_Get_Key();

#endif /* KP_H_ */
/*
 * STD_types.h
 *
 * Created: 9/3/2020 12:52:52 AM
 *  Author: Moataz
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/***unsigned types***/
typedef unsigned char		uint8;
typedef unsigned short int	uint16;
typedef unsigned long int	uint32;

/***signed types***/
typedef signed char			sint8;
typedef signed short int	sint16;
typedef signed long int		sint32;

/***decimal types***/
typedef float	float32;

/***enum for direction of signal***/
typedef enum
{
	IN=0,
	OUT=1
}STD_Direction;

/***enum for level of signal***/
typedef enum
{
	LOW=0,
	HIGH=1
}STD_SignalLevel;

/***enum for boolean***/
typedef enum
{
	FALSE=0,
	TRUE=1
}STD_Boolean;

#endif /* STD_TYPES_H_ */
/*
 * ADC_cfg.h
 *
 * Created: 9/21/2020 9:09:37 PM
 *  Author: Moataz
 */ 


#ifndef ADC_CFG_H_
#define ADC_CFG_H_

/*=========================================================
 * ADC Prescaler Select Bits
 *=========================================================*/
//#define ADC_Prescaler_2				0b00000000
#define ADC_Prescaler_2				0b00000001
#define ADC_Prescaler_4				0b00000010
#define ADC_Prescaler_8				0b00000011
#define ADC_Prescaler_16			0b00000100
#define ADC_Prescaler_32			0b00000101
#define ADC_Prescaler_64			0b00000110
#define ADC_Prescaler_128			0b00000111
//
#define ADC_Prescaler_Selected		ADC_Prescaler_64
#define ADC_Prescaler_Value			64

/*=========================================================
 * Reference Selection Bits
 *=========================================================*/
#define ADC_VoltRef_AREF			0b00000000
#define ADC_VoltRef_AVCC			0b01000000
#define ADC_VoltRef_2_56V			0b11000000
//selected voltage reference for the ADC
#define ADC_VoltRef_Selected		ADC_VoltRef_AVCC

/*=========================================================
 * ADC Left Adjust Result
 *=========================================================*/
#define ADC_RightAdjust				0b00000000
#define ADC_LeftAdjust				0b00100000
//selected presentation of the ADC conversion result in the ADC Data Register
#define ADC_Adjust_Selected			ADC_RightAdjust

/*=========================================================
 * ADC Auto Trigger Enable
 *=========================================================*/
#define ADC_SingleConversion		0b00000000
#define ADC_AutoTrigging			0b00100000
//selected mode for ADC
#define ADC_Mode_Selected			ADC_SingleConversion

/*=========================================================
 * ADC Auto Trigger Source
 *=========================================================*/
#define ADC_Trigger_Free_Running_mode			0b00000000
#define ADC_Trigger_Analog_Comparator			0b00100000
#define ADC_Trigger_Exti0						0b01000000
#define ADC_Trigger_Timer0Comp					0b01100000
#define ADC_Trigger_Timer0OVF					0b10000000
#define ADC_Trigger_Timer1CompB					0b10100000
#define ADC_Trigger_Timer1OVF					0b11000000
#define ADC_Trigger_Timer1CAPT					0b11100000
//select auto trigger source for the ADC
#define ADC_Trigger_Selected					ADC_Trigger_Free_Running_mode

#define ADC_VoltRef_mv 							5000

/*--------------------------
 * choose between 255, 1023
 * --------------------------*/
#define ADC_TOTAL_STEPS							1023

#endif /* ADC_CFG_H_ */
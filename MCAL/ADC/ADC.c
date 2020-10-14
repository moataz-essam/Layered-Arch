/*
 * ADC.c
 *
 * Created: 9/21/2020 9:10:41 PM
 *  Author: Moataz
 */ 

#include "../../utils/BitMath.h"
#include "../../utils/interrupts.h"
#include "ADC.h"


void ADC_init(ADC_Ch_type channel)
{
	//setting direction of selected ADC channel
	SET_BIT(ADC_PORT_DIR,channel);
	
	//turn on the ADC module
	SET_BIT(ADCSRA,ADEN);
	
	//select conversion speed (prescaler)
	CLR_BIT(ADCSRA,ADPS0);
	CLR_BIT(ADCSRA,ADPS1);
	CLR_BIT(ADCSRA,ADPS2);
	ADCSRA |= ADC_Prescaler_Selected;
	
	//select voltage reference
	CLR_BIT(ADMUX,REFS0);
	CLR_BIT(ADMUX,REFS1);
	ADMUX |= ADC_VoltRef_Selected;
	
	//select the adjust of the ADC conversion result in the ADC Data Register(right or left)
	CLR_BIT(ADMUX,ADLAR);
	ADMUX |= ADC_Adjust_Selected;
	
	//mode selected for ADC
	CLR_BIT(ADCSRA,ADATE);
	ADCSRA |= ADC_Mode_Selected;
	
#if ADC_Mode_Selected==ADC_AutoTrigging
	CLR_BIT(SFIOR,RESERVED);
	CLR_BIT(SFIOR,ADTS0);
	CLR_BIT(SFIOR,ADTS1);
	CLR_BIT(SFIOR,ADTS2);
	SFIOR |= ADC_Trigger_Selected;
#endif
	//select ADC input channels
	CLR_BIT(ADMUX,MUX0);
	CLR_BIT(ADMUX,MUX1);
	CLR_BIT(ADMUX,MUX2);
	CLR_BIT(ADMUX,MUX3);
	CLR_BIT(ADMUX,MUX4);
	ADMUX |= channel;
	
	//start conversion
	SET_BIT(ADCSRA,ADSC);
}

uint16 ADC_ReadChannel(ADC_Ch_type channel)
{
	/***start conversion if ADC mode is single conversion***/
#if ADC_Mode_Selected == ADC_SingleConversion
	/* ADC Selection */
	CLR_BIT(ADMUX,MUX0);
	CLR_BIT(ADMUX,MUX1);
	CLR_BIT(ADMUX,MUX2);
	CLR_BIT(ADMUX,MUX3);
	CLR_BIT(ADMUX,MUX4);
	ADMUX |= channel;
	/* Start Conversion */
	SET_BIT(ADCSRA,ADSC);
#endif
	/*wait until conversion is done */
	while((GET_BIT(ADCSRA,ADIF)) == 0)
	{
		;
	}
	return ADC;
}

void ADC_INT_EN(void)
{
	GLOBAL_INT_EN;
	SET_BIT(ADCSRA,ADIE);
}

void ADC_INT_DIS(void)
{
	CLR_BIT(ADCSRA,ADIE);
}

uint16 ADC_getVoltage_mv(ADC_Ch_type channel)
{
	uint16 StepsNum,InputVolt;
	StepsNum = ADC_ReadChannel(channel);
	InputVolt = StepsNum*(ADC_VoltRef_mv/ADC_TOTAL_STEPS);
	return InputVolt;
}
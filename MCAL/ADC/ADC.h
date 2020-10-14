/*
 * ADC.h
 *
 * Created: 9/21/2020 9:10:08 PM
 *  Author: Moataz
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "ADC_HW.h"
#include "ADC_types.h"
#include "../../config/ADC_cfg.h"

void ADC_init(ADC_Ch_type channel);
uint16 ADC_ReadChannel(ADC_Ch_type channel);
void ADC_INT_EN(void);
void ADC_INT_DIS(void);
uint16 ADC_getVoltage_mv(ADC_Ch_type channel);

#endif /* ADC_H_ */
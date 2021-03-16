/*
 * libADC.c
 *
 *  Created on: Mar 16, 2021
 *      Author: sacmq
 */
#include "main.h"



void ADC_Pin_Config(int Port){
	switch(Port){
	case 0:
		GPIOA->MODER &= 0xFFFFFF00;
		GPIOA->MODER |= 0x00000003;
		GPIOA->ASCR &= 0xFFFFFFFE;
		GPIOA->ASCR |= 0x00000001;
		break;
	default:
		break;

	}
}

int AnalogRead(ADC_HandleTypeDef hadc1){
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
	int Vol = HAL_ADC_GetValue(&hadc1);
	return Vol;
}

/*

File:   adc-handler.h
Author: Isaac Pawley

*/

#ifndef INC_ADC_HANDLER_H_
#define INC_ADC_HANDLER_H_

#include <stdint.h>
#include <stdbool.h>
#include "adc.h"

typedef enum {
    ADC_CAP_VOLT,
    ADC_RANDOM,
    NUMBER_OF_ADC_INPUTS
} ADC_Input_t;

void adc_handler_init(void);
uint16_t adc_handler_getValue(ADC_Input_t input);
bool adc_handler_isReady(void);

#endif /* INC_ADC_HANDLER_H_ */
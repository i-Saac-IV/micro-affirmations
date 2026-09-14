/*

File:   adc-handler.c
Author: Isaac Pawley

*/

#include "adc_handler.h"

static uint16_t adc_values[NUMBER_OF_ADC_INPUTS];
volatile bool adc_ready = false;

void adc_handler_start(void) {
    adc_ready = false;
    HAL_ADC_Start_DMA(&hadc1, (uint32_t*)adc_values, NUMBER_OF_ADC_INPUTS);
}

uint16_t adc_handler_getValue(ADC_Input_t input) {
    return adc_values[input];
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc) {
    if (hadc->Instance == ADC1) {
        adc_ready = true;
    }
}

bool adc_handler_isReady(void) {
    return adc_ready;
}
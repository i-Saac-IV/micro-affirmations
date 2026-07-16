/*

File:   app.h
Author: Isaac Pawley

*/

#include "app.h"

#include "adc.h"
#include "stm32c0xx_hal.h"

typedef enum
{
    ADC_RANDOM,
    ADC_CAP_VOLT
} ADC_Input_t;

uint16_t ADC_Read(ADC_Input_t input)
{
    uint16_t random_value = 0;
    uint16_t cap_voltage_value = 0;

    HAL_ADC_Start(&hadc1);

    // Rank 1: PA1 RANDOM
    if (HAL_ADC_PollForConversion(&hadc1, 10) == HAL_OK)
    {
        random_value = HAL_ADC_GetValue(&hadc1);
    }

    // Rank 2: PB7 CAP_VOLT
    if (HAL_ADC_PollForConversion(&hadc1, 10) == HAL_OK)
    {
        cap_voltage_value = HAL_ADC_GetValue(&hadc1);
    }

    HAL_ADC_Stop(&hadc1);

    if (input == ADC_RANDOM)
    {
        return random_value;
    }
    else
    {
        return cap_voltage_value;
    }
}

#include "matrix.h"
#include "nanoGL.h"

void app_main(void) {

    char c = ' ';

    uint32_t now = 0;
    uint32_t next = 0;

    nanoGL_clear();

    while (1) {

        if (HAL_GetTick() > next) {
            next = HAL_GetTick() + 250;
            nanoGL_clear();
            char str[3] = { c, '|', '\0' };
            nanoGL_drawString(0, 0, str, &Font_5x5);

            c++;

            // wrap back to space after '~'
            if (c > '~') {
                c = ' ';
            }
        }

        matrix_updateMultiplex();

        now = HAL_GetTick();
        while (HAL_GetTick() < now + 1) {};
    }    
}
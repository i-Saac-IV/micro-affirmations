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
#include "messages.h"

void app_main(void) {

    uint32_t now = 0;
    uint32_t next = 0;

    nanoGL_clear();

    static int16_t scrollX = PHYSICAL_COLS;

    while (1) {
        matrix_updateMultiplex();

        if (HAL_GetTick() > next) {
            next = HAL_GetTick() + 75;
            nanoGL_clear();

            nanoGL_drawString(scrollX, 0, messages[2], &Font_5x5);
            scrollX--;
            
            if (scrollX < -nanoGL_stringWidth(messages[2], &Font_5x5)) {
                scrollX = PHYSICAL_COLS;
            }
        }

        now = HAL_GetTick();
        while (HAL_GetTick() < now + 1) {};
    }    
}
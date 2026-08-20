/*

File:   app.h
Author: Isaac Pawley

*/

#include "app.h"

#include "adc.h"
#include "stm32c0xx_hal.h"

#define DEBUG_ENABLED 0

#define STM_VCC         3.6f
#define ADC_BITS        4095.0f
#define MAX_CAP_VOLTAGE 2.1f

typedef enum {
    ADC_RANDOM,
    ADC_CAP_VOLT
} ADC_Input_t;

uint16_t ADC_Read(ADC_Input_t input) {
    uint16_t random_value = 0;
    uint16_t cap_voltage_value = 0;

    HAL_ADC_Start(&hadc1);

    if (HAL_ADC_PollForConversion(&hadc1, 10) == HAL_OK) {
        cap_voltage_value = HAL_ADC_GetValue(&hadc1);
    }

    if (HAL_ADC_PollForConversion(&hadc1, 10) == HAL_OK) {
        random_value = HAL_ADC_GetValue(&hadc1);
    }

    HAL_ADC_Stop(&hadc1);

    if (input == ADC_RANDOM) {
        return random_value;
    } else {
        return cap_voltage_value;
    }
}

void enter_shutdown(void) {
    __HAL_RCC_PWR_CLK_ENABLE();
    __HAL_PWR_CLEAR_FLAG(PWR_FLAG_WUF);
    
    HAL_PWREx_EnterSHUTDOWNMode();
}

#include "matrix.h"
#include "nanoGL.h"
#include "messages.h"

void app_updateMultiplex(void) {
    matrix_updateMultiplex();
}

#include "bitmaps.h"

void app_main(void) {
    nanoGL_clear();

    size_t message_index = ADC_Read(ADC_RANDOM) % number_of_messages;

    uint32_t next_text_shift_ms = 0;

    static int16_t scrollX = PHYSICAL_COLS;

    while (HAL_GPIO_ReadPin(CHARGE_SENSE_GPIO_Port, CHARGE_SENSE_Pin)) {
        if (HAL_GetTick() >= next_text_shift_ms) {
        next_text_shift_ms = HAL_GetTick() + 1000;

        uint16_t capacitor_voltage = ADC_Read(ADC_CAP_VOLT);

        float voltage = capacitor_voltage * STM_VCC / ADC_BITS;
        float width = (voltage - 0.6f) * (PHYSICAL_COLS - 2) / MAX_CAP_VOLTAGE;
        
        if (width < 0.0f) {
            width = 0.0f;
        }

        if (width > 18.0f) {
            width = 18.0f;
        }

        __disable_irq();

        nanoGL_clear();

        nanoGL_drawBitmap(0, 0, battery_20x5, 20, 5);
        nanoGL_drawFilledRectangle(0, 1, width, 3);

        __enable_irq();
    }
    }

    while (1) {
        if (HAL_GetTick() > next_text_shift_ms) {
            next_text_shift_ms = HAL_GetTick() + 50;
            nanoGL_clear();

            nanoGL_drawString(scrollX, 0, messages[message_index], &Font_5x5);
            scrollX--;
            
            if (scrollX < -nanoGL_stringWidth(messages[message_index], &Font_5x5)) {
                if (DEBUG_ENABLED) {
                    message_index = ADC_Read(ADC_RANDOM) % number_of_messages;
                    scrollX = PHYSICAL_COLS;
                } else {
                    enter_shutdown();
                }               
            }
        }
    }    
}
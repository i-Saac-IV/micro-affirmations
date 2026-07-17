/*

File:   app.h
Author: Isaac Pawley

*/

#include "app.h"

#include "adc.h"
#include "stm32c0xx_hal.h"

typedef enum {
    ADC_RANDOM,
    ADC_CAP_VOLT
} ADC_Input_t;

uint16_t ADC_Read(ADC_Input_t input) {
    uint16_t random_value = 0;
    uint16_t cap_voltage_value = 0;

    HAL_ADC_Start(&hadc1);

    if (HAL_ADC_PollForConversion(&hadc1, 10) == HAL_OK) {
        random_value = HAL_ADC_GetValue(&hadc1);
    }

    if (HAL_ADC_PollForConversion(&hadc1, 10) == HAL_OK) {
        cap_voltage_value = HAL_ADC_GetValue(&hadc1);
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

void app_main(void) {

    size_t message_index = ADC_Read(ADC_RANDOM) % number_of_messages;

    uint32_t last_frame_end_ms = 0;
    uint32_t next_text_shift_ms = 0;

    nanoGL_clear();

    static int16_t scrollX = PHYSICAL_COLS;

    if (HAL_GPIO_ReadPin(CHARGE_SENSE_GPIO_Port, CHARGE_SENSE_Pin)) {
        
    }

    while (1) {
        matrix_updateMultiplex();
        last_frame_end_ms = HAL_GetTick();

        if (HAL_GetTick() > next_text_shift_ms) {
            next_text_shift_ms = HAL_GetTick() + 50;
            nanoGL_clear();

            nanoGL_drawString(scrollX, 0, messages[message_index], &Font_5x5);
            scrollX--;
            
            if (scrollX < -nanoGL_stringWidth(messages[message_index], &Font_5x5)) {
                message_index = ADC_Read(ADC_RANDOM) % number_of_messages;
                scrollX = PHYSICAL_COLS;
            }
        }

        while (HAL_GetTick() < last_frame_end_ms + 1) {};
    }    
}
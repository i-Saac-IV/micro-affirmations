/*

File:   app.h
Author: Isaac Pawley

*/

#include "app.h"

#include "adc.h"
#include "stm32c0xx_hal.h"

#define DEBUG_ENABLED 0

void enter_shutdown(void) {
    __HAL_RCC_PWR_CLK_ENABLE();
    __HAL_PWR_CLEAR_FLAG(PWR_FLAG_WUF);
    
    HAL_PWREx_EnterSHUTDOWNMode();
}

#include "nanoGL.h"
#include "matrix.h"
#include "messages.h"
#include "bitmaps.h"
#include "adc_handler.h"
#include "capacitor.h"

void app_updateMultiplex(void) {
    matrix_updateMultiplex();
}

void app_main(void) {
    nanoGL_clear();
    adc_handler_start();

    while (!adc_handler_isReady()) {
        // wait...
    }

    size_t message_index = adc_handler_getValue(ADC_RANDOM) % number_of_messages;

    uint32_t next_update_ms = 0;

    static int16_t scrollX = PHYSICAL_COLS;

    while (HAL_GPIO_ReadPin(CHARGE_SENSE_GPIO_Port, CHARGE_SENSE_Pin)) {
        if (HAL_GetTick() >= next_update_ms) {
            next_update_ms = HAL_GetTick() + 1000;
            adc_handler_start();
            capacitor_update();
        }
    }

    while (1) {
        if (HAL_GetTick() > next_update_ms) {
            next_update_ms = HAL_GetTick() + 50;
            nanoGL_clear();

            nanoGL_drawString(scrollX, 0, messages[message_index], &Font_5x5);
            scrollX--;
            
            if (scrollX < -nanoGL_stringWidth(messages[message_index], &Font_5x5)) {
                if (DEBUG_ENABLED) {
                    message_index = adc_handler_getValue(ADC_RANDOM) % number_of_messages;
                    scrollX = PHYSICAL_COLS;
                } else {
                    adc_handler_start();
                    capacitor_update();

                    HAL_Delay(1500);

                    enter_shutdown();
                }               
            }
        }
    }    
}
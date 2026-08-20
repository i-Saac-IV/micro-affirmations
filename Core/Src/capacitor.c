/*

File:   capacitor.c
Author: Isaac Pawley

*/

#include "capacitor.h"

#include "adc_handler.h"
#include "matrix.h"
#include "bitmaps.h"
#include "nanoGL.h"
#include "stm32c0xx_hal.h"
#include <stdint.h>

#define STM_VCC         3.6f
#define ADC_BITS        4095.0f
#define MAX_CAP_VOLTAGE 2.1f

void capacitor_update(void) {
    uint16_t capacitor_voltage = adc_handler_getValue(ADC_CAP_VOLT);

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
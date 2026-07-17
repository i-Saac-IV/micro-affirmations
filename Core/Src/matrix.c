/*

File:   matrix.h
Author: Isaac Pawley

*/

#include "matrix.h"

#include "stm32c0xx_hal.h"
#include "gpio.h"

#define ELECTRICAL_ROWS 10
#define ELECTRICAL_COLS 10

MatrixBrightness_t frame[ELECTRICAL_ROWS][ELECTRICAL_COLS] = {0};

typedef struct {
	GPIO_TypeDef* const port;
	const uint16_t pin;
	const GPIO_PinState activeState;
} LedPinConfig_t;

LedPinConfig_t rows[ELECTRICAL_ROWS] = {
    {MATRIX_A0_GPIO_Port, MATRIX_A0_Pin, GPIO_PIN_SET},
    {MATRIX_A1_GPIO_Port, MATRIX_A1_Pin, GPIO_PIN_SET},
    {MATRIX_A2_GPIO_Port, MATRIX_A2_Pin, GPIO_PIN_SET},
    {MATRIX_A3_GPIO_Port, MATRIX_A3_Pin, GPIO_PIN_SET},
    {MATRIX_A4_GPIO_Port, MATRIX_A4_Pin, GPIO_PIN_SET},
    {MATRIX_A5_GPIO_Port, MATRIX_A5_Pin, GPIO_PIN_SET},
    {MATRIX_A6_GPIO_Port, MATRIX_A6_Pin, GPIO_PIN_SET},
    {MATRIX_A7_GPIO_Port, MATRIX_A7_Pin, GPIO_PIN_SET},
    {MATRIX_A8_GPIO_Port, MATRIX_A8_Pin, GPIO_PIN_SET},
    {MATRIX_A9_GPIO_Port, MATRIX_A9_Pin, GPIO_PIN_SET}
};

LedPinConfig_t columns[ELECTRICAL_COLS] = {
    {MATRIX_K0_GPIO_Port, MATRIX_K0_Pin, GPIO_PIN_RESET},
    {MATRIX_K1_GPIO_Port, MATRIX_K1_Pin, GPIO_PIN_RESET},
    {MATRIX_K2_GPIO_Port, MATRIX_K2_Pin, GPIO_PIN_RESET},
    {MATRIX_K3_GPIO_Port, MATRIX_K3_Pin, GPIO_PIN_RESET},
    {MATRIX_K4_GPIO_Port, MATRIX_K4_Pin, GPIO_PIN_RESET},
    {MATRIX_K5_GPIO_Port, MATRIX_K5_Pin, GPIO_PIN_RESET},
    {MATRIX_K6_GPIO_Port, MATRIX_K6_Pin, GPIO_PIN_RESET},
    {MATRIX_K7_GPIO_Port, MATRIX_K7_Pin, GPIO_PIN_RESET},
    {MATRIX_K8_GPIO_Port, MATRIX_K8_Pin, GPIO_PIN_RESET},
    {MATRIX_K9_GPIO_Port, MATRIX_K9_Pin, GPIO_PIN_RESET}
};

void matrix_setPixel(int16_t physX, int16_t physY, MatrixBrightness_t value) {
    if (physX >= PHYSICAL_COLS || physY >= PHYSICAL_ROWS || physX < 0 || physY < 0) {
        return;
    }

    uint8_t elecRow = 0;
    uint8_t elecCol = 0;

    if (physX < 10) {
        elecRow = physY;
        elecCol = physX;
    } else {
        elecRow = physY + 5;
        elecCol = 19 - physX;
    }

    frame[elecRow][elecCol] = value;
}


void matrix_updateMultiplex(void) {
    static uint8_t currentElecRow = 0;

    HAL_GPIO_WritePin(rows[currentElecRow].port, rows[currentElecRow].pin, rows[currentElecRow].activeState == GPIO_PIN_SET ? GPIO_PIN_RESET : GPIO_PIN_SET);

    currentElecRow++;
    if (currentElecRow >= ELECTRICAL_ROWS) {
        currentElecRow = 0;
    }

    for (uint8_t col = 0; col < ELECTRICAL_COLS; col++) {
        GPIO_PinState state;
        
        if (frame[currentElecRow][col] == MATRIX_ON) {
            state = columns[col].activeState;
        } else {
            state = (columns[col].activeState == GPIO_PIN_SET) ? GPIO_PIN_RESET : GPIO_PIN_SET;
        }
        
        HAL_GPIO_WritePin(columns[col].port, columns[col].pin, state);
    }

    HAL_GPIO_WritePin(rows[currentElecRow].port, rows[currentElecRow].pin, rows[currentElecRow].activeState);
}



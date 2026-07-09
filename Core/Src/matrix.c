/*

File:   matrix.h
Author: Isaac Pawley

*/

#include "matrix.h"

#include "stm32c0xx_hal.h"

typedef enum {
    MATRIX_K0,
    MATRIX_K1,
    MATRIX_K2,
    MATRIX_K3,
    MATRIX_K4,
    MATRIX_K5,
    MATRIX_K6,
    MATRIX_K7,
    MATRIX_K8,
    MATRIX_K9,
    NUM_CATHODES
} matrixCathodes;

typedef enum {
    MATRIX_A0,
    MATRIX_A1,
    MATRIX_A2,
    MATRIX_A3,
    MATRIX_A4,
    MATRIX_A5,
    MATRIX_A6,
    MATRIX_A7,
    MATRIX_A8,
    MATRIX_A9,
    NUM_ANODES
} matrixAnodes;

typedef struct {
	GPIO_TypeDef* const port;
	const uint16_t pin;
	const GPIO_PinState activeState;
} matrix_t;
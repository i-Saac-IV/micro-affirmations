/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, MATRIX_K9_Pin|MATRIX_K8_Pin|MATRIX_K7_Pin|MATRIX_K6_Pin
                          |MATRIX_K5_Pin|MATRIX_A6_Pin|MATRIX_A5_Pin|MATRIX_A2_Pin
                          |MATRIX_A1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, MATRIX_K4_Pin|MATRIX_K3_Pin|MATRIX_K2_Pin|MATRIX_K1_Pin
                          |MATRIX_K0_Pin|MATRIX_A9_Pin|MATRIX_A8_Pin|MATRIX_A7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, MATRIX_A4_Pin|MATRIX_A3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(MATRIX_A0_GPIO_Port, MATRIX_A0_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : CHARGE_SENSE_Pin */
  GPIO_InitStruct.Pin = CHARGE_SENSE_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(CHARGE_SENSE_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : MATRIX_K9_Pin MATRIX_K8_Pin MATRIX_K7_Pin MATRIX_K6_Pin
                           MATRIX_K5_Pin MATRIX_A6_Pin MATRIX_A5_Pin MATRIX_A2_Pin
                           MATRIX_A1_Pin */
  GPIO_InitStruct.Pin = MATRIX_K9_Pin|MATRIX_K8_Pin|MATRIX_K7_Pin|MATRIX_K6_Pin
                          |MATRIX_K5_Pin|MATRIX_A6_Pin|MATRIX_A5_Pin|MATRIX_A2_Pin
                          |MATRIX_A1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : MATRIX_K4_Pin MATRIX_K3_Pin MATRIX_K2_Pin MATRIX_K1_Pin
                           MATRIX_K0_Pin MATRIX_A9_Pin MATRIX_A8_Pin MATRIX_A7_Pin */
  GPIO_InitStruct.Pin = MATRIX_K4_Pin|MATRIX_K3_Pin|MATRIX_K2_Pin|MATRIX_K1_Pin
                          |MATRIX_K0_Pin|MATRIX_A9_Pin|MATRIX_A8_Pin|MATRIX_A7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : MATRIX_A4_Pin MATRIX_A3_Pin */
  GPIO_InitStruct.Pin = MATRIX_A4_Pin|MATRIX_A3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : MATRIX_A0_Pin */
  GPIO_InitStruct.Pin = MATRIX_A0_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(MATRIX_A0_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */

/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32c0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define CHARGE_SENSE_Pin GPIO_PIN_3
#define CHARGE_SENSE_GPIO_Port GPIOF
#define CAP_VOLT_Pin GPIO_PIN_0
#define CAP_VOLT_GPIO_Port GPIOA
#define RANDOM_Pin GPIO_PIN_1
#define RANDOM_GPIO_Port GPIOA
#define MATRIX_K9_Pin GPIO_PIN_3
#define MATRIX_K9_GPIO_Port GPIOA
#define MATRIX_K8_Pin GPIO_PIN_4
#define MATRIX_K8_GPIO_Port GPIOA
#define MATRIX_K7_Pin GPIO_PIN_5
#define MATRIX_K7_GPIO_Port GPIOA
#define MATRIX_K6_Pin GPIO_PIN_6
#define MATRIX_K6_GPIO_Port GPIOA
#define MATRIX_K5_Pin GPIO_PIN_7
#define MATRIX_K5_GPIO_Port GPIOA
#define MATRIX_K4_Pin GPIO_PIN_0
#define MATRIX_K4_GPIO_Port GPIOB
#define MATRIX_K3_Pin GPIO_PIN_1
#define MATRIX_K3_GPIO_Port GPIOB
#define MATRIX_K2_Pin GPIO_PIN_2
#define MATRIX_K2_GPIO_Port GPIOB
#define MATRIX_K1_Pin GPIO_PIN_10
#define MATRIX_K1_GPIO_Port GPIOB
#define MATRIX_K0_Pin GPIO_PIN_11
#define MATRIX_K0_GPIO_Port GPIOB
#define MATRIX_A9_Pin GPIO_PIN_13
#define MATRIX_A9_GPIO_Port GPIOB
#define MATRIX_A8_Pin GPIO_PIN_14
#define MATRIX_A8_GPIO_Port GPIOB
#define MATRIX_A7_Pin GPIO_PIN_15
#define MATRIX_A7_GPIO_Port GPIOB
#define MATRIX_A6_Pin GPIO_PIN_8
#define MATRIX_A6_GPIO_Port GPIOA
#define MATRIX_A5_Pin GPIO_PIN_9
#define MATRIX_A5_GPIO_Port GPIOA
#define MATRIX_A4_Pin GPIO_PIN_6
#define MATRIX_A4_GPIO_Port GPIOC
#define MATRIX_A3_Pin GPIO_PIN_7
#define MATRIX_A3_GPIO_Port GPIOC
#define MATRIX_A2_Pin GPIO_PIN_10
#define MATRIX_A2_GPIO_Port GPIOA
#define MATRIX_A1_Pin GPIO_PIN_15
#define MATRIX_A1_GPIO_Port GPIOA
#define MATRIX_A0_Pin GPIO_PIN_0
#define MATRIX_A0_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

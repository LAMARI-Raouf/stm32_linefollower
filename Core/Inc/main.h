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
#include "stm32f4xx_hal.h"

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
#define QTR_0_Pin GPIO_PIN_0
#define QTR_0_GPIO_Port GPIOA
#define QTR_1_Pin GPIO_PIN_1
#define QTR_1_GPIO_Port GPIOA
#define QTR_2_Pin GPIO_PIN_2
#define QTR_2_GPIO_Port GPIOA
#define QTR_3_Pin GPIO_PIN_3
#define QTR_3_GPIO_Port GPIOA
#define QTR_4_Pin GPIO_PIN_4
#define QTR_4_GPIO_Port GPIOA
#define QTR_5_Pin GPIO_PIN_5
#define QTR_5_GPIO_Port GPIOA
#define QTR_6_Pin GPIO_PIN_6
#define QTR_6_GPIO_Port GPIOA
#define QTR_7_Pin GPIO_PIN_7
#define QTR_7_GPIO_Port GPIOA
#define PWM_A_Pin GPIO_PIN_10
#define PWM_A_GPIO_Port GPIOA
#define AN1_Pin GPIO_PIN_11
#define AN1_GPIO_Port GPIOA
#define AN2_Pin GPIO_PIN_12
#define AN2_GPIO_Port GPIOA
#define BN1_Pin GPIO_PIN_3
#define BN1_GPIO_Port GPIOB
#define BN2_Pin GPIO_PIN_4
#define BN2_GPIO_Port GPIOB
#define PWM_B_Pin GPIO_PIN_5
#define PWM_B_GPIO_Port GPIOB
#define IMU_SCL_Pin GPIO_PIN_6
#define IMU_SCL_GPIO_Port GPIOB
#define IMU_SDA_Pin GPIO_PIN_7
#define IMU_SDA_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
#define TIMER_CLOCK 96000000UL

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

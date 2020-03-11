/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
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
#include "stm32f7xx_hal.h"

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
#define LCD_EN_Pin GPIO_PIN_13
#define LCD_EN_GPIO_Port GPIOC
#define LCD_D0_Pin GPIO_PIN_0
#define LCD_D0_GPIO_Port GPIOC
#define LCD_D1_Pin GPIO_PIN_1
#define LCD_D1_GPIO_Port GPIOC
#define LCD_D2_Pin GPIO_PIN_2
#define LCD_D2_GPIO_Port GPIOC
#define LCD_D3_Pin GPIO_PIN_3
#define LCD_D3_GPIO_Port GPIOC
#define ADC1_VMEAS_Pin GPIO_PIN_0
#define ADC1_VMEAS_GPIO_Port GPIOA
#define ADC2_IMEAS_Pin GPIO_PIN_1
#define ADC2_IMEAS_GPIO_Port GPIOA
#define ADC3_VIN_Pin GPIO_PIN_2
#define ADC3_VIN_GPIO_Port GPIOA
#define VDAC_Pin GPIO_PIN_4
#define VDAC_GPIO_Port GPIOA
#define IDAC_Pin GPIO_PIN_5
#define IDAC_GPIO_Port GPIOA
#define Push1_Pin GPIO_PIN_0
#define Push1_GPIO_Port GPIOB
#define Push2_Pin GPIO_PIN_1
#define Push2_GPIO_Port GPIOB
#define LCD_D5_Pin GPIO_PIN_6
#define LCD_D5_GPIO_Port GPIOC
#define LCD_D6_Pin GPIO_PIN_7
#define LCD_D6_GPIO_Port GPIOC
#define LCD_D7_Pin GPIO_PIN_8
#define LCD_D7_GPIO_Port GPIOC
#define LCD_RS_Pin GPIO_PIN_9
#define LCD_RS_GPIO_Port GPIOC
#define LCD_C2_Pin GPIO_PIN_11
#define LCD_C2_GPIO_Port GPIOA
#define LCD_C1_Pin GPIO_PIN_12
#define LCD_C1_GPIO_Port GPIOA
#define LCD_RW_Pin GPIO_PIN_12
#define LCD_RW_GPIO_Port GPIOC
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

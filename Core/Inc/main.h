/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#define PRESSURE_MEAS_ADC1_Pin GPIO_PIN_0
#define PRESSURE_MEAS_ADC1_GPIO_Port GPIOA
#define BUTTON1_Pin GPIO_PIN_0
#define BUTTON1_GPIO_Port GPIOB
#define BUTTON2_Pin GPIO_PIN_1
#define BUTTON2_GPIO_Port GPIOB
#define EEROM_I2C2_SCL_Pin GPIO_PIN_10
#define EEROM_I2C2_SCL_GPIO_Port GPIOB
#define TEMP_SPI2_CS_Pin GPIO_PIN_12
#define TEMP_SPI2_CS_GPIO_Port GPIOB
#define TEMP_SPI2_SCK_Pin GPIO_PIN_13
#define TEMP_SPI2_SCK_GPIO_Port GPIOB
#define TEMP_SPI2_MISO_Pin GPIO_PIN_14
#define TEMP_SPI2_MISO_GPIO_Port GPIOB
#define CONTROL_VALVE_Pin GPIO_PIN_9
#define CONTROL_VALVE_GPIO_Port GPIOC
#define CONTROL_PUMP_Pin GPIO_PIN_8
#define CONTROL_PUMP_GPIO_Port GPIOA
#define CONTROL_HEATER_Pin GPIO_PIN_9
#define CONTROL_HEATER_GPIO_Port GPIOA
#define ZERO_CROSS_DET_Pin GPIO_PIN_10
#define ZERO_CROSS_DET_GPIO_Port GPIOA
#define DISPLAY_SPI3_NSS_Pin GPIO_PIN_15
#define DISPLAY_SPI3_NSS_GPIO_Port GPIOA
#define DISPLAY_SPI3_SCK_Pin GPIO_PIN_10
#define DISPLAY_SPI3_SCK_GPIO_Port GPIOC
#define DISPLAY_SPI3_MISO_Pin GPIO_PIN_11
#define DISPLAY_SPI3_MISO_GPIO_Port GPIOC
#define DISPLAY_SPI3_MOSI_Pin GPIO_PIN_12
#define DISPLAY_SPI3_MOSI_GPIO_Port GPIOC
#define DISPLAY_RESET_Pin GPIO_PIN_2
#define DISPLAY_RESET_GPIO_Port GPIOD
#define TOUCH_RESET_Pin GPIO_PIN_4
#define TOUCH_RESET_GPIO_Port GPIOB
#define TOUCH_INT_Pin GPIO_PIN_5
#define TOUCH_INT_GPIO_Port GPIOB
#define TOUCH_I2C1_SCL_Pin GPIO_PIN_6
#define TOUCH_I2C1_SCL_GPIO_Port GPIOB
#define TOUCH_I2C1_SDA_Pin GPIO_PIN_7
#define TOUCH_I2C1_SDA_GPIO_Port GPIOB
#define DISPLAY_DC_Pin GPIO_PIN_8
#define DISPLAY_DC_GPIO_Port GPIOB
#define EEPROM_I2C2_SDA_Pin GPIO_PIN_9
#define EEPROM_I2C2_SDA_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

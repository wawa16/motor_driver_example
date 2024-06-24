/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
#include "main.h"
#include "drv8701p.h"

// Initialized once, used within this module only
static uint32_t lastUpdateTime = 0;

/* Private variables ---------------------------------------------------------*/
// TIM_HandleTypeDef htim2;

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* MCU-specific Configuration----------------------*/
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_TIM2_Init();

  while (1)
  {
      uint32_t currentTime = HAL_GetTick();  // ms

      if (currentTime - lastUpdateTime >= 1) {

          // This function is called at 1khz by the application as required
          drv8701p_elapse_1ms();

          lastUpdateTime = currentTime; // Update the last update time
      }
  }
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
    /*Not within the scope of our assignment.
    Meant to be an example configuration that may need tweaking, all auto-generated and commented out.*/

  //RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  //RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  ///** Configure the main internal regulator output voltage
  //*/
  //__HAL_RCC_PWR_CLK_ENABLE();
  //__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  ///** Initializes the RCC Oscillators according to the specified parameters
  //* in the RCC_OscInitTypeDef structure.
  //*/
  //RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  //RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  //RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  //RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  //RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  //RCC_OscInitStruct.PLL.PLLM = 8;
  //RCC_OscInitStruct.PLL.PLLN = 84;
  //RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  //RCC_OscInitStruct.PLL.PLLQ = 2;
  //RCC_OscInitStruct.PLL.PLLR = 2;
  //if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  //{
  //  Error_Handler();
  //}

  ///** Initializes the CPU, AHB and APB buses clocks
  //*/
  //RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
  //                            |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  //RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  //RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  //RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  //RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  //if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  //{
  //  Error_Handler();
  //}
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{
    /*Not within the scope of our assignment.
    Meant to be an example configuration that may need tweaking, all auto-generated and commented out.*/

 /* TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};
   
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9999;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  HAL_TIM_MspPostInit(&htim2);*/
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
    /*Not within the scope of our assignment.
    Meant to be an example configuration that may need tweaking, all auto-generated and commented out.*/

  //GPIO_InitTypeDef GPIO_InitStruct = {0};

  ///* GPIO Ports Clock Enable */
  //__HAL_RCC_GPIOA_CLK_ENABLE();

  ///*Configure GPIO pin Output Level */
  //HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);

  ///*Configure GPIO pin : PA2 */
  //GPIO_InitStruct.Pin = GPIO_PIN_2;
  //GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  //GPIO_InitStruct.Pull = GPIO_NOPULL;
  //GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  //HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
}


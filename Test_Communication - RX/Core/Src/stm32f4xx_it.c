/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f4xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim5;
extern TIM_HandleTypeDef htim6;
extern TIM_HandleTypeDef htim7;
extern TIM_HandleTypeDef htim9;
extern DMA_HandleTypeDef hdma_usart1_rx;
extern DMA_HandleTypeDef hdma_usart1_tx;
extern DMA_HandleTypeDef hdma_usart2_rx;
extern DMA_HandleTypeDef hdma_usart2_tx;
extern DMA_HandleTypeDef hdma_usart3_rx;
extern DMA_HandleTypeDef hdma_usart3_tx;
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;
extern TIM_HandleTypeDef htim1;

/* USER CODE BEGIN EV */

extern uint8_t UART1_Rx_Buffer[UART1_RX_BUF_SIZE];  /* USART接收数据存储空间 */
extern uint8_t UART1_RX_FLAG;
extern uint8_t UART1_RX_LEN;  /* 接收数据帧大小 */


extern uint8_t UART2_Rx_Buffer[UART1_RX_BUF_SIZE];  /* USART接收数据存储空间 */
extern uint8_t UART2_RX_FLAG;
extern uint8_t UART2_RX_LEN;  /* 接收数据帧大小 */

extern uint8_t UART3_Rx_Buffer[UART1_RX_BUF_SIZE];  /* USART接收数据存储空间 */
extern uint8_t UART3_RX_FLAG;
extern uint8_t UART3_RX_LEN;  /* 接收数据帧大小 */

extern uint8_t MSG1;     
extern uint8_t MSG2; 
extern uint8_t MSG3; 
extern uint8_t MSG4;     
extern uint8_t MSG5; 
extern uint8_t MSG6;
extern uint8_t MSG101;     
extern uint8_t MSG102; 
extern uint8_t MSG103; 
extern uint8_t MSG104;     
extern uint8_t MSG105; 
extern uint8_t MSG106;
extern uint8_t MSG107; 
extern uint8_t MSG108; 
extern uint8_t MSG109;     
extern uint8_t MSG110; 
extern uint8_t MSG111;     
extern uint8_t MSG112; 
extern uint8_t MSG113; 
extern uint8_t MSG114;     
extern uint8_t MSG115; 
extern uint8_t MSG116;
extern uint8_t MSG117; 
extern uint8_t MSG118; 
extern uint8_t MSG119;
/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
  while (1)
  {
  }
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Pre-fetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */

  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f4xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles DMA1 stream1 global interrupt.
  */
void DMA1_Stream1_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Stream1_IRQn 0 */

  /* USER CODE END DMA1_Stream1_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_usart3_rx);
  /* USER CODE BEGIN DMA1_Stream1_IRQn 1 */

  /* USER CODE END DMA1_Stream1_IRQn 1 */
}

/**
  * @brief This function handles DMA1 stream3 global interrupt.
  */
void DMA1_Stream3_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Stream3_IRQn 0 */

  /* USER CODE END DMA1_Stream3_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_usart3_tx);
  /* USER CODE BEGIN DMA1_Stream3_IRQn 1 */

  /* USER CODE END DMA1_Stream3_IRQn 1 */
}

/**
  * @brief This function handles DMA1 stream5 global interrupt.
  */
void DMA1_Stream5_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Stream5_IRQn 0 */

  /* USER CODE END DMA1_Stream5_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_usart2_rx);
  /* USER CODE BEGIN DMA1_Stream5_IRQn 1 */

  /* USER CODE END DMA1_Stream5_IRQn 1 */
}

/**
  * @brief This function handles DMA1 stream6 global interrupt.
  */
void DMA1_Stream6_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Stream6_IRQn 0 */

  /* USER CODE END DMA1_Stream6_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_usart2_tx);
  /* USER CODE BEGIN DMA1_Stream6_IRQn 1 */

  /* USER CODE END DMA1_Stream6_IRQn 1 */
}

/**
  * @brief This function handles TIM1 break interrupt and TIM9 global interrupt.
  */
void TIM1_BRK_TIM9_IRQHandler(void)
{
  /* USER CODE BEGIN TIM1_BRK_TIM9_IRQn 0 */

  /* USER CODE END TIM1_BRK_TIM9_IRQn 0 */
  HAL_TIM_IRQHandler(&htim9);
  /* USER CODE BEGIN TIM1_BRK_TIM9_IRQn 1 */

  /* USER CODE END TIM1_BRK_TIM9_IRQn 1 */
}

/**
  * @brief This function handles TIM1 update interrupt and TIM10 global interrupt.
  */
void TIM1_UP_TIM10_IRQHandler(void)
{
  /* USER CODE BEGIN TIM1_UP_TIM10_IRQn 0 */

  /* USER CODE END TIM1_UP_TIM10_IRQn 0 */
  HAL_TIM_IRQHandler(&htim1);
  /* USER CODE BEGIN TIM1_UP_TIM10_IRQn 1 */

  /* USER CODE END TIM1_UP_TIM10_IRQn 1 */
}

/**
  * @brief This function handles TIM2 global interrupt.
  */
void TIM2_IRQHandler(void)
{
  /* USER CODE BEGIN TIM2_IRQn 0 */

  /* USER CODE END TIM2_IRQn 0 */
  HAL_TIM_IRQHandler(&htim2);
  /* USER CODE BEGIN TIM2_IRQn 1 */

  /* USER CODE END TIM2_IRQn 1 */
}

/**
  * @brief This function handles TIM3 global interrupt.
  */
void TIM3_IRQHandler(void)
{
  /* USER CODE BEGIN TIM3_IRQn 0 */


  /* USER CODE END TIM3_IRQn 0 */
  HAL_TIM_IRQHandler(&htim3);
  /* USER CODE BEGIN TIM3_IRQn 1 */

  /* USER CODE END TIM3_IRQn 1 */
}

/**
  * @brief This function handles TIM4 global interrupt.
  */
void TIM4_IRQHandler(void)
{
  /* USER CODE BEGIN TIM4_IRQn 0 */

		
  /* USER CODE END TIM4_IRQn 0 */
  HAL_TIM_IRQHandler(&htim4);
  /* USER CODE BEGIN TIM4_IRQn 1 */

  /* USER CODE END TIM4_IRQn 1 */
}

/**
  * @brief This function handles USART1 global interrupt.
  */
void USART1_IRQHandler(void)
{
  /* USER CODE BEGIN USART1_IRQn 0 */
	
	uint8_t tmp_flag = 0;
	uint32_t temp;
	uint8_t tempLen;
	tmp_flag =__HAL_UART_GET_FLAG(&huart1,UART_FLAG_IDLE); /* 读取串口空闲中断(IDLE)标志位 */
	if((tmp_flag != RESET))
	{ 
		__HAL_UART_CLEAR_IDLEFLAG(&huart1); /* 清除空闲中断标志位 */
		
		temp = huart1.Instance->SR;  /* 清楚状态寄存器SR,读取SR寄存器可以实现清除SR寄存器的功能 */
		temp = huart1.Instance->DR;  /* 清楚状态寄存器DR,读取DR寄存器可以实现清除SR寄存器的功能 */
		/* 以上两个读取操作必须要有，否则无法清除空闲中断标志位，芯片硬件要求*/
		
		HAL_UART_DMAStop(&huart1);  /* 停止串口DMA接收 */
		temp  = hdma_usart1_rx.Instance->NDTR;  /* 在NDTR寄存器中，获取DMA中未传输的数据个数 */
		UART1_RX_LEN = sizeof(UART1_Rx_Buffer) - temp;  /* 总的数据报道小-DMA中剩余未存储空间大小=接收到的数据大小 */
		
		/*  BEGIN OF CODE */
		
		tempLen = UART1_Rx_Buffer[4] + (UART1_Rx_Buffer[5] <<8); /* 根据通讯协议的定义，计算出数据帧的大小 */
		
		if (UART1_Rx_Buffer[0] == 0x4A && UART1_RX_LEN == tempLen)  /* 判断接收到得数据帧的头、数据量大小与定义是否一致，如果一致则说明接收到的数据帧是对的*/
		{
      //HAL_UART_Transmit(&huart1,(uint8_t *)UART1_Rx_Buffer,UART1_RX_LEN,0xffff); 
      HAL_UART_Transmit(&huart3,(uint8_t *)UART1_Rx_Buffer,UART1_RX_LEN,0xffff); 
		}	 
	 			
		/*  END OF CODE */

		HAL_UART_Receive_DMA(&huart1,UART1_Rx_Buffer,sizeof(UART1_Rx_Buffer));  /* 开启串口DMA，接收新一帧数据 */
	}


  /* USER CODE END USART1_IRQn 0 */
  HAL_UART_IRQHandler(&huart1);
  /* USER CODE BEGIN USART1_IRQn 1 */

  /* USER CODE END USART1_IRQn 1 */
}

/**
  * @brief This function handles USART2 global interrupt.
  */
void USART2_IRQHandler(void)
{
  /* USER CODE BEGIN USART2_IRQn 0 */
	
  /* USER CODE END USART2_IRQn 0 */
  HAL_UART_IRQHandler(&huart2);
  /* USER CODE BEGIN USART2_IRQn 1 */

  /* USER CODE END USART2_IRQn 1 */
}

/**
  * @brief This function handles USART3 global interrupt.
  */
void USART3_IRQHandler(void)
{
  /* USER CODE BEGIN USART3_IRQn 0 */
	
		
	uint8_t tmp_flag = 0;
	uint32_t temp;
  uint8_t tempLen;
	tmp_flag =__HAL_UART_GET_FLAG(&huart3,UART_FLAG_IDLE); /* 读取串口空闲中断(IDLE)标志位 */
	if((tmp_flag != RESET))//idle标志被置位
	{ 
		__HAL_UART_CLEAR_IDLEFLAG(&huart3); /* 清除空闲中断标志位 */
		
		temp = huart3.Instance->SR;  /* 清楚状态寄存器SR,读取SR寄存器可以实现清除SR寄存器的功能 */
		temp = huart3.Instance->DR;  /* 清楚状态寄存器DR,读取DR寄存器可以实现清除SR寄存器的功能 */
		/* 以上两个读取操作必须要有，否则无法清除空闲中断标志位，芯片硬件要求*/
		
		HAL_UART_DMAStop(&huart3);  /* 停止串口DMA接收 */
		temp  = hdma_usart3_rx.Instance->NDTR;  /* 在NDTR寄存器中，获取DMA中未传输的数据个数 */
		UART3_RX_LEN = sizeof(UART3_Rx_Buffer) - temp;  /* 总的数据报道小-DMA中剩余未存储空间大小=接收到的数据大小 */
	  
		/*  BEGIN OF CODE */
		
			   // printf("UART3_RX_LEN:%d\r\n",UART3_RX_LEN);
		
		tempLen = UART3_Rx_Buffer[4] + (UART3_Rx_Buffer[5] <<8); /* 根据通讯协议的定义，计算出数据帧的大小 */
		
		if (UART3_Rx_Buffer[0] == 0x4A)  /* 判断接收到得数据帧的头、数据量大小与定义是否一致，如果一致则说明接收到的数据帧是对的*/
		{
 			if (UART3_Rx_Buffer[1] == 1)
			{
        MSG1++;
			}
			if (UART3_Rx_Buffer[1] == 2)
			{
        MSG2++;
			}
			if (UART3_Rx_Buffer[1] == 3)
			{
        MSG3++;
			}
			if (UART3_Rx_Buffer[1] == 4)
			{
        MSG4++;
			}
			if (UART3_Rx_Buffer[1] == 5)
			{
        MSG5++;
			  HAL_UART_Transmit_DMA(&huart1, (uint8_t *)UART3_Rx_Buffer, UART3_RX_LEN);
			}
			if (UART3_Rx_Buffer[1] == 6)
			{
        MSG6++;
			  HAL_UART_Transmit_DMA(&huart1, (uint8_t *)UART3_Rx_Buffer, UART3_RX_LEN);
			}
		}
		/*  END OF CODE */
		
		HAL_UART_Receive_DMA(&huart3,UART3_Rx_Buffer,sizeof(UART3_Rx_Buffer));  /* 开启串口DMA，接收新一帧数据 */
	}


  /* USER CODE END USART3_IRQn 0 */
  HAL_UART_IRQHandler(&huart3);
  /* USER CODE BEGIN USART3_IRQn 1 */

  /* USER CODE END USART3_IRQn 1 */
}

/**
  * @brief This function handles TIM5 global interrupt.
  */
void TIM5_IRQHandler(void)
{
  /* USER CODE BEGIN TIM5_IRQn 0 */

  /* USER CODE END TIM5_IRQn 0 */
  HAL_TIM_IRQHandler(&htim5);
  /* USER CODE BEGIN TIM5_IRQn 1 */

  /* USER CODE END TIM5_IRQn 1 */
}

/**
  * @brief This function handles TIM6 global interrupt, DAC1 and DAC2 underrun error interrupts.
  */
void TIM6_DAC_IRQHandler(void)
{
  /* USER CODE BEGIN TIM6_DAC_IRQn 0 */

  /* USER CODE END TIM6_DAC_IRQn 0 */
  HAL_TIM_IRQHandler(&htim6);
  /* USER CODE BEGIN TIM6_DAC_IRQn 1 */

  /* USER CODE END TIM6_DAC_IRQn 1 */
}

/**
  * @brief This function handles TIM7 global interrupt.
  */
void TIM7_IRQHandler(void)
{
  /* USER CODE BEGIN TIM7_IRQn 0 */
	
  /* USER CODE END TIM7_IRQn 0 */
  HAL_TIM_IRQHandler(&htim7);
  /* USER CODE BEGIN TIM7_IRQn 1 */

  /* USER CODE END TIM7_IRQn 1 */
}

/**
  * @brief This function handles DMA2 stream2 global interrupt.
  */
void DMA2_Stream2_IRQHandler(void)
{
  /* USER CODE BEGIN DMA2_Stream2_IRQn 0 */

  /* USER CODE END DMA2_Stream2_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_usart1_rx);
  /* USER CODE BEGIN DMA2_Stream2_IRQn 1 */

  /* USER CODE END DMA2_Stream2_IRQn 1 */
}

/**
  * @brief This function handles DMA2 stream7 global interrupt.
  */
void DMA2_Stream7_IRQHandler(void)
{
  /* USER CODE BEGIN DMA2_Stream7_IRQn 0 */

  /* USER CODE END DMA2_Stream7_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_usart1_tx);
  /* USER CODE BEGIN DMA2_Stream7_IRQn 1 */

  /* USER CODE END DMA2_Stream7_IRQn 1 */
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

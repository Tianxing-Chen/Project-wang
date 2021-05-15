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
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "main_Encode.h"
#include "main_Decode.h"

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
extern DMA_HandleTypeDef hdma_uart4_rx;
extern DMA_HandleTypeDef hdma_uart4_tx;
extern DMA_HandleTypeDef hdma_uart5_rx;
extern DMA_HandleTypeDef hdma_uart5_tx;
extern DMA_HandleTypeDef hdma_usart2_rx;
extern DMA_HandleTypeDef hdma_usart2_tx;
extern DMA_HandleTypeDef hdma_usart3_rx;
extern DMA_HandleTypeDef hdma_usart3_tx;
extern UART_HandleTypeDef huart4;
extern UART_HandleTypeDef huart5;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;
extern TIM_HandleTypeDef htim1;

/* USER CODE BEGIN EV */

extern uint8_t UART2_Rx_Buffer[UART2_RX_BUF_SIZE];  /* USART接收数据存储空间 */
extern uint8_t UART2_RX_FLAG;  /* 是否完成一帧数据的接收 */
extern uint8_t UART2_RX_LEN;  /* 接收数据帧大小 */

extern uint8_t UART3_Rx_Buffer[UART3_RX_BUF_SIZE];  /* USART接收数据存储空间 */
extern uint8_t UART3_RX_FLAG;  /* 是否完成一帧数据的接收 */
extern uint8_t UART3_RX_LEN;  /* 接收数据帧大小 */

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
  * @brief This function handles DMA1 stream0 global interrupt.
  */
void DMA1_Stream0_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Stream0_IRQn 0 */

  /* USER CODE END DMA1_Stream0_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_uart5_rx);
  /* USER CODE BEGIN DMA1_Stream0_IRQn 1 */

  /* USER CODE END DMA1_Stream0_IRQn 1 */
}

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
  * @brief This function handles DMA1 stream2 global interrupt.
  */
void DMA1_Stream2_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Stream2_IRQn 0 */

  /* USER CODE END DMA1_Stream2_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_uart4_rx);
  /* USER CODE BEGIN DMA1_Stream2_IRQn 1 */

  /* USER CODE END DMA1_Stream2_IRQn 1 */
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
  * @brief This function handles DMA1 stream4 global interrupt.
  */
void DMA1_Stream4_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Stream4_IRQn 0 */

  /* USER CODE END DMA1_Stream4_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_uart4_tx);
  /* USER CODE BEGIN DMA1_Stream4_IRQn 1 */

  /* USER CODE END DMA1_Stream4_IRQn 1 */
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
  * @brief This function handles USART2 global interrupt.
  */
void USART2_IRQHandler(void)
{
  /* USER CODE BEGIN USART2_IRQn 0 */
	
	uint8_t tmp_flag = 0;
	uint32_t temp;

	tmp_flag =__HAL_UART_GET_FLAG(&huart2,UART_FLAG_IDLE); /* 读取串口空闲中断(IDLE)标志位 */
	if((tmp_flag != RESET))
	{ 
		__HAL_UART_CLEAR_IDLEFLAG(&huart2); /* 清除空闲中断标志位 */
		
		temp = huart2.Instance->SR;  /* 清楚状态寄存器SR,读取SR寄存器可以实现清除SR寄存器的功能 */
		temp = huart2.Instance->DR;  /* 清楚状态寄存器DR,读取DR寄存器可以实现清除SR寄存器的功能 */
		/* 以上两个读取操作必须要有，否则无法清除空闲中断标志位，芯片硬件要求*/
		
		HAL_UART_DMAStop(&huart2);  /* 停止串口DMA接收 */
		temp  = hdma_usart2_rx.Instance->NDTR;  /* 在NDTR寄存器中，获取DMA中未传输的数据个数 */
		UART2_RX_LEN = sizeof(UART2_Rx_Buffer) - temp;  /* 总的数据报道小-DMA中剩余未存储空间大小=接收到的数据大小 */
		
		/*  BEGIN OF CODE */
		
		if (UART2_Rx_Buffer[0] == 0x4A)  /* 判断接收到得数据帧的头、数据量大小与定义是否一致，如果一致则说明接收到的数据帧是对的*/
		{
			UART2_RX_FLAG = 1;  /* 接受完成标志位置1	*/
		}
	 			
		/*  END OF CODE */

		HAL_UART_Receive_DMA(&huart2,UART2_Rx_Buffer,sizeof(UART2_Rx_Buffer));  /* 开启串口DMA，接收新一帧数据 */
	
	 }

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
//	uint8_t tmp_flag = 0;
//	uint32_t temp;
//	tmp_flag =__HAL_UART_GET_FLAG(&huart3,UART_FLAG_IDLE); /* 读取串口空闲中断(IDLE)标志位 */
//	if((tmp_flag != RESET))//idle标志被置位
//	{ 
//		__HAL_UART_CLEAR_IDLEFLAG(&huart3); /* 清除空闲中断标志位 */
//		
//		temp = huart3.Instance->SR;  /* 清楚状态寄存器SR,读取SR寄存器可以实现清除SR寄存器的功能 */
//		temp = huart3.Instance->DR;  /* 清楚状态寄存器DR,读取DR寄存器可以实现清除SR寄存器的功能 */
//		/* 以上两个读取操作必须要有，否则无法清除空闲中断标志位，芯片硬件要求*/
//		
//		HAL_UART_DMAStop(&huart3);  /* 停止串口DMA接收 */
//		temp  = hdma_usart3_rx.Instance->NDTR;  /* 在NDTR寄存器中，获取DMA中未传输的数据个数 */
//		UART3_RX_LEN = sizeof(UART3_Rx_Buffer) - temp;  /* 总的数据报道小-DMA中剩余未存储空间大小=接收到的数据大小 */
//	  
//		/*  BEGIN OF CODE */
//		
//		if (UART3_Rx_Buffer[0] == 0X7E && UART3_Rx_Buffer[2] == UART3_RX_LEN) 
//		{
//			if(UART3_Rx_Buffer[1] == 1)
//			   {
//			     Dynamic_key = UART3_Rx_Buffer[3];
//					 if (IF_DEBUG == 1)
//					 {
//						 printf("Dynamic key:%d\r\n",Dynamic_key);
//					 }
//			   }
//			if(UART3_Rx_Buffer[1] == 2)
//			   {
//					 memcpy(&(Time4_stamp), &UART3_Rx_Buffer[3], sizeof(uint64_t));/* timestamp */
//			     if (IF_DEBUG == 1)
//					 {
//					 printf("Time4_stamp:%lld ms\r\n",Time4_stamp);
//					 }
//		       //Time4_stamp = 0;
//			   }
//			if(UART3_Rx_Buffer[1] == 3 && UART3_Rx_Buffer[3] == 201)
//			   {
//					 if (IF_DEBUG == 1)
//					 {
//						 printf("Dynamic key:%d\r\n",Dynamic_key);
//					 }
//					 XHMY();
//			   }
//		}
//		else
//		{
//		  UART3_RX_FLAG = 1;
//		}

//		/*  END OF CODE */
//		
//		HAL_UART_Receive_DMA(&huart3,UART3_Rx_Buffer,sizeof(UART3_Rx_Buffer));  /* 开启串口DMA，接收新一帧数据 */
//	}
    if((__HAL_UART_GET_FLAG(&huart3,UART_FLAG_RXNE) != RESET))//idle标志被置位
	  { 
			uint8_t ch;
      ch = huart3.Instance->DR;	
      if (ch == 0X5A)
		  {
			  UART3_RX_FLAG = 1;
		  }
			if (UART3_RX_FLAG == 1)
			{				
			  UART3_Rx_Buffer[UART3_RX_LEN] =  ch;
			  UART3_RX_LEN ++;
			  if (UART3_Rx_Buffer[UART3_RX_LEN-2] == 0X0D && UART3_Rx_Buffer[UART3_RX_LEN-1] == 0X0A)
			  { 
				   uint8_t flag = 0;
		  	   if (mark1 == 0 && flag == 0)
				   {
				      memcpy(&msg_before_encode1[0], &UART3_Rx_Buffer[1], UART3_RX_LEN); 
					    mark1 = 1;
					    flag = 1;
				   }
				   if (mark2 == 0 && flag == 0)
				   {
				      memcpy(&msg_before_encode2[0], &UART3_Rx_Buffer[1], UART3_RX_LEN); 
					    mark2 = 1;
					    flag = 1;
				   }
				   if (mark3 == 0 && flag == 0)
				   {
				      memcpy(&msg_before_encode3[0], &UART3_Rx_Buffer[1], UART3_RX_LEN); 
					    mark3 = 1;
					    flag = 1;
				   }
				   if (mark4 == 0 && flag == 0)
				   {
				      memcpy(&msg_before_encode4[0], &UART3_Rx_Buffer[1], UART3_RX_LEN); 
					    mark4 = 1;
					    flag = 1;
				   }
				   if (mark5 == 0 && flag == 0)
				   {
				      memcpy(&msg_before_encode5[0], &UART3_Rx_Buffer[1], UART3_RX_LEN); 
					    mark5 = 1;
					    flag = 1;
				   }
				   if (mark6 == 0 && flag == 0)
				   {
				      memcpy(&msg_before_encode6[0], &UART3_Rx_Buffer[1], UART3_RX_LEN); 
					    mark6 = 1;
					    flag = 1;
				   }
				   if (mark7 == 0 && flag == 0)
				   {
				      memcpy(&msg_before_encode7[0], &UART3_Rx_Buffer[1], UART3_RX_LEN); 
					    mark7 = 1;
					    flag = 1;
				   }
				   if (mark8 == 0 && flag == 0)
				   {
				      memcpy(&msg_before_encode8[0], &UART3_Rx_Buffer[1], UART3_RX_LEN); 
					    mark8 = 1;
					    flag = 1;
				   }
				   if (mark9 == 0 && flag == 0)
				   {
				      memcpy(&msg_before_encode9[0], &UART3_Rx_Buffer[1], UART3_RX_LEN); 
					    mark9 = 1;
					    flag = 1;
				   }
				   if (mark10 == 0 && flag == 0)
				   {
				      memcpy(&msg_before_encode10[0], &UART3_Rx_Buffer[1], UART3_RX_LEN); 
					    mark5 = 1;
					    flag = 1;
				   }					 
			     UART3_RX_LEN = 0;
					 UART3_RX_FLAG = 0;
		    }
		  }

	}
		
  /* USER CODE END USART3_IRQn 0 */
  HAL_UART_IRQHandler(&huart3);
  /* USER CODE BEGIN USART3_IRQn 1 */

  /* USER CODE END USART3_IRQn 1 */
}

/**
  * @brief This function handles DMA1 stream7 global interrupt.
  */
void DMA1_Stream7_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Stream7_IRQn 0 */

  /* USER CODE END DMA1_Stream7_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_uart5_tx);
  /* USER CODE BEGIN DMA1_Stream7_IRQn 1 */

  /* USER CODE END DMA1_Stream7_IRQn 1 */
}

/**
  * @brief This function handles UART4 global interrupt.
  */
void UART4_IRQHandler(void)
{
  /* USER CODE BEGIN UART4_IRQn 0 */

  /* USER CODE END UART4_IRQn 0 */
  HAL_UART_IRQHandler(&huart4);
  /* USER CODE BEGIN UART4_IRQn 1 */

  /* USER CODE END UART4_IRQn 1 */
}

/**
  * @brief This function handles UART5 global interrupt.
  */
void UART5_IRQHandler(void)
{
  /* USER CODE BEGIN UART5_IRQn 0 */

  /* USER CODE END UART5_IRQn 0 */
  HAL_UART_IRQHandler(&huart5);
  /* USER CODE BEGIN UART5_IRQn 1 */

  /* USER CODE END UART5_IRQn 1 */
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

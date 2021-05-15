/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "stdio.h"

#include "main_Encode.h"
#include "main_Decode.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/


/*
中断优先级：
					0-所有串口IO中断
					1-TIM2,加解密算法定时器
					2-TIM3,50Hz触发式定时器，备用可调频率
					3-TIM4,1ms计数器
					
其中串口统一设置如下：
          波特率：115200 bps
          数据位：8
					停止位：1
					校验位：无
*/

TIM_HandleTypeDef htim2;	/* 加解密算法调用定时器，50Hz触发式调用 */
TIM_HandleTypeDef htim3;	/* 50Hz触发式调用，备用，可调频率*/
TIM_HandleTypeDef htim4;	/* 1ms计数器 */

UART_HandleTypeDef huart4;	/* 调试打印信息 */
UART_HandleTypeDef huart5;	/* 备用串口*/
UART_HandleTypeDef huart2;	/* 输入 */
UART_HandleTypeDef huart3;	/* 输出 */
DMA_HandleTypeDef hdma_uart4_rx;
DMA_HandleTypeDef hdma_uart4_tx;
DMA_HandleTypeDef hdma_uart5_rx;
DMA_HandleTypeDef hdma_uart5_tx;
DMA_HandleTypeDef hdma_usart2_rx;
DMA_HandleTypeDef hdma_usart2_tx;
DMA_HandleTypeDef hdma_usart3_rx;
DMA_HandleTypeDef hdma_usart3_tx;

/* USER CODE BEGIN PV */

uint8_t mark1 = 0;
uint8_t mark2 = 0;
uint8_t mark3 = 0;
uint8_t mark4 = 0;
uint8_t mark5 = 0;
uint8_t mark6 = 0;
uint8_t mark7 = 0;
uint8_t mark8 = 0;
uint8_t mark9 = 0;
uint8_t mark10 = 0;
uint8_t msg_before_encode1[100]; 
uint8_t msg_before_encode2[100]; 
uint8_t msg_before_encode3[100]; 
uint8_t msg_before_encode4[100]; 
uint8_t msg_before_encode5[100]; 
uint8_t msg_before_encode6[100]; 
uint8_t msg_before_encode7[100]; 
uint8_t msg_before_encode8[100]; 
uint8_t msg_before_encode9[100]; 
uint8_t msg_before_encode10[100]; 

uint64_t Time4_stamp;       /* 用于1毫秒定时器计数 */
uint8_t Dynamic_key = 0; /* 外部调用动态密码数 */

uint8_t MSG1;     
uint8_t MSG2;
uint8_t MSG3;
uint8_t MSG4;     
uint8_t MSG5;
uint8_t MSG6;

uint16_t MSG116_1;   
uint16_t MSG116_2;  
uint16_t MSG116_3;  

/*
		串口2、3接收信息使用
*/
uint8_t UART2_Rx_Buffer[UART2_RX_BUF_SIZE];  /* USART接收数据存储空间 */
uint8_t UART2_RX_FLAG;  /* 是否完成一帧数据的接收 */
uint8_t UART2_RX_LEN;  /* 接收数据帧大小 */

uint8_t UART3_Rx_Buffer[UART3_RX_BUF_SIZE];  /* USART接收数据存储空间 */
uint8_t UART3_RX_FLAG = 0;  /* 是否完成一帧数据的接收 */
uint8_t UART3_RX_LEN = 0;  /* 接收数据帧大小 */



/*
		串口3发送信息使用
*/
uint8_t UART3_Tx_Buffer[UART3_TX_BUF_SIZE];//USART接收数据存储空间



/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_USART3_UART_Init(void);
static void MX_TIM2_Init(void);
static void MX_UART4_Init(void);
static void MX_UART5_Init(void);
static void MX_TIM3_Init(void);
static void MX_TIM4_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */



/*
	串口4打印调试信息用，printf重定位函数
*/
int fputc(int ch,FILE *f)
{
	 uint8_t temp[1]={ch};
	 HAL_UART_Transmit(&huart4,temp,1,2);
	 return ch;
}

void XHMY(void)
{
		uint32_t SectorError = 0;
    FLASH_EraseInitTypeDef EraseInitStruct;		
		HAL_FLASH_Unlock();
    EraseInitStruct.TypeErase = ((uint32_t)0x00);
    EraseInitStruct.Sector = ((uint32_t)0x08000000);
    EraseInitStruct.NbSectors = 11;
 
    if (HAL_FLASHEx_Erase(&EraseInitStruct, &SectorError) != HAL_OK)
    {
        while (1)
        {
            /* User doing something here */
									printf("HAL_FLASHEx_Erase OK\r\n");
        }
    }
    HAL_FLASH_Lock();
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_USART2_UART_Init();
  MX_USART3_UART_Init();
  MX_TIM2_Init();
  MX_UART4_Init();
  MX_UART5_Init();
  MX_TIM3_Init();
  MX_TIM4_Init();
  /* USER CODE BEGIN 2 */
	
	/* 启动定时器中断 */
	HAL_TIM_Base_Start_IT(&htim2);
	HAL_TIM_Base_Start_IT(&htim3);
	HAL_TIM_Base_Start_IT(&htim4);


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */		 
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

    if (UART2_RX_FLAG == 1)
    {
			  uint8_t tempLen1 = 0;
        uint8_t tempLen2 = 0;
        uint8_t tempLen3 = 0;
        uint8_t tempLen4 = 0;
        uint8_t msg_before_encode[100]; 

      tempLen1 = UART2_Rx_Buffer[4] + (UART2_Rx_Buffer[5] <<8); 
      if (UART2_RX_LEN == tempLen1)
      {
          memcpy(&msg_before_encode[0], &UART2_Rx_Buffer[0], tempLen1); 
          main_Encode(msg_before_encode,Time4_stamp,Dynamic_key);
      }     
      else 
      {
          tempLen1 = UART2_Rx_Buffer[4] + (UART2_Rx_Buffer[5] <<8); 
          memcpy(&msg_before_encode[0], &UART2_Rx_Buffer[0], tempLen1); 
          main_Encode(msg_before_encode,Time4_stamp,Dynamic_key);
 
          tempLen2 = UART2_Rx_Buffer[tempLen1+4] + (UART2_Rx_Buffer[tempLen1+5] <<8); 
          memcpy(&msg_before_encode[0], &UART2_Rx_Buffer[tempLen1], tempLen2); 
          main_Encode(msg_before_encode,Time4_stamp,Dynamic_key);
    
          if (UART2_RX_LEN > (tempLen1 + tempLen2))  
          {
            tempLen3 = UART2_Rx_Buffer[tempLen1 + tempLen2+4] + (UART2_Rx_Buffer[tempLen1 + tempLen2+5] <<8); 
            memcpy(&msg_before_encode[0], &UART2_Rx_Buffer[tempLen1 + tempLen2], tempLen3);   
            main_Encode(msg_before_encode,Time4_stamp,Dynamic_key); 

            if (UART2_RX_LEN > (tempLen1 + tempLen2 + tempLen3))   
            {
               tempLen4 = UART2_Rx_Buffer[tempLen1 + tempLen2 + tempLen3+4] + (UART2_Rx_Buffer[tempLen1 + tempLen2 + tempLen3+5] <<8); 		
			         memcpy(&msg_before_encode[0], &UART2_Rx_Buffer[tempLen1 + tempLen2 + tempLen3], tempLen4);   
               main_Encode(msg_before_encode,Time4_stamp,Dynamic_key); 
						}
					}
				}
			UART2_RX_FLAG = 0;
			}

			
			if (mark1 == 1)
		  {
       main_Decode(msg_before_encode1,Time4_stamp,Dynamic_key);
			 mark1 = 0; 
	  	}
			if (mark2 == 1)
		  {
       main_Decode(msg_before_encode2,Time4_stamp,Dynamic_key);
			 mark2 = 0; 
	  	}
			if (mark3 == 1)
		  {
       main_Decode(msg_before_encode3,Time4_stamp,Dynamic_key);
			 mark3 = 0; 
	  	}
			if (mark4 == 1)
		  {
       main_Decode(msg_before_encode4,Time4_stamp,Dynamic_key);
			 mark4 = 0; 
	  	}
			if (mark5 == 1)
		  {
       main_Decode(msg_before_encode5,Time4_stamp,Dynamic_key);
			 mark5 = 0; 
	  	}	
			if (mark5 == 1)
		  {
       main_Decode(msg_before_encode5,Time4_stamp,Dynamic_key);
			 mark5 = 0; 
	  	}	
			if (mark6 == 1)
		  {
       main_Decode(msg_before_encode6,Time4_stamp,Dynamic_key);
			 mark6 = 0; 
	  	}	
			if (mark7 == 1)
		  {
       main_Decode(msg_before_encode7,Time4_stamp,Dynamic_key);
			 mark7 = 0; 
	  	}	
			if (mark8 == 1)
		  {
       main_Decode(msg_before_encode8,Time4_stamp,Dynamic_key);
			 mark8 = 0; 
	  	}	
			if (mark9 == 1)
		  {
       main_Decode(msg_before_encode9,Time4_stamp,Dynamic_key);
			 mark9 = 0; 
	  	}	
			if (mark10 == 1)
		  {
       main_Decode(msg_before_encode10,Time4_stamp,Dynamic_key);
			 mark10 = 0; 
	  	}				
			
			
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 8400-1;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 100000-1;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 840-1;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 1000-1;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */

}

/**
  * @brief TIM4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM4_Init(void)
{

  /* USER CODE BEGIN TIM4_Init 0 */

  /* USER CODE END TIM4_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM4_Init 1 */

  /* USER CODE END TIM4_Init 1 */
  htim4.Instance = TIM4;
  htim4.Init.Prescaler = 840-1;
  htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim4.Init.Period = 100-1;
  htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim4) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim4, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM4_Init 2 */

  /* USER CODE END TIM4_Init 2 */

}

/**
  * @brief UART4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_UART4_Init(void)
{

  /* USER CODE BEGIN UART4_Init 0 */

  /* USER CODE END UART4_Init 0 */

  /* USER CODE BEGIN UART4_Init 1 */

  /* USER CODE END UART4_Init 1 */
  huart4.Instance = UART4;
  huart4.Init.BaudRate = 115200;
  huart4.Init.WordLength = UART_WORDLENGTH_8B;
  huart4.Init.StopBits = UART_STOPBITS_1;
  huart4.Init.Parity = UART_PARITY_NONE;
  huart4.Init.Mode = UART_MODE_TX_RX;
  huart4.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart4.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart4) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN UART4_Init 2 */

  /* USER CODE END UART4_Init 2 */

}

/**
  * @brief UART5 Initialization Function
  * @param None
  * @retval None
  */
static void MX_UART5_Init(void)
{

  /* USER CODE BEGIN UART5_Init 0 */

  /* USER CODE END UART5_Init 0 */

  /* USER CODE BEGIN UART5_Init 1 */

  /* USER CODE END UART5_Init 1 */
  huart5.Instance = UART5;
  huart5.Init.BaudRate = 115200;
  huart5.Init.WordLength = UART_WORDLENGTH_8B;
  huart5.Init.StopBits = UART_STOPBITS_1;
  huart5.Init.Parity = UART_PARITY_NONE;
  huart5.Init.Mode = UART_MODE_TX_RX;
  huart5.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart5.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart5) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN UART5_Init 2 */

  /* USER CODE END UART5_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */
	
	  __HAL_UART_ENABLE_IT(&huart2, UART_IT_IDLE);	 /* 使能串口空闲(IDLE)中断 */
	  HAL_UART_Receive_DMA(&huart2,(uint8_t *)UART2_Rx_Buffer,sizeof(UART2_Rx_Buffer));  /* 打开DMA接收，数据存入UART2_Rx_Buffer数据中 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief USART3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */
	
      __HAL_UART_ENABLE_IT(&huart3, UART_IT_RXNE);

//	  __HAL_UART_ENABLE_IT(&huart3, UART_IT_IDLE);	 /* 使能串口空闲(IDLE)中断 */
//	  HAL_UART_Receive_DMA(&huart3,(uint8_t *)UART3_Rx_Buffer,sizeof(UART3_Rx_Buffer));  /* 打开DMA接收，数据存入UART3_Rx_Buffer数据中 */

  /* USER CODE END USART3_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Stream0_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Stream0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream0_IRQn);
  /* DMA1_Stream1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Stream1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream1_IRQn);
  /* DMA1_Stream2_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Stream2_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream2_IRQn);
  /* DMA1_Stream3_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Stream3_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream3_IRQn);
  /* DMA1_Stream4_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Stream4_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream4_IRQn);
  /* DMA1_Stream5_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Stream5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream5_IRQn);
  /* DMA1_Stream6_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Stream6_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream6_IRQn);
  /* DMA1_Stream7_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Stream7_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream7_IRQn);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : LED_Pin */
  GPIO_InitStruct.Pin = LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

 /**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM1 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM1) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */
	
  if (htim == (&htim2))              //50HZ定时器，用于加密/解密处理
	{
		printf("MSG1:%d\r\n",MSG1);				
		printf("MSG2:%d\r\n",MSG2);
		printf("MSG3:%d\r\n",MSG3);		
		printf("MSG4:%d\r\n",MSG4);			
		MSG1 = 0;
		MSG2 = 0;
		MSG3 = 0;
		MSG4 = 0;

					
		printf("MSG116_1:%d\r\n",MSG116_1);
		printf("MSG116_2:%d\r\n",MSG116_2);		
		printf("MSG116_3:%d\r\n",MSG116_3);			
//		printf("MSG116_4:%d\r\n",MSG116_4);			
		MSG116_1 = 0;
		MSG116_2 = 0;
		MSG116_3 = 0;
//		MSG116_4 = 0;
  }
	
  if(htim == (&htim3))               //50HZ定时器
	{     

			
  }
	
	if(htim == (&htim4))               //1000HZ定时器
	{      
			Time4_stamp++; 	
      if(Time4_stamp == 6000*60*24)		
			{
			  Time4_stamp = 0;
			}
	}
   


  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

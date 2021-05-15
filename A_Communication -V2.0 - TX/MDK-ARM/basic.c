//#include <basic.h>
//#include <main.h>


//#define UART_DMA_BUFF_LEN_MAX	255
//uint16_t Uart1RxBuffLen = 0; 
//uint16_t Uart3RxBuffLen = 0;

//UART_HandleTypeDef huart1;
//UART_HandleTypeDef huart3;
//void USRT_DMA_IDLE_Start()
//{
//	__HAL_UART_ENABLE_IT(&huart1,UART_IT_IDLE);        //使能IDLE中断
//	HAL_UART_Receive_DMA(&huart1,Uart1RxBuff,UART_DMA_BUFF_LEN_MAX);    //开启DMA接受
//	
//	__HAL_UART_ENABLE_IT(&huart3,UART_IT_IDLE);
//	HAL_UART_Receive_DMA(&huart3,Uart3RxBuff,UART_DMA_BUFF_LEN_MAX);
//}


//void UART1_Rx_IDLE_Callback()
//{
//	//暂停DMA
//	HAL_UART_DMAStop(&huart1);
//	
//	//获取DMA
////	Uart3BuffLen_DMA = __HAL_DMA_GET_COUNTER(&hdma_usart1_rx);
//	
//	//实际长度 = 总长度 - 剩余长度
//	Uart1RxBuffLen = UART_DMA_BUFF_LEN_MAX-__HAL_DMA_GET_COUNTER(&hdma_usart1_rx);
//	
//	//回发测试
//	//UART_Transmit_DMA(&huart1,Uart1RxBuff,Uart1RxBuffLen);
//	
//	//开启DMA接收
//	HAL_UART_Receive_DMA(&huart1,Uart1RxBuff,UART_DMA_BUFF_LEN_MAX);
//}
//void UART3_Rx_IDLE_Callback()
//{
//	//暂停DMA
//	HAL_UART_DMAStop(&huart3);
//	
//	//获取DMA缓冲区剩余长度
////	Uart3BuffLen_DMA = __HAL_DMA_GET_COUNTER(&hdma_usart1_rx);
//	
//	//实际长度 = 总长度- 剩余长度
//	//Uart3RxBuffLen = UART_DMA_BUFF_LEN_MAX-__HAL_DMA_GET_COUNTER(&hdma_usart3_rx);
//	
//	//UART_Transmit_DMA(&huart3,Uart3RxBuff,Uart3RxBuffLen);
//	//开启DMA接受
//	HAL_UART_Receive_DMA(&huart3,Uart3RxBuff,UART_DMA_BUFF_LEN_MAX);
//}
// 


//void UART_Rx_Callback(UART_HandleTypeDef *huart)
//{
//	//判断IDLE中断
//	if(!__HAL_UART_GET_FLAG(huart,UART_FLAG_IDLE))
//	{
//		return;
//	}
//	//清楚IDLE中断--直接读取SR、DR寄存器即可清楚IDLE中断
//	__HAL_UART_CLEAR_IDLEFLAG(huart);
////	temp = huart->Instance->SR;
////	temp = huart->Instance->DR;
//	
//	//判断中断源
//	if(huart == &huart1)
//	{
//		UART1_Rx_IDLE_Callback();
//	}
//	else if(huart == &huart3)
//	{
//		UART3_Rx_IDLE_Callback();
//	}
//}




 



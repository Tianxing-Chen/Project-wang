//#include <basic.h>
//#include <main.h>


//#define UART_DMA_BUFF_LEN_MAX	255
//uint16_t Uart1RxBuffLen = 0; 
//uint16_t Uart3RxBuffLen = 0;

//UART_HandleTypeDef huart1;
//UART_HandleTypeDef huart3;
//void USRT_DMA_IDLE_Start()
//{
//	__HAL_UART_ENABLE_IT(&huart1,UART_IT_IDLE);        //ʹ��IDLE�ж�
//	HAL_UART_Receive_DMA(&huart1,Uart1RxBuff,UART_DMA_BUFF_LEN_MAX);    //����DMA����
//	
//	__HAL_UART_ENABLE_IT(&huart3,UART_IT_IDLE);
//	HAL_UART_Receive_DMA(&huart3,Uart3RxBuff,UART_DMA_BUFF_LEN_MAX);
//}


//void UART1_Rx_IDLE_Callback()
//{
//	//��ͣDMA
//	HAL_UART_DMAStop(&huart1);
//	
//	//��ȡDMA
////	Uart3BuffLen_DMA = __HAL_DMA_GET_COUNTER(&hdma_usart1_rx);
//	
//	//ʵ�ʳ��� = �ܳ��� - ʣ�೤��
//	Uart1RxBuffLen = UART_DMA_BUFF_LEN_MAX-__HAL_DMA_GET_COUNTER(&hdma_usart1_rx);
//	
//	//�ط�����
//	//UART_Transmit_DMA(&huart1,Uart1RxBuff,Uart1RxBuffLen);
//	
//	//����DMA����
//	HAL_UART_Receive_DMA(&huart1,Uart1RxBuff,UART_DMA_BUFF_LEN_MAX);
//}
//void UART3_Rx_IDLE_Callback()
//{
//	//��ͣDMA
//	HAL_UART_DMAStop(&huart3);
//	
//	//��ȡDMA������ʣ�೤��
////	Uart3BuffLen_DMA = __HAL_DMA_GET_COUNTER(&hdma_usart1_rx);
//	
//	//ʵ�ʳ��� = �ܳ���- ʣ�೤��
//	//Uart3RxBuffLen = UART_DMA_BUFF_LEN_MAX-__HAL_DMA_GET_COUNTER(&hdma_usart3_rx);
//	
//	//UART_Transmit_DMA(&huart3,Uart3RxBuff,Uart3RxBuffLen);
//	//����DMA����
//	HAL_UART_Receive_DMA(&huart3,Uart3RxBuff,UART_DMA_BUFF_LEN_MAX);
//}
// 


//void UART_Rx_Callback(UART_HandleTypeDef *huart)
//{
//	//�ж�IDLE�ж�
//	if(!__HAL_UART_GET_FLAG(huart,UART_FLAG_IDLE))
//	{
//		return;
//	}
//	//���IDLE�ж�--ֱ�Ӷ�ȡSR��DR�Ĵ����������IDLE�ж�
//	__HAL_UART_CLEAR_IDLEFLAG(huart);
////	temp = huart->Instance->SR;
////	temp = huart->Instance->DR;
//	
//	//�ж��ж�Դ
//	if(huart == &huart1)
//	{
//		UART1_Rx_IDLE_Callback();
//	}
//	else if(huart == &huart3)
//	{
//		UART3_Rx_IDLE_Callback();
//	}
//}




 



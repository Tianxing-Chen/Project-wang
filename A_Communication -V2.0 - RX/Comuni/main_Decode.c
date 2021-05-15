#include "main_Decode.h"


BYTE key_decode[1][32] = 
{
	{0x60,0x3d,0xeb,0x10,0x15,0xca,0x71,0xbe,0x2b,0x73,0xae,0xf0,0x85,0x7d,0x77,0x81,0x1f,0x35,0x2c,0x07,0x3b,0x61,0x08,0xd7,0x2d,0x98,0x10,0xa3,0x09,0x14,0xdf,0xf4}
};
BYTE key_decode1[1][32] = 
{
	{0x61,0x3d,0xeb,0x10,0x15,0xca,0x71,0xbe,0x2b,0x73,0xae,0xf0,0x85,0x7d,0x77,0x81,0x1f,0x35,0x2c,0x07,0x3b,0x61,0x08,0xd7,0x2d,0x98,0x10,0xa3,0x09,0x14,0xdf,0xf4}
};
BYTE key_decode2[1][32] = 
{
	{0x62,0x3d,0xeb,0x10,0x15,0xca,0x71,0xbe,0x2b,0x73,0xae,0xf0,0x85,0x7d,0x77,0x81,0x1f,0x35,0x2c,0x07,0x3b,0x61,0x08,0xd7,0x2d,0x98,0x10,0xa3,0x09,0x14,0xdf,0xf4}
};
BYTE key_decode3[1][32] = 
{
	{0x63,0x3d,0xeb,0x10,0x15,0xca,0x71,0xbe,0x2b,0x73,0xae,0xf0,0x85,0x7d,0x77,0x81,0x1f,0x35,0x2c,0x07,0x3b,0x61,0x08,0xd7,0x2d,0x98,0x10,0xa3,0x09,0x14,0xdf,0xf4}
};
BYTE key_decode4[1][32] = 
{
	{0x64,0x3d,0xeb,0x10,0x15,0xca,0x71,0xbe,0x2b,0x73,0xae,0xf0,0x85,0x7d,0x77,0x81,0x1f,0x35,0x2c,0x07,0x3b,0x61,0x08,0xd7,0x2d,0x98,0x10,0xa3,0x09,0x14,0xdf,0xf4}
};
BYTE key_decode5[1][32] = 
{
	{0x65,0x3d,0xeb,0x10,0x15,0xca,0x71,0xbe,0x2b,0x73,0xae,0xf0,0x85,0x7d,0x77,0x81,0x1f,0x35,0x2c,0x07,0x3b,0x61,0x08,0xd7,0x2d,0x98,0x10,0xa3,0x09,0x14,0xdf,0xf4}
};
BYTE key_decode6[1][32] = 
{
	{0x66,0x3d,0xeb,0x10,0x15,0xca,0x71,0xbe,0x2b,0x73,0xae,0xf0,0x85,0x7d,0x77,0x81,0x1f,0x35,0x2c,0x07,0x3b,0x61,0x08,0xd7,0x2d,0x98,0x10,0xa3,0x09,0x14,0xdf,0xf4}
};
BYTE key_decode7[1][32] = 
{
	{0x67,0x3d,0xeb,0x10,0x15,0xca,0x71,0xbe,0x2b,0x73,0xae,0xf0,0x85,0x7d,0x77,0x81,0x1f,0x35,0x2c,0x07,0x3b,0x61,0x08,0xd7,0x2d,0x98,0x10,0xa3,0x09,0x14,0xdf,0xf4}
};
BYTE key_decode8[1][32] = 
{
	{0x68,0x3d,0xeb,0x10,0x15,0xca,0x71,0xbe,0x2b,0x73,0xae,0xf0,0x85,0x7d,0x77,0x81,0x1f,0x35,0x2c,0x07,0x3b,0x61,0x08,0xd7,0x2d,0x98,0x10,0xa3,0x09,0x14,0xdf,0xf4}
};
BYTE key_decode9[1][32] = 
{
	{0x69,0x3d,0xeb,0x10,0x15,0xca,0x71,0xbe,0x2b,0x73,0xae,0xf0,0x85,0x7d,0x77,0x81,0x1f,0x35,0x2c,0x07,0x3b,0x61,0x08,0xd7,0x2d,0x98,0x10,0xa3,0x09,0x14,0xdf,0xf4}
};
BYTE key_decode10[1][32] = 
{
	{0x6A,0x3d,0xeb,0x10,0x15,0xca,0x71,0xbe,0x2b,0x73,0xae,0xf0,0x85,0x7d,0x77,0x81,0x1f,0x35,0x2c,0x07,0x3b,0x61,0x08,0xd7,0x2d,0x98,0x10,0xa3,0x09,0x14,0xdf,0xf4}
};
WORD key_schedule_decode[60];
BYTE iv_decode[1][16] = 
{
	{0xf0,0xf1,0xf2,0xf3,0xf4,0xf5,0xf6,0xf7,0xf8,0xf9,0xfa,0xfb,0xfc,0xfd,0xfe,0xff},
};
// hash密钥
static const uint8_t secret_key_decode[32] = 
{
    0x40, 0x71, 0xb5, 0xe9,
    0x40, 0x71, 0xb5, 0xe9,
    0x40, 0x71, 0xb5, 0xe9,
    0x40, 0x71, 0xb5, 0xe9,
    0x40, 0x71, 0xb5, 0xe9,
    0x40, 0x71, 0xb5, 0xe9,
    0x40, 0x71, 0xb5, 0xe9,
    0x40, 0x71, 0xb5, 0xe9
};
// hash1密钥
static const uint8_t secret_key1_decode[32] = 
{
    0x41, 0x71, 0xb5, 0xe9,
    0x41, 0x71, 0xb5, 0xe9,
    0x41, 0x71, 0xb5, 0xe9,
    0x41, 0x71, 0xb5, 0xe9,
    0x41, 0x71, 0xb5, 0xe9,
    0x41, 0x71, 0xb5, 0xe9,
    0x41, 0x71, 0xb5, 0xe9,
    0x41, 0x71, 0xb5, 0xe9
};
// hash2密钥
static const uint8_t secret_key2_decode[32] = 
{
    0x42, 0x71, 0xb5, 0xe9,
    0x42, 0x71, 0xb5, 0xe9,
    0x42, 0x71, 0xb5, 0xe9,
    0x42, 0x71, 0xb5, 0xe9,
    0x42, 0x71, 0xb5, 0xe9,
    0x42, 0x71, 0xb5, 0xe9,
    0x42, 0x71, 0xb5, 0xe9,
    0x42, 0x71, 0xb5, 0xe9
};
// hash3密钥
static const uint8_t secret_key3_decode[32] = 
{
    0x43, 0x71, 0xb5, 0xe9,
    0x43, 0x71, 0xb5, 0xe9,
    0x43, 0x71, 0xb5, 0xe9,
    0x43, 0x71, 0xb5, 0xe9,
    0x43, 0x71, 0xb5, 0xe9,
    0x43, 0x71, 0xb5, 0xe9,
    0x43, 0x71, 0xb5, 0xe9,
    0x43, 0x71, 0xb5, 0xe9
};
// hash4密钥
static const uint8_t secret_key4_decode[32] = 
{
    0x44, 0x71, 0xb5, 0xe9,
    0x44, 0x71, 0xb5, 0xe9,
    0x44, 0x71, 0xb5, 0xe9,
    0x44, 0x71, 0xb5, 0xe9,
    0x44, 0x71, 0xb5, 0xe9,
    0x44, 0x71, 0xb5, 0xe9,
    0x44, 0x71, 0xb5, 0xe9,
    0x44, 0x71, 0xb5, 0xe9
};
// hash5密钥
static const uint8_t secret_key5_decode[32] = 
{
    0x45, 0x71, 0xb5, 0xe9,
    0x45, 0x71, 0xb5, 0xe9,
    0x45, 0x71, 0xb5, 0xe9,
    0x45, 0x71, 0xb5, 0xe9,
    0x45, 0x71, 0xb5, 0xe9,
    0x45, 0x71, 0xb5, 0xe9,
    0x45, 0x71, 0xb5, 0xe9,
    0x45, 0x71, 0xb5, 0xe9
};
// hash6密钥
static const uint8_t secret_key6_decode[32] = 
{
    0x46, 0x71, 0xb5, 0xe9,
    0x46, 0x71, 0xb5, 0xe9,
    0x46, 0x71, 0xb5, 0xe9,
    0x46, 0x71, 0xb5, 0xe9,
    0x46, 0x71, 0xb5, 0xe9,
    0x46, 0x71, 0xb5, 0xe9,
    0x46, 0x71, 0xb5, 0xe9,
    0x46, 0x71, 0xb5, 0xe9
};
// hash7密钥
static const uint8_t secret_key7_decode[32] = 
{
    0x47, 0x71, 0xb5, 0xe9,
    0x47, 0x71, 0xb5, 0xe9,
    0x47, 0x71, 0xb5, 0xe9,
    0x47, 0x71, 0xb5, 0xe9,
    0x47, 0x71, 0xb5, 0xe9,
    0x47, 0x71, 0xb5, 0xe9,
    0x47, 0x71, 0xb5, 0xe9,
    0x47, 0x71, 0xb5, 0xe9
};
// hash8密钥
static const uint8_t secret_key8_decode[32] = 
{
    0x48, 0x71, 0xb5, 0xe9,
    0x48, 0x71, 0xb5, 0xe9,
    0x48, 0x71, 0xb5, 0xe9,
    0x48, 0x71, 0xb5, 0xe9,
    0x48, 0x71, 0xb5, 0xe9,
    0x48, 0x71, 0xb5, 0xe9,
    0x48, 0x71, 0xb5, 0xe9,
    0x48, 0x71, 0xb5, 0xe9
};
// hash9密钥
static const uint8_t secret_key9_decode[32] = 
{
    0x49, 0x71, 0xb5, 0xe9,
    0x49, 0x71, 0xb5, 0xe9,
    0x49, 0x71, 0xb5, 0xe9,
    0x49, 0x71, 0xb5, 0xe9,
    0x49, 0x71, 0xb5, 0xe9,
    0x49, 0x71, 0xb5, 0xe9,
    0x49, 0x71, 0xb5, 0xe9,
    0x49, 0x71, 0xb5, 0xe9
};
// hash10密钥
static const uint8_t secret_key10_decode[32] = 
{
    0x50, 0x71, 0xb5, 0xe9,
    0x50, 0x71, 0xb5, 0xe9,
    0x50, 0x71, 0xb5, 0xe9,
    0x50, 0x71, 0xb5, 0xe9,
    0x50, 0x71, 0xb5, 0xe9,
    0x50, 0x71, 0xb5, 0xe9,
    0x50, 0x71, 0xb5, 0xe9,
    0x50, 0x71, 0xb5, 0xe9
};

_signing_decode_t signing_decode;
_signature_decode_t signature_decode;

uint8_t sign_frame_decode[MSG_LEN_SIG];
uint64_t timestamp_k_1;
uint64_t timestamp_k;
uint64_t timestamp1_k_1;
uint64_t timestamp1_k;
uint64_t timestamp2_k_1;
uint64_t timestamp2_k;
uint64_t timestamp3_k_1;
uint64_t timestamp3_k;
uint64_t timestamp4_k_1;
uint64_t timestamp4_k;

void initial_Decode()
{
   memset(&signing_decode, 0, sizeof(signing_decode));
   memcpy(signing_decode.secret_key, secret_key_decode, 32);
	 aes_key_setup(key_decode[0], key_schedule_decode, 256); /* 设置密钥 */	
}



void main_Decode(uint8_t msg_payload[], uint64_t Time_Stamp, uint8_t secret_ID)
{

       if (secret_ID == 0)
			 {
          memset(&signing_decode, 0, sizeof(signing_decode));
          memcpy(signing_decode.secret_key, secret_key_decode, 32);
					aes_key_setup(key_decode[0], key_schedule_decode, 256);
			 }
			 if (secret_ID == 1)
			 {
          memset(&signing_decode, 0, sizeof(signing_decode));
          memcpy(signing_decode.secret_key, secret_key1_decode, 32);
					aes_key_setup(key_decode1[0], key_schedule_decode, 256);				 
			 }
			 if (secret_ID == 2)
			 {
          memset(&signing_decode, 0, sizeof(signing_decode));
          memcpy(signing_decode.secret_key, secret_key2_decode, 32);
					aes_key_setup(key_decode2[0], key_schedule_decode, 256);				 
			 } 
			 if (secret_ID == 3)
			 {
          memset(&signing_decode, 0, sizeof(signing_decode));
          memcpy(signing_decode.secret_key, secret_key3_decode, 32);
					aes_key_setup(key_decode3[0], key_schedule_decode, 256);				 
			 }
			 if (secret_ID == 4)
			 {
          memset(&signing_decode, 0, sizeof(signing_decode));
          memcpy(signing_decode.secret_key, secret_key4_decode, 32);
					aes_key_setup(key_decode4[0], key_schedule_decode, 256);				 
			 }			 
			 if (secret_ID == 5)
			 {
          memset(&signing_decode, 0, sizeof(signing_decode));
          memcpy(signing_decode.secret_key, secret_key5_decode, 32);
					aes_key_setup(key_decode5[0], key_schedule_decode, 256);				 
			 }  
			 if (secret_ID == 6)
			 {
          memset(&signing_decode, 0, sizeof(signing_decode));
          memcpy(signing_decode.secret_key, secret_key6_decode, 32);
					aes_key_setup(key_decode6[0], key_schedule_decode, 256);				 
			 }
			 if (secret_ID == 7)
			 {
          memset(&signing_decode, 0, sizeof(signing_decode));
          memcpy(signing_decode.secret_key, secret_key7_decode, 32);
					aes_key_setup(key_decode7[0], key_schedule_decode, 256);				 
			 }
			 if (secret_ID == 8)
			 {
          memset(&signing_decode, 0, sizeof(signing_decode));
          memcpy(signing_decode.secret_key, secret_key8_decode, 32);
					aes_key_setup(key_decode8[0], key_schedule_decode, 256);				 
			 } 
			 if (secret_ID == 9)
			 {
          memset(&signing_decode, 0, sizeof(signing_decode));
          memcpy(signing_decode.secret_key, secret_key9_decode, 32);
					aes_key_setup(key_decode9[0], key_schedule_decode, 256);				 
			 }		
			 if (secret_ID == 10)
			 {
          memset(&signing_decode, 0, sizeof(signing_decode));
          memcpy(signing_decode.secret_key, secret_key10_decode, 32);
					aes_key_setup(key_decode10[0], key_schedule_decode, 256);				 
			 }			 


        if (msg_payload[0] == MSG_ID_FX)
				{
            uint8_t msg_FX_before_decode[MSG_LEN_FX];					
            uint8_t sign_frame_raw[MSG_LEN_SIG];
					  uint64_t Time_Stamp_Sign;  /* 用于存放接收数据中的时间戳大小*/
					  uint8_t i;
					  MSG1_1++;	
            for (i=0; i < MSG_LEN_SIG; i++)
            {
               sign_frame_raw[i] = msg_payload[i+MSG_LEN_FX+1];
            }
            for (i=0; i < MSG_LEN_FX; i++)
            {
               msg_FX_before_decode[i] = msg_payload[i+1];
            }	
            memcpy(&(Time_Stamp_Sign), &sign_frame_raw[0], sizeof(uint64_t));	  /* 提取签名中的时间戳，用于重新计算签名帧 */ 		
            sign_Decode(msg_FX_before_decode, Time_Stamp_Sign);  /* 重新计算解密签名帧,存入sign_frame_decode */       						
						if (memcmp(sign_frame_decode, sign_frame_raw, sizeof(sign_frame_raw)) != 0)  /* 判断解算的签名 和 发送过来的签名是否一致 error */
						{
//								if (IF_DEBUG == 1)
//						    {
									 printf("Signature1:NOT Pass\r\n");
//								}
						}
						else
						{
							  MSG1_2++;	
								if (IF_DEBUG == 1)
						    {
									 printf("Signature:Pass\r\n");
                   printf("Time difference1:%lld\r\n",Time_Stamp - Time_Stamp_Sign);							
								}																																									  							
								/* 判断传过来的时间戳：本时刻  >  上一时刻
								   判断传过来的时间戳 - 减去本地时间戳 <1000
						       满足上述条件，则签名校验通过，否则签名校验失败 */
								//printf("Time difference1:%lld\r\n",Time_Stamp - Time_Stamp_Sign);
                   int Time_difference = Time_Stamp - Time_Stamp_Sign; 								
								   timestamp1_k = Time_Stamp_Sign;						
                if (timestamp1_k - timestamp1_k_1 >0 && (Time_difference < Threshold && Time_difference > -Threshold))								
								{ 											
						       BYTE ciphertext[1][MSG_LEN_FX];
						       BYTE decode_buf[MSG_LEN_FX];						  
			             memcpy(&ciphertext[0][0], &msg_FX_before_decode[0], MSG_LEN_FX);  /* 将mavlink payload结构体转为密文 */
						       aes_decrypt_ctr(ciphertext[0], MSG_LEN_FX, decode_buf, key_schedule_decode, 256, iv_decode[0]);  /* 解密，此处key_schedule为秘钥 */								
                   HAL_UART_Transmit(&huart3,(uint8_t *)decode_buf,sizeof(decode_buf),0xffff);									
                   MSG1_3++;								
							  }
						    timestamp1_k_1 = timestamp1_k;   /* 存储本时刻的时间戳，用于下一次运行时比较使用*/				  
						}							     
				}   
						 
        if (msg_payload[0] == MSG_ID_YK)
				{
            uint8_t msg_YK_before_decode[MSG_LEN_YK];					
            uint8_t sign_frame_raw[MSG_LEN_SIG];
					  uint64_t Time_Stamp_Sign;  /* 用于存放接收数据中的时间戳大小*/
					  uint8_t i;	
				    MSG2_1++;	
            for (i=0; i < MSG_LEN_SIG; i++)
            {
               sign_frame_raw[i] = msg_payload[i+MSG_LEN_YK+1];
            }
            for (i=0; i < MSG_LEN_YK; i++)
            {
               msg_YK_before_decode[i] = msg_payload[i+1];
            }	
            memcpy(&(Time_Stamp_Sign), &sign_frame_raw[0], sizeof(uint64_t));	  		
            sign_Decode(msg_YK_before_decode, Time_Stamp_Sign);  
						if (memcmp(sign_frame_decode, sign_frame_raw, sizeof(sign_frame_raw)) != 0)
						{

								if (IF_DEBUG == 1)
						    {
									 printf("Signature2:NOT Pass\r\n");
								}
						}
						else
						{
							  MSG2_2++;
								if (IF_DEBUG == 1)
						    {
									 printf("Signature:Pass\r\n");
									 printf("Time difference2:%lld\r\n",Time_Stamp - Time_Stamp_Sign);						  
								}	
                   int Time_difference = Time_Stamp - Time_Stamp_Sign; 								
								   timestamp2_k = Time_Stamp_Sign;						
                if (timestamp2_k - timestamp2_k_1 >0 && (Time_difference < Threshold && Time_difference > -Threshold))								
								{ 											
						       BYTE ciphertext[1][MSG_LEN_YK];
						       BYTE decode_buf[MSG_LEN_YK];						  
			             memcpy(&ciphertext[0][0], &msg_YK_before_decode[0], MSG_LEN_YK);  
						       aes_decrypt_ctr(ciphertext[0], MSG_LEN_YK, decode_buf, key_schedule_decode, 256, iv_decode[0]);  								
								   //HAL_UART_Transmit_DMA(&huart3, (uint8_t *)decode_buf, sizeof(decode_buf));	
                   HAL_UART_Transmit(&huart3,(uint8_t *)decode_buf,sizeof(decode_buf),0xffff);	
                   MSG2_3++;
							  }
						    timestamp2_k_1 = timestamp2_k;   	  
						}
				 }
       if (msg_payload[0] == MSG_ID_ZT)
			 {				 
            uint8_t msg_ZT_before_decode[MSG_LEN_ZT];				 
            uint8_t sign_frame_raw[MSG_LEN_SIG];
					  uint64_t Time_Stamp_Sign;  /* 用于存放接收数据中的时间戳大小*/
					  uint8_t i;					
			      MSG3_1++;	
            for (i=0; i < MSG_LEN_SIG; i++)
            {
               sign_frame_raw[i] = msg_payload[i+MSG_LEN_ZT+1];
            }
            for (i=0; i < MSG_LEN_ZT; i++)
            {
               msg_ZT_before_decode[i] = msg_payload[i+1];
            }	
            memcpy(&(Time_Stamp_Sign), &sign_frame_raw[0], sizeof(uint64_t));	  		
            sign_Decode(msg_ZT_before_decode, Time_Stamp_Sign); 
						if (memcmp(sign_frame_decode, sign_frame_raw, sizeof(sign_frame_raw)) != 0)
						{
								if (IF_DEBUG == 1)
						    {
									 printf("Signature3:NOT Pass\r\n");
								}
						}
						else
						{
							  MSG3_2++;	
								if (IF_DEBUG == 1)
						    {
									 printf("Signature:Pass\r\n");
                   printf("Time difference3:%lld\r\n",Time_Stamp - Time_Stamp_Sign);	
								}
                   int Time_difference = Time_Stamp - Time_Stamp_Sign; 								
								   timestamp3_k = Time_Stamp_Sign;						
                if (timestamp3_k - timestamp3_k_1 >0 && (Time_difference < Threshold || Time_difference > -Threshold))								
								{ 											
						       BYTE ciphertext[1][MSG_LEN_ZT];
						       BYTE decode_buf[MSG_LEN_ZT];						  
			             memcpy(&ciphertext[0][0], &msg_ZT_before_decode[0], MSG_LEN_ZT);  
						       aes_decrypt_ctr(ciphertext[0], MSG_LEN_ZT, decode_buf, key_schedule_decode, 256, iv_decode[0]);  						
								   //HAL_UART_Transmit_DMA(&huart3, (uint8_t *)decode_buf, sizeof(decode_buf));
                   HAL_UART_Transmit(&huart3,(uint8_t *)decode_buf,sizeof(decode_buf),0xffff);		 
                   MSG3_3++;
							  }
						    timestamp3_k_1 = timestamp3_k;  				  
						}
				 }  
						
       if (msg_payload[0] == MSG_ID_HX)
			 {
            uint8_t msg_HX_before_decode[MSG_LEN_HX];				 
            uint8_t sign_frame_raw[MSG_LEN_SIG];
					  uint64_t Time_Stamp_Sign;  /* 用于存放接收数据中的时间戳大小*/
					  uint8_t i;					
			      MSG4_1++;	
            for (i=0; i < MSG_LEN_SIG; i++)
            {
               sign_frame_raw[i] = msg_payload[i+MSG_LEN_HX+1];
            }
            for (i=0; i < MSG_LEN_HX; i++)
            {
               msg_HX_before_decode[i] = msg_payload[i+1];
            }	
            memcpy(&(Time_Stamp_Sign), &sign_frame_raw[0], sizeof(uint64_t));	 			
            sign_Decode(msg_HX_before_decode, Time_Stamp_Sign);  
						if (memcmp(sign_frame_decode, sign_frame_raw, sizeof(sign_frame_raw)) != 0)
						{
								if (IF_DEBUG == 1)
						    {
									 printf("Signature4:NOT Pass\r\n");
								}
						}
						else
						{
							  MSG4_2++;	
								if (IF_DEBUG == 1)
						    {
									 printf("Signature:Pass\r\n");
									 printf("Time difference4:%lld\r\n",Time_Stamp - Time_Stamp_Sign);	
								}		
                   int Time_difference = Time_Stamp - Time_Stamp_Sign; 								
								   timestamp4_k = Time_Stamp_Sign;						
                if (timestamp4_k - timestamp4_k_1 >0 && (Time_difference < Threshold && Time_difference > -Threshold))								
								{ 											
						       BYTE ciphertext[1][MSG_LEN_HX];
						       BYTE decode_buf[MSG_LEN_HX];						  
			             memcpy(&ciphertext[0][0], &msg_HX_before_decode[0], MSG_LEN_HX);  
						       aes_decrypt_ctr(ciphertext[0], MSG_LEN_HX, decode_buf, key_schedule_decode, 256, iv_decode[0]);  					
								   //HAL_UART_Transmit_DMA(&huart3, (uint8_t *)decode_buf, sizeof(decode_buf));	 
                   HAL_UART_Transmit(&huart3,(uint8_t *)decode_buf,sizeof(decode_buf),0xffff);	
                   MSG4_3++;
							  }
						    timestamp4_k_1 = timestamp4_k;   		  
						}
				}  			

       if (msg_payload[0] == MSG_ID_HD)
			 {
				    uint8_t msg_HD_before_decode[MSG_LEN_HD];
            uint8_t sign_frame_raw[MSG_LEN_SIG];
					  uint64_t Time_Stamp_Sign;  /* 用于存放接收数据中的时间戳大小*/
					  uint8_t i;			      
            for (i=0; i < MSG_LEN_SIG; i++)
            {
               sign_frame_raw[i] = msg_payload[i+MSG_LEN_HD+1];
            }
            for (i=0; i < MSG_LEN_HD; i++)
            {
               msg_HD_before_decode[i] = msg_payload[i+1];
            }	
            memcpy(&(Time_Stamp_Sign), &sign_frame_raw[0], sizeof(uint64_t));	  		
            sign_Decode(msg_HD_before_decode, Time_Stamp_Sign);  
						if (memcmp(sign_frame_decode, sign_frame_raw, sizeof(sign_frame_raw)) != 0)
						{
								if (IF_DEBUG == 1)
						    {
									 printf("Signature:NOT Pass\r\n");
								}
						}
						else
						{
								if (IF_DEBUG == 1)
						    {
									 printf("Signature:Pass\r\n");
									 printf("Time difference5:%lld\r\n",Time_Stamp - Time_Stamp_Sign);							
								}
                   int Time_difference = Time_Stamp - Time_Stamp_Sign; 								
								   timestamp_k = Time_Stamp_Sign;						
                if (timestamp_k - timestamp_k_1 >0 && (Time_difference < Threshold && Time_difference > -Threshold))								
								{ 											
						       BYTE ciphertext[1][MSG_LEN_HD];
						       BYTE decode_buf[MSG_LEN_HD];						  
			             memcpy(&ciphertext[0][0], &msg_HD_before_decode[0], MSG_LEN_HD);  
						       aes_decrypt_ctr(ciphertext[0], MSG_LEN_HD, decode_buf, key_schedule_decode, 256, iv_decode[0]);  						
                   HAL_UART_Transmit(&huart3,(uint8_t *)decode_buf,sizeof(decode_buf),0xffff);										
							  }
						    timestamp_k_1 = timestamp_k;  			  
						}
				}  								

       if (msg_payload[0] == MSG_ID_DC)
			 {
            uint8_t msg_DC_before_decode[MSG_LEN_DC];				 
            uint8_t sign_frame_raw[MSG_LEN_SIG];
					  uint64_t Time_Stamp_Sign;  /* 用于存放接收数据中的时间戳大小*/
					  uint8_t i;			     
            for (i=0; i < MSG_LEN_SIG; i++)
            {
               sign_frame_raw[i] = msg_payload[i+MSG_LEN_DC+1];
            }
            for (i=0; i < MSG_LEN_DC; i++)
            {
               msg_DC_before_decode[i] = msg_payload[i+1];
            }	
            memcpy(&(Time_Stamp_Sign), &sign_frame_raw[0], sizeof(uint64_t));	 			
            sign_Decode(msg_DC_before_decode, Time_Stamp_Sign);  
						if (memcmp(sign_frame_decode, sign_frame_raw, sizeof(sign_frame_raw)) != 0)
						{
								if (IF_DEBUG == 1)
						    {
									 printf("Signature:NOT Pass\r\n");
								}
						}
						else
						{
								if (IF_DEBUG == 1)
						    {
									 printf("Signature:Pass\r\n");
									 printf("Time difference6:%lld\r\n",Time_Stamp - Time_Stamp_Sign);							
								}
                   int Time_difference = Time_Stamp - Time_Stamp_Sign;								
								   timestamp_k = Time_Stamp_Sign;						
                if (timestamp_k - timestamp_k_1 >0 && (Time_difference < Threshold && Time_difference > -Threshold))								
								{ 											
						       BYTE ciphertext[1][MSG_LEN_DC];
						       BYTE decode_buf[MSG_LEN_DC];						  
			             memcpy(&ciphertext[0][0], &msg_DC_before_decode[0], MSG_LEN_DC); 
						       aes_decrypt_ctr(ciphertext[0], MSG_LEN_DC, decode_buf, key_schedule_decode, 256, iv_decode[0]);  							
                   HAL_UART_Transmit(&huart3,(uint8_t *)decode_buf,sizeof(decode_buf),0xffff);											
							  }
						    timestamp_k_1 = timestamp_k;   		  
						}   
        }
}

void sign_Decode(uint8_t msg_AES[], uint64_t Time_Stamp)
{
    mavlink_sha256_ctx ctx;
	
	union
	{
	  uint64_t t64;
	  uint8_t t8[8];
	} tstamp;

	  tstamp.t64 = Time_Stamp;   //timestamp 是 uint64
    int i;
    for (i=0;i<8;i++) signature_decode.timestamp[i] = tstamp.t8[i];
  	//signing->timestamp++;   			//为什么要加1？

	  //sha256算法加密的过程
	  //初始化，设定8个哈希初值
	  mavlink_sha256_init(&ctx);
	  //加入密钥
	  mavlink_sha256_update(&ctx, signing_decode.secret_key, sizeof(signing_decode.secret_key));

	  //加入payload帧
	  mavlink_sha256_update(&ctx, msg_AES, sizeof(msg_AES));

	  //加入时间戳
	  mavlink_sha256_update(&ctx, signature_decode.timestamp, 8);
	  //生成最终的48位密码，6个byte，并存入了签名帧中
	  mavlink_sha256_final_48(&ctx, signature_decode.sig);

    for (i=0;i<8;i++) sign_frame_decode[i] = signature_decode.timestamp[i];
    for (i=0;i<6;i++) sign_frame_decode[i+8] = signature_decode.sig[i];

}


#include "main_Decode.h"
#include "main_Encode.h"

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
uint64_t timestamp116_k_1;
uint64_t timestamp116_k;

void initial_Decode()
{      
    //密钥初始化及读取
    memset(&signing_decode, 0, sizeof(signing_decode));
    memcpy(signing_decode.secret_key, secret_key_decode, 32);
		aes_key_setup(key_decode[0], key_schedule_decode, 256); /* 设置密钥 */
}

void main_Decode(uint8_t msg_payload[], uint64_t Time_Stamp, uint8_t secret_ID)
{
     	/* 密钥初始化及读取 */
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
       
			 /* 对地面端盒子过来的密文进行解密处理 */
       if (msg_payload[0] == MSG_ID_ZDFX)
			 {
				    uint8_t msg_ZDFX_before_decode[MSG_LEN_ZDFX];         /* 指点飞行数据密文存储数组 */
            uint8_t sign_frame_raw[MSG_LEN_SIG];	
            uint64_t Time_Stamp_Sign;  /* 用于存放接收数据中的时间戳大小*/	
	          uint8_t i;				 
            for (i=0; i < MSG_LEN_SIG; i++)
            {
               sign_frame_raw[i] = msg_payload[i+MSG_LEN_ZDFX+1];
            }
            for (i=0; i < MSG_LEN_ZDFX; i++)
            {
               msg_ZDFX_before_decode[i] = msg_payload[i+1];
            }							
            memcpy(&(Time_Stamp_Sign), &sign_frame_raw[0], sizeof(uint64_t));	  /* 提取签名中的时间戳，用于重新计算签名帧 */ 	
            sign_Decode(msg_ZDFX_before_decode, Time_Stamp_Sign);  /* 重新计算解密签名帧,存入sign_frame_decode */

            /* 判断解算的签名 和 发送过来的签名是否一致 error */
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
									 printf("Time difference101:%lld\r\n",Time_Stamp - Time_Stamp_Sign);	
								}																																									  							
								/* 判断传过来的时间戳：本时刻  >  上一时刻
								   判断传过来的时间戳 - 减去本地时间戳 <1000
						       满足上述条件，则签名校验通过，否则签名校验失败 */	
                   int Time_difference = Time_Stamp - Time_Stamp_Sign;								
								   timestamp_k = Time_Stamp_Sign;						
                if (timestamp_k - timestamp_k_1 >0 && (Time_difference < Threshold && Time_difference > -Threshold))								
								{ 											
						       BYTE ciphertext[1][MSG_LEN_ZDFX];
						       BYTE decode_buf[MSG_LEN_ZDFX];						  
			             memcpy(&ciphertext[0][0], &msg_ZDFX_before_decode[0], MSG_LEN_ZDFX);  /* 将mavlink payload结构体转为密文 */
						       aes_decrypt_ctr(ciphertext[0], MSG_LEN_ZDFX, decode_buf, key_schedule_decode, 256, iv_decode[0]);  /* 解密，此处key_schedule为秘钥 */													   	 
								 	 HAL_UART_Transmit(&huart2,(uint8_t *)decode_buf,sizeof(decode_buf),0xffff);
							}
						    timestamp_k_1 = timestamp_k;   /* 存储本时刻的时间戳，用于下一次运行时比较使用*/				  
						}				     
			 }

        if (msg_payload[0] == MSG_ID_ZDQF)
				{	
					  uint8_t msg_ZDQF_before_decode[MSG_LEN_ZDQF];         /* 自动飞行数据密文存储数组 */
            uint8_t sign_frame_raw[MSG_LEN_SIG];	
            uint64_t Time_Stamp_Sign;  /* 用于存放接收数据中的时间戳大小*/	
	          uint8_t i;					
            for (i=0; i < MSG_LEN_SIG; i++)
            {
               sign_frame_raw[i] = msg_payload[i+MSG_LEN_ZDQF+1];
            }
            for (i=0; i < MSG_LEN_ZDQF; i++)
            {
               msg_ZDQF_before_decode[i] = msg_payload[i+1];
            }							
            memcpy(&(Time_Stamp_Sign), &sign_frame_raw[0], sizeof(uint64_t));	  			
            sign_Decode(msg_ZDQF_before_decode, Time_Stamp_Sign);  
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
                   printf("Time difference102:%lld\r\n",Time_Stamp - Time_Stamp_Sign);							
								}		
                   int Time_difference = Time_Stamp - Time_Stamp_Sign;								
								   timestamp_k = Time_Stamp_Sign;						
                if (timestamp_k - timestamp_k_1 >0 && (Time_difference < Threshold && Time_difference > -Threshold))								
								{ 											
						       BYTE ciphertext[1][MSG_LEN_ZDQF];
						       BYTE decode_buf[MSG_LEN_ZDQF];						  
			             memcpy(&ciphertext[0][0], &msg_ZDQF_before_decode[0], MSG_LEN_ZDQF);  
						       aes_decrypt_ctr(ciphertext[0], MSG_LEN_ZDQF, decode_buf, key_schedule_decode, 256, iv_decode[0]);  											   	 
								 	 HAL_UART_Transmit(&huart2,(uint8_t *)decode_buf,sizeof(decode_buf),0xffff);		 
							}
						    timestamp_k_1 = timestamp_k;  		  
						}				     
				}  

				
        if (msg_payload[0] == MSG_ID_ZDJL)
				{
					  uint8_t msg_ZDJL_before_decode[MSG_LEN_ZDJL];         /* 自动降落数据密文存储数组 */
            uint8_t sign_frame_raw[MSG_LEN_SIG];	
            uint64_t Time_Stamp_Sign;  /* 用于存放接收数据中的时间戳大小*/	
	          uint8_t i;					
            for (i=0; i < MSG_LEN_SIG; i++)
            {
               sign_frame_raw[i] = msg_payload[i+MSG_LEN_ZDJL+1];
            }
            for (i=0; i < MSG_LEN_ZDJL; i++)
            {
               msg_ZDJL_before_decode[i] = msg_payload[i+1];
            }	
            memcpy(&(Time_Stamp_Sign), &sign_frame_raw[0], sizeof(uint64_t));	  			
            sign_Decode(msg_ZDJL_before_decode, Time_Stamp_Sign);  
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
									 printf("Time difference103:%lld\r\n",Time_Stamp - Time_Stamp_Sign);					
								}		
                   int Time_difference = Time_Stamp - Time_Stamp_Sign;								
								   timestamp_k = Time_Stamp_Sign;						
                if (timestamp_k - timestamp_k_1 >0 && (Time_difference < Threshold && Time_difference > -Threshold))								
								{ 											
						       BYTE ciphertext[1][MSG_LEN_ZDJL];
						       BYTE decode_buf[MSG_LEN_ZDJL];						  
			             memcpy(&ciphertext[0][0], &msg_ZDJL_before_decode[0], MSG_LEN_ZDJL);  
						       aes_decrypt_ctr(ciphertext[0], MSG_LEN_ZDJL, decode_buf, key_schedule_decode, 256, iv_decode[0]);  											   	 
								 	 HAL_UART_Transmit(&huart2,(uint8_t *)decode_buf,sizeof(decode_buf),0xffff);				 
							}
						    timestamp_k_1 = timestamp_k;   /* 存储本时刻的时间戳，用于下一次运行时比较使用*/				  
						}				     
				}
										
        if (msg_payload[0] == MSG_ID_ZDFH)
				{
					  uint8_t msg_ZDFH_before_decode[MSG_LEN_ZDFH];         /* 自动返航数据密文存储数组 */
            uint8_t sign_frame_raw[MSG_LEN_SIG];	
            uint64_t Time_Stamp_Sign;  /* 用于存放接收数据中的时间戳大小*/	
	          uint8_t i;					
            for (i=0; i < MSG_LEN_SIG; i++)
            {
               sign_frame_raw[i] = msg_payload[i+MSG_LEN_ZDFH+1];
            }
            for (i=0; i < MSG_LEN_ZDFH; i++)
            {
               msg_ZDFH_before_decode[i] = msg_payload[i+1];
            }	
						
            memcpy(&(Time_Stamp_Sign), &sign_frame_raw[0], sizeof(uint64_t));	  		
            sign_Decode(msg_ZDFH_before_decode, Time_Stamp_Sign);  
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
									 printf("Time difference104:%lld\r\n",Time_Stamp - Time_Stamp_Sign);	
								}	
                   int Time_difference = Time_Stamp - Time_Stamp_Sign;								
								   timestamp_k = Time_Stamp_Sign;						
                if (timestamp_k - timestamp_k_1 >0 && (Time_difference < Threshold && Time_difference > -Threshold))								
								{ 											
						       BYTE ciphertext[1][MSG_LEN_ZDFH];
						       BYTE decode_buf[MSG_LEN_ZDFH];						  
			             memcpy(&ciphertext[0][0], &msg_ZDFH_before_decode[0], MSG_LEN_ZDFH);  
						       aes_decrypt_ctr(ciphertext[0], MSG_LEN_ZDFH, decode_buf, key_schedule_decode, 256, iv_decode[0]);  											   	 
								 	 HAL_UART_Transmit(&huart2,(uint8_t *)decode_buf,sizeof(decode_buf),0xffff);													 
							}
						    timestamp_k_1 = timestamp_k;   /* 存储本时刻的时间戳，用于下一次运行时比较使用*/				  
						}				     
				}

        if (msg_payload[0] == MSG_ID_GBGD)
				{	
					  uint8_t msg_GBGD_before_decode[MSG_LEN_GBGD];         /* 改变高毒密文存储数组 */
            uint8_t sign_frame_raw[MSG_LEN_SIG];	
            uint64_t Time_Stamp_Sign;  /* 用于存放接收数据中的时间戳大小*/	
	          uint8_t i;					
            for (i=0; i < MSG_LEN_SIG; i++)
            {
               sign_frame_raw[i] = msg_payload[i+MSG_LEN_GBGD+1];
            }
            for (i=0; i < MSG_LEN_GBGD; i++)
            {
               msg_GBGD_before_decode[i] = msg_payload[i+1];
            }							
            memcpy(&(Time_Stamp_Sign), &sign_frame_raw[0], sizeof(uint64_t));	  	
            sign_Decode(msg_GBGD_before_decode, Time_Stamp_Sign);  
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
                   printf("Time difference105:%lld\r\n",Time_Stamp - Time_Stamp_Sign);	
								}	
                   int Time_difference = Time_Stamp - Time_Stamp_Sign;								
								   timestamp_k = Time_Stamp_Sign;						
                if (timestamp_k - timestamp_k_1 >0 && (Time_difference < Threshold && Time_difference > -Threshold))								
								{ 											
						       BYTE ciphertext[1][MSG_LEN_GBGD];
						       BYTE decode_buf[MSG_LEN_GBGD];						  
			             memcpy(&ciphertext[0][0], &msg_GBGD_before_decode[0], MSG_LEN_GBGD);  
						       aes_decrypt_ctr(ciphertext[0], MSG_LEN_GBGD, decode_buf, key_schedule_decode, 256, iv_decode[0]);  											   	 
								 	 HAL_UART_Transmit(&huart2,(uint8_t *)decode_buf,sizeof(decode_buf),0xffff);
							}
						    timestamp_k_1 = timestamp_k;   	  
						}				     
				}	

        if (msg_payload[0] == MSG_ID_UNLOCK)
				{
					  uint8_t msg_UNLOCK_before_decode[MSG_LEN_UNLOCK];     /* 解锁数据密文存储数组 */
            uint8_t sign_frame_raw[MSG_LEN_SIG];	
            uint64_t Time_Stamp_Sign;  /* 用于存放接收数据中的时间戳大小*/	
	          uint8_t i;					
            for (i=0; i < MSG_LEN_SIG; i++)
            {
               sign_frame_raw[i] = msg_payload[i+MSG_LEN_UNLOCK+1];
            }
            for (i=0; i < MSG_LEN_UNLOCK; i++)
            {
               msg_UNLOCK_before_decode[i] = msg_payload[i+1];
            }	
            memcpy(&(Time_Stamp_Sign), &sign_frame_raw[0], sizeof(uint64_t));	  				
            sign_Decode(msg_UNLOCK_before_decode, Time_Stamp_Sign);  
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
                   printf("Time difference106:%lld\r\n",Time_Stamp - Time_Stamp_Sign);	
								}	
                   int Time_difference = Time_Stamp - Time_Stamp_Sign;								
								   timestamp_k = Time_Stamp_Sign;						
                if (timestamp_k - timestamp_k_1 >0 && (Time_difference < Threshold && Time_difference > -Threshold))								
								{ 											
						       BYTE ciphertext[1][MSG_LEN_UNLOCK];
						       BYTE decode_buf[MSG_LEN_UNLOCK];						  
			             memcpy(&ciphertext[0][0], &msg_UNLOCK_before_decode[0], MSG_LEN_UNLOCK);  
						       aes_decrypt_ctr(ciphertext[0], MSG_LEN_UNLOCK, decode_buf, key_schedule_decode, 256, iv_decode[0]);  											   	 
								 	 HAL_UART_Transmit(&huart2,(uint8_t *)decode_buf,sizeof(decode_buf),0xffff);															 
							}
						    timestamp_k_1 = timestamp_k;   			  
						}				     
				}													

        if (msg_payload[0] == MSG_ID_LOCK)
				{
					  uint8_t msg_LOCK_before_decode[MSG_LEN_LOCK];         /* 加锁数据密文存储数组 */
            uint8_t sign_frame_raw[MSG_LEN_SIG];	
            uint64_t Time_Stamp_Sign;  /* 用于存放接收数据中的时间戳大小*/	
	          uint8_t i;					
            for (i=0; i < MSG_LEN_SIG; i++)
            {
               sign_frame_raw[i] = msg_payload[i+MSG_LEN_LOCK+1];
            }
            for (i=0; i < MSG_LEN_LOCK; i++)
            {
               msg_LOCK_before_decode[i] = msg_payload[i+1];
            }	
            memcpy(&(Time_Stamp_Sign), &sign_frame_raw[0], sizeof(uint64_t));	  			
            sign_Decode(msg_LOCK_before_decode, Time_Stamp_Sign);  
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
                   printf("Time difference107:%lld\r\n",Time_Stamp - Time_Stamp_Sign);	
								}	
                   int Time_difference = Time_Stamp - Time_Stamp_Sign;								
								   timestamp_k = Time_Stamp_Sign;						
                if (timestamp_k - timestamp_k_1 >0 && (Time_difference < Threshold && Time_difference > -Threshold))								
								{ 											
						       BYTE ciphertext[1][MSG_LEN_LOCK];
						       BYTE decode_buf[MSG_LEN_LOCK];						  
			             memcpy(&ciphertext[0][0], &msg_LOCK_before_decode[0], MSG_LEN_LOCK);  
						       aes_decrypt_ctr(ciphertext[0], MSG_LEN_LOCK, decode_buf, key_schedule_decode, 256, iv_decode[0]);  											   	 
								 	 HAL_UART_Transmit(&huart2,(uint8_t *)decode_buf,sizeof(decode_buf),0xffff);
							}
						    timestamp_k_1 = timestamp_k;   				  
						}				     
				}
				
       if (msg_payload[0] == MSG_ID_ONHX)
			 {
				    uint8_t msg_ONHX_before_decode[MSG_LEN_ONHX];         /* 开启航线数据密文存储数组 */
            uint8_t sign_frame_raw[MSG_LEN_SIG];	
            uint64_t Time_Stamp_Sign;  /* 用于存放接收数据中的时间戳大小*/	
	          uint8_t i;					
            for (i=0; i < MSG_LEN_SIG; i++)
            {
               sign_frame_raw[i] = msg_payload[i+MSG_LEN_ONHX+1];
            }
            for (i=0; i < MSG_LEN_ONHX; i++)
            {
               msg_ONHX_before_decode[i] = msg_payload[i+1];
            }	
						
            memcpy(&(Time_Stamp_Sign), &sign_frame_raw[0], sizeof(uint64_t));	  			
            sign_Decode(msg_ONHX_before_decode, Time_Stamp_Sign);  
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
                   printf("Time difference108:%lld\r\n",Time_Stamp - Time_Stamp_Sign);	
								}		
                   int Time_difference = Time_Stamp - Time_Stamp_Sign;									
								   timestamp_k = Time_Stamp_Sign;						
                if (timestamp_k - timestamp_k_1 >0 && (Time_difference < Threshold && Time_difference > -Threshold))								
								{ 											
						       BYTE ciphertext[1][MSG_LEN_ONHX];
						       BYTE decode_buf[MSG_LEN_ONHX];						  
			             memcpy(&ciphertext[0][0], &msg_ONHX_before_decode[0], MSG_LEN_ONHX);  
						       aes_decrypt_ctr(ciphertext[0], MSG_LEN_ONHX, decode_buf, key_schedule_decode, 256, iv_decode[0]);  											   	 
								 	 HAL_UART_Transmit(&huart2,(uint8_t *)decode_buf,sizeof(decode_buf),0xffff);
							}
						    timestamp_k_1 = timestamp_k;  		  
						}				     
				}		

        if (msg_payload[0] == MSG_ID_OFFHX)
				{
					  uint8_t msg_OFFHX_before_decode[MSG_LEN_OFFHX];       /* 暂停航线数据密文存储数组 */
            uint8_t sign_frame_raw[MSG_LEN_SIG];	
            uint64_t Time_Stamp_Sign;  /* 用于存放接收数据中的时间戳大小*/	
	          uint8_t i;					
            for (i=0; i < MSG_LEN_SIG; i++)
            {
               sign_frame_raw[i] = msg_payload[i+MSG_LEN_OFFHX+1];
            }
            for (i=0; i < MSG_LEN_OFFHX; i++)
            {
               msg_OFFHX_before_decode[i] = msg_payload[i+1];
            }	
						
            memcpy(&(Time_Stamp_Sign), &sign_frame_raw[0], sizeof(uint64_t));	  				
            sign_Decode(msg_OFFHX_before_decode, Time_Stamp_Sign);  
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
                   printf("Time difference109:%lld\r\n",Time_Stamp - Time_Stamp_Sign);	
								}			
                   int Time_difference = Time_Stamp - Time_Stamp_Sign;										
								   timestamp_k = Time_Stamp_Sign;						
                if (timestamp_k - timestamp_k_1 >0 && (Time_difference < Threshold && Time_difference > -Threshold))								
								{ 											
						       BYTE ciphertext[1][MSG_LEN_OFFHX];
						       BYTE decode_buf[MSG_LEN_OFFHX];						  
			             memcpy(&ciphertext[0][0], &msg_OFFHX_before_decode[0], MSG_LEN_OFFHX);  
						       aes_decrypt_ctr(ciphertext[0], MSG_LEN_OFFHX, decode_buf, key_schedule_decode, 256, iv_decode[0]);  											   	 
								 	 HAL_UART_Transmit(&huart2,(uint8_t *)decode_buf,sizeof(decode_buf),0xffff);
							}
						    timestamp_k_1 = timestamp_k;   			  
						}				     
				}		

       if (msg_payload[0] == MSG_ID_GSMS)
			 {
            uint8_t msg_GSMS_before_decode[MSG_LEN_GSMS];         /* 跟随模式数据密文存储数组 */				 
            uint8_t sign_frame_raw[MSG_LEN_SIG];	
            uint64_t Time_Stamp_Sign;  /* 用于存放接收数据中的时间戳大小*/	
	          uint8_t i;					
            for (i=0; i < MSG_LEN_SIG; i++)
            {
               sign_frame_raw[i] = msg_payload[i+MSG_LEN_GSMS+1];
            }
            for (i=0; i < MSG_LEN_GSMS; i++)
            {
               msg_GSMS_before_decode[i] = msg_payload[i+1];
            }	
            memcpy(&(Time_Stamp_Sign), &sign_frame_raw[0], sizeof(uint64_t));	  	
            sign_Decode(msg_GSMS_before_decode, Time_Stamp_Sign);  
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
                   printf("Time difference110:%lld\r\n",Time_Stamp - Time_Stamp_Sign);	
								}		
                   int Time_difference = Time_Stamp - Time_Stamp_Sign;									
								   timestamp_k = Time_Stamp_Sign;						
                if (timestamp_k - timestamp_k_1 >0 && (Time_difference < Threshold && Time_difference > -Threshold))								
								{ 											
						       BYTE ciphertext[1][MSG_LEN_GSMS];
						       BYTE decode_buf[MSG_LEN_GSMS];						  
			             memcpy(&ciphertext[0][0], &msg_GSMS_before_decode[0], MSG_LEN_GSMS);  
						       aes_decrypt_ctr(ciphertext[0], MSG_LEN_GSMS, decode_buf, key_schedule_decode, 256, iv_decode[0]);  												   	 
								 	 HAL_UART_Transmit(&huart2,(uint8_t *)decode_buf,sizeof(decode_buf),0xffff);
							}
						    timestamp_k_1 = timestamp_k;  		  
						}				     
				}	
	
        if (msg_payload[0] == MSG_ID_ONBOARD)
				{
					  uint8_t msg_ONBOARD_before_decode[MSG_LEN_ONBOARD];   /* ONBOARD数据密文存储数组 */
            uint8_t sign_frame_raw[MSG_LEN_SIG];	
            uint64_t Time_Stamp_Sign;  /* 用于存放接收数据中的时间戳大小*/	
	          uint8_t i;					
            for (i=0; i < MSG_LEN_SIG; i++)
            {
               sign_frame_raw[i] = msg_payload[i+MSG_LEN_ONBOARD+1];
            }
            for (i=0; i < MSG_LEN_ONBOARD; i++)
            {
               msg_ONBOARD_before_decode[i] = msg_payload[i+1];
            }	
            memcpy(&(Time_Stamp_Sign), &sign_frame_raw[0], sizeof(uint64_t));	 	
            sign_Decode(msg_ONBOARD_before_decode, Time_Stamp_Sign);  
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
                   printf("Time difference111:%lld\r\n",Time_Stamp - Time_Stamp_Sign);	
								}	
                   int Time_difference = Time_Stamp - Time_Stamp_Sign;								
								   timestamp_k = Time_Stamp_Sign;						
                if (timestamp_k - timestamp_k_1 >0 && (Time_difference < Threshold && Time_difference > -Threshold))								
								{ 											
						       BYTE ciphertext[1][MSG_LEN_ONBOARD];
						       BYTE decode_buf[MSG_LEN_ONBOARD];						  
			             memcpy(&ciphertext[0][0], &msg_ONBOARD_before_decode[0], MSG_LEN_ONBOARD);  
						       aes_decrypt_ctr(ciphertext[0], MSG_LEN_ONBOARD, decode_buf, key_schedule_decode, 256, iv_decode[0]); 											   	 
								 	 HAL_UART_Transmit(&huart2,(uint8_t *)decode_buf,sizeof(decode_buf),0xffff);
							}
						    timestamp_k_1 = timestamp_k;   /* 存储本时刻的时间戳，用于下一次运行时比较使用*/				  
						}				     
				}		

        if (msg_payload[0] == MSG_ID_OFFBOARD)
				{
					  uint8_t msg_OFFBOARD_before_decode[MSG_LEN_OFFBOARD]; /* OFFBOARD数据密文存储数组 */
            uint8_t sign_frame_raw[MSG_LEN_SIG];	
            uint64_t Time_Stamp_Sign;  /* 用于存放接收数据中的时间戳大小*/	
	          uint8_t i;					
            for (i=0; i < MSG_LEN_SIG; i++)
            {
               sign_frame_raw[i] = msg_payload[i+MSG_LEN_OFFBOARD+1];
            }
            for (i=0; i < MSG_LEN_OFFBOARD; i++)
            {
               msg_OFFBOARD_before_decode[i] = msg_payload[i+1];
            }	
            memcpy(&(Time_Stamp_Sign), &sign_frame_raw[0], sizeof(uint64_t));	 		
            sign_Decode(msg_OFFBOARD_before_decode, Time_Stamp_Sign); 
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
                   printf("Time difference112:%lld\r\n",Time_Stamp - Time_Stamp_Sign);	
								}		
                   int Time_difference = Time_Stamp - Time_Stamp_Sign;									
								   timestamp_k = Time_Stamp_Sign;						
                if (timestamp_k - timestamp_k_1 >0 && (Time_difference < Threshold && Time_difference > -Threshold))								
								{ 											
						       BYTE ciphertext[1][MSG_LEN_OFFBOARD];
						       BYTE decode_buf[MSG_LEN_OFFBOARD];						  
			             memcpy(&ciphertext[0][0], &msg_OFFBOARD_before_decode[0], MSG_LEN_OFFBOARD);  
						       aes_decrypt_ctr(ciphertext[0], MSG_LEN_OFFBOARD, decode_buf, key_schedule_decode, 256, iv_decode[0]);											   	 
								 	 HAL_UART_Transmit(&huart2,(uint8_t *)decode_buf,sizeof(decode_buf),0xffff);
							}
						    timestamp_k_1 = timestamp_k;   				  
						}				     
				}	

        if (msg_payload[0] == MSG_ID_ZWJZ)
				{
					  uint8_t msg_ZWJZ_before_decode[MSG_LEND_ZWJZ];        /* 开始遥控器中位校准数据密文存储数组 */
            uint8_t sign_frame_raw[MSG_LEN_SIG];	
            uint64_t Time_Stamp_Sign;  /* 用于存放接收数据中的时间戳大小*/	
	          uint8_t i;					
            for (i=0; i < MSG_LEN_SIG; i++)
            {
               sign_frame_raw[i] = msg_payload[i+MSG_LEND_ZWJZ+1];
            }
            for (i=0; i < MSG_LEND_ZWJZ; i++)
            {
               msg_ZWJZ_before_decode[i] = msg_payload[i+1];
            }	
            memcpy(&(Time_Stamp_Sign), &sign_frame_raw[0], sizeof(uint64_t));	   				
            sign_Decode(msg_ZWJZ_before_decode, Time_Stamp_Sign);  
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
                   printf("Time difference113:%lld\r\n",Time_Stamp - Time_Stamp_Sign);	
								}		
                   int Time_difference = Time_Stamp - Time_Stamp_Sign;																
								   timestamp_k = Time_Stamp_Sign;						
                if (timestamp_k - timestamp_k_1 >0 && (Time_difference < Threshold && Time_difference > -Threshold))								
								{ 											
						       BYTE ciphertext[1][MSG_LEND_ZWJZ];
						       BYTE decode_buf[MSG_LEND_ZWJZ];						  
			             memcpy(&ciphertext[0][0], &msg_ZWJZ_before_decode[0], MSG_LEND_ZWJZ); 
						       aes_decrypt_ctr(ciphertext[0], MSG_LEND_ZWJZ, decode_buf, key_schedule_decode, 256, iv_decode[0]);  											   	 
								 	 HAL_UART_Transmit(&huart2,(uint8_t *)decode_buf,sizeof(decode_buf),0xffff);
							}
						    timestamp_k_1 = timestamp_k;    
						}				     
				}				

       if (msg_payload[0] == MSG_ID_XCJZ)
			 {
				    uint8_t msg_XCJZ_before_decode[MSG_LEN_XCJZ];         /* 开始遥控器行程校准数据密文存储数组 */
            uint8_t sign_frame_raw[MSG_LEN_SIG];	
            uint64_t Time_Stamp_Sign;  /* 用于存放接收数据中的时间戳大小*/	
	          uint8_t i;					
            for (i=0; i < MSG_LEN_SIG; i++)
            {
               sign_frame_raw[i] = msg_payload[i+MSG_LEN_XCJZ+1];
            }
            for (i=0; i < MSG_LEN_XCJZ; i++)
            {
               msg_XCJZ_before_decode[i] = msg_payload[i+1];
            }	
            memcpy(&(Time_Stamp_Sign), &sign_frame_raw[0], sizeof(uint64_t));	 		
            sign_Decode(msg_XCJZ_before_decode, Time_Stamp_Sign);  
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
                   printf("Time difference114:%lld\r\n",Time_Stamp - Time_Stamp_Sign);	
								}			
                   int Time_difference = Time_Stamp - Time_Stamp_Sign;								
								   timestamp_k = Time_Stamp_Sign;						
                if (timestamp_k - timestamp_k_1 >0 && (Time_difference < Threshold && Time_difference > -Threshold))								
								{ 											
						       BYTE ciphertext[1][MSG_LEN_XCJZ];
						       BYTE decode_buf[MSG_LEN_XCJZ];						  
			             memcpy(&ciphertext[0][0], &msg_XCJZ_before_decode[0], MSG_LEN_XCJZ);  
						       aes_decrypt_ctr(ciphertext[0], MSG_LEN_XCJZ, decode_buf, key_schedule_decode, 256, iv_decode[0]);  											   	 
								 	 HAL_UART_Transmit(&huart2,(uint8_t *)decode_buf,sizeof(decode_buf),0xffff);
							}
						    timestamp_k_1 = timestamp_k;   			  
						}				     
				}	

        if (msg_payload[0] == MSG_ID_CQFK)
				{
					  uint8_t msg_CQFK_before_decode[MSG_LEN_CQFK];         /* 重启飞控数据密文存储数组 */
            uint8_t sign_frame_raw[MSG_LEN_SIG];	
            uint64_t Time_Stamp_Sign;  /* 用于存放接收数据中的时间戳大小*/	
	          uint8_t i;					
            for (i=0; i < MSG_LEN_SIG; i++)
            {
               sign_frame_raw[i] = msg_payload[i+MSG_LEN_CQFK+1];
            }
            for (i=0; i < MSG_LEN_CQFK; i++)
            {
               msg_CQFK_before_decode[i] = msg_payload[i+1];
            }	
            memcpy(&(Time_Stamp_Sign), &sign_frame_raw[0], sizeof(uint64_t));	  		
            sign_Decode(msg_CQFK_before_decode, Time_Stamp_Sign);  
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
                   printf("Time difference115:%lld\r\n",Time_Stamp - Time_Stamp_Sign);	
								}			
                   int Time_difference = Time_Stamp - Time_Stamp_Sign;									
								   timestamp_k = Time_Stamp_Sign;						
                if (timestamp_k - timestamp_k_1 >0 && (Time_difference < Threshold && Time_difference > -Threshold))								
								{ 											
						       BYTE ciphertext[1][MSG_LEN_CQFK];
						       BYTE decode_buf[MSG_LEN_CQFK];						  
			             memcpy(&ciphertext[0][0], &msg_CQFK_before_decode[0], MSG_LEN_CQFK);  
						       aes_decrypt_ctr(ciphertext[0], MSG_LEN_CQFK, decode_buf, key_schedule_decode, 256, iv_decode[0]);  											   	 
								 	 HAL_UART_Transmit(&huart2,(uint8_t *)decode_buf,sizeof(decode_buf),0xffff);
							}
						    timestamp_k_1 = timestamp_k;    
						}				     
				}				
						
        if (msg_payload[0] == MSG_ID_XNYG)
				{
					  uint8_t msg_XNYG_before_decode[MSG_LEN_XNYG];         /* 虚拟摇杆数据密文存储数组 */
            uint8_t sign_frame_raw[MSG_LEN_SIG];	
            uint64_t Time_Stamp_Sign;  /* 用于存放接收数据中的时间戳大小*/	
	          uint8_t i;					
				    MSG116_1 ++;
            for (i=0; i < MSG_LEN_SIG; i++)
            {
               sign_frame_raw[i] = msg_payload[i+MSG_LEN_XNYG+1];
            }
            for (i=0; i < MSG_LEN_XNYG; i++)
            {
               msg_XNYG_before_decode[i] = msg_payload[i+1];
            }	
            memcpy(&(Time_Stamp_Sign), &sign_frame_raw[0], sizeof(uint64_t));					
            sign_Decode(msg_XNYG_before_decode, Time_Stamp_Sign); 
						if (memcmp(sign_frame_decode, sign_frame_raw, sizeof(sign_frame_raw)) != 0)
						{
								if (IF_DEBUG == 1)
						    {
									 printf("Signature:NOT Pass\r\n");
								}
						}
						else
						{
							  MSG116_2 ++;
								if (IF_DEBUG == 1)
						    {
									 printf("Signature:Pass\r\n");
                   printf("Time difference116:%lld\r\n",Time_Stamp - Time_Stamp_Sign);	
								}		  
								   //printf("Time difference116:%lld\r\n",Time_Stamp - Time_Stamp_Sign);		
                   int Time_difference = Time_Stamp - Time_Stamp_Sign;                				
								   timestamp116_k = Time_Stamp_Sign;						
                   if (timestamp116_k - timestamp116_k_1 > 0 && (Time_difference < Threshold && Time_difference > -Threshold))								
								   { 											
						         BYTE ciphertext[1][MSG_LEN_XNYG];
						         BYTE decode_buf[MSG_LEN_XNYG];						  
			               memcpy(&ciphertext[0][0], &msg_XNYG_before_decode[0], MSG_LEN_XNYG);  
						         aes_decrypt_ctr(ciphertext[0], MSG_LEN_XNYG, decode_buf, key_schedule_decode, 256, iv_decode[0]); 											   	 
								 	   HAL_UART_Transmit(&huart2,(uint8_t *)decode_buf,sizeof(decode_buf),0xffff);
									   MSG116_3 ++;
							     }	
						         timestamp116_k_1 = timestamp116_k;   /* 存储本时刻的时间戳，用于下一次运行时比较使用*/				  
						}				     
				}					

        if (msg_payload[0] == MSG_ID_HDDA)
				{
					  uint8_t msg_HDDA_before_decode[MSG_LEN_HDDA];         /* 航点数据（上传）数据密文存储数组 */
            uint8_t sign_frame_raw[MSG_LEN_SIG];	
            uint64_t Time_Stamp_Sign;  /* 用于存放接收数据中的时间戳大小*/	
	          uint8_t i;					
            for (i=0; i < MSG_LEN_SIG; i++)
            {
               sign_frame_raw[i] = msg_payload[i+MSG_LEN_HDDA+1];
            }
            for (i=0; i < MSG_LEN_HDDA; i++)
            {
               msg_HDDA_before_decode[i] = msg_payload[i+1];
            }	
            memcpy(&(Time_Stamp_Sign), &sign_frame_raw[0], sizeof(uint64_t));	  				
            sign_Decode(msg_HDDA_before_decode, Time_Stamp_Sign);  
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
									 printf("Time difference117:%lld\r\n",Time_Stamp - Time_Stamp_Sign);	
								}
                   int Time_difference = Time_Stamp - Time_Stamp_Sign;  								
								   timestamp_k = Time_Stamp_Sign;						
                if (timestamp_k - timestamp_k_1 >0 && (Time_difference< Threshold && Time_difference > -Threshold))								
								{ 											
						       BYTE ciphertext[1][MSG_LEN_HDDA];
						       BYTE decode_buf[MSG_LEN_HDDA];						  
			             memcpy(&ciphertext[0][0], &msg_HDDA_before_decode[0], MSG_LEN_HDDA);  
						       aes_decrypt_ctr(ciphertext[0], MSG_LEN_HDDA, decode_buf, key_schedule_decode, 256, iv_decode[0]); 											   	 
								 	 HAL_UART_Transmit(&huart2,(uint8_t *)decode_buf,sizeof(decode_buf),0xffff);
							}
						    timestamp_k_1 = timestamp_k;   /* 存储本时刻的时间戳，用于下一次运行时比较使用*/				  
						}
				} 

        if (msg_payload[0] == MSG_ID_HDZS)
				{
					  uint8_t msg_HDZS_before_decode[MSG_LEN_HDZS];         /* 航点总数（上传）数据密文存储数组 */
            uint8_t sign_frame_raw[MSG_LEN_SIG];	
            uint64_t Time_Stamp_Sign;  /* 用于存放接收数据中的时间戳大小*/	
	          uint8_t i;					
            for (i=0; i < MSG_LEN_SIG; i++)
            {
               sign_frame_raw[i] = msg_payload[i+MSG_LEN_HDZS+1];
            }
            for (i=0; i < MSG_LEN_HDZS; i++)
            {
               msg_HDZS_before_decode[i] = msg_payload[i+1];
            }	
						
            memcpy(&(Time_Stamp_Sign), &sign_frame_raw[0], sizeof(uint64_t));	 			
            sign_Decode(msg_HDZS_before_decode, Time_Stamp_Sign); 
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
                   printf("Time difference118:%lld\r\n",Time_Stamp - Time_Stamp_Sign);	
								}	
                   int Time_difference = Time_Stamp - Time_Stamp_Sign; 								
								   timestamp_k = Time_Stamp_Sign;						
                if (timestamp_k - timestamp_k_1 >0 && (Time_difference < Threshold && Time_difference > -Threshold))								
								{ 											
						       BYTE ciphertext[1][MSG_LEN_HDZS];
						       BYTE decode_buf[MSG_LEN_HDZS];						  
			             memcpy(&ciphertext[0][0], &msg_HDZS_before_decode[0], MSG_LEN_HDZS);  
						       aes_decrypt_ctr(ciphertext[0], MSG_LEN_HDZS, decode_buf, key_schedule_decode, 256, iv_decode[0]);  											   	 
								 	 HAL_UART_Transmit(&huart2,(uint8_t *)decode_buf,sizeof(decode_buf),0xffff);
							}
						    timestamp_k_1 = timestamp_k;   /* 存储本时刻的时间戳，用于下一次运行时比较使用*/				  
						}				     
				}								


        if (msg_payload[0] == MSG_ID_CSSZ)
				{
					  uint8_t msg_CSSZ_before_decode[MSG_LEN_CSSZ];         /* 参数设置（上传）数据密文存储数组 */
            uint8_t sign_frame_raw[MSG_LEN_SIG];	
            uint64_t Time_Stamp_Sign;  /* 用于存放接收数据中的时间戳大小*/	
	          uint8_t i;					
            for (i=0; i < MSG_LEN_SIG; i++)
            {
               sign_frame_raw[i] = msg_payload[i+MSG_LEN_CSSZ+1];
            }
            for (i=0; i < MSG_LEN_CSSZ; i++)
            {
               msg_CSSZ_before_decode[i] = msg_payload[i+1];
            }	
            memcpy(&(Time_Stamp_Sign), &sign_frame_raw[0], sizeof(uint64_t));	  			
            sign_Decode(msg_CSSZ_before_decode, Time_Stamp_Sign); 
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
                   printf("Time difference119:%lld\r\n",Time_Stamp - Time_Stamp_Sign);	
								}		
                   int Time_difference = Time_Stamp - Time_Stamp_Sign;								
								   timestamp_k = Time_Stamp_Sign;						
                if (timestamp_k - timestamp_k_1 >0 && (Time_difference < Threshold && Time_difference > -Threshold))								
								{ 											
						       BYTE ciphertext[1][MSG_LEN_CSSZ];
						       BYTE decode_buf[MSG_LEN_CSSZ];						  
			             memcpy(&ciphertext[0][0], &msg_CSSZ_before_decode[0], MSG_LEN_CSSZ);  
						       aes_decrypt_ctr(ciphertext[0], MSG_LEN_CSSZ, decode_buf, key_schedule_decode, 256, iv_decode[0]); 											   	 
								 	 HAL_UART_Transmit(&huart2,(uint8_t *)decode_buf,sizeof(decode_buf),0xffff);
							}
						    timestamp_k_1 = timestamp_k;     
						}				     
				}	

        if (msg_payload[0] == MSG_ID_KQSF)
				{
					  uint8_t msg_KQSF_before_decode[MSG_LEN_KQSF];         /* 开启飞控算法数据密文存储数组 */
            uint8_t sign_frame_raw[MSG_LEN_SIG];	
            uint64_t Time_Stamp_Sign;  /* 用于存放接收数据中的时间戳大小*/	
	          uint8_t i;					
            for (i=0; i < MSG_LEN_SIG; i++)
            {
               sign_frame_raw[i] = msg_payload[i+MSG_LEN_KQSF+1];
            }
            for (i=0; i < MSG_LEN_KQSF; i++)
            {
               msg_KQSF_before_decode[i] = msg_payload[i+1];
            }	
            memcpy(&(Time_Stamp_Sign), &sign_frame_raw[0], sizeof(uint64_t));	 		
            sign_Decode(msg_KQSF_before_decode, Time_Stamp_Sign);  
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
                   printf("Time difference120:%lld\r\n",Time_Stamp - Time_Stamp_Sign);	
								}		
                   int Time_difference = Time_Stamp - Time_Stamp_Sign;								
								   timestamp_k = Time_Stamp_Sign;						
                if (timestamp_k - timestamp_k_1 >0 && (Time_difference < Threshold && Time_difference > -Threshold))								
								{ 											
						       BYTE ciphertext[1][MSG_LEN_KQSF];
						       BYTE decode_buf[MSG_LEN_KQSF];						  
			             memcpy(&ciphertext[0][0], &msg_KQSF_before_decode[0], MSG_LEN_KQSF);  
						       aes_decrypt_ctr(ciphertext[0], MSG_LEN_KQSF, decode_buf, key_schedule_decode, 256, iv_decode[0]); 											   	 
								 	 HAL_UART_Transmit(&huart2,(uint8_t *)decode_buf,sizeof(decode_buf),0xffff);
							}
						    timestamp_k_1 = timestamp_k;   		  
						}				     	
		    }
				
				
		if (msg_payload[0] == 0X7E) 
		{
			if(msg_payload[1] == 1)
			   {
			       Dynamic_key = msg_payload[2];
//					 if (IF_DEBUG == 1)
//					 {
						  printf("Dynamic key:%d\r\n",msg_payload[2]);
//					 }
			   }
			if(msg_payload[1] == 2)
			   {
					 if (IF_DEBUG == 1)
					 {
					    printf("Time4_stamp:%lld ms\r\n",Time4_stamp);
					 }
              Time4_stamp --;	
					    memcpy(&(Time4_stamp), &msg_payload[2], sizeof(uint64_t));/* timestamp */
			   }
			if(msg_payload[1] == 3 && msg_payload[2] == 201)
			   {
//					 if (IF_DEBUG == 1)
//					 {
						 printf("销毁代码\r\n");
//					 }				 
					 XHMY();
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




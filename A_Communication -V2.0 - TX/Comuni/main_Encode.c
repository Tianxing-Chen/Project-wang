#include "main_Encode.h"
#include "sysu_sha256.h"


// 初始化, 对于AES算法，设置后的密码存在key_schedule中，若需要动态变化密码，则需要对key_schedule进行重新赋值
//256 bit密码
BYTE key0[1][32] = 
{
	{0x60,0x3d,0xeb,0x10,0x15,0xca,0x71,0xbe,0x2b,0x73,0xae,0xf0,0x85,0x7d,0x77,0x81,0x1f,0x35,0x2c,0x07,0x3b,0x61,0x08,0xd7,0x2d,0x98,0x10,0xa3,0x09,0x14,0xdf,0xf4}
};
BYTE key1[1][32] = 
{
	{0x61,0x3d,0xeb,0x10,0x15,0xca,0x71,0xbe,0x2b,0x73,0xae,0xf0,0x85,0x7d,0x77,0x81,0x1f,0x35,0x2c,0x07,0x3b,0x61,0x08,0xd7,0x2d,0x98,0x10,0xa3,0x09,0x14,0xdf,0xf4}
};
BYTE key2[1][32] = 
{
	{0x62,0x3d,0xeb,0x10,0x15,0xca,0x71,0xbe,0x2b,0x73,0xae,0xf0,0x85,0x7d,0x77,0x81,0x1f,0x35,0x2c,0x07,0x3b,0x61,0x08,0xd7,0x2d,0x98,0x10,0xa3,0x09,0x14,0xdf,0xf4}
};
BYTE key3[1][32] = 
{
	{0x63,0x3d,0xeb,0x10,0x15,0xca,0x71,0xbe,0x2b,0x73,0xae,0xf0,0x85,0x7d,0x77,0x81,0x1f,0x35,0x2c,0x07,0x3b,0x61,0x08,0xd7,0x2d,0x98,0x10,0xa3,0x09,0x14,0xdf,0xf4}
};
BYTE key4[1][32] = 
{
	{0x64,0x3d,0xeb,0x10,0x15,0xca,0x71,0xbe,0x2b,0x73,0xae,0xf0,0x85,0x7d,0x77,0x81,0x1f,0x35,0x2c,0x07,0x3b,0x61,0x08,0xd7,0x2d,0x98,0x10,0xa3,0x09,0x14,0xdf,0xf4}
};
BYTE key5[1][32] = 
{
	{0x65,0x3d,0xeb,0x10,0x15,0xca,0x71,0xbe,0x2b,0x73,0xae,0xf0,0x85,0x7d,0x77,0x81,0x1f,0x35,0x2c,0x07,0x3b,0x61,0x08,0xd7,0x2d,0x98,0x10,0xa3,0x09,0x14,0xdf,0xf4}
};
BYTE key6[1][32] = 
{
	{0x66,0x3d,0xeb,0x10,0x15,0xca,0x71,0xbe,0x2b,0x73,0xae,0xf0,0x85,0x7d,0x77,0x81,0x1f,0x35,0x2c,0x07,0x3b,0x61,0x08,0xd7,0x2d,0x98,0x10,0xa3,0x09,0x14,0xdf,0xf4}
};
BYTE key7[1][32] = 
{
	{0x67,0x3d,0xeb,0x10,0x15,0xca,0x71,0xbe,0x2b,0x73,0xae,0xf0,0x85,0x7d,0x77,0x81,0x1f,0x35,0x2c,0x07,0x3b,0x61,0x08,0xd7,0x2d,0x98,0x10,0xa3,0x09,0x14,0xdf,0xf4}
};
BYTE key8[1][32] = 
{
	{0x68,0x3d,0xeb,0x10,0x15,0xca,0x71,0xbe,0x2b,0x73,0xae,0xf0,0x85,0x7d,0x77,0x81,0x1f,0x35,0x2c,0x07,0x3b,0x61,0x08,0xd7,0x2d,0x98,0x10,0xa3,0x09,0x14,0xdf,0xf4}
};
BYTE key9[1][32] = 
{
	{0x69,0x3d,0xeb,0x10,0x15,0xca,0x71,0xbe,0x2b,0x73,0xae,0xf0,0x85,0x7d,0x77,0x81,0x1f,0x35,0x2c,0x07,0x3b,0x61,0x08,0xd7,0x2d,0x98,0x10,0xa3,0x09,0x14,0xdf,0xf4}
};
BYTE key10[1][32] = 
{
	{0x6A,0x3d,0xeb,0x10,0x15,0xca,0x71,0xbe,0x2b,0x73,0xae,0xf0,0x85,0x7d,0x77,0x81,0x1f,0x35,0x2c,0x07,0x3b,0x61,0x08,0xd7,0x2d,0x98,0x10,0xa3,0x09,0x14,0xdf,0xf4}
};
WORD key_schedule[60];
BYTE iv[1][16] = 
{
	{0xf0,0xf1,0xf2,0xf3,0xf4,0xf5,0xf6,0xf7,0xf8,0xf9,0xfa,0xfb,0xfc,0xfd,0xfe,0xff},
};

// hash密钥
static const uint8_t secret_key_encode[32] = 
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
static const uint8_t secret_key1_encode[32] = 
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
static const uint8_t secret_key2_encode[32] = 
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
static const uint8_t secret_key3_encode[32] = 
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
static const uint8_t secret_key4_encode[32] = 
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
static const uint8_t secret_key5_encode[32] = 
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
static const uint8_t secret_key6_encode[32] = 
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
static const uint8_t secret_key7_encode[32] = 
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
static const uint8_t secret_key8_encode[32] = 
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
static const uint8_t secret_key9_encode[32] = 
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
static const uint8_t secret_key10_encode[32] = 
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

_signing_t signing;       
_signature_t signature;
uint8_t sign_frame[MSG_LEN_SIG]; /* 定义签名帧存储数组 */ 

void initial_Encode()
{
	//密钥初始化及读取
    memset(&signing, 0, sizeof(signing));
    memcpy(signing.secret_key, secret_key_encode, 32);
	  aes_key_setup(key0[0], key_schedule, 256);	
}


void main_Encode(uint8_t msg_payload[], uint64_t Time_Stamp, uint8_t secret_ID)
{
/* 密钥初始化及读取 */
      if (secret_ID == 0)
      {
         memset(&signing, 0, sizeof(signing));
         memcpy(signing.secret_key, secret_key_encode, 32);
		  	 aes_key_setup(key0[0], key_schedule, 256);	 
	  	} 
      if (secret_ID == 1)
      {
         memset(&signing, 0, sizeof(signing));
         memcpy(signing.secret_key, secret_key1_encode, 32);
	  		 aes_key_setup(key1[0], key_schedule, 256);	
		  }
      if (secret_ID == 2)
      {
         memset(&signing, 0, sizeof(signing));
         memcpy(signing.secret_key, secret_key2_encode, 32);
		  	 aes_key_setup(key2[0], key_schedule, 256);	
	  	}
      if (secret_ID == 3)
      {
         memset(&signing, 0, sizeof(signing));
         memcpy(signing.secret_key, secret_key3_encode, 32);
	  		 aes_key_setup(key3[0], key_schedule, 256);	
	  	}
      if (secret_ID == 4)
      {
         memset(&signing, 0, sizeof(signing));
         memcpy(signing.secret_key, secret_key4_encode, 32);
	  		 aes_key_setup(key4[0], key_schedule, 256);	
	  	}		 
      if (secret_ID == 5)
      {
         memset(&signing, 0, sizeof(signing));
         memcpy(signing.secret_key, secret_key5_encode, 32);
		  	 aes_key_setup(key5[0], key_schedule, 256);	
	  	}  
      if (secret_ID == 6)
      {
         memset(&signing, 0, sizeof(signing));
         memcpy(signing.secret_key, secret_key6_encode, 32);
	  		 aes_key_setup(key6[0], key_schedule, 256);	
	  	}
      if (secret_ID == 7)
      {
         memset(&signing, 0, sizeof(signing));
         memcpy(signing.secret_key, secret_key7_encode, 32);
	  		 aes_key_setup(key7[0], key_schedule, 256);	
	  	} 
      if (secret_ID == 8)
      {
         memset(&signing, 0, sizeof(signing));
         memcpy(signing.secret_key, secret_key8_encode, 32);
			   aes_key_setup(key8[0], key_schedule, 256);	
		  }
      if (secret_ID == 9)
      {
         memset(&signing, 0, sizeof(signing));
         memcpy(signing.secret_key, secret_key9_encode, 32);
			   aes_key_setup(key9[0], key_schedule, 256);	
		  } 		
      if (secret_ID == 10)
      {
         memset(&signing, 0, sizeof(signing));
         memcpy(signing.secret_key, secret_key10_encode, 32);
			   aes_key_setup(key10[0], key_schedule, 256);	
		  }	

      /* 对飞控过来的数据进行加密处理 */			
			if (msg_payload[1] == MSG_ID_FX)
			{
										
					      MSG1++;
					      int i;	
		            signing.timestamp = Time_Stamp; 
				        uint8_t msg_FX_encode[2+MSG_LEN_FX+MSG_LEN_SIG+2]; /* 定义飞行数据密文存储数组 */
								msg_FX_encode[0] = MW_Header;				
								msg_FX_encode[1] = MSG_ID_FX;	
								BYTE plaintext[1][MSG_LEN_FX];
								BYTE msg_AES[MSG_LEN_FX];
								memcpy(&plaintext[0][0], &msg_payload[0], MSG_LEN_FX);	/* 将mavlink payload结构体转为明文 error */	
								aes_encrypt_ctr(plaintext[0], MSG_LEN_FX, msg_AES, key_schedule, 256, iv[0]);  /* 使用AES算法加密，并将密文存储到msg_AES中，此处key_schedule为秘钥 */
								sign_Encode(msg_AES, Time_Stamp); 				
								for (i=0;i<MSG_LEN_FX;i++)
								{
									msg_FX_encode[i+2] = msg_AES[i];
								}
								for (i=0;i<MSG_LEN_SIG;i++)
								{
									msg_FX_encode[i+MSG_LEN_FX+2] = sign_frame[i];
								}
								msg_FX_encode[sizeof(msg_FX_encode)-2] = 0X0D;
								msg_FX_encode[sizeof(msg_FX_encode)-1] = 0X0A;								
								HAL_UART_Transmit(&huart3,(uint8_t *)msg_FX_encode,sizeof(msg_FX_encode),0xffff);   /* 利用串口3将加密候的数据发送出去 */									
								if (IF_DEBUG == 1)
								{
										uint8_t f;
										for (f=0; f < sizeof(msg_FX_encode); f++)
										{
											 printf("Ciphertext_FX%d:%02X\r\n",f, msg_FX_encode[f]);
										} 
									 
								}
				}
								
				if (msg_payload[1] == MSG_ID_YK)
				{

					      MSG2++;
					      int i;	
		            signing.timestamp = Time_Stamp; 					
                uint8_t msg_YK_encode[2+MSG_LEN_YK+MSG_LEN_SIG+2]; /* 定义遥控数据密文存储数组 */	
								msg_YK_encode[0] = MW_Header;				
								msg_YK_encode[1] = MSG_ID_YK;					
								BYTE plaintext_YK[1][MSG_LEN_YK];
								BYTE msg_AES_YK[MSG_LEN_YK];	
								memcpy(&plaintext_YK[0][0], &msg_payload[0], MSG_LEN_YK);	
								aes_encrypt_ctr(plaintext_YK[0], MSG_LEN_YK, msg_AES_YK, key_schedule, 256, iv[0]);
								sign_Encode(msg_AES_YK, Time_Stamp);				
								for (i=0;i<MSG_LEN_YK;i++)
								{
									msg_YK_encode[i+2] = msg_AES_YK[i];
								}
								for (i=0;i<MSG_LEN_SIG;i++)
								{
									msg_YK_encode[i+MSG_LEN_YK+2] = sign_frame[i];
								}	
								msg_YK_encode[sizeof(msg_YK_encode)-2] = 0X0D;
								msg_YK_encode[sizeof(msg_YK_encode)-1] = 0X0A;								
								HAL_UART_Transmit(&huart3,(uint8_t *)msg_YK_encode,sizeof(msg_YK_encode),0xffff); 
								if (IF_DEBUG == 1)
								{
										uint8_t f;
										for (f=0; f < sizeof(msg_YK_encode); f++)
										{
											 printf("Ciphertext_YK%d:%02X\r\n",f, msg_YK_encode[f]);
										} 
									 
								}
					}
							
				if (msg_payload[1] == MSG_ID_ZT)
				{

					      MSG3++;	
					      int i;	
		            signing.timestamp = Time_Stamp; 					
                uint8_t msg_ZT_encode[2+MSG_LEN_ZT+MSG_LEN_SIG+2]; /* 定义状态数据密文存储数组 */	
								msg_ZT_encode[0] = MW_Header;				
								msg_ZT_encode[1] = MSG_ID_ZT;						
								BYTE plaintext_ZT[1][MSG_LEN_ZT];
								BYTE msg_AES_ZT[MSG_LEN_ZT];				
								memcpy(&plaintext_ZT[0][0], &msg_payload[0], MSG_LEN_ZT);			
								aes_encrypt_ctr(plaintext_ZT[0], MSG_LEN_ZT, msg_AES_ZT, key_schedule, 256, iv[0]);
								sign_Encode(msg_AES_ZT, Time_Stamp);			
								for (i=0;i<MSG_LEN_ZT;i++)
								{
									msg_ZT_encode[i+2] = msg_AES_ZT[i];
								}
								for (i=0;i<MSG_LEN_SIG;i++)
								{
									msg_ZT_encode[i+MSG_LEN_ZT+2] = sign_frame[i];
								}
								msg_ZT_encode[sizeof(msg_ZT_encode)-2] = 0X0D;
								msg_ZT_encode[sizeof(msg_ZT_encode)-1] = 0X0A;	
								HAL_UART_Transmit(&huart3,(uint8_t *)msg_ZT_encode,sizeof(msg_ZT_encode),0xffff);  									
								if (IF_DEBUG == 1)
								{
										uint8_t f;
										for (f=0; f < sizeof(msg_ZT_encode); f++)
										{
											 printf("Ciphertext_ZT%d:%02X\r\n",f, msg_ZT_encode[f]);
										} 
									 
								}
					}								

			if (msg_payload[1] == MSG_ID_HX)
			{

					      MSG4++;	
					      int i;	
		            signing.timestamp = Time_Stamp; 				
                uint8_t msg_HX_encode[2+MSG_LEN_HX+MSG_LEN_SIG+2]; /* 定义航线数据密文存储数组 */				
								msg_HX_encode[0] = MW_Header;				
								msg_HX_encode[1] = MSG_ID_HX;					
								BYTE plaintext_HX[1][MSG_LEN_HX];
								BYTE msg_AES_HX[MSG_LEN_HX];			
								memcpy(&plaintext_HX[0][0], &msg_payload[0], MSG_LEN_HX);	
								aes_encrypt_ctr(plaintext_HX[0], MSG_LEN_HX, msg_AES_HX, key_schedule, 256, iv[0]);
								sign_Encode(msg_AES_HX, Time_Stamp);			
								for (i=0;i<MSG_LEN_HX;i++)
								{
									msg_HX_encode[i+2] = msg_AES_HX[i];
								}
								for (i=0;i<MSG_LEN_SIG;i++)
								{
									msg_HX_encode[i+MSG_LEN_HX+2] = sign_frame[i];
								}
								msg_HX_encode[sizeof(msg_HX_encode)-2] = 0X0D;
								msg_HX_encode[sizeof(msg_HX_encode)-1] = 0X0A;								
								HAL_UART_Transmit(&huart3,(uint8_t *)msg_HX_encode,sizeof(msg_HX_encode),0xffff);
								if (IF_DEBUG == 1)
								{
										uint8_t f;
										for (f=0; f < sizeof(msg_HX_encode); f++)
										{
											 printf("Ciphertext_HX%d:%02X\r\n",f, msg_HX_encode[f]);
										} 
									 
								}
			}					

			if (msg_payload[1] == MSG_ID_HD)
			{
				
								MSG5++;
					      int i;	
		            signing.timestamp = Time_Stamp; 				
                uint8_t msg_HD_encode[2+MSG_LEN_HD+MSG_LEN_SIG+2]; /* 定义航点数据密文存储数组 */	
								msg_HD_encode[0] = MW_Header;				
								msg_HD_encode[1] = MSG_ID_HD;				
								BYTE plaintext_HD[1][MSG_LEN_HD];
								BYTE msg_AES_HD[MSG_LEN_HD];						
								memcpy(&plaintext_HD[0][0], &msg_payload[0], MSG_LEN_HD);		
								aes_encrypt_ctr(plaintext_HD[0], MSG_LEN_HD, msg_AES_HD, key_schedule, 256, iv[0]);
								sign_Encode(msg_AES_HD, Time_Stamp); 				
								for (i=0;i<MSG_LEN_HD;i++)
								{
									msg_HD_encode[i+2] = msg_AES_HD[i];
								}
								for (i=0;i<MSG_LEN_SIG;i++)
								{
									msg_HD_encode[i+MSG_LEN_HD+2] = sign_frame[i];
								}	
								msg_HD_encode[sizeof(msg_HD_encode)-2] = 0X0D;
								msg_HD_encode[sizeof(msg_HD_encode)-1] = 0X0A;								
                HAL_UART_Transmit(&huart3,(uint8_t *)msg_HD_encode,sizeof(msg_HD_encode),0xffff);								
								if (IF_DEBUG == 1)
								{
										uint8_t f;
										for (f=0; f < sizeof(msg_HD_encode); f++)
										{
											 printf("Ciphertext_HD%d:%02X\r\n",f, msg_HD_encode[f]);
										} 
									 
								}
			}						
								
			if (msg_payload[1] == MSG_ID_DC)
			{

					      MSG6++;
					      int i;	
		            signing.timestamp = Time_Stamp; 				
                uint8_t msg_DC_encode[2+MSG_LEN_DC+MSG_LEN_SIG+2]; /* 定义参识读取密文存储数组 */
								msg_DC_encode[0] = MW_Header;				
								msg_DC_encode[1] = MSG_ID_DC;					
								BYTE plaintext_DC[1][MSG_LEN_DC];
								BYTE msg_AES_DC[MSG_LEN_DC];				
								memcpy(&plaintext_DC[0][0], &msg_payload[0], MSG_LEN_DC);			
								aes_encrypt_ctr(plaintext_DC[0], MSG_LEN_DC, msg_AES_DC, key_schedule, 256, iv[0]);
								sign_Encode(msg_AES_DC, Time_Stamp);			
								for (i=0;i<MSG_LEN_DC;i++)
								{
									msg_DC_encode[i+2] = msg_AES_DC[i];
								}
								for (i=0;i<MSG_LEN_SIG;i++)
								{
									msg_DC_encode[i+MSG_LEN_DC+2] = sign_frame[i];
								}
								msg_DC_encode[sizeof(msg_DC_encode)-2] = 0X0D;
								msg_DC_encode[sizeof(msg_DC_encode)-1] = 0X0A;									
                HAL_UART_Transmit(&huart3,(uint8_t *)msg_DC_encode,sizeof(msg_DC_encode),0xffff);									
								if (IF_DEBUG == 1)
								{
										uint8_t f;
										for (f=0; f < sizeof(msg_DC_encode); f++)
										{
											 printf("Ciphertext_DC%d:%02X\r\n",f, msg_DC_encode[f]);
										} 
									 
								}
								
			}
			     
}


void sign_Encode(uint8_t msg_AES[], uint64_t Time_Stamp)
{
		union
		{
			uint64_t t64;
			uint8_t t8[8];
		} tstamp;
	
    mavlink_sha256_ctx ctx;
	  tstamp.t64 = Time_Stamp;   //timestamp 是 uint64
    int i;
    for (i=0;i<8;i++) signature.timestamp[i] = tstamp.t8[i];
	  //signing->timestamp++;   			//为什么要加1
	  //sha256算法加密的过程
	  //初始化，设定8个哈希初值
	  mavlink_sha256_init(&ctx);
	  //加入密钥
	  mavlink_sha256_update(&ctx, signing.secret_key, sizeof(signing.secret_key));
	  //加入payload帧
	  mavlink_sha256_update(&ctx, msg_AES, sizeof(msg_AES));
	  //加入时间戳
	  mavlink_sha256_update(&ctx, signature.timestamp, sizeof(signature.timestamp));
	  //生成最终的48位密码，6个byte，并存入了签名帧中
	  mavlink_sha256_final_48(&ctx, signature.sig);
    for (i=0;i<8;i++) sign_frame[i] = signature.timestamp[i];
    for (i=0;i<6;i++) sign_frame[i+8] = signature.sig[i];
}

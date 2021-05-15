#include "main_Encode.h"
#include "sysu_sha256.h"


// 初始化, 对于AES算法，设置后的密码存在key_schedule中，若需要动态变化密码，则需要对key_schedule进行重新赋值
//256 bit密码
BYTE key[1][32] = 
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
	  aes_key_setup(key[0], key_schedule, 256);	 /* 设置密钥 */
}

void main_Encode(uint8_t msg_payload[], uint64_t Time_Stamp, uint8_t secret_ID)
{
	
        /* 密钥初始化及读取 */
			  if (secret_ID == 0)
				{
           memset(&signing, 0, sizeof(signing));
           memcpy(signing.secret_key, secret_key_encode, 32);
					 aes_key_setup(key[0], key_schedule, 256);	 /* 设置密钥 */
				}			
			  if (secret_ID == 1)
				{
           memset(&signing, 0, sizeof(signing));
           memcpy(signing.secret_key, secret_key1_encode, 32);
					 aes_key_setup(key1[0], key_schedule, 256);	 /* 设置密钥 */
				}				
			  if (secret_ID == 2)
				{
           memset(&signing, 0, sizeof(signing));
           memcpy(signing.secret_key, secret_key2_encode, 32);
					 aes_key_setup(key2[0], key_schedule, 256);	 /* 设置密钥 */
				}			
			  if (secret_ID == 3)
				{
           memset(&signing, 0, sizeof(signing));
           memcpy(signing.secret_key, secret_key3_encode, 32);
					 aes_key_setup(key3[0], key_schedule, 256);	 /* 设置密钥 */
				} 				
			  if (secret_ID == 4)
				{
           memset(&signing, 0, sizeof(signing));
           memcpy(signing.secret_key, secret_key4_encode, 32);
					 aes_key_setup(key4[0], key_schedule, 256);	 /* 设置密钥 */
				}					
			  if (secret_ID == 5)
				{
           memset(&signing, 0, sizeof(signing));
           memcpy(signing.secret_key, secret_key5_encode, 32);
					 aes_key_setup(key5[0], key_schedule, 256);	 /* 设置密钥 */
				}  				
			  if (secret_ID == 6)
				{
           memset(&signing, 0, sizeof(signing));
           memcpy(signing.secret_key, secret_key6_encode, 32);
					 aes_key_setup(key6[0], key_schedule, 256);	 /* 设置密钥 */
				} 				
			  if (secret_ID == 7)
				{
           memset(&signing, 0, sizeof(signing));
           memcpy(signing.secret_key, secret_key7_encode, 32);
					 aes_key_setup(key7[0], key_schedule, 256);	 /* 设置密钥 */
				}				
			  if (secret_ID == 8)
				{
           memset(&signing, 0, sizeof(signing));
           memcpy(signing.secret_key, secret_key8_encode, 32);
					 aes_key_setup(key8[0], key_schedule, 256);	 /* 设置密钥 */
				}
			  if (secret_ID == 9)
				{
           memset(&signing, 0, sizeof(signing));
           memcpy(signing.secret_key, secret_key9_encode, 32);		
					 aes_key_setup(key9[0], key_schedule, 256);	 /* 设置密钥 */					
				}						
			  if (secret_ID == 10)
				{
           memset(&signing, 0, sizeof(signing));
           memcpy(signing.secret_key, secret_key10_encode, 32);
					 aes_key_setup(key10[0], key_schedule, 256);	 /* 设置密钥 */
				}


        /* 对地面站进来的信息进行加密 */
				
        if (msg_payload[1] == MSG_ID_ZDFX)
				{
                int i;
			          signing.timestamp = Time_Stamp; 					
                uint8_t msg_ZDFX_encode[2+MSG_LEN_ZDFX+MSG_LEN_SIG+2];         /* 指点飞行数据密文存储数组 */
								msg_ZDFX_encode[0] = 0X5A;
				        msg_ZDFX_encode[1] = MSG_ID_ZDFX;				
								BYTE plaintext_ZDFX[1][MSG_LEN_ZDFX];
								BYTE msg_AES_ZDFX[MSG_LEN_ZDFX];								
								memcpy(&plaintext_ZDFX[0][0], &msg_payload[0], MSG_LEN_ZDFX);	 /* 将mavlink payload结构体转为明文 error */	
								aes_encrypt_ctr(plaintext_ZDFX[0], MSG_LEN_ZDFX, msg_AES_ZDFX, key_schedule, 256, iv[0]);  /* 使用AES算法加密，并将密文存储到msg_AES中，此处key_schedule为秘钥 */
								sign_Encode(msg_AES_ZDFX, Time_Stamp);   
								for (i=0;i<MSG_LEN_ZDFX;i++)
								{
									msg_ZDFX_encode[i+2] = msg_AES_ZDFX[i];
								}
								for (i=0;i<MSG_LEN_SIG;i++)
								{
									msg_ZDFX_encode[i+MSG_LEN_ZDFX+2] = sign_frame[i];
								}								
								msg_ZDFX_encode[sizeof(msg_ZDFX_encode)-2] = 0X0D;
								msg_ZDFX_encode[sizeof(msg_ZDFX_encode)-1] = 0X0A;
								HAL_UART_Transmit(&huart2,(uint8_t *)msg_ZDFX_encode,sizeof(msg_ZDFX_encode),0xffff);   /* 利用串口2将加密候的数据发送出去 */										
								if (IF_DEBUG == 1)
								{
										uint8_t f;
										for (f=0; f < sizeof(msg_ZDFX_encode); f++)
										{
											 printf("Ciphertext_ZDFX%d:%02X\r\n",f, msg_ZDFX_encode[f]);	
										} 
									 
								}
				}

				if (msg_payload[1] == MSG_ID_ZDQF)
				{
                int i;
			          signing.timestamp = Time_Stamp; 
                uint8_t msg_ZDQF_encode[2+MSG_LEN_ZDQF+MSG_LEN_SIG+2];         /* 自动飞行数据密文存储数组 */		
								msg_ZDQF_encode[0] = 0X5A;
				        msg_ZDQF_encode[1] = MSG_ID_ZDQF;						
								BYTE plaintext_ZDQF[1][MSG_LEN_ZDQF];
								BYTE msg_AES_ZDQF[MSG_LEN_ZDQF];
								memcpy(&plaintext_ZDQF[0][0], &msg_payload[0], MSG_LEN_ZDQF);		/* 将mavlink payload结构体转为明文 error */	
								aes_encrypt_ctr(plaintext_ZDQF[0], MSG_LEN_ZDQF, msg_AES_ZDQF, key_schedule, 256, iv[0]);  /* 使用AES算法加密，并将密文存储到msg_AES中，此处key_schedule为秘钥 */
								sign_Encode(msg_AES_ZDQF, Time_Stamp);   
								for (i=0;i<MSG_LEN_ZDQF;i++)
								{
									msg_ZDQF_encode[i+2] = msg_AES_ZDQF[i];
								}
								for (i=0;i<MSG_LEN_SIG;i++)
								{
									msg_ZDQF_encode[i+MSG_LEN_ZDQF+2] = sign_frame[i];
								}							
								msg_ZDQF_encode[sizeof(msg_ZDQF_encode)-2] = 0X0D;
								msg_ZDQF_encode[sizeof(msg_ZDQF_encode)-1] = 0X0A;	
                HAL_UART_Transmit(&huart2,(uint8_t *)msg_ZDQF_encode,sizeof(msg_ZDQF_encode),0xffff); 								
								if (IF_DEBUG == 1)
								{
										uint8_t f;
										for (f=0; f < sizeof(msg_ZDQF_encode); f++)
										{
											 printf("Ciphertext_ZDQF%d:%02X\n",f, msg_ZDQF_encode[f]);
											 printf("\r\n");
										} 
									 
								}
					}
				
				if (msg_payload[1] == MSG_ID_ZDJL)
				{
                int i;
			          signing.timestamp = Time_Stamp; 
                uint8_t msg_ZDJL_encode[2+MSG_LEN_ZDJL+MSG_LEN_SIG+2];         /* 自动降落数据密文存储数组 */					 	
								msg_ZDJL_encode[0] = 0X5A;
				        msg_ZDJL_encode[1] = MSG_ID_ZDJL;
								BYTE plaintext_ZDJL[1][MSG_LEN_ZDJL];
								BYTE msg_AES_ZDJL[MSG_LEN_ZDJL];								
								memcpy(&plaintext_ZDJL[0][0], &msg_payload[0], MSG_LEN_ZDJL);										
								aes_encrypt_ctr(plaintext_ZDJL[0], MSG_LEN_ZDJL, msg_AES_ZDJL, key_schedule, 256, iv[0]);
								sign_Encode(msg_AES_ZDJL, Time_Stamp);   

								for (i=0;i<MSG_LEN_ZDJL;i++)
								{
									msg_ZDJL_encode[i+2] = msg_AES_ZDJL[i];
								}
								for (i=0;i<MSG_LEN_SIG;i++)
								{
									msg_ZDJL_encode[i+MSG_LEN_ZDJL+2] = sign_frame[i];
								}
								msg_ZDJL_encode[sizeof(msg_ZDJL_encode)-2] = 0X0D;
								msg_ZDJL_encode[sizeof(msg_ZDJL_encode)-1] = 0X0A;									
                HAL_UART_Transmit(&huart2,(uint8_t *)msg_ZDJL_encode,sizeof(msg_ZDJL_encode),0xffff);								
								if (IF_DEBUG == 1)
								{
										uint8_t f;
										for (f=0; f < sizeof(msg_ZDJL_encode); f++)
										{
											 printf("Ciphertext_ZDJL%d:%02X\r\n",f, msg_ZDJL_encode[f]);
										} 
									 
								}
				}						

					if (msg_payload[1] == MSG_ID_ZDFH)
					{
                int i;
			          signing.timestamp = Time_Stamp; 
                uint8_t msg_ZDFH_encode[2+MSG_LEN_ZDFH+MSG_LEN_SIG+2];         /* 自动返航数据密文存储数组 */
								msg_ZDFH_encode[0] = 0X5A;
				        msg_ZDFH_encode[1] = MSG_ID_ZDFH;						
								BYTE plaintext_ZDFH[1][MSG_LEN_ZDFH];
								BYTE msg_AES_ZDFH[MSG_LEN_ZDFH];								
								memcpy(&plaintext_ZDFH[0][0], &msg_payload[0], MSG_LEN_ZDFH);		
								aes_encrypt_ctr(plaintext_ZDFH[0], MSG_LEN_ZDFH, msg_AES_ZDFH, key_schedule, 256, iv[0]);
								sign_Encode(msg_AES_ZDFH, Time_Stamp);   
								for (i=0;i<MSG_LEN_ZDFH;i++)
								{
									msg_ZDFH_encode[i+2] = msg_AES_ZDFH[i];
								}
								for (i=0;i<MSG_LEN_SIG;i++)
								{
									msg_ZDFH_encode[i+MSG_LEN_ZDFH+2] = sign_frame[i];
								}
								msg_ZDFH_encode[sizeof(msg_ZDFH_encode)-2] = 0X0D;
								msg_ZDFH_encode[sizeof(msg_ZDFH_encode)-1] = 0X0A;								
                HAL_UART_Transmit(&huart2,(uint8_t *)msg_ZDFH_encode,sizeof(msg_ZDFH_encode),0xffff);
								
								if (IF_DEBUG == 1)
								{
										uint8_t f;
										for (f=0; f < sizeof(msg_ZDFH_encode); f++)
										{
											 printf("Ciphertext_ZDJL%d:%02X\r\n",f, msg_ZDFH_encode[f]);
										} 
									 
								}
					}		

        if (msg_payload[1] == MSG_ID_GBGD)
				{
                int i;
			          signing.timestamp = Time_Stamp; 
                uint8_t msg_GBGD_encode[2+MSG_LEN_GBGD+MSG_LEN_SIG+2];         /* 改变高度数据密文存储数组 */
								msg_GBGD_encode[0] = 0X5A;
				        msg_GBGD_encode[1] = MSG_ID_GBGD;						
								BYTE plaintext_GBGD[1][MSG_LEN_GBGD];
								BYTE msg_AES_GBGD[MSG_LEN_GBGD];
								memcpy(&plaintext_GBGD[0][0], &msg_payload[0], MSG_LEN_GBGD);		
								aes_encrypt_ctr(plaintext_GBGD[0], MSG_LEN_GBGD, msg_AES_GBGD, key_schedule, 256, iv[0]);
								sign_Encode(msg_AES_GBGD, Time_Stamp);   
								for (i=0;i<MSG_LEN_GBGD;i++)
								{
									msg_GBGD_encode[i+2] = msg_AES_GBGD[i];
								}
								for (i=0;i<MSG_LEN_SIG;i++)
								{
									msg_GBGD_encode[i+MSG_LEN_GBGD+2] = sign_frame[i];
								}
								msg_GBGD_encode[sizeof(msg_GBGD_encode)-2] = 0X0D;
								msg_GBGD_encode[sizeof(msg_GBGD_encode)-1] = 0X0A;									
                HAL_UART_Transmit(&huart2,(uint8_t *)msg_GBGD_encode,sizeof(msg_GBGD_encode),0xffff);									
								if (IF_DEBUG == 1)
								{
										uint8_t f;
										for (f=0; f < sizeof(msg_GBGD_encode); f++)
										{
											 printf("Ciphertext_GBGD%d:%02X\r\n",f, msg_GBGD_encode[f]);
										} 
									 
								}
					}

        if (msg_payload[1] == MSG_ID_UNLOCK)
				{
                int i;
			          signing.timestamp = Time_Stamp; 
		            uint8_t msg_UNLOCK_encode[2+MSG_LEN_UNLOCK+MSG_LEN_SIG+2];     /* 解锁数据密文存储数组 */
								msg_UNLOCK_encode[0] = 0X5A;
				        msg_UNLOCK_encode[1] = MSG_ID_UNLOCK;	
								BYTE plaintext_UNLOCK[1][MSG_LEN_UNLOCK];
								BYTE msg_AES_UNLOCK[MSG_LEN_UNLOCK];
								memcpy(&plaintext_UNLOCK[0][0], &msg_payload[0], MSG_LEN_UNLOCK);	
								aes_encrypt_ctr(plaintext_UNLOCK[0], MSG_LEN_UNLOCK, msg_AES_UNLOCK, key_schedule, 256, iv[0]);
								sign_Encode(msg_AES_UNLOCK, Time_Stamp);   
								for (i=0;i<MSG_LEN_UNLOCK;i++)
								{
									msg_UNLOCK_encode[i+2] = msg_AES_UNLOCK[i];
								}
								for (i=0;i<MSG_LEN_SIG;i++)
								{
									msg_UNLOCK_encode[i+MSG_LEN_UNLOCK+2] = sign_frame[i];
								}
								msg_UNLOCK_encode[sizeof(msg_UNLOCK_encode)-2] = 0X0D;
								msg_UNLOCK_encode[sizeof(msg_UNLOCK_encode)-1] = 0X0A;								
                HAL_UART_Transmit(&huart2,(uint8_t *)msg_UNLOCK_encode,sizeof(msg_UNLOCK_encode),0xffff);																
								if (IF_DEBUG == 1)
								{
										uint8_t f;
										for (f=0; f < sizeof(msg_UNLOCK_encode); f++)
										{
											 printf("Ciphertext_UNLOCK%d:%02X\n",f, msg_UNLOCK_encode[f]);
											 printf("\r\n");
										} 
									 
								}
					}			
					
														
        if (msg_payload[1] == MSG_ID_LOCK)
				{
                int i;
			          signing.timestamp = Time_Stamp; 
		            uint8_t msg_LOCK_encode[2+MSG_LEN_LOCK+MSG_LEN_SIG+2];         /* 加锁数据密文存储数组 */
								msg_LOCK_encode[0] = 0X5A;
				        msg_LOCK_encode[1] = MSG_ID_LOCK;	
								BYTE plaintext_LOCK[1][MSG_LEN_LOCK];
								BYTE msg_AES_LOCK[MSG_LEN_LOCK];
								memcpy(&plaintext_LOCK[0][0], &msg_payload[0], MSG_LEN_LOCK);		
								aes_encrypt_ctr(plaintext_LOCK[0], MSG_LEN_LOCK, msg_AES_LOCK, key_schedule, 256, iv[0]);
								sign_Encode(msg_AES_LOCK, Time_Stamp);   
								for (i=0;i<MSG_LEN_LOCK;i++)
								{
									msg_LOCK_encode[i+2] = msg_AES_LOCK[i];
								}
								for (i=0;i<MSG_LEN_SIG;i++)
								{
									msg_LOCK_encode[i+MSG_LEN_LOCK+2] = sign_frame[i];
								}
								msg_LOCK_encode[sizeof(msg_LOCK_encode)-2] = 0X0D;
								msg_LOCK_encode[sizeof(msg_LOCK_encode)-1] = 0X0A;									
                HAL_UART_Transmit(&huart2,(uint8_t *)msg_LOCK_encode,sizeof(msg_LOCK_encode),0xffff);										
								if (IF_DEBUG == 1)
								{
										uint8_t f;
										for (f=0; f < sizeof(msg_LOCK_encode); f++)
										{
											 printf("Ciphertext_LOCK%d:%02X\r\n",f, msg_LOCK_encode[f]);
										} 
								}
				}		

        if (msg_payload[1] == MSG_ID_ONHX)
				{
                int i;
			          signing.timestamp = Time_Stamp; 
                uint8_t msg_ONHX_encode[2+MSG_LEN_ONHX+MSG_LEN_SIG+2];         /* 开启航线数据密文存储数组 */
								msg_ONHX_encode[0] = 0X5A;
				        msg_ONHX_encode[1] = MSG_ID_ONHX;
								BYTE plaintext_ONHX[1][MSG_LEN_ONHX];
								BYTE msg_AES_ONHX[MSG_LEN_ONHX];
								memcpy(&plaintext_ONHX[0][0], &msg_payload[0], MSG_LEN_ONHX);		
								aes_encrypt_ctr(plaintext_ONHX[0], MSG_LEN_ONHX, msg_AES_ONHX, key_schedule, 256, iv[0]);
								sign_Encode(msg_AES_ONHX, Time_Stamp);   
								for (i=0;i<MSG_LEN_ONHX;i++)
								{
									msg_ONHX_encode[i+2] = msg_AES_ONHX[i];
								}
								for (i=0;i<MSG_LEN_SIG;i++)
								{
									msg_ONHX_encode[i+MSG_LEN_ONHX+2] = sign_frame[i];
								}
								msg_ONHX_encode[sizeof(msg_ONHX_encode)-2] = 0X0D;
								msg_ONHX_encode[sizeof(msg_ONHX_encode)-1] = 0X0A;								
                HAL_UART_Transmit(&huart2,(uint8_t *)msg_ONHX_encode,sizeof(msg_ONHX_encode),0xffff);
								if (IF_DEBUG == 1)
								{
										uint8_t f;
										for (f=0; f < sizeof(msg_ONHX_encode); f++)
										{
											 printf("Ciphertext_ONHX%d:%02X\r\n",f, msg_ONHX_encode[f]);
										} 	 
								}
				}	
				
        if (msg_payload[1] == MSG_ID_OFFHX)
				{
                int i;
			          signing.timestamp = Time_Stamp; 
                uint8_t msg_OFFHX_encode[2+MSG_LEN_OFFHX+MSG_LEN_SIG+2];       /* 暂停航线数据密文存储数组 */						
								msg_OFFHX_encode[0] = 0X5A;
				        msg_OFFHX_encode[1] = MSG_ID_OFFHX;
								BYTE plaintext_OFFHX[1][MSG_LEN_OFFHX];
								BYTE msg_AES_OFFHX[MSG_LEN_OFFHX];
								memcpy(&plaintext_OFFHX[0][0], &msg_payload[0], MSG_LEN_OFFHX);	
								aes_encrypt_ctr(plaintext_OFFHX[0], MSG_LEN_OFFHX, msg_AES_OFFHX, key_schedule, 256, iv[0]);
								sign_Encode(msg_AES_OFFHX, Time_Stamp);   
								for (i=0;i<MSG_LEN_OFFHX;i++)
								{
									msg_OFFHX_encode[i+2] = msg_AES_OFFHX[i];
								}
								for (i=0;i<MSG_LEN_SIG;i++)
								{
									msg_OFFHX_encode[i+MSG_LEN_OFFHX+2] = sign_frame[i];
								}
								msg_OFFHX_encode[sizeof(msg_OFFHX_encode)-2] = 0X0D;
								msg_OFFHX_encode[sizeof(msg_OFFHX_encode)-1] = 0X0A;								
                HAL_UART_Transmit(&huart2,(uint8_t *)msg_OFFHX_encode,sizeof(msg_OFFHX_encode),0xffff);
								if (IF_DEBUG == 1)
								{
										uint8_t f;
										for (f=0; f < sizeof(msg_OFFHX_encode); f++)
										{
											 printf("Ciphertext_OFFHX%d:%02X\r\n",f, msg_OFFHX_encode[f]);
										} 
									 
								}
			 }

        if (msg_payload[1] == MSG_ID_GSMS)
				{
                int i;
			          signing.timestamp = Time_Stamp; 
					      uint8_t msg_GSMS_encode[2+MSG_LEN_GSMS+MSG_LEN_SIG+2];         /* 跟随模式数据密文存储数组 */
								msg_GSMS_encode[0] = 0X5A;
				        msg_GSMS_encode[1] = MSG_ID_GSMS;
								BYTE plaintext_GSMS[1][MSG_LEN_GSMS];
								BYTE msg_AES_GSMS[MSG_LEN_GSMS];
								memcpy(&plaintext_GSMS[0][0], &msg_payload[0], MSG_LEN_GSMS);		
								aes_encrypt_ctr(plaintext_GSMS[0], MSG_LEN_GSMS, msg_AES_GSMS, key_schedule, 256, iv[0]);
								sign_Encode(msg_AES_GSMS, Time_Stamp);   
								for (i=0;i<MSG_LEN_GSMS;i++)
								{
									msg_GSMS_encode[i+2] = msg_AES_GSMS[i];
								}
								for (i=0;i<MSG_LEN_SIG;i++)
								{
									msg_GSMS_encode[i+MSG_LEN_GSMS+2] = sign_frame[i];
								}
								msg_GSMS_encode[sizeof(msg_GSMS_encode)-2] = 0X0D;
								msg_GSMS_encode[sizeof(msg_GSMS_encode)-1] = 0X0A;								
								HAL_UART_Transmit(&huart2,(uint8_t *)msg_GSMS_encode,sizeof(msg_GSMS_encode),0xffff);
								if (IF_DEBUG == 1)
								{
										uint8_t f;
										for (f=0; f < sizeof(msg_GSMS_encode); f++)
										{
											 printf("Ciphertext_GSMS%d:%02X\r\n",f, msg_GSMS_encode[f]);
										} 
									 
								}
				}	
	
        if (msg_payload[1] == MSG_ID_ONBOARD)
				{
                int i;
			          signing.timestamp = Time_Stamp; 
		            uint8_t msg_ONBOARD_encode[2+MSG_LEN_ONBOARD+MSG_LEN_SIG+2];   /* ONBOARD数据密文存储数组 */
								msg_ONBOARD_encode[0] = 0X5A;
				        msg_ONBOARD_encode[1] = MSG_ID_ONBOARD;
								BYTE plaintext_ONBOARD[1][MSG_LEN_ONBOARD];
								BYTE msg_AES_ONBOARD[MSG_LEN_ONBOARD];
								memcpy(&plaintext_ONBOARD[0][0], &msg_payload[0], MSG_LEN_ONBOARD);		
								aes_encrypt_ctr(plaintext_ONBOARD[0], MSG_LEN_ONBOARD, msg_AES_ONBOARD, key_schedule, 256, iv[0]);
								sign_Encode(msg_AES_ONBOARD, Time_Stamp);   
								for (i=0;i<MSG_LEN_ONBOARD;i++)
								{
									msg_ONBOARD_encode[i+2] = msg_AES_ONBOARD[i];
								}
								for (i=0;i<MSG_LEN_SIG;i++)
								{
									msg_ONBOARD_encode[i+MSG_LEN_ONBOARD+2] = sign_frame[i];
								}
								msg_ONBOARD_encode[sizeof(msg_ONBOARD_encode)-2] = 0X0D;
								msg_ONBOARD_encode[sizeof(msg_ONBOARD_encode)-1] = 0X0A;								
								HAL_UART_Transmit(&huart2,(uint8_t *)msg_ONBOARD_encode,sizeof(msg_ONBOARD_encode),0xffff);
								if (IF_DEBUG == 1)
								{
										uint8_t f;
										for (f=0; f < sizeof(msg_ONBOARD_encode); f++)
										{
											 printf("Ciphertext_ONBOARD%d:%02X\r\n",f, msg_ONBOARD_encode[f]);
										} 
								}
					}									
										
       if (msg_payload[1] == MSG_ID_OFFBOARD)
			 {
                int i;
			          signing.timestamp = Time_Stamp; 	 
                uint8_t msg_OFFBOARD_encode[2+MSG_LEN_OFFBOARD+MSG_LEN_SIG+2]; /* OFFBOARD数据密文存储数组 */	
								msg_OFFBOARD_encode[0] = 0X5A;
				        msg_OFFBOARD_encode[1] = MSG_ID_OFFBOARD;
								BYTE plaintext_OFFBOARD[1][MSG_LEN_OFFBOARD];
								BYTE msg_AES_OFFBOARD[MSG_LEN_OFFBOARD];
								memcpy(&plaintext_OFFBOARD[0][0], &msg_payload[0], MSG_LEN_OFFBOARD);		
								aes_encrypt_ctr(plaintext_OFFBOARD[0], MSG_LEN_OFFBOARD, msg_AES_OFFBOARD, key_schedule, 256, iv[0]);
								sign_Encode(msg_AES_OFFBOARD, Time_Stamp);   
								for (i=0;i<MSG_LEN_OFFBOARD;i++)
								{
									msg_OFFBOARD_encode[i+2] = msg_AES_OFFBOARD[i];
								}
								for (i=0;i<MSG_LEN_SIG;i++)
								{
									msg_OFFBOARD_encode[i+MSG_LEN_OFFBOARD+2] = sign_frame[i];
								}
								msg_OFFBOARD_encode[sizeof(msg_OFFBOARD_encode)-2] = 0X0D;
								msg_OFFBOARD_encode[sizeof(msg_OFFBOARD_encode)-1] = 0X0A;								
								HAL_UART_Transmit(&huart2,(uint8_t *)msg_OFFBOARD_encode,sizeof(msg_OFFBOARD_encode),0xffff);
								if (IF_DEBUG == 1)
								{
										uint8_t f;
										for (f=0; f < sizeof(msg_OFFBOARD_encode); f++)
										{
											 printf("Ciphertext_OFFBOARD%d:%02X\r\n",f, msg_OFFBOARD_encode[f]);
										} 
								}
				}		

        if (msg_payload[1] == MSG_ID_ZWJZ)
				{
                int i;
			          signing.timestamp = Time_Stamp; 
                uint8_t msg_ZWJZ_encode[2+MSG_LEND_ZWJZ+MSG_LEN_SIG+2];        /* 开始遥控器中位校准数据密文存储数组 */					
								msg_ZWJZ_encode[0] = 0X5A;
				        msg_ZWJZ_encode[1] = MSG_ID_ZWJZ;
								BYTE plaintext_ZWJZ[1][MSG_LEND_ZWJZ];
								BYTE msg_AES_ZWJZ[MSG_LEND_ZWJZ];
								memcpy(&plaintext_ZWJZ[0][0], &msg_payload[0], MSG_LEND_ZWJZ);		
								aes_encrypt_ctr(plaintext_ZWJZ[0], MSG_LEND_ZWJZ, msg_AES_ZWJZ, key_schedule, 256, iv[0]);
								sign_Encode(msg_AES_ZWJZ, Time_Stamp);   
								for (i=0;i<MSG_LEND_ZWJZ;i++)
								{
									msg_ZWJZ_encode[i+2] = msg_AES_ZWJZ[i];
								}
								for (i=0;i<MSG_LEN_SIG;i++)
								{
									msg_ZWJZ_encode[i+MSG_LEND_ZWJZ+2] = sign_frame[i];
								}
								msg_ZWJZ_encode[sizeof(msg_ZWJZ_encode)-2] = 0X0D;
								msg_ZWJZ_encode[sizeof(msg_ZWJZ_encode)-1] = 0X0A;								
								HAL_UART_Transmit(&huart2,(uint8_t *)msg_ZWJZ_encode,sizeof(msg_ZWJZ_encode),0xffff);
								if (IF_DEBUG == 1)
								{
										uint8_t f;
										for (f=0; f < sizeof(msg_ZWJZ_encode); f++)
										{
											 printf("Ciphertext_ZWJZ%d:%02X\n",f, msg_ZWJZ_encode[f]);
											 printf("\r\n");
										} 
								}
				}

        if (msg_payload[1] == MSG_ID_XCJZ)
				{
                int i;
			          signing.timestamp = Time_Stamp; 
                uint8_t msg_XCJZ_encode[2+MSG_LEN_XCJZ+MSG_LEN_SIG+2];         /* 开始遥控器行程校准数据密文存储数组 */						
								msg_XCJZ_encode[0] = 0X5A;
				        msg_XCJZ_encode[1] = MSG_ID_XCJZ;
								BYTE plaintext_XCJZ[1][MSG_LEN_XCJZ];
								BYTE msg_AES_XCJZ[MSG_LEN_XCJZ];
								memcpy(&plaintext_XCJZ[0][0], &msg_payload[0], MSG_LEN_XCJZ);		
								aes_encrypt_ctr(plaintext_XCJZ[0], MSG_LEN_XCJZ, msg_AES_XCJZ, key_schedule, 256, iv[0]);
								sign_Encode(msg_AES_XCJZ, Time_Stamp);   
								for (i=0;i<MSG_LEN_XCJZ;i++)
								{
									msg_XCJZ_encode[i+2] = msg_AES_XCJZ[i];
								}
								for (i=0;i<MSG_LEN_SIG;i++)
								{
									msg_XCJZ_encode[i+MSG_LEN_XCJZ+2] = sign_frame[i];
								}
								msg_XCJZ_encode[sizeof(msg_XCJZ_encode)-2] = 0X0D;
								msg_XCJZ_encode[sizeof(msg_XCJZ_encode)-1] = 0X0A;								
								HAL_UART_Transmit(&huart2,(uint8_t *)msg_XCJZ_encode,sizeof(msg_XCJZ_encode),0xffff);
								if (IF_DEBUG == 1)
								{
										uint8_t f;
										for (f=0; f < sizeof(msg_XCJZ_encode); f++)
										{
											 printf("Ciphertext_XCJZ%d:%02X\r\n",f, msg_XCJZ_encode[f]);
										} 
								}
				}	

        if (msg_payload[1] == MSG_ID_CQFK)
				{		
                int i;
			          signing.timestamp = Time_Stamp; 
					      uint8_t msg_CQFK_encode[2+MSG_LEN_CQFK+MSG_LEN_SIG+2];         /* 重启飞控数据密文存储数组 */
								msg_CQFK_encode[0] = 0X5A;
				        msg_CQFK_encode[1] = MSG_ID_CQFK;
								BYTE plaintext_CQFK[1][MSG_LEN_CQFK];
								BYTE msg_AES_CQFK[MSG_LEN_CQFK];
								memcpy(&plaintext_CQFK[0][0], &msg_payload[0], MSG_LEN_CQFK);		
								aes_encrypt_ctr(plaintext_CQFK[0], MSG_LEN_CQFK, msg_AES_CQFK, key_schedule, 256, iv[0]);
								sign_Encode(msg_AES_CQFK, Time_Stamp);   
								for (i=0;i<MSG_LEN_CQFK;i++)
								{
									msg_CQFK_encode[i+2] = msg_AES_CQFK[i];
								}
								for (i=0;i<MSG_LEN_SIG;i++)
								{
									msg_CQFK_encode[i+MSG_LEN_CQFK+2] = sign_frame[i];
								}	
								msg_CQFK_encode[sizeof(msg_CQFK_encode)-2] = 0X0D;
								msg_CQFK_encode[sizeof(msg_CQFK_encode)-1] = 0X0A;																
								HAL_UART_Transmit(&huart2,(uint8_t *)msg_CQFK_encode,sizeof(msg_CQFK_encode),0xffff);
								if (IF_DEBUG == 1)
								{
										uint8_t f;
										for (f=0; f < sizeof(msg_CQFK_encode); f++)
										{
											 printf("Ciphertext_CQFK%d:%02X\r\n",f, msg_CQFK_encode[f]);
										} 
								}
				}								
							
			
			if (msg_payload[1] == MSG_ID_XNYG)
			{
                int i;
			          signing.timestamp = Time_Stamp; 
				        MSG116 ++;
                uint8_t msg_XNYG_encode[2+MSG_LEN_XNYG+MSG_LEN_SIG+2];         /* 虚拟摇杆数据密文存储数组 */
								msg_XNYG_encode[0] = 0X5A;
				        msg_XNYG_encode[1] = MSG_ID_XNYG;				
								BYTE plaintext_XNYG[1][MSG_LEN_XNYG];
								BYTE msg_AES_XNYG[MSG_LEN_XNYG];
								memcpy(&plaintext_XNYG[0][0], &msg_payload[0], MSG_LEN_XNYG);		
								aes_encrypt_ctr(plaintext_XNYG[0], MSG_LEN_XNYG, msg_AES_XNYG, key_schedule, 256, iv[0]);
								sign_Encode(msg_AES_XNYG, Time_Stamp);   
								for (i=0;i<MSG_LEN_XNYG;i++)
								{
									msg_XNYG_encode[i+2] = msg_AES_XNYG[i];
								}
								for (i=0;i<MSG_LEN_SIG;i++)
								{
									msg_XNYG_encode[i+MSG_LEN_XNYG+2] = sign_frame[i];
								}
								msg_XNYG_encode[sizeof(msg_XNYG_encode)-2] = 0X0D;
								msg_XNYG_encode[sizeof(msg_XNYG_encode)-1] = 0X0A;
								HAL_UART_Transmit(&huart2,(uint8_t *)msg_XNYG_encode,sizeof(msg_XNYG_encode),0xffff);
								if (IF_DEBUG == 1)
								{
										uint8_t f;
										for (f=0; f < 1+MSG_LEN_XNYG+MSG_LEN_SIG; f++)
										{
											 printf("Ciphertext_XNYG%d:%02X\r\n",f, msg_XNYG_encode[f]);
										} 
									 
								}
			}

			if (msg_payload[1] == MSG_ID_HDDA)
			{
                int i;
			          signing.timestamp = Time_Stamp; 
                uint8_t msg_HDDA_encode[2+MSG_LEN_HDDA+MSG_LEN_SIG+2];         /* 航点数据（上传）数据密文存储数组 */
								msg_HDDA_encode[0] = 0X5A;
				        msg_HDDA_encode[1] = MSG_ID_HDDA;				
								BYTE plaintext_HDDA[1][MSG_LEN_HDDA];
								BYTE msg_AES_HDDA[MSG_LEN_HDDA];								
								memcpy(&plaintext_HDDA[0][0], &msg_payload[0], MSG_LEN_HDDA);		
								aes_encrypt_ctr(plaintext_HDDA[0], MSG_LEN_HDDA, msg_AES_HDDA, key_schedule, 256, iv[0]);
								sign_Encode(msg_AES_HDDA, Time_Stamp);   
								for (i=0;i<MSG_LEN_HDDA;i++)
								{
									msg_HDDA_encode[i+2] = msg_AES_HDDA[i];
								}
								for (i=0;i<MSG_LEN_SIG;i++)
								{
									msg_HDDA_encode[i+MSG_LEN_HDDA+2] = sign_frame[i];
								}
								msg_HDDA_encode[sizeof(msg_HDDA_encode)-2] = 0X0D;
								msg_HDDA_encode[sizeof(msg_HDDA_encode)-1] = 0X0A;								
								HAL_UART_Transmit(&huart2,(uint8_t *)msg_HDDA_encode,sizeof(msg_HDDA_encode),0xffff);						
								if (IF_DEBUG == 1)
								{
										uint8_t f;
										for (f=0; f < sizeof(msg_HDDA_encode); f++)
										{
											 printf("Ciphertext_HDDA%d:%02X\r\n",f, msg_HDDA_encode[f]);
										} 	 
								}						
			}			
 
			if (msg_payload[1] == MSG_ID_HDZS)
			{
                int i;
			          signing.timestamp = Time_Stamp; 
                uint8_t msg_HDZS_encode[2+MSG_LEN_HDZS+MSG_LEN_SIG+2];         /* 航点总数（上传）数据密文存储数组 */				
								msg_HDZS_encode[0] = 0X5A;
				        msg_HDZS_encode[1] = MSG_ID_HDZS;	
								BYTE plaintext_HDZS[1][MSG_LEN_HDZS];
								BYTE msg_AES_HDZS[MSG_LEN_HDZS];
								memcpy(&plaintext_HDZS[0][0], &msg_payload[0], MSG_LEN_HDZS);		
								aes_encrypt_ctr(plaintext_HDZS[0], MSG_LEN_HDZS, msg_AES_HDZS, key_schedule, 256, iv[0]);
								sign_Encode(msg_AES_HDZS, Time_Stamp);   
								for (i=0;i<MSG_LEN_HDZS;i++)
								{
									msg_HDZS_encode[i+2] = msg_AES_HDZS[i];
								}
								for (i=0;i<MSG_LEN_SIG;i++)
								{
									msg_HDZS_encode[i+MSG_LEN_HDZS+2] = sign_frame[i];
								}
								msg_HDZS_encode[sizeof(msg_HDZS_encode)-2] = 0X0D;
								msg_HDZS_encode[sizeof(msg_HDZS_encode)-1] = 0X0A;									
								HAL_UART_Transmit(&huart2,(uint8_t *)msg_HDZS_encode,sizeof(msg_HDZS_encode),0xffff);						
								if (IF_DEBUG == 1)
								{
										uint8_t f;
										for (f=0; f < sizeof(msg_HDZS_encode); f++)
										{
											 printf("Ciphertext_HDZS%d:%02X\r\n",f, msg_HDZS_encode[f]);
										}  
								}		
			}
			
			if (msg_payload[1] == MSG_ID_CSSZ)
			{
                int i;
			          signing.timestamp = Time_Stamp; 
                uint8_t msg_CSSZ_encode[2+MSG_LEN_CSSZ+MSG_LEN_SIG+2];         /* 参数设置（上传）数据密文存储数组 */				
								msg_CSSZ_encode[0] = 0X5A;
				        msg_CSSZ_encode[1] = MSG_ID_CSSZ;	
								BYTE plaintext_CSSZ[1][MSG_LEN_CSSZ];
								BYTE msg_AES_CSSZ[MSG_LEN_CSSZ];
								memcpy(&plaintext_CSSZ[0][0], &msg_payload[0], MSG_LEN_CSSZ);		
								aes_encrypt_ctr(plaintext_CSSZ[0], MSG_LEN_CSSZ, msg_AES_CSSZ, key_schedule, 256, iv[0]);
								sign_Encode(msg_AES_CSSZ, Time_Stamp);   
								for (i=0;i<MSG_LEN_CSSZ;i++)
								{
									msg_CSSZ_encode[i+2] = msg_AES_CSSZ[i];
								}
								for (i=0;i<MSG_LEN_SIG;i++)
								{
									msg_CSSZ_encode[i+MSG_LEN_CSSZ+2] = sign_frame[i];
								}
								msg_CSSZ_encode[sizeof(msg_CSSZ_encode)-2] = 0X0D;
								msg_CSSZ_encode[sizeof(msg_CSSZ_encode)-1] = 0X0A;								
								HAL_UART_Transmit(&huart2,(uint8_t *)msg_CSSZ_encode,sizeof(msg_CSSZ_encode),0xffff);
								if (IF_DEBUG == 1)
								{
										uint8_t f;
										for (f=0; f < sizeof(msg_CSSZ_encode); f++)
										{
											 printf("Ciphertext_CSSZ%d:%02X\r\n",f, msg_CSSZ_encode[f]);
										} 
								}
			}	

			if (msg_payload[1] == MSG_ID_KQSF)
			{
                int i;
			          signing.timestamp = Time_Stamp; 
				        uint8_t msg_KQSF_encode[2+MSG_LEN_KQSF+MSG_LEN_SIG+2];         /* 开启飞控算法数据密文存储数组 */
								msg_KQSF_encode[0] = 0X5A;
				        msg_KQSF_encode[1] = MSG_ID_KQSF;	
								BYTE plaintext_KQSF[1][MSG_LEN_KQSF];
								BYTE msg_AES_KQSF[MSG_LEN_KQSF];
								memcpy(&plaintext_KQSF[0][0], &msg_payload[0], MSG_LEN_KQSF);		
								aes_encrypt_ctr(plaintext_KQSF[0], MSG_LEN_KQSF, msg_AES_KQSF, key_schedule, 256, iv[0]);
								sign_Encode(msg_AES_KQSF, Time_Stamp);   
								for (i=0;i<MSG_LEN_KQSF;i++)
								{
									msg_KQSF_encode[i+2] = msg_AES_KQSF[i];
								}
								for (i=0;i<MSG_LEN_SIG;i++)
								{
									msg_KQSF_encode[i+MSG_LEN_KQSF+2] = sign_frame[i];
								}
								msg_KQSF_encode[sizeof(msg_KQSF_encode)-2] = 0X0D;
								msg_KQSF_encode[sizeof(msg_KQSF_encode)-1] = 0X0A;									
								HAL_UART_Transmit(&huart2,(uint8_t *)msg_KQSF_encode,sizeof(msg_KQSF_encode),0xffff);
								if (IF_DEBUG == 1)
								{
										uint8_t f;
										for (f=0; f < sizeof(msg_KQSF_encode); f++)
										{
											 printf("Ciphertext_KQSF%d:%02X\r\n",f, msg_KQSF_encode[f]);
										} 									 
								}
			}	
			
			
			if (msg_payload[1] == MSG_ID_MY)
			{
				        uint8_t SEC_Buffer[6];
                SEC_Buffer[0] = 0X5A;       /* Header 0 */
                SEC_Buffer[1] = 0X7E;          /* Header 1 */
				        SEC_Buffer[2] = 1;          /* ID 1 */
                SEC_Buffer[3] = msg_payload[6];/* secret_key_Buffer */
				        SEC_Buffer[4] = 0X0D;          /* End 0 */
				        SEC_Buffer[5] = 0X0A;          /* End 1 */	
				        HAL_UART_Transmit(&huart2,(uint8_t *)SEC_Buffer,sizeof(SEC_Buffer),0xffff);
				        Dynamic_key = SEC_Buffer[3];				
//								if (IF_DEBUG == 1)
//								{
				            printf("Dynamic key:%d\r\n",Dynamic_key);		
//								}									
			}			
			if (msg_payload[1] == MSG_ID_XHMY)
			{
				        uint8_t XHMY_Buffer[6];
                XHMY_Buffer[0] = 0X5A;       /* Header 0 */
                XHMY_Buffer[1] = 0X7E;          /* Header 1 */
				        XHMY_Buffer[2] = 3;          /* ID 3 */
                XHMY_Buffer[3] = MSG_ID_XHMY;/* secret_key_Buffer */
                XHMY_Buffer[4] = 0X0D;          /* End 0 */
				        XHMY_Buffer[5] = 0X0A;          /* End 1 */				        
				        HAL_UART_Transmit(&huart2,(uint8_t *)XHMY_Buffer,sizeof(XHMY_Buffer),0xffff);
		
//								if (IF_DEBUG == 1)
//								{
									printf("销毁代码");		
//								}					
                XHMY();								
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

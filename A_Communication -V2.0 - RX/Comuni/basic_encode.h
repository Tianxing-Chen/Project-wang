#ifndef __BASIC_ENCODE_H
#define __BASIC_ENCODE_H

#include <stdint.h>
#include "stm32f4xx_hal.h"
#include "stdio.h"

void XHMY(void);

extern UART_HandleTypeDef huart2;	/* 外部调用串口3发送信息 */
extern UART_HandleTypeDef huart3;	/* 外部调用串口3发送信息 */
extern uint8_t Dynamic_key;       //用于动态密钥

extern uint8_t mark1;
extern uint8_t mark2;
extern uint8_t mark3;
extern uint8_t mark4;
extern uint8_t mark5;
extern uint8_t mark6;
extern uint8_t mark7 ;
extern uint8_t mark8;
extern uint8_t mark9;
extern uint8_t mark10;
extern uint8_t msg_before_encode1[100]; 
extern uint8_t msg_before_encode2[100]; 
extern uint8_t msg_before_encode3[100]; 
extern uint8_t msg_before_encode4[100]; 
extern uint8_t msg_before_encode5[100]; 
extern uint8_t msg_before_encode6[100]; 
extern uint8_t msg_before_encode7[100]; 
extern uint8_t msg_before_encode8[100]; 
extern uint8_t msg_before_encode9[100]; 
extern uint8_t msg_before_encode10[100];

extern uint8_t MSG1_1;     
extern uint8_t MSG1_2; 
extern uint8_t MSG1_3; 
extern uint8_t MSG2_1;     
extern uint8_t MSG2_2; 
extern uint8_t MSG2_3;
extern uint8_t MSG3_1;     
extern uint8_t MSG3_2; 
extern uint8_t MSG3_3;
extern uint8_t MSG4_1;     
extern uint8_t MSG4_2; 
extern uint8_t MSG4_3;


extern uint16_t MSG116;

#define Threshold 1000

#define IF_DEBUG 0  /* 1-使能串口4打印数据，0-不使能串口4打印数据*/

#define UART3_TX_BUF_SIZE 250   /* 定义串口3发送数组大小*/
#define UART3_RX_BUF_SIZE 250   /* 定义串口3接收数组大小*/
#define UART2_TX_BUF_SIZE 250   /* 定义串口2发送数组大小*/
#define UART2_RX_BUF_SIZE 250   /* 定义串口2接收数组大小*/

#define MSG_ID_FX 1  /* 飞行数据包ID */
#define MSG_ID_YK 2  /* 遥控器数据包ID */
#define MSG_ID_ZT 3  /* 状态数据包ID */
#define MSG_ID_HX 4  /* 航线数据包ID */
#define MSG_ID_HD 5  /* 航点数据包ID */
#define MSG_ID_DC 6  /* 参数读取包ID */

#define MSG_LEN_FX 56  /* 飞行数据包大小 */
#define MSG_LEN_YK 15  /* 遥控器数据包大小 */
#define MSG_LEN_ZT 24  /* 状态数据包大小 */
#define MSG_LEN_HX 19  /* 航线数据包大小 */
#define MSG_LEN_HD 22  /* 航点数据包大小 */
#define MSG_LEN_DC 55  /* 参数读取包大小 */

#define MSG_ID_ZDFX 101  /* 指点飞行 ID */
#define MSG_ID_ZDQF 102  /* 自动飞行 ID */
#define MSG_ID_ZDJL 103  /* 自动降落 ID */
#define MSG_ID_ZDFH 104  /* 自动返航 ID */
#define MSG_ID_GBGD 105  /* 改变高度 ID */
#define MSG_ID_UNLOCK 106  /* 解锁 ID */
#define MSG_ID_LOCK 107  /* 加锁 ID */
#define MSG_ID_ONHX 108  /* 开启航线 ID */
#define MSG_ID_OFFHX 109  /* 暂停航线 ID */
#define MSG_ID_GSMS 110  /* 跟随模式 ID */
#define MSG_ID_ONBOARD 111  /* ONBOARD ID */
#define MSG_ID_OFFBOARD 112  /* OFFBOARD ID */
#define MSG_ID_ZWJZ 113  /* 开始遥控器中位校准 ID */
#define MSG_ID_XCJZ 114  /* 开始遥控器行程校准 ID */
#define MSG_ID_CQFK 115  /* 重启飞控 ID */
#define MSG_ID_XNYG 116  /* 虚拟摇杆 ID */
#define MSG_ID_HDDA 117  /* 航点数据（上传）ID */
#define MSG_ID_HDZS 118  /* 航点总数（上传）ID */
#define MSG_ID_CSSZ 119  /* 参数设置（上传）ID */
#define MSG_ID_KQSF 120  /* 开启飞控算法 ID */



#define MSG_ID_MY 200  /*动态密钥*/
#define MSG_ID_XHMY 201  /* 开启飞控算法 ID */

#define MSG_LEN_ZDFX 17  /* 指点飞行 大小 */
#define MSG_LEN_ZDQF 9  /* 自动飞行 大小 */
#define MSG_LEN_ZDJL 7  /* 自动降落 大小 */
#define MSG_LEN_ZDFH 7  /* 自动返航 大小 */
#define MSG_LEN_GBGD 9  /* 改变高度 大小 */
#define MSG_LEN_UNLOCK 7  /* 解锁 大小 */
#define MSG_LEN_LOCK 7  /* 加锁 大小 */
#define MSG_LEN_ONHX 7  /* 开启航线 大小 */
#define MSG_LEN_OFFHX 7  /* 暂停航线 大小 */
#define MSG_LEN_GSMS 7  /* 跟随模式 大小 */
#define MSG_LEN_ONBOARD 7  /* ONBOARD 大小 */
#define MSG_LEN_OFFBOARD 7  /* OFFBOARD 大小 */
#define MSG_LEND_ZWJZ 7  /* 开始遥控器中位校准 大小 */
#define MSG_LEN_XCJZ 7  /* 开始遥控器行程校准 大小 */
#define MSG_LEN_CQFK 7  /* 重启飞控 大小 */
#define MSG_LEN_XNYG 15  /* 虚拟摇杆 大小 */
#define MSG_LEN_HDDA 22  /* 航点数据（上传）大小 */
#define MSG_LEN_HDZS 8  /* 航点总数（上传）大小 */
#define MSG_LEN_CSSZ 55  /* 参数设置（上传）大小 */
#define MSG_LEN_KQSF 8  /* 开启飞控算法 大小 */

#define MSG_LEN_SIG 14  /*签名包大小*/




/* 下行数据包 */
typedef struct __sysu_dn_fxsj_t 
{
	uint8_t head;
	uint8_t msg_id;
	uint8_t target_id;
	uint8_t local_id;
	uint16_t msg_len;

	int32_t GPS_lat; /*<  int32_t*/
	int32_t GPS_lon; /*<  int32_t*/
	int32_t GPS_alt; /*<  int32_t*/
	int16_t GPS_Vn; /*<  int16_t*/
	int16_t GPS_Ve; /*<  int16_t*/
	uint8_t GPS_num; /*<  uint8_t*/
	uint32_t GPS_time; /*<  uint32_t*/
	uint16_t GPS_sec; /*<  uint16_t*/
	int16_t x; /*<  int16_t*/
	int16_t y; /*<  int16_t*/
	int16_t z; /*<  int16_t*/
	int16_t vx; /*<  int16_t*/
	int16_t vy; /*<  int16_t*/
	int16_t vz; /*<  int16_t*/
	int16_t ax; /*<  int16_t*/
	int16_t ay; /*<  int16_t*/
	int16_t az; /*<  int16_t*/
	int16_t pitch; /*<  int16_t*/
	int16_t roll; /*<  int16_t*/
	int16_t yaw; /*<  int16_t*/
	uint8_t acc_vibe; /*<  uint8_t*/
	uint8_t gyro_vibe; /*<  uint8_t*/
	uint8_t checksum; /*<  uint8_t*/
} sysu_dn_fxsj_t;


typedef struct __sysu_dn_yksj_t 
{
	uint8_t head;
	uint8_t msg_id;
	uint8_t target_id;
	uint8_t local_id;
	uint16_t msg_len;

	uint8_t man_pitch; /*<  uint8_t*/
	uint8_t man_roll; /*<  uint8_t*/
	uint8_t man_yaw; /*<  uint8_t*/
	uint8_t man_throttle; /*<  uint8_t*/
	uint8_t real_pitch; /*<  uint8_t*/
	uint8_t real_roll; /*<  uint8_t*/
	uint8_t real_yaw; /*<  uint8_t*/
	uint8_t real_throttle; /*<  uint8_t*/
	uint8_t checksum; /*<  uint8_t*/
} sysu_dn_yksj_t;

typedef struct __sysu_dn_ztsj_t 
{
	uint8_t head;
	uint8_t msg_id;
	uint8_t target_id;
	uint8_t local_id;
	uint16_t msg_len;

	uint16_t total_time; /*<  uint16_t*/
	uint16_t fly_time; /*<  uint16_t*/
	uint8_t skyway_state; /*<  uint8_t*/
	uint16_t temperature; /*<  uint16_t*/
	uint16_t bat_v; /*<  uint16_t*/
	uint8_t ctl_state; /*<  uint8_t*/
	uint8_t alert_flag; /*<  uint8_t*/
	uint8_t version; /*<  uint8_t*/
	uint8_t IMU_status; /*<  uint8_t*/
	uint8_t mag_status; /*<  uint8_t*/
	uint8_t GPS_status; /*<  uint8_t*/
	uint8_t arm_state; /*<  uint8_t*/
	uint8_t land_state; /*<  uint8_t*/
	uint8_t checksum; /*<  uint8_t*/
} sysu_dn_ztsj_t;

typedef struct __sysu_dn_hxsj_t 
{
	uint8_t head;
	uint8_t msg_id;
	uint8_t target_id;
	uint8_t local_id;
	uint16_t msg_len;

	int32_t WP_lat; /*<  int32_t*/
	int32_t WP_lon; /*<  int32_t*/
	int16_t WP_alt; /*<  int16_t*/
	uint8_t total_snum; /*<  uint8_t*/
	uint8_t seq; /*<  uint8_t*/
	uint8_t checksum; /*<  uint8_t*/
} sysu_dn_hxsj_t;

typedef struct __sysu_dn_hdsj_t 
{
	uint8_t head;
	uint8_t msg_id;
	uint8_t target_id;
	uint8_t local_id;
	uint16_t msg_len;
	
	int32_t WP_lat; /*<  int32_t*/
	int32_t WP_lon; /*<  int32_t*/
	int32_t WP_alt; /*<  int32_t*/
	uint16_t WP_time; /*<  int16_t*/
	uint16_t WP_speed; /*<  int16_t*/
	uint8_t WP_seq; /*<  uint8_t*/
	uint8_t checksum; /*<  uint8_t*/
} sysu_dn_hdsj_t;

typedef struct __sysu_dn_dcsj_t 
{
	uint8_t head;
	uint8_t msg_id;
	uint8_t target_id;
	uint8_t local_id;
	uint16_t msg_len;

	uint16_t ang_p; /*<  uint16_t*/
	uint16_t ang_i; /*<  uint16_t*/
	uint16_t ang_d; /*<  uint16_t*/
	uint16_t vel_p; /*<  uint16_t*/
	uint16_t vel_i; /*<  uint16_t*/
	uint16_t vel_d; /*<  uint16_t*/
	uint16_t pos_p; /*<  uint16_t*/
	uint16_t att_p; /*<  uint16_t*/
	uint16_t alt_p; /*<  uint16_t*/
	uint16_t thr_p; /*<  uint16_t*/
	uint16_t thr_i; /*<  uint16_t*/
	uint16_t thr_d; /*<  uint16_t*/
	uint16_t vel_hor_max; /*<  uint16_t*/
	uint16_t vel_up_max; /*<  uint16_t*/
	uint16_t vel_dn_max; /*<  uint16_t*/
	uint16_t acc_hor_max; /*<  uint16_t*/
	uint16_t acc_ver_max; /*<  uint16_t*/
	
	uint16_t ang_max; /*<  uint16_t*/
	uint16_t yawrate_max; /*<  uint16_t*/
	uint16_t hgt_max; /*<  uint16_t*/
	uint16_t dis_max; /*<  uint16_t*/
	uint8_t a1; /*<  uint8_t*/
	uint8_t a2; /*<  uint8_t*/
	uint8_t a3; /*<  uint8_t*/
	uint8_t a4; /*<  uint8_t*/
	uint8_t a5; /*<  uint8_t*/
	uint8_t checksum; /*<  uint8_t*/
} sysu_dn_dcsj_t;




/* 上行数据包 */
typedef struct __sysu_dn_zdfx_t   /* 指点飞行 */
{
	uint8_t head;
	uint8_t msg_id;
	uint8_t target_id;
	uint8_t local_id;
	uint16_t msg_len;

	int32_t WP_lat; /*<  int32_t */
	int32_t WP_lon; /*<  int32_t */
	int32_t WP_alt; /*<  int32_t */
	uint8_t checksum; /*<  uint8_t*/
} sysu_dn_zdfx_t;

typedef struct __sysu_dn_zdqf_t  /* 自动飞行 */
{
	uint8_t head;
	uint8_t msg_id;
	uint8_t target_id;
	uint8_t local_id;
	uint16_t msg_len;

	uint16_t TK_alt; /*<  int32_t */
	uint8_t checksum; /*<  uint8_t*/
} sysu_dn_zdqf_t;

typedef struct __sysu_dn_zdjl_t  /* 自动降落 */
{
	uint8_t head;
	uint8_t msg_id;
	uint8_t target_id;
	uint8_t local_id;
	uint16_t msg_len;

	uint8_t checksum; /*<  uint8_t*/
} sysu_dn_zdjl_t;

typedef struct __sysu_dn_zdfh_t  /* 自动返航 */
{
	uint8_t head;
	uint8_t msg_id;
	uint8_t target_id;
	uint8_t local_id;
	uint16_t msg_len;

	uint8_t checksum; /*<  uint8_t*/
} sysu_dn_zdfh_t;

typedef struct __sysu_dn_gbgd_t  /* 改变高度 */
{
	uint8_t head;
	uint8_t msg_id;
	uint8_t target_id;
	uint8_t local_id;
	uint16_t msg_len;
  
	uint16_t CH_alt;  /*<  uint16_t*/
	uint8_t checksum; /*<  uint8_t*/
} sysu_dn_gbgd_t;

typedef struct __sysu_dn_unlock_t  /* 解锁 */
{
	uint8_t head;
	uint8_t msg_id;
	uint8_t target_id;
	uint8_t local_id;
	uint16_t msg_len;

	uint8_t checksum; /*<  uint8_t*/
} sysu_dn_unlock_t;

typedef struct __sysu_dn_lock_t   /* 加锁 */
{
	uint8_t head;
	uint8_t msg_id;
	uint8_t target_id;
	uint8_t local_id;
	uint16_t msg_len;

	uint8_t checksum; /*<  uint8_t*/
} sysu_dn_lock_t;

typedef struct __sysu_dn_onhx_t   /* 开启航线 */
{
	uint8_t head;
	uint8_t msg_id;
	uint8_t target_id;
	uint8_t local_id;
	uint16_t msg_len;

	uint8_t checksum; /*<  uint8_t*/
} sysu_dn_onhx_t;

typedef struct __sysu_dn_offhx_t   /* 暂停航线 */
{
	uint8_t head;
	uint8_t msg_id;
	uint8_t target_id;
	uint8_t local_id;
	uint16_t msg_len;

	uint8_t checksum; /*<  uint8_t*/
} sysu_dn_offhx_t;

typedef struct __sysu_dn_gsms_t   /* 跟随模式 */
{
	uint8_t head;
	uint8_t msg_id;
	uint8_t target_id;
	uint8_t local_id;
	uint16_t msg_len;

	uint8_t checksum; /*<  uint8_t*/
} sysu_dn_gsms_t;

typedef struct __sysu_dn_onboard_t   /* ONBOARD */
{
	uint8_t head;
	uint8_t msg_id;
	uint8_t target_id;
	uint8_t local_id;
	uint16_t msg_len;

	uint8_t checksum; /*<  uint8_t*/
} sysu_dn_onboard_t;

typedef struct __sysu_dn_offboard_t    /* OFFBOARD */
{
	uint8_t head;
	uint8_t msg_id;
	uint8_t target_id;
	uint8_t local_id;
	uint16_t msg_len;

	uint8_t checksum; /*<  uint8_t*/
} sysu_dn_offboard_t;

typedef struct __sysu_dn_zwjz_t       /* 开始遥控器中位校准 */
{
	uint8_t head;
	uint8_t msg_id;
	uint8_t target_id;
	uint8_t local_id;
	uint16_t msg_len;

	uint8_t checksum; /*<  uint8_t*/
} sysu_dn_zwjz_t;

typedef struct __sysu_dn_xcjz_t      /* 开始遥控器行程校准 */
{
	uint8_t head;
	uint8_t msg_id;
	uint8_t target_id;
	uint8_t local_id;
	uint16_t msg_len;

	uint8_t checksum; /*<  uint8_t*/
} sysu_dn_xcjz_t;

typedef struct __sysu_dn_cqfk_t      /* 重启飞控 */
{
	uint8_t head;
	uint8_t msg_id;
	uint8_t target_id;
	uint8_t local_id;
	uint16_t msg_len;

	uint8_t checksum; /*<  uint8_t*/
} sysu_dn_cqfk_t;

typedef struct __sysu_dn_xnyg_t      /* 虚拟摇杆 */
{
	uint8_t head;
	uint8_t msg_id;
	uint8_t target_id;
	uint8_t local_id;
	uint16_t msg_len;
	
	uint16_t VS_pitch;
	uint16_t VS_roll;
	uint16_t VS_yaw;
	uint16_t VS_throttle;	
	uint8_t checksum; /*<  uint8_t*/
} sysu_dn_xnyg_t;

typedef struct __sysu_dn_hdda_t       /* 航点数据（上传）*/
{
	uint8_t head;
	uint8_t msg_id;
	uint8_t target_id;
	uint8_t local_id;
	uint16_t msg_len;
	
	int32_t WP_lat; /*<  int32_t*/
	int32_t WP_lon; /*<  int32_t*/
	int32_t WP_alt; /*<  int32_t*/
	uint16_t WP_time; /*<  uint16_t*/
	uint16_t WP_speed; /*<  uint16_t*/
	uint8_t WP_seq; /*<  uint8_t*/
	uint8_t checksum; /*<  uint8_t*/
} sysu_dn_hdda_t;

typedef struct __sysu_dn_hdzs_t       /* 航点总数（上传）*/
{
	uint8_t head;
	uint8_t msg_id;
	uint8_t target_id;
	uint8_t local_id;
	uint16_t msg_len;

	uint8_t WP_num;   /*<  uint8_t*/
	uint8_t checksum; /*<  uint8_t*/
} sysu_dn_hdzs_t;

typedef struct __sysu_dn_cssz_t      /* 参数设置（上传）*/
{
	uint8_t head;
	uint8_t msg_id;
	uint8_t target_id;
	uint8_t local_id;
	uint16_t msg_len;

	uint16_t ang_p; /*<  uint16_t*/
	uint16_t ang_i; /*<  uint16_t*/
	uint16_t ang_d; /*<  uint16_t*/
	uint16_t vel_p; /*<  uint16_t*/
	uint16_t vel_i; /*<  uint16_t*/
	uint16_t vel_d; /*<  uint16_t*/
	uint16_t pos_p; /*<  uint16_t*/
	uint16_t att_p; /*<  uint16_t*/
	uint16_t alt_p; /*<  uint16_t*/
	uint16_t thr_p; /*<  uint16_t*/
	uint16_t thr_i; /*<  uint16_t*/
	uint16_t thr_d; /*<  uint16_t*/
	uint16_t vel_hor_max; /*<  uint16_t*/
	uint16_t vel_up_max; /*<  uint16_t*/
	uint16_t vel_dn_max; /*<  uint16_t*/
	uint16_t acc_hor_max; /*<  uint16_t*/
	uint16_t acc_ver_max; /*<  uint16_t*/
	
	uint16_t ang_max; /*<  uint16_t*/
	uint16_t yawrate_max; /*<  uint16_t*/
	uint16_t hgt_max; /*<  uint16_t*/
	uint16_t dis_max; /*<  uint16_t*/
	uint8_t a1; /*<  uint8_t*/
	uint8_t a2; /*<  uint8_t*/
	uint8_t a3; /*<  uint8_t*/
	uint8_t a4; /*<  uint8_t*/
	uint8_t a5; /*<  uint8_t*/
	uint8_t checksum; /*<  uint8_t*/
} sysu_dn_cssz_t;

typedef struct __sysu_dn_kqsf_t     /* 开启飞控算法 */
{
	uint8_t head;
	uint8_t msg_id;
	uint8_t target_id;
	uint8_t local_id;
	uint16_t msg_len;

	uint8_t fksf; /*<  uint8_t*/
	uint8_t checksum; /*<  uint8_t*/
} sysu_dn_kqsf_t;



#endif

#ifndef __MAIN_ENCODE_H
#define __MAIN_ENCODE_H

#include "basic_encode.h"
#include "sysu_sha256.h"
#include "encode_aes.h"
#include "stm32f4xx_hal.h"
#include <string.h>


typedef struct __signing 
{
    uint8_t flags;                     ///< MAVLINK_SIGNING_FLAG_*
    uint8_t link_id;                   ///< Same as MAVLINK_CHANNEL
    uint64_t timestamp;                ///< Timestamp, in microseconds since UNIX epoch GMT
    uint8_t secret_key[32];
} _signing_t;

typedef struct __signature 
{
    uint8_t timestamp[8]; 
    uint8_t sig[6]; 
} _signature_t;


void initial_Encode(void);
void main_Encode(uint8_t msg_payload[], uint64_t Time_Stamp, uint8_t secret_ID);
void sign_Encode(uint8_t msg_AES[], uint64_t Time_Stamp);

#endif

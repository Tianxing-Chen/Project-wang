#ifndef __MAIN_DECODE_H
#define __MAIN_DECODE_H

#include "basic_encode.h"
#include "sysu_sha256.h"
#include "encode_aes.h"
#include <stdio.h> 
#include <string.h>
#include "stm32f4xx_hal.h"


void initial_Decode(void);
void main_Decode(uint8_t msg_payload[], uint64_t Time_Stamp, uint8_t secret_ID);
void sign_Decode(uint8_t msg_AES[], uint64_t Time_Stamp);

typedef struct __signing_decode 
{
    uint8_t flags;                     ///< MAVLINK_SIGNING_FLAG_*
    uint8_t link_id;                   ///< Same as MAVLINK_CHANNEL
    uint64_t timestamp;                ///< Timestamp, in microseconds since UNIX epoch GMT
    uint8_t secret_key[32];
   // mavlink_accept_unsigned_t accept_unsigned_callback;
} _signing_decode_t;

typedef struct __signature_decode 
{
    uint8_t timestamp[8]; 
    uint8_t sig[6]; 
} _signature_decode_t;

#endif

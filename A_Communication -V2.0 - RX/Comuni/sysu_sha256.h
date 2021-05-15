#ifndef __SYSU_SHA256_H
#define __SYSU_SHA256_H

#include <stdint.h>
#include <string.h>

typedef struct
{
  uint32_t sz[2];
  uint32_t counter[8];
  union {
      unsigned char save_bytes[64];
      uint32_t save_u32[16];
  } u;
} mavlink_sha256_ctx;


void mavlink_sha256_init(mavlink_sha256_ctx *m);
void mavlink_sha256_update(mavlink_sha256_ctx *m, const void *v, uint32_t len);
void mavlink_sha256_final_48(mavlink_sha256_ctx *m, uint8_t result[6]);

// prevent conflicts with users of the header
#undef A
#undef B
#undef C
#undef D
#undef E
#undef F
#undef G
#undef H
#undef Ch
#undef ROTR
#undef Sigma0
#undef Sigma1
#undef sigma0
#undef sigma1

#endif

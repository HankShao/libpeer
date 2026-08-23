/*
 * 自定义平台熵源实现 (MBEDTLS_ENTROPY_HARDWARE_ALT)
 *
 * 背景: mbedtls 3.x 默认用 getrandom(..., flags=0) 作为平台熵源, 该调用在
 * 内核 CRNG 未初始化时(设备刚开机)会阻塞数十秒, 导致 WebRTC 建连极慢。
 * 这里提供一个非阻塞的自定义熵源, 直接读取 /dev/urandom, 保证开机即可用。
 */
#include <stdio.h>
#include <stddef.h>
#include <string.h>

#include "mbedtls/entropy.h"

int mbedtls_hardware_poll(void *data, unsigned char *output, size_t len, size_t *olen)
{
    FILE *fp;
    size_t read_len;

    ((void) data);

    *olen = 0;

    fp = fopen("/dev/urandom", "rb");
    if (fp == NULL) {
        return MBEDTLS_ERR_ENTROPY_SOURCE_FAILED;
    }

    read_len = fread(output, 1, len, fp);
    fclose(fp);

    if (read_len != len) {
        return MBEDTLS_ERR_ENTROPY_SOURCE_FAILED;
    }

    *olen = read_len;
    return 0;
}

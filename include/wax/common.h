#ifndef WAX_COMMON_H
#define WAX_COMMON_H

#include <stdio.h>
#include <stdint.h>


#define WAX_SUCCESS 0
#define WAX_ERROR 1
#define WAX_FILE_HEADER_LENGTH 16
#define WAX_MAX_COLUMNS_COUNT 16



typedef unsigned char Byte;
typedef uint32_t u32;

u32 read_n_bytes_into_u32 (Byte const *buffer, int n);



#endif
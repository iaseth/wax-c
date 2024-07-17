#ifndef WAX_H
#define WAX_H

#include <stdint.h>



const int WAX_FILE_HEADER_LENGTH = 16;

typedef unsigned char Byte;
typedef uint32_t u32;

typedef struct WaxHeader
{
	u32 version; // 2 bytes
	u32 format; // 2 bytes
	u32 header_lines_count; // 1 byte
	u32 column_count; // 1 byte
	u32 row_length; // 2 bytes
	u32 row_count; // 4 bytes
	u32 default_value; // 4 bytes
} WaxHeader;



#endif
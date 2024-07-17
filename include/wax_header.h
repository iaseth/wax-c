#ifndef WAX_HEADER_H
#define WAX_HEADER_H

#include "wax_common.h"



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


int read_header_row_from_bytes (WaxHeader *header, Byte const *buffer);
int print_header_row (WaxHeader *header);


#endif
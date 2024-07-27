#ifndef WAX_ENCODING_SCHEME_H
#define WAX_ENCODING_SCHEME_H

#include "wax/common.h"



typedef struct EncodingScheme {
	u32 code, count, width;
	u32 widths[WAX_MAX_COLUMNS_COUNT];
	u32 multipliers[WAX_MAX_COLUMNS_COUNT];
	char name[16];
} EncodingScheme;

#endif
#include "wax/common.h"



u32 read_n_bytes_into_u32 (Byte const *buffer, int n)
{
	u32 num = 0;
	for (int i = 0; i < n; ++i) {
		num = (num * 256) + buffer[i];
	}

	return num;
}


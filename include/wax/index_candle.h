#ifndef WAX_INDEX_CANDLE_H
#define WAX_INDEX_CANDLE_H

#include "wax/common.h"



typedef struct IndexCandle {
	u32 timestamp, open, high, low, close;
} IndexCandle;



#endif
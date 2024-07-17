#ifndef WAX_OPTION_CANDLE_H
#define WAX_OPTION_CANDLE_H

#include "wax.h"



typedef struct OptionCandle {
	u32 timestamp, open, high, low, close, volume, oi;
} OptionCandle;



#endif
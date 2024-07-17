#ifndef WAX_STOCK_CANDLE_H
#define WAX_STOCK_CANDLE_H

#include "wax.h"



typedef struct StockCandle {
	u32 timestamp, open, high, low, close, volume;
} StockCandle;



#endif
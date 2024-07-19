#ifndef WAX_STOCK_CANDLE_H
#define WAX_STOCK_CANDLE_H

#include "wax/common.h"



typedef struct StockCandle {
	u32 timestamp, open, high, low, close, volume;
} StockCandle;

int read_stock_candle_from_bytes(StockCandle *candle, Byte const *buffer);
int print_stock_candle(StockCandle *candle, int n);


#endif
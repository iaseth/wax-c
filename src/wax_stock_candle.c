#include "wax_stock_candle.h"



int print_stock_candle(StockCandle *candle, int n)
{
	printf("Row %3d: [ %d, %d, %d, %d, %d, %d ]\n", n, candle->timestamp,
		candle->open, candle->high, candle->low, candle->close, candle->volume);

	return WAX_SUCCESS;
}


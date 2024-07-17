#include "wax_stock_candle.h"

#include "wax_convert.h"



int read_stock_candle_from_bytes(StockCandle *candle, Byte const *buffer)
{
	candle->timestamp = read_n_bytes_into_u32(&buffer[0], 4);
	candle->open = read_n_bytes_into_u32(&buffer[4], 4);
	candle->high = read_n_bytes_into_u32(&buffer[8], 4);
	candle->low = read_n_bytes_into_u32(&buffer[12], 4);
	candle->close = read_n_bytes_into_u32(&buffer[16], 4);
	candle->volume = read_n_bytes_into_u32(&buffer[20], 4);
}


int print_stock_candle(StockCandle *candle, int n)
{
	printf("Row %3d: [ %d, %.2f, %.2f, %.2f, %.2f, %.1fM ]\n", n, candle->timestamp,
		x100(candle->open), x100(candle->high),
		x100(candle->low), x100(candle->close),
		xm(candle->volume));

	return WAX_SUCCESS;
}


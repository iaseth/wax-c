#include "wax/stock_candle.h"

#include "wax/convert.h"



int read_stock_candle_from_bytes(StockCandle *candle, Byte const *buffer)
{
	candle->timestamp = read_n_bytes_into_u32(&buffer[0], 4);
	candle->open = read_n_bytes_into_u32(&buffer[4], 3);
	candle->high = read_n_bytes_into_u32(&buffer[7], 3);
	candle->low = read_n_bytes_into_u32(&buffer[10], 3);
	candle->close = read_n_bytes_into_u32(&buffer[13], 3);
	candle->volume = read_n_bytes_into_u32(&buffer[16], 4);

	return WAX_SUCCESS;
}


int print_stock_candle(StockCandle *candle, int n)
{
	TimeOfDay t = xtod(candle->timestamp);
	printf("Row %3d: [ %02d:%02d, %.2f, %.2f, %.2f, %.2f, %.1fM ]\n", n, t.hh, t.mm,
		x100(candle->open), x100(candle->high),
		x100(candle->low), x100(candle->close),
		xm(candle->volume));

	return WAX_SUCCESS;
}


#include <stdio.h>
#include <stdlib.h>

#include "wax_common.h"
#include "wax_header.h"
#include "wax_stock_candle.h"



int main (int argc, char const *argv[])
{
	int number_of_rows_to_read = 16;

	if (argc == 1) {
		printf("Usage:\n\twaxc $filepath\n");
		return 0;
	}

	const char *filepath = argv[1];

	if (argc > 2) {
		number_of_rows_to_read = atoi(argv[2]);
	}

	FILE *ptr = fopen(filepath,"rb");
	if (ptr == NULL) {
		printf("File not found: %s\n", filepath);
		return 0;
	}

	Byte header_buffer[WAX_FILE_HEADER_LENGTH];
	fread(header_buffer, WAX_FILE_HEADER_LENGTH, 1, ptr);
	WaxHeader header;
	read_header_row(header_buffer, &header);
	print_header_row(&header);

	Byte *buffer = NULL;
	int buffer_size = 24;
	buffer = malloc(buffer_size);

	for (int i = 0; i < header.row_count; ++i) {
		fread(buffer, buffer_size, 1, ptr);
		StockCandle candle;
		candle.timestamp = read_n_bytes_into_u32(&buffer[0], 4);
		candle.open = read_n_bytes_into_u32(&buffer[4], 4);
		candle.high = read_n_bytes_into_u32(&buffer[8], 4);
		candle.low = read_n_bytes_into_u32(&buffer[12], 4);
		candle.close = read_n_bytes_into_u32(&buffer[16], 4);
		candle.volume = read_n_bytes_into_u32(&buffer[20], 4);
		printf("Row %3d: [ %d, %d, %d, %d, %d, %d ]\n", i+1, candle.timestamp,
			candle.open, candle.high, candle.low, candle.close, candle.volume);
	}

	fclose(ptr);
	free(buffer);

	return 0;
}

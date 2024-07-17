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
	read_header_row_from_bytes(&header, header_buffer);
	print_header_row(&header);

	Byte *buffer = NULL;
	int buffer_size = 24;
	buffer = malloc(buffer_size);

	for (int i = 0; i < header.row_count; ++i) {
		fread(buffer, buffer_size, 1, ptr);
		StockCandle candle;
		read_stock_candle_from_bytes(&candle, buffer);
		print_stock_candle(&candle, i+1);

		if (i+1 >= number_of_rows_to_read) break;
	}

	fclose(ptr);
	free(buffer);

	return 0;
}

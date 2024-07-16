#include <stdio.h>
#include <stdlib.h>



const int WAX_FILE_HEADER_LENGTH = 16;

typedef unsigned char Byte;

typedef struct WaxHeader
{
	int version;
	int format;
	int row_length;
	int column_count;
	int row_count;
} WaxHeader;


int read_n_bytes_into_int (Byte const *buffer, int n)
{
	int num = 0;
	for (int i = 0; i < n; ++i) {
		num = (num * 256) + buffer[i];
	}

	return num;
}


void read_header_row (Byte const *buffer, WaxHeader *header)
{
	header->version = read_n_bytes_into_int(&buffer[0], 2);
	header->format = read_n_bytes_into_int(&buffer[2], 2);
	header->row_length = read_n_bytes_into_int(&buffer[4], 2);
	header->column_count = read_n_bytes_into_int(&buffer[6], 2);
	header->row_count = read_n_bytes_into_int(&buffer[8], 4);
}


void print_header_row (WaxHeader *header)
{
	printf("\tVersion: %d\n", header->version);
	printf("\t Format: %d\n", header->format);
	printf("\t Length: %d\n", header->row_length);
	printf("\tColumns: %d\n", header->column_count);
	printf("\t   Rows: %d\n", header->row_count);
}


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

	for (int i = 0; i < 10; ++i) {
		printf("Row %3d: [ ", i+1);

		fread(buffer, buffer_size, 1, ptr);
		int t = read_n_bytes_into_int(&buffer[0], 4);
		int o = read_n_bytes_into_int(&buffer[4], 4);
		int h = read_n_bytes_into_int(&buffer[8], 4);
		int l = read_n_bytes_into_int(&buffer[12], 4);
		int c = read_n_bytes_into_int(&buffer[16], 4);
		int v = read_n_bytes_into_int(&buffer[20], 4);
		printf("%d, %d, %d, %d, %d, %d", t, o, h, l, c, v);

		printf("]\n");
	}

	fclose(ptr);
	free(buffer);

	return 0;
}

#include <stdio.h>
#include <stdlib.h>



const int WAX_FILE_HEADER_LENGTH = 16;

typedef unsigned char Byte;

typedef struct WaxHeader
{
	int version; // 2 bytes
	int format; // 2 bytes
	int header_lines_count; // 1 byte
	int column_count; // 1 byte
	int row_length; // 2 bytes
	int row_count; // 4 bytes
	int default_value; // 4 bytes
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
	header->header_lines_count = read_n_bytes_into_int(&buffer[4], 1);
	header->column_count = read_n_bytes_into_int(&buffer[5], 1);
	header->row_length = read_n_bytes_into_int(&buffer[6], 2);
	header->row_count = read_n_bytes_into_int(&buffer[8], 4);
	header->default_value = read_n_bytes_into_int(&buffer[12], 4);
}


void print_header_row (WaxHeader *header)
{
	printf("\tWax Version: %d\n", header->version);
	printf("\tWax Format: %d\n", header->format);
	printf("\tHeader Lines: %d\n", header->header_lines_count);
	printf("\tColumn Count: %d\n", header->column_count);
	printf("\tRow Length: %d\n", header->row_length);
	printf("\tRow Count: %d\n", header->row_count);
	printf("\tDefault Value: %d\n", header->default_value);
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

	for (int i = 0; i < header.row_count; ++i) {
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

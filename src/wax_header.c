#include "wax_header.h"

#include <stdio.h>

#include "wax_common.h"



int read_header_row_from_bytes (WaxHeader *header, Byte const *buffer)
{
	header->version = read_n_bytes_into_u32(&buffer[0], 2);
	header->format = read_n_bytes_into_u32(&buffer[2], 2);
	header->header_lines_count = read_n_bytes_into_u32(&buffer[4], 1);
	header->column_count = read_n_bytes_into_u32(&buffer[5], 1);
	header->row_length = read_n_bytes_into_u32(&buffer[6], 2);
	header->row_count = read_n_bytes_into_u32(&buffer[8], 4);
	header->default_value = read_n_bytes_into_u32(&buffer[12], 4);
	return WAX_SUCCESS;
}


int print_header_row (WaxHeader *header)
{
	printf("\tWax Version: %d\n", header->version);
	printf("\tWax Format: %d\n", header->format);
	printf("\tHeader Lines: %d\n", header->header_lines_count);
	printf("\tColumn Count: %d\n", header->column_count);
	printf("\tRow Length: %d\n", header->row_length);
	printf("\tRow Count: %d\n", header->row_count);
	printf("\tDefault Value: %d\n", header->default_value);
	return WAX_SUCCESS;
}



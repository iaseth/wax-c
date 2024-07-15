#include <stdio.h>
#include <stdlib.h>



const int HEADER_LENGTH = 32;


int read_n_byte_int (char const *buffer, int n)
{
	int num = 0;
	for (int i = 0; i < n; ++i) {
		num = (num * 256) + buffer[i];
	}

	return num;
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

	unsigned char *buffer = NULL;
	int buffer_size = 24;
	buffer = malloc(buffer_size);

	for (int i = 0; i < 10; ++i) {
		printf("Row %3d: [ ", i+1);

		fread(buffer, buffer_size, 1, ptr);
		int t = read_n_byte_int(&buffer[0], 4);
		int o = read_n_byte_int(&buffer[4], 4);
		int h = read_n_byte_int(&buffer[8], 4);
		int l = read_n_byte_int(&buffer[12], 4);
		int c = read_n_byte_int(&buffer[16], 4);
		int v = read_n_byte_int(&buffer[20], 4);
		printf("%d, %d, %d, %d, %d, %d", t, o, h, l, c, v);

		printf("]\n");
	}

	fclose(ptr);
	free(buffer);

	return 0;
}

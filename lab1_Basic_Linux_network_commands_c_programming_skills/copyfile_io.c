#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void copy_file(const char* src_f, const char* dest_f) {
	FILE *src, *dst;
	unsigned int file_t;
	int character;
	clock_t start, end;
	double cpu_time_used;

	// Start the clock
	start = clock();

	// Open Source File in rrb mode
	src = fopen(src_f, "rb");
	if (!src) {
		perror("Error opening source file");
		exit(EXIT_FAILURE);
	}

	// Open Destination File in wb mode
	dst = fopen(dest_f, "wb");
	if (!dst) {
		perror("Error opening destination file");
		fclose(src);
		exit(EXIT_FAILURE);
	}

	// Read from source, copying to destination
	while ((character = fgetc(src)) != EOF) {
		fputc(character, dst);
	}
	
	// Check for errors while reading from source file
	if (ferror(src)) {
		perror("Error reading from source file.");
		fclose(src);
		fclose(dst);
		exit(EXIT_FAILURE);
	}

	fclose(src);
	fclose(dst);
	end = clock();
	// Calculate CPU time used
	cpu_time_used = ((double)(end - start));
	printf("File copied successfully using functions. CPU Time Used: %f\n", cpu_time_used);
}

int main(int argc, char *argv[]) {
	if (argc != 3) {
		fprintf(stderr, "Correct Usage: %s <source_file> <destination_file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	copy_file(argv[1], argv[2]);
}

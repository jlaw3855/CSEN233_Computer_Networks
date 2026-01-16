#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const char *get_filetype(const char *file_n) {
	const char *dot = strrchr(file_n, '.');
	// Check if there are no dots in the requested filename, or if the filename is just a dot
	if (dot == file_n) return "";
	if (dot) return dot+1;
	else return "";
}

void copy_file(const char* src_f, const char* dest_f) {
	FILE *src, *dst;
	const char *file_ext_ptr;
	char buff[2048], file_ext[3];
	unsigned int file_t;
	int character;
	size_t read_b, buffer_size = sizeof(buff);
	clock_t start, end;
	double cpu_time_used;

	// Start the clock
	start = clock();

	// Check file extension to determine filetype
	file_ext_ptr = get_filetype(src_f);
	strcpy(file_ext, file_ext_ptr);
	if (file_ext == "txt") file_t = 0;
	if (file_ext == "bin") file_t = 1;

	// Open Source File in r or rb mode based on filetype
	src = fopen(src_f, "rb");
	if (!src) {
		perror("Error opening source file");
		exit(EXIT_FAILURE);
	}

	// Open Destination File in w or wb mode based on filetype
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

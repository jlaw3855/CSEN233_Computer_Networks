#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>


int main(int argc, char *argv[]) {
	int src, dst;
	char buffer[2048];
	long int charcopy;
	mode_t filePerms;
	clock_t start, end;
	double cpu_time_used;
	
	// Start timer
	start = clock();

	if (argc != 3) {
		fprintf(stderr, "Correct Usage: %s <source_file> <destination_file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	src = open(argv[1], O_RDONLY);
	if (!src) {
		perror("Error opening source file");
		exit(EXIT_FAILURE);
	}

	filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;
	dst = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, filePerms);
	if (!dst) {
		perror("Error opening destination file");
		exit(EXIT_FAILURE);
	}

	while ((charcopy = read(src, buffer, 1024)) > 0 ) {
		if (write(dst, buffer, charcopy) != charcopy) {
			perror("Error writing to destination file");
			exit(EXIT_FAILURE);
		}
	}
	close(src);
	close(dst);
	end = clock();

	cpu_time_used = ((double)(end - start));
	printf("File copied successfully using system calls. CPU Time Used: %f\n", cpu_time_used);
}

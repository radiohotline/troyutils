#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

#define PROGRAM_NAME "tac"

struct stat statbuf;

int main(int argc, char* argv[]) {
	FILE *fileptr = NULL;
	char buf[8192];
	char ch;
	int size = 0;

	if (argc < 2) {
		while (fgets(buf, sizeof(buf), stdin) != NULL) {
			printf("%s", buf);
		}

		return 0;
	}	

	if (access(argv[1], F_OK) != 0) {
		printf("%s: %s: No such file or directory.\n", PROGRAM_NAME, argv[1]);
		return 1;
	}
		
	if (stat(argv[1], &statbuf) == 0 && S_ISDIR(statbuf.st_mode)) {
		printf("%s: %s is a directory.\n", PROGRAM_NAME, argv[1]);
		return 1;
	}

	fileptr = fopen(argv[1], "r");
	
	if (fileptr == NULL) {
		perror("tac");
		return 1;
	}

	while ((ch = fgetc(fileptr)) != EOF) {
		size++;
	}
		
	size = size - 2;
	rewind(fileptr);

	while (size >= 0) {
		fseek(fileptr, size, 0);
		ch = fgetc(fileptr);
		putchar(ch);
		size--;
	}

	printf("\n");

	fclose(fileptr);
	return 0;
}

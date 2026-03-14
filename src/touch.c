#include <stdio.h>
#include <sys/time.h>
#include <fcntl.h>
#include <unistd.h>

#define PROGRAM_NAME "touch"

int main(int argc, char* argv[]) {
	if (argc < 2) {
		fprintf(stderr, "%s: missing file operand\n", PROGRAM_NAME);
		return 1;
	}

	for (int i = 1; i < argc; i++) {
		if (utimes(argv[i], NULL) != 0) {
			int file = open(argv[i], O_CREAT | O_WRONLY, 0644);

			if (file == -1) {
				perror("touch");
				continue;
			}

			close(file);
		}
	}

	return 0;
}

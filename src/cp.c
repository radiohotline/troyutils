#include <stdio.h>

int main(int argc, char* argv[]) {
	FILE *input, *output;
	char ch;

	if (argv[2] == NULL) {
		printf("specify a destination\n");
		return 1;
	}

	input = fopen(argv[1], "r");
	output = fopen(argv[2], "a");
	
	if (input == NULL || output == NULL) {
		printf("failed to open the file dingus\n");
		return 1;
	} else {
		while ((ch = fgetc(input)) != EOF) {
			fputc(ch, output);
		}
	}

	fclose(input);
	fclose(output);

	return 0;
}

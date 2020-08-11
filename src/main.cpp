#include<stdio.h>


int main(int argc, const char **argv) {
	const int arr = argc;
	if (arr < 2) {
		printf("ERROR: No argument entered\n");
		return -1;
	}
	printf("Argument = %s\n", argv[1]);
	return 1;

}
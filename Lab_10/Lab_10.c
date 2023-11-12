#include <stdio.h>

void main() {
	int x = 10, i = 1;
	printf("");
	do {
	printf("%d", x);
	x += 10;
	i++;

	} while (i <= 20);
	printf("");
}
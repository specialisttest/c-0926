#include <stdio.h>


// lifetime - global
// scope - this module (private)
static int globalZ;

void decrementGlobalZ() {
	globalZ--;
}

void printGlobalZ() {
	printf("globalZ (from module): %d\n", globalZ);
}

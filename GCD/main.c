#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int k1, k2, k3;
	
	printf("GCD enter a b: ");
	scanf("%d %d", &k1, &k2);
	
	
	while( (k3 = k1 % k2) != 0 ) {
		k1 = k2;
		k2 = k3;
	}
	
	printf("GCD %d\n", k2);
	
	
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	printf("Enter x y z: ");
	int x,y,z;
	scanf("%d%d%d", &x, &y, &z);
	
	int q = (x>y) ? x : y;
	int max3 = (q > z) ? q : z;
	
	printf("max of (%d, %d, %d): %d\n",x,y,z,max3);
	
	return 0;
}

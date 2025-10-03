#include <stdio.h>
#include <stdlib.h>


enum Colors { red = 1, green = 100, blue = 200};
//				1         100         200
//				0         1           2

typedef enum Colors Color;

int main(int argc, char *argv[]) {
	enum Colors c1 = green;
	Color c2 = blue;
	
	printf("c1 = %d\n", c1);
	int k1 = c1;
	printf("k1 = %d\n", k1);
	
	return 0;
}

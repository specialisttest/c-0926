#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
		printf("   ");
		for(int i=0; i <= 0xF; i++)
			printf("%3X", i);
		
		
		for(int row=0; row <= 0xF; row++) {
			printf("%3X", row);
			
			for(int col=0; col <= 0xF; col++) {
				int ch = (col << 4) + row;
				if (ch < 0x20 ) ch = 0x20; // space
				printf("%3c", ch);
			}

			puts("");
		}
	
	
	return 0;
}

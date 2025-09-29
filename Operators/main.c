#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	system("chcp 1251 > nul");
	
	int a = 2;
	int b = 1;
	
	// оператор-выражение
	++a * ( b = a * 2);
	
	// блочный (составной) оператор
	{
		#define ABC 123
		int x = 5;
		printf("x = %d\n", x);
	}
	
	
	double x = 2.5;
	printf("x = %lf\n", x);
	
abc:	
	{
		printf("%d\n", ABC);
		x = 3.5;
		{
			printf("x = %lf\n", x);
			unsigned char x = 5;
			printf("x = %d\n", x);	
		}
		printf("x = %lf\n", x);
	}
	printf("x = %lf\n", x);	
	
	// goto abc; // лучше не использовать
	
	// пустой оператор
	;;;;;;;;;;;;;;;;;;;;;;;;;
	
	int n = -10;
	if ( n > 0 ) {
		puts("n больше 0");
		puts("n > 0");
	}
	else 
		if ( n > -100)
			puts("n in (-100, 0]");
		else {
			puts("n Ќ≈ больше 0");
			puts("n <= 0");
		}
			
	n = -1;
	
	switch(n) {
		case -1:
		case 1:
			puts("один");
			break; // return
		case 2:
			puts("два");
			break;
		case 3:
			puts("три");
			break;
		default:
			puts("много");
	}
		
	
	
	
	
	return 0;
}

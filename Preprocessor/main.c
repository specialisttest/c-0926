#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>


#define THE_END {\
	printf("Press enter...");\
	getchar();\
	fflush(stdin);\
}


#define ARCH x64
#define OS 1 // 0 - win, 1 - unix
#define RUS

#define ERROR_LEVEL 1 // 0 - errors; 1 - errors, warnings; 2 -  - errors, warnings, notices

//#undef RUS

#include "test.h"
#include "super_test.h"
#include "circle.h"

int main(int argc, char *argv[]) {
	int r = 5;
	
	printf("Circle length for radius %d : %lf\n", r, CLEN(r));
	printf("Circle square for radius %d : %lf\n", r, CSQR(r));
	
#ifdef RUS
#if OS == 0
	system("chcp 1251 > nul");
	puts("win");
#elif OS == 1
	setlocale(LC_ALL, "Russian");
	puts("unix");
#endif
#endif

#if ERROR_LEVEL	== 0
	puts("Errors");
#elif ERROR_LEVEL == 1
	puts("Errors, Warnings");
#elif ERROR_LEVEL == 2
	puts("Errors, Warnings, Notices");
#else
	#line 9
	#warning INVALID ERROR LEVEL [0,2]
	//#error INVALID ERROR LEVEL [0,2]
#endif
	printf("Главная\n");
	printf("Very long string.....................................\
.....................................................................................\n");
	
	test();
	super_test();
	
	printf("globalConst = %d\n", globalConst);
	#undef PI
	#define PI 4.0
	
	printf("PI = %lf\n", PI);
	
// макрофункция
#define Q(a) ((a)*(a)*(a))

	int x = 5;
	long y = 7;
	printf("x^3 = %d\n", Q(x)); // x*x*x
	printf("y^3 = %d\n", Q(y-2)); // (y-2)*(y-2)*(y-2)
	printf("y^3 = %d\n", Q(--x)); //(--x)*(--x)*(--x) UB
	

#define ROUND(x) _Generic((x),\
	long double : roundl,\
	float : roundf,\
	 default: round)\
	 ((x))
	
	float r1 = 2.5;
	double r2 = 2.5;
	long double r3 = 2.5;
	//printf("round r1 = %f\n", roundf(r1));
	//printf("round r2 = %lf\n", round(r2));
	//printf("round r3 = %Lf\n", roundl(r3));
	printf("round r1 = %f\n", ROUND(r1));
	printf("round r2 = %lf\n", ROUND(r2));
	printf("round r3 = %Lf\n", ROUND(r3));

#define STR(s) #s
#define CONCAT(x,y) x##y
	int ab = 7;
	
	printf("ab = %d\n", CONCAT(a, b)); printf("%d\n", ab);


	



	puts(STR(Hello world)); // put("Hello world");
	
	if (x == 0)
		THE_END
	
	return 0;
}

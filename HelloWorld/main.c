#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

// M_PI

#define PI 3.1415
const double PI2 = 2 * 3.1415;
// 2e-7

/*
 * 
 *
 *
 */

int main(int argc, char *argv[]) {
	
	int a;
	int A;   // bad practice
	int Int; // bad practice
	/*
	
	// comments
	char* userName;
	*/
	constexpr int n = 1'000'000; // C23
	
	char ch = '\x1F';
	
	int k = 0b010101;  // C23
	k      =    (2 + 3) * 4;
	// lvalue		rvalue
	
	k = a;
	auto name = "Sergey";
	

	constexpr typeof(n) z = n + 7;   // C23
	
	double x = 123.5;
	printf("x0 = %lf\n", x);
	
	
	x = 2.5;
	
	printf("Hello world!\n");
	printf("n = %d!\n", n);
	printf("k = %d!\n", k);
	printf("name = %s!\n", name);
	printf("z = %d!\n", z);
	printf("pi = %lf\n", M_PI);
	printf("sizeof(char) = %d\n", sizeof(char));
	printf("sizeof(short) = %d\n", sizeof(short));
	printf("sizeof(int) = %d\n", sizeof(int));
	printf("sizeof(long) = %d\n", sizeof(long));
	printf("sizeof(long long) = %d\n", sizeof(long long));
	printf("sizeof(float) = %d\n", sizeof(float));
	printf("sizeof(double) = %d\n", sizeof(double));
	printf("sizeof(long double) = %d\n", sizeof(long double));
	printf("040 = %d\n", 040); // 32
	printf("0b101 = %d\n", 0b101); // 5
	printf("x1 = %lf\n", x); // 2.5
	
	x = 3.5 + 1.7;
	
	printf("x2 = %lf\n", x); // 5.2
	
	const double y = 6.7;
	printf("y = %lf\n", y); // 6.7
	
	// 3 ^ 4 ^ 4 == 3
	// 3 ^ 4 XOR
	// 0011
	// 0100
	// 0111

	int q = pow(3, 4); 
	
	printf("q = %d\n", q);
	return 0;
}

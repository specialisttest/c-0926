#include <stdio.h>
#include <stdlib.h>

#define PI 3.1415

// int globalZ; //  = 0
int globalZ = 10;

int funcCounter() {
	// scope - local var
	// lifetime - global var
	// class - global var
	static int counter = 0;

	counter++;
	printf("call funcCounter: %d\n", counter);
	
	return counter;
}

void incrementGlobalZ() {
	//auto int k = 5;
	//int k = 5;
	auto k = 5;
	
	printf("local k = %d\n", k);
	
	globalZ++;
}

int power(register int base, register int e) {
	register int result = 1;
	while (e-- > 0) result *= base;
	return result ;
}
// restrict since C11
void update(int* restrict pa, int* restrict pb, int add) {
	*pa += add;
	*pb += add;
}


int main(int argc, char *argv[]) {
	#undef PI
	#define PI 4.0
	printf("PI = %lf\n", PI);
	
	const double pi = 3.1415; // readonly
	printf("pi = %lf\n", pi);
	// pi = 4.0; // compile error
	const double* cppi = &pi;
	double* ppi = (double*)cppi;
	(*ppi) = 4.0;
	
	
	printf("pi = %lf\n", pi);
	
	printf("globalZ = %d\n", globalZ);
	incrementGlobalZ();
	printf("globalZ = %d\n", globalZ);
	
	funcCounter();
	funcCounter();
	
	{
		register int x = 5;
		//int* px = &x; // compile error
		printf("register x = %d\n", x);
	}
	
	printf("4^3 = %d\n", power(4, 3));
	
	int a = 10;
	int b = 20;
	
	update(&a, &a, 5);
	
	printf("a = %d\nb = %d\n", a, b);
	
	volatile int y = 5;
	
	// _Atomic - no race condition
	int _Atomic count = 0; // since C11
	
	count++; // count = count + 1
	
	
	return 0;
}

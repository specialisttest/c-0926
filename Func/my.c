#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void say_hello() {
	puts("Hello");
}

void say_hello_w_name(const char* name) {
	printf("Hello, %s!\n", name);
}

void say_hello_w_name_age(const char* name, int age) {
	//age++;
	printf("Hello, %s - %d!\n", name, age);
	//return;
}

double my_average(int a, int b) {
	double r = (a + b) / 2.0;
	return r;
}

double average_m(int m_size, /*int* m*/ int m[]) {
	long long summa = 0;
	for(int i = 0; i < m_size; i++)
		summa += m[i];
		
	return (double)summa / m_size;
}

double average_n(int n, ...) {
	
	long summa = 0;
	
	va_list params;
	va_start(params, n);
	
	for(int i = 0; i < n; i++) {
		int k = va_arg(params, int);
		summa += k;
	}
		
	va_end(params);
	
	return (double)summa / n;
	
}



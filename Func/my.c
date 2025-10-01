#include <stdio.h>
#include <stdlib.h>

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

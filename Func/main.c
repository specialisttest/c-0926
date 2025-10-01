#include <stdio.h>
#include <stdlib.h>

#include "my.h"

/*
	SP ---->  
		yyyy+1

	xxxx: nop
		  mov
		  ret

	PC ---->
		  push data
	yyyy  call xxxx
	yyyy+1

*/

// n! = 1 * 2 * 3 * .. * n
// 0! = 1
// n! = (n-1)! * n

int factorial(int n) {
	if (n == 0) return 1;
	return n*factorial(n-1);
}

void test1(int a) {
	printf("Address a in test 1: %p\n", &a);
	a++;
	printf("test 1 a = %d\n", a); // 11
}

void test2(int* pa) {
	printf("Address a in test 2: %p\n", pa);
	(*pa)++;
	printf("test 2 a = %d\n", *pa); // 11
}

int main(int argc, char *argv[]) {
	{
		int a = 10;
		printf("Address a in main 1: %p\n", &a);
		test1(a);  // by value (copy on stack)
		printf("main 1 a = %d\n", a); // 10
		
	}
	{
		int a = 10;
		printf("Address a in main 1: %p\n", &a);
		test2(&a); // by ref (pointer copy on stack)
		printf("main 2 a = %d\n", a); // 11
		
	}	
	
	say_hello();
	say_hello();
	say_hello_w_name("Sergey"); // name = "Sergey"
	say_hello_w_name("Andrey"); // name = "Andrey"
	say_hello_w_name_age("Andrey", 50);
	
	//double avg = my_average(10, 11);
	//printf("avg = %lf\n", avg);
	printf("avg = %lf\n", my_average(10, 11) );
	
	printf("6! = %d\n", factorial(6) );
	
	
	return 0;
}

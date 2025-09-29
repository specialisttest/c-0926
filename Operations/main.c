#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
	
	system("chcp 1251 > nul");
	
	int a;
	
	int b = a = 101;
	
	a += 2; //a = a + 2;
	
	a = 10;
	//a = a + 1;
	//a += 1;
	//a++; // suffix postfix increment
	//++a;  // prefix
	b = ++a;
	//b = a++ + ++a; // UB - bad
	//   10 + 12
	
	printf("a = %d\nb = %d\n", a, b);
	
	bool r = (1 > 2);
	r = true;
	r = false;
	
	int k = (10 >= 2);
	
	printf("(1 > 2) %d\n", r);
	
	bool b1 = true;
	bool b2 = false;
	
	r = b1 && b2; // false
	r = b1 || b2; // true
	r = !b1; 	  // false
	r = b1 && !b2;// true
	
	
	r = (a >= 0) && (a <= 100);
	
	printf("%d\n", r);
	
	int x = 5; // 0101
	int y = 7; // 0111
	
	int z = x & y; // 0101
	z = x | y;     // 0111
	z = x ^ y;     // 0010 XOR
	
	z = x ^ y ^ y; // z == x
	
	printf("z = %d\n", z);
	printf("x = %d\ny = %d\n", x, y);
	
	/*z = x;
	x = y;
	y = z;*/
	x ^= y ^= x ^= y;
	
	printf("x = %d\ny = %d\n", x, y);
	
	//z = x >> 2; // 0111 >> 2 == 0001
	z = x << 3; // 0111 << 3 == 0111000
	
	x = 7; // 0111 7
	       // 1001 -7
	       // 0000 
	
    // маска 0001
	z = (x >> 1) & 1;
	
	z = ~x; // -x == ~x+1  ~x= -x-1
	
	printf("z = %d\n", z);
	
	int nums[20];
	nums[0] = 10;
	
	int q = 5;
	int* pq = &q;
	int k2 = *pq;
	
	double e = 5.9;
	
	//int j = e; // implicit conv
	int j = (int)e; // explicit conv  - cast operator
	
	long l = j;
	int k3 = l;
	
	printf("j = %d\n", j);
	
	x = 5;
	//z = (7, x);
	z = y = (x + 5, x++); // 6 5 5
	
	printf("x = %d\ny = %d\nz = %d\n", x, y, z);
	
	char* result = (x > y) ? "x больше y" : "x не больше y";
	
	int m = (x > y) ? x : y;
	
	puts(result);

	
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

int y = 20; // global - data segment

void swap(int* pa, int* pb) {
	int c = *pa;
	*pa = *pb;
	*pb = c;
}

// Лабораторная 9.1
void swap_u(void* pa, void* pb, size_t size) {
	char pc[size]; // vla
	//void* pc = malloc( size );
	
	memcpy(pc, pa, size);
	memcpy(pa, pb, size);
	memcpy(pb, pc, size);
	
	//free(pc);
}

int main(int argc, char *argv[]) {
	
	int x = 10; // local [auto] = stack;
	int* px = &x;
	int* py = &y;
	
	//void* implicit conv to int*
	int* pz = malloc( sizeof(int) ); // dynamic - heap
	//*pz = 0;
	//memset(pz, 0, sizeof(int));
	//*pz = x;
	memcpy(pz, &x, sizeof(int));
	// x y z q
	// 1 2 3 4
	
	
	*px = 12; // x = 12
	printf("x  = %d\n", x);
	printf("*px(stack       ) = %d\n", *px);
	printf("px (stack       ) = %p\n", px);
	printf("py (data segment) = %p\n", py);
	printf("pz (heap        ) = %p\n", pz);
	printf("*pz (heap       ) = %d\n", *pz);
	
	py = px;
	
	(*px)++;
	
	const int* cp = px; // &x
	// cp = pz; // OK
	// (*cp)++; // compile error = const pointer
	printf("*cp  = %d\n", *cp);
	x++;
	printf("*cp  = %d\n", *cp);
	int* pp = (int*)cp;
	(*pp)++;
	printf("*cp  = %d\n", *cp); 
	
	double d = 2.5;
	double* pd = &d;
	
	//pd = (double*)px; 
	//*pd = 1.0; //  dangerous - corrupt data
	
	x  = 0x1232560D;
	px = &x; // int*
	unsigned char* pbyte = (unsigned char*)px;
	printf("unsigned char: 0x%X\n", *pbyte); // safe - get first byte
	
	void* pv = px;
	pv = pd;
	pd = pv;
	
	printf("void*: %p\n", pv);
	pv++;
	printf("void*: %p\n", pv);
	printf("int*: %p\n", px);
	px += 3; // 3*sizeof(int)
	printf("int*: %p\n", px);
	int a = 10, b = 5;
	ptrdiff_t ab_diff = &a - &b;
	printf("&a: %p\n", &a);
	printf("&b: %p\n", &b);
	printf("&a - &b: %ld\n", ab_diff);
	
	printf("a = %d b = %d\n", a, b);
	swap(&a, &b);
	printf("a = %d b = %d\n", a, b);
	
	{
		long a = 5, b = 10;
		printf("a = %ld b = %ld\n", a, b);
		swap_u(&a, &b, sizeof(a));
		printf("a = %ld b = %ld\n", a, b);
	}
	{
		long double  a = 5.2, b = 10.1;
		printf("a = %Lf b = %Lf\n", a, b);
		swap_u(&a, &b, sizeof(a));
		printf("a = %Lf b = %Lf\n", a, b);
	}
	
	int nums[] = {10, 20, 30};
	int* pnums = nums; // pnums = &nums[0];
	
	for(int i=0; i < 3; i++)
		//printf("nums[%d] = %d\n", i, nums[i]);
		//printf("nums[%d] = %d\n", i, pnums[i]);
		printf("nums[%d] = %d\n", i, *(pnums+i) ); // (pnums+i) == &nums[i]
	
	printf("*pnums = %d\n", *pnums); // nums[0];
	printf(" pnums = %p\n", pnums);  // &nums[0]
	pnums++;//pnums +=1; // pnums = &nums[1]
	
	printf("*pnums = %d\n", *pnums); // nums[1];
	printf(" pnums = %p\n", pnums);  // &nums[1]
	
	for( /*int* */ auto pn = nums; pn < nums + 3; ++pn)		
		printf("%-4d", *pn);
		
	puts("");
	
	free(pz);
	// *pz // unsafe
	pz = nullptr; // NULL
	printf("pz (heap        ) = %p\n", pz);
	
	
	//if (pz != nullptr)
	if (pz)
		printf("*pz (heap       ) = %d\n", *pz); // UNSAFE
	
	return 0;
}

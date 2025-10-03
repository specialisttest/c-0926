#include <stdio.h>
#include <stdlib.h>

#define ODD(x) ( (x) % 2 == 1 )
#define EVEN(x) ( (x) % 2 == 0 )

/*int custom_compare(const int* a, const int* b) {
	int k1 = *a;
	int k2 = *b;
	
	if ( EVEN(k1) && ODD(k2)) return -1;
	if ( ODD(k1) && EVEN(k2)) return 1;
	if ( EVEN(k1) && EVEN(k2)) return k1-k2;
	if ( ODD(k1) && ODD(k2)) return k2-k1;

}*/

int custom_compare(int k1, int k2) {
	if ( EVEN(k1) && ODD(k2)) return -1;
	if ( ODD(k1) && EVEN(k2)) return 1;
	if ( EVEN(k1) && EVEN(k2)) return k1-k2;
	if ( ODD(k1) && ODD(k2)) return k2-k1;

}

int custom_compare_pointer(const void* a, const void* b) {
	int k1 = *(const int*)a;
	int k2 = *(const int*)b;
	
	return custom_compare(k1, k2);
	
}

int main(int argc, char *argv[]) {
	#define NSIZE 10
	int n[] = {10, 15, 7, 3, 21, 1000, 18, 30, 14, 17};
	for(int i = 0; i < NSIZE; i++)	printf("%-5d", n[i]);
	puts("");
	
	//qsort(n, NSIZE, sizeof(int), (int (*)(const void*, const void*))custom_compare);
	qsort(n, NSIZE, sizeof(int), custom_compare_pointer);
	
	for(int i = 0; i < NSIZE; i++)	printf("%-5d", n[i]);
	puts("");
	
}

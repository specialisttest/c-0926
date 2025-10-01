#include <stdio.h>
#include <stdlib.h>

int compare_int(const void* a, const void* b){
	int arg1 = *(const int*)a;
	int arg2 = *(const int*)b;
	return arg1 - arg2;
}


int main(int argc, char *argv[]) {
	#define NSIZE 10
	int n[] = {10, 15, 7, 3, 21, 1000, 18, 30, 14, 17};

	#define PRINT_ARRAY(h) puts(h);\
	for(int i = 0; i < NSIZE; i++) printf("%-5d", n[i]);\
	puts("");
	
	PRINT_ARRAY("Unsorted array")
	
	// бинарный поиск
	// O(log2(n))
	int search = 1000;
	int found_index = -1;
	
	qsort(n, NSIZE, sizeof(int), compare_int);

	PRINT_ARRAY("Sorted array")

	int begin = 0, end = NSIZE - 1;
	do {
		int middle_index = (begin + end) / 2;
		int k = n[middle_index];
		if (k == search) {
			found_index = middle_index;
			break;
		}
		if (k > search)
			end = middle_index;
		else // k < search
			begin = middle_index;
			
		if (end - begin <= 1) {
			if (n[begin] == search) {
				found_index = begin;
				break;
			}
			if (n[end] == search) {
				found_index = end;
				break;
			}
		}
	} while ( end - begin > 1 );
	
	if (found_index == -1)
		printf("Value %d not found in array\n", search);
	else
		printf("Value %d found in %d position\n", search, found_index);
		
}

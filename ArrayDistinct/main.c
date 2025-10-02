#include <stdio.h>
#include <stdlib.h>

int compare_int(const void* a, const void* b) {
	return *(const int*)a - *(const int*)b;
}


int main(int argc, char *argv[]) {
	#define SIZE 15
	int numbers[SIZE]  = {18, 15, 17, 3, 21, 1000, 18, 30, 15, 17, 1000, 21, 18, 34, 12};
	
	int counter = 0;
	for(int i = 0; i < SIZE; i++) {
		bool found = false;
		int k = numbers[i];
		for(int j = 0; j < i; j++)
			if (k == numbers[j]) {
				found = true;
				break;
			}
		if(!found) counter++;
	}
	
	for(int i=0; i < SIZE; i++) printf("%-5d", numbers[i]);
	puts("");
	printf("Unique count: %d\n", counter);
	
	int unique_counter = 0;
	int unique_numbers[SIZE];
	
	//int unique_numbers[counter];
	
	for(int i = 0; i < SIZE; i++) {
		bool found = false;
		int k = numbers[i];
		for(int j = 0; j < i; j++)
			if (k == numbers[j]) {
				found = true;
				break;
			}
		if(!found) unique_numbers[unique_counter++] = k;
		
	}
	
	printf("Unique values\n");
	for(int i=0; i < unique_counter; i++) printf("%-5d", unique_numbers[i]);
	puts("");
	
	qsort(unique_numbers, unique_counter, sizeof(int), compare_int);
	
	printf("Unique values sorted\n");
	for(int i=0; i < unique_counter; i++) printf("%-5d", unique_numbers[i]);
	puts("");
	
	// SELECT DISTINCT ... ORDER BY .. ASC
	
	return 0;
}

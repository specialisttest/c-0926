#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_int(const void* a, const void* b) {
	int arg1 = *(const int*)a;
	int arg2 = *(const int*)b;
	
	return arg1 - arg2;
	/*if (arg1 > arg2) return 1;
	if (arg1 < arg2) return -1;
	return 0;*/
}

int main(int argc, char *argv[]) {
	//#define ASIZE 3
	
	//int nums[ASIZE] = {100, 200}; // nums[0] = 100; nums[1] = 200; nums[2] = 0;
	//int nums[ASIZE] = {}; // fill with zero
	int nums[3] = {}; // fill with zero
	#define ASIZE (sizeof(nums)/sizeof(int))
	
	printf("sizeof int[3]: %d\n", sizeof(nums));
	
	//nums[0] = 100;
	//nums[1] = 200;
	//for(int i = 0; i < ASIZE; i++)
	//	nums[i] = (i+1)*100;
	//for(int i = 0; i < sizeof(nums)/sizeof(int); i++)
	
	int* pNums = nums; // указатель на 0 элемент массив
	(*pNums)++; // nums[0]++
	
	for(int i = 0; i < ASIZE; i++)
		printf("nums[%d] : %-4d\n", i, nums[i]);
		
	//char str[10] = { 'H', 'e', 'l', 'l', 'o', 0};
	//char str[10] = { 72, 101, 108, 108, 111, 0};
	char str[10] = "Hello";
	puts(str);
	
	#define NSIZE 10
	int n[] = {10, 15, 7, 3, 21, 1000, 18, 30, 14, 17};
	for(int i = 0; i < NSIZE; i++)	printf("%-5d", n[i]);
	puts("");
	
	// find value in unsorted array
	// O(n)
	int search = 22;
	int found_index = -1;
	for(int i = 0 ; i < NSIZE; i++)
		if (n[i] == search) {
			found_index = i;
			break;
		}
		
	if (found_index != -1)
		printf("Value %d found in %d position\n", search, found_index);
	else
		printf("Value %d not found array\n", search);
	
	
	// summary array
	int summa = 0;
	for(int i = 0 ; i < NSIZE; i++)
		summa += n[i]; // summa = summa + n[i];
		
	printf("Summa: %d\n", summa);
	
	// average
	double average = (double)summa / NSIZE;
	printf("Average: %lf\n", average);
	
	// min
	int min = n[0];
	for(int i = 1; i < NSIZE; i++)
		if (n[i] < min) min = n[i];
		
	printf("Minimum: %d\n", min);
	
	int max = n[0];
	for(int i = 1; i < NSIZE; i++)
		if (n[i] > max) max = n[i];
		
	printf("Maximum: %d\n", max);
	
	/*
	// bubble sort
	// O(n^2)
	for(int i = 0; i < NSIZE-1; i++) {
		for(int j = i+1; j < NSIZE; j++)
			if (n[j] < n[i]) {
				int x = n[i];
				n[i] = n[j];
				n[j] = x;
			}
	}*/
	
	// average O(n*log(n)) worst O(n^2)
	qsort(n, NSIZE, sizeof(int), compare_int );
	
	for(int i = 0; i < NSIZE; i++)
		printf("%-5d", n[i]);
	puts("");
	
		
	// ОПАСНО !!!
	// printf("nums[5] : %-4d\n", nums[-5]);
	// nums[-5] = 100;
	
	// VLA (since C11) - only local arrays
	/*printf("Enter array size for ints: ");
	const int arr_size;
	scanf("%d", &arr_size);
	
	int arr[arr_size] = {}; // VLA
	//memset(arr,1,sizeof(arr));
	
	printf("sizeof VLA: %d\n", sizeof(arr));
	for(int i = 0; i < arr_size; i++)
		printf("%-15d", arr[i]);
	puts("");*/
	
	// Многомерные массивы
	#define ROWS 2
	#define COLS 3
	
	int m[ROWS][COLS] =  {
		{1,2,3},
		{4,5,6}
	};
	
	for(int i = 0; i < ROWS; i++) {
		for(int j = 0; j < COLS; j++)
			printf("%-3d", m[i][j]);
			
		printf("\n");
	}
	
	

	
	return 0;
}

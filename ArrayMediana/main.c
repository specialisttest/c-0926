#include <stdio.h>
#include <stdlib.h>

int compare_int(const void* a, const void* b){
	int arg1 = *(const int*)a;
	int arg2 = *(const int*)b;
	
	return arg1 - arg2;
}

int main(int argc, char *argv[]) {
	//#define NSIZE 11
	//int n[NSIZE] = {10, 15, 7, 3, 21, 1000, 18, 30, 14, 17, 33};	
	printf("Enter count: ");
	int NSIZE;
	scanf("%d", &NSIZE);
	int n[NSIZE]; // vla
	
	for(int i = 0; i < NSIZE; i++)	{
		printf("n[%d] = ", i+1);
		scanf("%d", &n[i]);
		//scanf("%d", n+i);
	}
	
	
	
	puts("Unsorted array");
	for(int i = 0; i < NSIZE; i++)	printf("%-5d", n[i]);
	puts("");

	// find median value
	// SORT !!!
	qsort(n, NSIZE, sizeof(int), compare_int);
	double mediana;
	if ( NSIZE % 2 == 1)
		mediana = n[NSIZE / 2];
	else
		mediana = (n[NSIZE / 2 -1] + n[NSIZE / 2]) / 2.0;
	
	
	puts("Sorted array");
	for(int i = 0; i < NSIZE; i++)	printf("%-5d", n[i]);
	puts("");
	
	
	// average
	int summa = 0;
	for(int i=0; i < NSIZE; i++) summa += n[i];
	double average = (double)summa / NSIZE;


	printf("Average: %.2lf\n", average);
	printf("Mediana: %.2lf\n", mediana);	
	
	
	
	return 0;
}

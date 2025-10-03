#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_int(const void* a, const void* b) {
	return *(const int*)a - *(const int*)b;
}

bool analize( const int* n, size_t size, int* pmax, int* pmin, double* pavg, double* pmediana ) {
	if (size < 1) return false;
	
	*pmin = n[0];	
	*pmax = n[0];
	long summa = 0;
	for(int i = 0 ; i < size; i++) {
		if (n[i] < *pmin) *pmin = n[i];
		if (n[i] > *pmax) *pmax = n[i];
		summa += n[i]; 
	}
	*pavg = (double)summa / size;
	
	int* arr = malloc(size * sizeof(int));
	memcpy(arr, n, size * sizeof(int));
	qsort(arr, size, sizeof(int), compare_int);
	*pmediana = ( size % 2 == 1) ? arr[size / 2] : (arr[size / 2 -1] + arr[size / 2]) / 2.0;
	free(arr);
	
	return true;
	
}

int main(int argc, char *argv[]) {
	int n[] = {10, 15, 7, 3, 21, 1000, 18, 30, 14, 17};
	#define NSIZE sizeof(n)/sizeof(int)
	for(int i = 0; i < NSIZE; i++)	printf("%-5d", n[i]);
	puts("");
	
	int max, min;
	double avg, mediana;
	if (analize(n, NSIZE, &max, &min, &avg, &mediana )) {
		printf("Maximum: %d\n", max);
		printf("Minimum: %d\n", min);	

		printf("Average: %.2lf\n", avg);
		printf("Mediana: %.2lf\n", mediana);	
		
		for(int i = 0; i < NSIZE; i++)	printf("%-5d", n[i]);
		puts("");
	}
	
	
	
	
	return 0;
}

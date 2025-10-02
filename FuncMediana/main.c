#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int compare_int(const void* a, const void* b){
	return *(const int*)a - *(const int*)b;
}

double mediana(int n, ...) {
	int arr[n]; // VLA
	va_list params;
	va_start(params, n);
	
	for(int i = 0; i < n; i++)
		arr[i] = va_arg(params, int);
		
	va_end(params);
	
	qsort(arr, n, sizeof(int), compare_int);
	
	return (n % 2 == 1) ? arr[n/2] : (arr[n/2 - 1] + arr[n/2]) / 2.0;
	
	
}

int main(int argc, char *argv[]) {
	
	printf("mediana(3,1,2): %lf\n", mediana(3, 3,1,2));
	printf("mediana(3,1,4,2): %lf\n", mediana(4, 3,1,4,2));
	
	printf("mediana(10, 15, 7, 3, 21, 1000, 18, 30, 14, 17): %lf\n",
	 mediana(10, 
	 	10, 15, 7, 3, 21, 1000, 18, 30, 14, 17));
	
	return 0;
}

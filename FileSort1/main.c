#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* fin_name = "..\\names.txt";
const char* fout_name = "..\\namesSorted.txt";

#define MAX_STR_SIZE 200
#define MAX_LINES 1000 

int main(int argc, char *argv[]) {
	FILE* fin = fopen(fin_name, "rt");
	if (fin == NULL) {
		perror(fin_name);
		exit(1);
	}
	
	char names[MAX_LINES][MAX_STR_SIZE];
	int lines = 0;
	while (fgets(names[lines], MAX_STR_SIZE, fin) != NULL && lines < MAX_LINES) 
		lines++;
		
	fclose(fin);
	
	qsort(names, lines, MAX_STR_SIZE, (int (*)(const void*,const void*))strcmp);
		
	FILE* fout = fopen(fout_name, "wt");
	if (fout == NULL) {
		perror(fout_name);
		exit(2);
	}
	
	for(int i=0; i < lines; i++)
		fputs (names[i], fout);
	
	fclose(fout);
	
	printf("Write %d line(s)\n", lines);
		
	return 0;
}
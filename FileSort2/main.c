#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <unistd.h>

//const char* fin_name = "..\\names.txt";
//const char* fout_name = "..\\namesSorted.txt";

int compareStringByRef(const char** pc1, const char** pc2) {
	return strcmp(*pc1, *pc2);
}

#define MAX_STR_SIZE 65535
int main(int argc, char *argv[]) {
	
	//sleep(5);
	
	if (argc != 3) {
		puts("Usage: FileSort2.exe input_file_name output_file_name");
		exit(2);
	}
	const char* fin_name = argv[1];
	const char* fout_name = argv[2];
	
	printf("Copying sorted lines from %s to %s\n", fin_name, fout_name);
	
	FILE* fin = fopen(fin_name, "rt");
	if (fin == NULL) {
		perror(fin_name);
		exit(1);
	}
	
	char* line = malloc((MAX_STR_SIZE+1)*sizeof(char));
	
	
	char** names = NULL;
	
	
	int lines = 0;
	while (fgets(line, MAX_STR_SIZE, fin) != NULL) {
		int line_len = strlen(line);
		
		// if names == NULL, realloc works as malloc
		names = realloc(names, (lines+1)*sizeof(char*));
		if (names == NULL)	{
			perror("Out of memory");
			fclose(fin);
			exit(3);
		}
		names[lines] = malloc( (line_len+1)*sizeof(char));
		if (names[lines] == NULL)	{
			perror("Out of memory");
			fclose(fin);
			exit(3);
		}
		strcpy(names[lines], line);
		lines++;
	}
	free(line);
		
	fclose(fin);
	
		
	qsort(names, lines, sizeof(char*), 
		(int (*)(const void*,const void*))compareStringByRef);

	FILE* fout = fopen(fout_name, "wt");
	if (fout == NULL) {
		perror(fout_name);
		exit(1);
	}
	
	for(int i=0; i < lines; i++)
		fputs (names[i], fout);
	
	fclose(fout);
	
	printf("Write %d line(s)\n", lines);
	
	for(int i=0; i < lines; i++)
		free(names[i]);
	free(names);
		
	return 0;
}
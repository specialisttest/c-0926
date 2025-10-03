#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const char* fname_1 = "test.txt";

int count_words(const char* s) {
	int wordCount = 0;
	const int len = strlen(s);
	for(int i=0; i < len; i++){
		if (isblank(s[i])) {
			wordCount++;
		}
	}
	return wordCount+1;
	
}

int main(int argc, char *argv[]) {
	FILE* f = fopen(fname_1, "r");
	if (!f) {
		perror( fname_1);
		exit(1);
	}
	#define MAX_STR_SIZE 200
	char str[MAX_STR_SIZE];
	
	int lines = 0;
	int chars = 0;
	int words = 0;
	
	while (fgets(str, MAX_STR_SIZE, f) != NULL){
		int p = strlen(str)-1;
		while(p >= 0 && (str[p]=='\n' || str[p]=='\r'))
			str[p--] = '\0';
		
		puts(str);
		lines++;
		chars += strlen(str);
		words += count_words(str);
	}
	
	fclose(f);
	
	puts("****************************");
	printf("Lines : %d Chars : %d Words : %d\n", lines, chars, words);
	
	return 0;
}

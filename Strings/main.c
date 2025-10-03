#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <ctype.h>
#include <wchar.h>

typedef char* string;
//typedef const char* cstring;
typedef const string cstring;

// Лабораторная 10.1
/*
 *
 */
char* string_concat(const char* /*cstring*/ s1, const char* s2) {
	char* r = malloc( (strlen(s1)+strlen(s2)+1)*sizeof(char) );
	if (r == NULL) return r;
	
	strcpy(r, s1);
	return strcat(r, s2);
}


int strcmp_p(const void *a, const void *b) {
	const char* s1 = *(const char**)a;
	const char* s2 = *(const char**)b;
	return strcmp(s1, s2);
}

int main(int argc, char *argv[]) {
	system("chcp 1251 > nul");
	
	char s[20] = "Привет"; // string length up to 19
	
	wchar_t wch;
	printf("sizeof(wchar_t): %d\n", sizeof(wch));
	wchar_t ws[20] = L"Hello";
	puts(s);
	
	printf("strlen(s): %d sizeof(s): %d\n", strlen(s), sizeof(s));
	printf("wcslen(ws): %d sizeof(ws): %d\n", wcslen(ws), sizeof(ws));	
	
	
	char name[21] = "Sergey";
	// Hello, Sergey!
	//char hello[strlen(name) + 8 + 1]; // vla
	
	//char* hello = malloc ( (strlen(name) + 8 + 1)*sizeof(char) ); // heap
	string hello = malloc ( (strlen(name) + 8 + 1)*sizeof(char) ); // heap
	
	/*strcpy(hello, "Hello, ");
	strcat(hello, name);
	strcat(hello, "!");*/
	
	sprintf(hello, "Hello, %s!", name);
	puts(hello);
	
	const char* source = ",,Sergey,,,Andrey,Elena, Konstantin,Alexander,Matvey";
	int strl = strlen(source);
	int word_start = 0, word_end = 0;
	
	char** words = NULL;
	size_t word_count = 0;
	for(int i = 0; i < strl; i++)  {
		if( isspace(source[i]) || ispunct(source[i]) || i == strl-1) {
			
			if (i == strl-1)
				word_end = i;
			else
				word_end = i-1;
			
			if (word_end > word_start) {
				char* word = malloc( (word_end-word_start+1)*sizeof(char));
				memcpy(word,&source[word_start],(word_end-word_start+1)*sizeof(char));
				word[word_end-word_start+1] = '\0';
				//puts(word);
				words = realloc( words, sizeof(char*)*(++word_count));
				words[word_count-1] = word;
			}
			word_start = i+1;
			
		}
	}
	puts("******");
	for(int i = 0; i < word_count; i++)
		puts(words[i]);
		
	qsort(words, word_count, sizeof(char*), strcmp_p);
	puts("******");
	
	for(int i = 0; i < word_count; i++)
		puts(words[i]);
	
	free(hello);

	for(int i = 0; i < word_count; i++)
		free(words[i]);
		
	free(words);
	
	char* s1 = "Привет ";
	char* s2 = "Сергей";
	char* r = string_concat(s1, s2);
	
	puts(r);
	free(r);
	
	return 0;
}

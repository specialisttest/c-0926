#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// const char* source = "Sergey, Andrey, Alex, Anna";
// 1. Разрезать строка с именами (разделенных прболами или символами пунктуации)
// на массив строк (имен)
// 2. Вывестит массив имен в столбик
// 3.* Отсортировать массив имен (вывести таже в столбик)
// 4. Объединиить имена отсортированного массива в одну строку.

/* Ф-ии работы с кучей (Heap)

	void* malloc(size_t) // в памяти мусор
	void* calloc(size_t num_var, size_t one_var ); //  one_var*num_var обнуляет выделенную память
	void* realloc(void* p, size_t)
	free(void*)

*/

#define MAX_LN 6000

int compareStringByRef(const char** pc1, const char** pc2)
{
	return strcmp(*pc1, *pc2);
}
 
int main(int argc, char *argv[]) {
	char s[MAX_LN] = "  Sergey , Andrey,Alex, Anna    Julia   ";
	puts(s);
	
	char** words = NULL;
	int wordCount = 0;
	
	int len = strlen(s);
	for(int i = 0; i < len; i++) {
		if (isalpha(s[i])) {
			int last = len;
			for(int j = i + 1; j < len; j++)
				if(!isalpha(s[j])) {
					last = j;
					break;
				}
			// add new word	
			
			/*if (words == NULL)
				words = malloc(sizeof(char*)));
			else
				words = realloc(words, (wordCount+1)*sizeof(char*));*/
				
			words = realloc(words, (wordCount+1)*sizeof(char*));
			if (words == NULL) return -1;
			// words[wordCount] = calloc( last - i + 1, sizeof(char)  );
			words[wordCount] = malloc( (last - i + 1) * sizeof(char));
			if (words == NULL) return -1;
			
			strncpy(words[wordCount], &s[i], last - i);
			words[wordCount][last-i] = '\0';
			
			
			wordCount++;
			i = last;			
		}
	}
	
	printf("words count: %d\n", wordCount);
	for(int i = 0; i < wordCount; i++)
		printf("'%s'\n", words[i]);
		
	qsort(words, wordCount, sizeof(char*), compareStringByRef);
	
	puts(" ***** Sorted  ****");
	
	for(int i = 0; i < wordCount; i++)
		printf("'%s'\n", words[i]);
	
	int resultLength = 0;
	for(int i = 0; i < wordCount; i++)
		resultLength += strlen(words[i]) + 1;
		
	char* result = malloc(resultLength * sizeof(char));
	if (result == NULL) return -1;
	result[0] = '\0';
	
	for(int i = 0; i < wordCount; i++){
		strcat(result, words[i]);
		if (i != wordCount-1)
			strcat(result, ",");
	}
	
	puts(result);
		
	for(int i = 0; i < wordCount; i++)
		free(words[i]);
	free(words);
	
	free(result);
	
	return 0;
}
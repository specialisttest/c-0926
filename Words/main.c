#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// const char* source = "Sergey, Andrey, Alex, Anna";
// 1. Разрезать строка с именами (разделенных пробелами или символами пунктуации)
// на массив строк (имен)
// 2. Вывести массив имен в столбик
// 3.* Отсортировать массив имен (вывести таже в столбик)
// 4. Объединиить имена отсортированного массива в одну строку.

#define MAX_LN 60
 
int main(int argc, char *argv[]) {
	char s[MAX_LN] = "  Sergey , Andrey,Alex, Anna    Julia   ";
	puts(s);
	
	char words[MAX_LN/2 + 1][MAX_LN];
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
			strncpy(words[wordCount], &s[i], last - i);
			words[wordCount][last-i] = '\0';
			wordCount++;
			i = last;			
		}
	}
	
	printf("words count: %d\n", wordCount);
	for(int i = 0; i < wordCount; i++)
		printf("'%s'\n", words[i]);
		
	qsort(words, wordCount, MAX_LN, strcmp);
	
	puts(" ***** Sorted  ****");
	
	for(int i = 0; i < wordCount; i++)
		printf("'%s'\n", words[i]);
	
	char result[MAX_LN] = {0};
	for(int i = 0; i < wordCount; i++){
		strcat(result, words[i]);
		if (i != wordCount-1)
			strcat(result, ",");
	}
	
	puts(result);
	
	return 0;
}
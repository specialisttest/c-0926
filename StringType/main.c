#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

typedef char* String;
//typedef const char* CString;
typedef const String CString;

/*
	Реализовать bool parseInt(const char* s, int* pn)
	для перевода строки в число в десятичной системе счисления

*/

bool parseInt(const char* s, int* n) {
	if (s == NULL) return false;
	int len = strlen(s);
	if (len == 0) return false;
	int p = 1;
	int r = 0;
	for(int i= len - 1; i >= 0; i--) {
		if (isdigit(s[i]))
			r += p*(s[i] - '0');
		else
			if(i == 0) {
				if (s[i] == '-') r = -r;
				else if (s[i] != '+') return false;
			} else return false;
			
		p *= 10;
	}
	*n = r;
	return true;
}


int main(int argc, char *argv[]) {
	system("chcp 65001 > nul");
	{
		char* s = "abc";
		const char* cs = "Sergey";
		char* names[] = { "Анна", "Алиса", "Арабелла"};
		
		char** strArray = names;
	}
	
	{
		String s = "abc";
		CString cs = "Sergey";
		String names[] = { "Анна", "Алиса", "Арабелла"};
		
		String* strArray = names;
	}
	{
		CString s = "123";
		int x = atoi(s);
		
		printf("%d\n", x);
	}
	{
		CString s = "123";
		int x;
		if (parseInt(s, &x))
			printf("Conversion ok: %d\n", x);
		else
			printf("Conversion failed\n");
		
	}
	
	return 0;
}
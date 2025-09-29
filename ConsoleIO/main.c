#define _USE_MATH_DEFINES
#define __STDC_WANT_LIB_EXT1__ 1

#include <stdio.h>
#include <stdlib.h>

#include <math.h>

#include <locale.h>


int main(int argc, char *argv[]) {
	//setlocale(LC_ALL, "Russian");
	
	system("chcp 1251 > nul"); // specific for Windows (ansi codepage)
	//system("chcp 65001 > nul"); // utf-8
	
	#define MAX_NAME_SIZE 100
	
	char userName[MAX_NAME_SIZE];
	
	int age;
	
	printf("Enter your name: ");
	
//#ifdef __STDC_LIB_EXT1__ 
	scanf_s("%s", userName, MAX_NAME_SIZE);
	//gets_s(userName, MAX_NAME_SIZE);
//#else
	//scanf("%s", userName);
	//gets(userName);
//#endif

	printf("Enter your age: ");
	scanf("%d", &age);
	// %lf for double
	// %Lf for long double
	
	
	// Hello, Sergey - 48!
	printf("username address: %p\n", userName);
	
	printf("Hello, %s - 0x%x!\n", userName, age);
	printf("Hello, %s - %d!\n", userName, age);
	
	char* userNameRus = "Сергей";
	// Привет, Сергей - 48!
	
	printf("Привет, %s - %d!\n", userNameRus, age);
	
	
	printf("pi = %lf\n", M_PI);
	
	return 0;
}

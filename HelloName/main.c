#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
	char name[31];
	printf("Enter your name: ");
	gets(name); // gets_s(name, 31);
	
	/*if (strlen(name) != 0)
	//if (name[0] != '\0')
		printf("Hello, %s!\n", name);
	else
		printf("Hello, Stranger!\n");*/
		
	if (strlen(name) == 0)
		strcpy(name, "Stranger");
		
	printf("Hello, %s!\n", name);
	
	return 0;
}

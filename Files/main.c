#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <dirent.h>
#include <sys/stat.h>

const char* fname_1 = "test.txt";
const char* fname_2 = "test2.txt";
const char* dir_name = "c:\\c-0926\\";

int main(int argc, char *argv[]) {
	DIR* dir = opendir(dir_name);
	if (dir != NULL) {
		struct dirent* ent;
		while ( (ent = readdir(dir)) != NULL)
			//puts( (*ent).d_name );
			puts( ent->d_name );
		
		closedir(dir);
	} else {
		perror(dir_name);
		return 2; //exit(2);
	}
	
	struct stat attr;
	stat(fname_1, &attr);
	
	printf("%s\n", asctime(localtime(&attr.st_mtime)));
	
	
	FILE* f = fopen(fname_1, "r"); // "rt"
	if (f == NULL) {
		perror(fname_1);
		exit(1);
	}
	
	puts("Read by char");
	int byte;
	while ( (byte = fgetc(f)) != EOF )
		putchar(byte);
		
	puts("\nRead lines");
	
	fseek(f, 0, SEEK_SET ); // rewind(f);
#define MAX_STR_SIZE 200
	char str[MAX_STR_SIZE];
	
	while ( fgets(str, MAX_STR_SIZE, f) != NULL )
		printf(str);
		
	fseek(f, 0, SEEK_END);
	long f_size = ftell(f);
	printf("\nFile size: %ld\n", f_size);
	
	rewind(f);
	puts("Read formatted data (%s %d)");
	char word[MAX_STR_SIZE];
	int x;
	
	while(!feof(f)) {
		if (fscanf(f, "%s %d", word, &x) == 2)
			printf("word: %s number: %d\n", word, x);
	}
	
	fclose(f);
	
	puts("Write to file");
	FILE* f2 = fopen(fname_2, "a" /*"a"*/);
	if (f2 == NULL) {
		perror(fname_2);
		exit(3);
	}
	
	for(int i = 1; i <= 4; i++)
		fprintf(f2, "Line %d\n", i);
		
	fclose(f2);
	
	// rename(old_name, new_name);
	// remove(name);
	//FILE* tmp = tmpfile(); "w+b"
	
	return 0;
}

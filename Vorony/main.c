#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	system("chcp 1251 > nul");
	
	printf("������� ����� �� �����: ");
	int n;
	scanf("%d", &n);
	
	char* v;
	int n2 = n % 100;
	
	if ( n2 >= 11 && n2 <= 14)
		v = "�����";
	else
		switch( n % 10 ) {
			case 1: v = "������"; break;
			case 2:
			case 3:
			case 4: v = "������"; break;
			default: v = "�����"; break;
		}
	
	printf("�� ����� %d %s\n", n, v);
	
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	system("chcp 1251 > nul");
	
	// ���� ������
	printf("������� ����������� � �������� �������: ");
	double tc;
	scanf("%lf", &tc);
	
	// ��������� ������
	double tf =  9.0 / 5.0 * tc + 32.0;
	
	// ����� ������
	printf("����������� � �������� ����������: %.3lf\n", tf);
	
	return 0;
}

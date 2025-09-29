#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	system("chcp 1251 > nul");
	
	// ВВОД ДАННЫХ
	printf("Введите температуру в градусах Цельсия: ");
	double tc;
	scanf("%lf", &tc);
	
	// ОБРАБОТКА ДАННЫХ
	double tf =  9.0 / 5.0 * tc + 32.0;
	
	// ВЫВОД ДАННЫХ
	printf("Температуру в градусах Фаренгейта: %.3lf\n", tf);
	
	return 0;
}

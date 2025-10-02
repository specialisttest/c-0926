#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double bank_round(double x) {
	if ( (x - floor(x) == 0.5) &&
		 ( (long long)floor(fabs(x)) % 2 == 0 )
	)
		return x >= 0 ? floor(x) : ceil(x);
	
	return round(x);
}

int main(int argc, char *argv[]) {
	
	printf("round %.1lf : %.1lf\n", 1.1, round(1.1));
	printf("round %.1lf : %.1lf\n", 1.9, round(1.9));
	printf("round %.1lf : %.1lf\n", 1.5, round(1.5));
	printf("round %.1lf : %.1lf\n", 2.5, round(2.5));
	
	printf("round %.1lf : %.1lf\n", -1.1, round(-1.1));
	printf("round %.1lf : %.1lf\n", -1.9, round(-1.9));
	printf("round %.1lf : %.1lf\n", -1.5, round(-1.5));
	printf("round %.1lf : %.1lf\n", -2.5, round(-2.5));
	
	printf("floor %.1lf : %.1lf\n", 1.9, floor(1.9));
	printf("ceil %.1lf : %.1lf\n", 1.1, ceil(1.1));
	
	printf("floor %.1lf : %.1lf\n", -1.9, floor(-1.9));
	printf("ceil %.1lf : %.1lf\n", -1.1, ceil(-1.1));
	
	double d = -1.5;
	printf("|d| = %f\n", fabs(d));
	
	printf("bank_round %.1lf : %.1lf\n", 1.1, bank_round(1.1));
	printf("bank_round %.1lf : %.1lf\n", 1.9, bank_round(1.9));
	printf("bank_round %.1lf : %.1lf\n", 2.9, bank_round(2.9));
	printf("bank_round %.1lf : %.1lf\n", 1.5, bank_round(1.5));
	printf("bank_round %.1lf : %.1lf\n", 2.5, bank_round(2.5));
	printf("bank_round %.1lf : %.1lf\n", 0.5, bank_round(0.5));
	
	
	printf("bank_round %.1lf : %.1lf\n", -1.1, bank_round(-1.1));
	printf("bank_round %.1lf : %.1lf\n", -1.9, bank_round(-1.9));
	printf("bank_round %.1lf : %.1lf\n", -2.9, bank_round(-2.9));
	printf("bank_round %.1lf : %.1lf\n", -1.5, bank_round(-1.5));
	printf("bank_round %.1lf : %.1lf\n", -2.5, bank_round(-2.5));	
	printf("bank_round %.1lf : %.1lf\n", -0.5, bank_round(-0.5));
	
	
	
	return 0;
}

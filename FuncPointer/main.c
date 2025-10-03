#define _USE_MATH_DEFINES


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef double (*MathFunction)(double) ;

#define STEPS 1'000'000

double integral(/*double (* pToFunc)(double)*/ MathFunction pToFunc, double a, double b) {
	double w = (b - a) / STEPS;
	double summa = 0.0;
	for(int i = 0; i < STEPS; i++) {
		double x = a + w * i + w / 2;
		double h = pToFunc(x); // (*pToFunc)(x)
		summa += h * w;
	}
	
	return summa;
}

double x2(double x) {
	return x*x;
}

double log_sin(double x) {
	return log(sin(x));
}


int main(int argc, char *argv[]) {
	
	// указатель на функцию
	//  double (*)(double)
	
	double (* pToFunc)(double) = sin; // &sin
	
	
	double r1 = integral(sin, 0.0, M_PI / 2);
	printf("integral sin (0, PI/2) = %.14f\n", r1);

	double r2 = integral(cos, 0.0, M_PI / 2);
	printf("integral cos (0, PI/2) = %.14f\n", r2);
	
	double r3 = integral(x2, 0.0, 1.0);
	printf("integral x^2 (0,1) = %.14f\n", r3);
	
	double r4 = integral(log_sin, 0.0, M_PI / 2);
	printf("integral log_sin (0, PI/2) = %.14f\n", r4);
	
	printf("log_sin address: %p\n", &log_sin); // code segment
	
	return 0;
}

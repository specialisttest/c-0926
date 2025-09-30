#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*
	������ ���������� ���������
	
	ax^2 + bx + c = 0
	a!=0
	
	D = b*b-4*a*c;
	
	D < no roots
	D == 0.0 x = -b/(2*a)
	D > 0 x1 = (-b+sqrt(D))/(2*a) x2 = (-b-sqrt(D))/(2*a)
	
*/

int main(int argc, char *argv[]) {
	
	puts("Square equation");
	double a, b, c;
	printf("Enter a b c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	if (a == 0.0)
		puts("This is not square equation");
	else {
		double d = b*b - 4*a*c;
		if (d < 0.0)
			puts("No roots");
		else
			/*
				const double eps = 0.0000001
				if (d == 0.0)
				if (fabs(d) < eps)
				double target = 2.5;
				if (d == target)
				if ( fabs(d-target)< eps )
			*/
			if (d == 0.0) {
				double x = -b / (2*a);
				printf("Single root: %lf\n", x);
			}
			else { // d > 0
				double ds = sqrt(d);
				double x1 = (-b + ds) / (2*a);
				double x2 = (-b - ds) / (2*a);
				printf("x1 = %lf\nx2 = %lf\n", x1, x2);
			}
				
	}
	
	return 0;
}

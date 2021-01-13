#include <stdio.h>
#include <math.h>

int main(){
	double i = 1;
	double ai = 1;
	double eps = pow(10, -6);
	double pi = 0;
	do{
		pi += ai * pow(-1, i - 1);
		i++;
		ai = (1 / (2 * (i - 1) + 1));
		
	}while(ai >= eps);
	printf("PI=%10.8f\n", pi * 4);
	return 0;
}
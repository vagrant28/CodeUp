#include <stdio.h>

void swap(double* x, double* y){
	double tmp = *x;
	*x = *y;
	*y = tmp;
}

int main(){
	double a, b, c, tmp;
	scanf("%lf%lf%lf", &a, &b, &c);
	if(a > b){
		swap(&a, &b);
	}
	if(b > c){
		swap(&b, &c);
	}
	if(a > b){
		swap(&a, &b);
	}
	printf("%.2f %.2f %.2f\n", a, b, c);
	return 0;
}
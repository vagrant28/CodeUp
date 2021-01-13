#include <stdio.h>

int main(){
	double a, b;
	scanf("%lf%lf", &a, &b);
	if(a > b){
		double tmp = a;
		a = b;
		b = tmp;
	}
	printf("%.2f %.2f\n", a, b);
	return 0;
}
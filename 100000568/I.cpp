#include <stdio.h>

int main(){
	double sum = 0;
	double a = 2, b = 3, c;
	double x = 1, y = 2, z;
	int i = 0;
	sum += a / x;
	sum += b / y;
	for(; i < 18; i++){
		c = a + b;
		z = x + y;
		sum += c / z;
		a = b;
		b = c;
		x = y;
		y = z;
	}
	printf("%.6f\n", sum);
	return 0;
}
#include <stdio.h>

int main(){
	double y;
	int n;
	while(scanf("%lf%d", &y, &n) != EOF){
		int y0 = y;
		while(n--){
			y = y * 2 / 3 + y0 / (3 * y * y);
		}
		printf("%.6f\n", y);
	}
	return 0;
}

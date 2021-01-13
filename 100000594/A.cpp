#include <stdio.h>

int exGcd(int a, int b, int &x, int &y){
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	int g = exGcd(b, a % b, x, y);
	int tmp = x;
	x = y;
	y = tmp - a / b * y;
	return g;
}

int inverse(int a, int m){
	int x, y;
	int g = exGcd(a, m, x, y);
	return (x % m + m) % m;
}

int main(){
	int a, m;
	while(scanf("%d%d", &a, &m) != EOF){
		int ans = inverse(a, m);
		printf("%d\n", ans);
	}
	return 0;
}

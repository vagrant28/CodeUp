#include <stdio.h>

int a[25];

int F(int i){
	if(i == 0 || i == 1){
		a[i] = 1;
		return 1;
	}
	return a[i] =  F(i - 1) + F(i - 2);
}

int main(){
	F(20);
	int n, m;
	scanf("%d", &m);
	while(m--){
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 2 * (n - i); j++){
				putchar(' ');
			}
			printf("0");
			for(int j = 0; j < 2 * (i - 1); j++){
				printf(" %d", a[j]);
			}
			putchar('\n');
		}
	}
	return 0;
}

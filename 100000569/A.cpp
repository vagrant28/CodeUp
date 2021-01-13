#include <stdio.h>

int main(){
	int a[10];
	int n;
	for(int i = 0; i < 9; i++){
		scanf("%d", &a[i]);
	}
	scanf("%d", &n);
	int i = 0;
	while(a[i] <= n){
		i++;
	}
	int tmp;
	for(int j = 8; j >= i; j--){
		a[j + 1] = a[j];
	}
	a[i] = n;
	for(int i = 0; i < 10; i++){
		printf("%d", a[i]);
		if(i != 9){
			putchar('\n');
		}
	}
	return 0;
}

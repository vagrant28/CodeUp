#include <stdio.h>

int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		int ans[20];
		int num = 0;
		do{
			ans[num++] = n % 8;
			n /= 8;
		}while(n != 0);
		for(int i = num - 1; i >= 0; i--){
			printf("%d", ans[i]);
		}
		putchar('\n');
	}
	return 0;
}

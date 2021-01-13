#include <stdio.h>

int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= i - 1; j++){
				putchar(' ');
			}
			for(int j = 1; j <= n - i + 1; j++){
				putchar('*');
				if(j == n - i + 1){
					putchar('\n');
				}
				else{
					putchar(' ');
				}
			}
		}
		for(int i = 2; i <= n; i++){
			for(int j = 1; j <= n - i; j++){
				putchar(' ');
			}
			for(int j = 1; j <= i; j++){
				putchar('*');
				if(j == i){
					putchar('\n');
				}
				else{
					putchar(' ');
				}
			}
		}
	}
	return 0;
}

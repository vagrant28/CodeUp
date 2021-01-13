#include <stdio.h>

int main(){
	int m, h;
	scanf("%d", &m);
	while(m--){
		scanf("%d", &h);
		for(int i = 1; i <= h; i++){
			for(int j = 1; j <= h - i; j++){
				putchar(' ');
			}
			for(int j = 1; j <= h + 2 * (i - 1); j++){
				putchar('*');
			}
			putchar('\n');
		}
	}
	return 0;
}

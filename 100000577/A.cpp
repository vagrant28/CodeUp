#include <stdio.h>

int main(){
	int h;
	while(scanf("%d", &h) != EOF){
		for(int i = 1; i <= h; i++){
			for(int j = 1; j <= 2 * (h - i); j++){
				putchar(' ');
			}
			for(int k = 1; k <= h + 2 * (i - 1); k++){
				putchar('*');
			}
			putchar('\n');
		}
	}
	return 0;
}

#include <stdio.h>

int main(){
	int m;
	char str[200][30];
	while(scanf("%d", &m) != EOF){
		for(int i = 0; i < m; i++){
			scanf("%s", str[i]);
		}
		for(int i = 1; i <= m; i++){
			int h;
			if(i <= 4){
				h = i;
			}
			else{
				h = 4;
			}
			for(int j = 1; j <= h; j++){
				printf("%d=%s", j, str[i-j]);
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

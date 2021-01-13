#include <stdio.h>

int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		for(int i = 0; i <= n / 5; i++){
			for(int j = 0; j <= n / 3; j++){
				for(int k = 0; k <= n * 3; k++){
					if(i + j + k == 100 && (15 * i + 9 * j + k <= 3 * n)){
						printf("x=%d,y=%d,z=%d\n", i, j, k);
					}
				}
			}
		}
	}
	return 0;
}

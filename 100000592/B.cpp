#include <stdio.h>
#include <string.h>
#include <math.h>
const int maxn = 1e6 + 10;

int wan[maxn] = {6, 28, 496, 8128}, wNum = 4;

void findWan(){
	wNum = 0;
	for(int i = 2; i < maxn; i++){
		int sum = 1, h = (int)sqrt(1.0 * i);
		for(int j = 2; j <= h; j++){
			if(i % j == 0){
				sum += j;
				sum += i / j;
			}
		}
		if(sum == i){
			wan[wNum++] = i;
		}
	}
}

int main(){
	// 6 28 496 8128
//	findWan();
//	printf("%d\n", wNum);
//	for(int i = 0; i < wNum; i++){
//		printf("%d ", wan[i]);
//	}
	int n;
	while(scanf("%d", &n) != EOF){
		int s = 0;
		for(int i = 0; i < wNum; i++){
			if(wan[i] <= n){
				if(s){
					printf(" ");
				}
				s = 1;
				printf("%d", wan[i]);
			}
		}
		printf("\n");
	}
	return 0;
}

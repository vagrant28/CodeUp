#include <stdio.h>
#include <math.h>
const int maxn = 70;

int w[maxn], y[maxn];
int wNum, yNum;

void find(){
	wNum = 0, yNum = 0;
	for(int i = 2; i <= 60; i++){
		int sum = 1, h = (int)sqrt(1.0 * i);
		for(int j = 2; j <= h; j++){
			if(i % j == 0){
				sum += j;
				if(i / j != j){
					sum += i / j;
				}
			}
		}
		if(sum == i){
			w[wNum++] = i;
		}
		else if(sum > i){
			y[yNum++] = i;
		}
	}
}

int main(){
	find();
	printf("E: ");
	for(int i = 0; i < wNum; i++){
		printf("%d ", w[i]);
	}
	printf("G:");
	for(int i = 0; i < yNum; i++){
		printf(" %d", y[i]);
	}
	return 0;
}

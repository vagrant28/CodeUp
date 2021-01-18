#include <stdio.h>

int a[10];

void swap(int x, int y){
	int tmp = a[x];
	a[x] = a[y];
	a[y] = tmp;
	return;
}

int main(){
	for(int i = 0; i < 10; i++){
		scanf("%d", &a[i]);
	}
	int max = a[0], index = 0;
	for(int i = 1; i < 10; i++){
		if(a[i] > max){
			max = a[i];
			index = i;
		}
	}
	swap(index, 9);
	
	int min = a[0];
	index = 0;
	for(int i = 1; i < 10; i++){
		if(a[i] < min){
			min = a[i];
			index = i;
		}
	}
	swap(0, index);
	
	for(int i = 0; i < 10; i++){
		printf("%d ", a[i]);
	}
	return 0;
} 

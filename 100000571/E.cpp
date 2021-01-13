#include <stdio.h>

void input(int* a){
	for(int i = 0; i < 10; i++)
		scanf("%d", &a[i]);
}

void output(int* a){
	for(int i = 0; i < 10; i++){
		printf("%d ", a[i]);
	}
	putchar('\n');		
}

void process(int* a){
	int min_index = 0, max_index = 0;
	for(int i = 0; i < 10; i++){
		if(a[i] < a[min_index]){
			min_index = i;
		}
		if(a[i] > a[max_index]){
			max_index = i;
		}
	}
	int tmp;
	tmp = a[0];
	a[0] = a[min_index];
	a[min_index] = tmp;
	tmp = a[9];
	a[9] = a[max_index];
	a[max_index] = tmp;
}

int main(){
	int a[10];
	input(a);
	process(a);
	output(a);
	return 0;
}

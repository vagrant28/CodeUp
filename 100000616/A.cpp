#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 100000 + 10;

int n;
int heap[maxn];

void downAdjust(int low, int high){
	int i = low, j = 2 * i;
	while(j <= high){
		if(j + 1 <= high && heap[j + 1] > heap[j]){
			j = j + 1;
		}
		if(heap[i] < heap[j]){
			swap(heap[i], heap[j]);
			i = j;
			j = 2 * i;
		}
		else{
			break;
		}
	}
}

void createHeap(){
	for(int i = n / 2; i >= 1; i--){
		downAdjust(i, n);
	}
}

void heapSort(){
	createHeap();
	for(int i = n; i > 1; i--){
		swap(heap[1], heap[i]);
		downAdjust(1, i - 1);
	}
}

int main(){
	while(scanf("%d", &n) != EOF){
		for(int i = 1; i <= n; i++){
			scanf("%d", &heap[i]);
		}
		heapSort();
		for(int i = 1; i <= n; i++){
			printf("%d ", heap[i]);
		}
		printf("\n");
	}
	return 0;
}

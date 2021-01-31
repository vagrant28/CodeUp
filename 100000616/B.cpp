#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 100000 + 10;

int N, num;
int heap[maxn], A[maxn], B[maxn];

void downAdjust(int low, int high){
	int i = low, j = 2 * i;
	while(j <= high){
		if(j + 1 <= high && heap[j + 1] > heap[j]){
			j = j + 1;
		}
		if(heap[j] > heap[i]){
			swap(heap[j], heap[i]);
			i = j;
			j = 2 * i;
		}
		else{
			break;
		}
	}

}

void createHeap(){
	for(int i = N / 2; i >= 1; i--){
		downAdjust(i, N);
	}
}

void heapSort(){
	for(int i = N; i > 1; i--){
		swap(heap[1], heap[i]);
		downAdjust(1, i - 1);
	}
}


int main(){
	while(scanf("%d", &N) != EOF){
		for(int i = 1; i <= N; i++){
			scanf("%d", &A[i]);
		}
		for(int i = 1; i <= N; i++){
			scanf("%d", &B[i]);
		}
		for(int i = 1; i <= N; i++){
			heap[i] = A[1] + B[i];
		}
		createHeap();
		for(int i = 2; i <= N; i++){
			for(int j = 1; j <= N; j++){
				if(A[i] + B[j] < heap[1]){
					heap[1] = A[i] + B[j];
					downAdjust(1, N);
				}
				else{
					break;
				}
			} 
		}
		heapSort();
		for(int i = 1; i <= N; i++){
			printf("%d ", heap[i]);
		}
		printf("\n");
	}
	return 0;
}

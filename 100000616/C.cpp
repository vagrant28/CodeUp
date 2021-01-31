#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 30000 + 10;

int n;
int heap[maxn];

void print(){
	for(int i = 1; i <= n; i++){
		printf("%d ", heap[i]);
	}
	printf("\n");
}

void downAdjust(int low, int high){
	int i = low, j = 2 * i;
	while(j <= high){
		if(j + 1 <= high && heap[j + 1] < heap[j]){
			j = j + 1;
		}
		if(heap[j] < heap[i]){
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
	for(int i = n / 2; i >= 1; i--){
		downAdjust(i, n);
//		print();
	}
}

int deleteTop(){
	int top = heap[1];
	heap[1] = heap[n--];
	downAdjust(1, n);
	return top;
}

void upAdjust(int low, int high){
	int i = high, j = i / 2;
	while(j >= low){
		if(heap[j] > heap[i]){
			swap(heap[j], heap[i]);
			i = j;
			j = i / 2;
		}
		else{
			break;
		}
	}
}

int insert(int x){
	heap[++n] = x;
	upAdjust(1, n);
}


int main(){
	while(scanf("%d", &n) != EOF){
		for(int i = 1; i <= n; i++){
			scanf("%d", &heap[i]);
		}
		createHeap();
//		print();
		int sum = 0;
		while(n > 1){
			int a = deleteTop();
			int b = deleteTop();
			sum = sum + a + b;
			insert(a + b);
		}
		printf("%d\n", sum);
	}
	return 0;
}

#include <stdio.h>
const int maxn = 5010;

int n;
int a[maxn];

int Partition(int L, int R){
	int tmp = a[L];
	while(L < R){
		while(L < R && a[R] > tmp){
			R--;
		}
		a[L] = a[R];
		while(L < R && a[L] <= tmp){
			L++;
		}
		a[R] = a[L];
	}
	a[L] = tmp;
	return L;
}

void qsort(int L, int R){
	if(L < R){
		int pos = Partition(L, R);
		qsort(L, pos - 1);
		qsort(pos + 1, R);
	}
}

int main(){
	while(scanf("%d", &n) != EOF){
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
		}
		qsort(0, n - 1);
		for(int i = 0; i < n; i++){
			printf("%d\n", a[i]);
		}
	}
	return 0;
}

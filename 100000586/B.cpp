#include <stdio.h>
const int maxn = 1e5 + 10;

int a[maxn], tmp[maxn];
int n, m;

void merge(int L1, int R1, int L2, int R2){
	int i = L1, j = L2;
	int index = 0;
	while(i <= R1 && j <= R2){
		if(a[i] <= a[j]){
			tmp[index++] = a[i++];
		}
		else{
			tmp[index++] = a[j++];
		}
	}
	while(i <= R1){
		tmp[index++] = a[i++];
	}
	while(j <= R2){
		tmp[index++] = a[j++];
	}
	for(int k = 0; k < index; k++){
		a[L1 + k] = tmp[k];
	}
}

void mergeSort(int L, int R){
	if(L < R){
		int mid = (L + R) / 2;
		mergeSort(L, mid);
		mergeSort(mid + 1, R);
		merge(L, mid, mid + 1, R);
	}
}

int main(){
	scanf("%d", &n);
	while(n--){
		scanf("%d", &m);
		for(int i = 0; i < m; i++){
			scanf("%d", &a[i]);
		}
		mergeSort(0, m - 1);
		for(int i = 0; i < m; i++){
			printf("%d\n", a[i]);
		}
	}
	return 0;
}

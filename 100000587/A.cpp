#include <stdio.h>
//#include <time.h>
//#include <stdlib.h>
//#include <math.h>
const int maxn = 1e6 + 10;

int a[maxn];
int n, k;

void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

int randPartition(int L, int R){
//	int p = (int)(round(1.0 * rand() / RAND_MAX * (R - L) + L));
//	swap(a[L], a[p]);
	int tmp = a[L];
	while(L < R){
		while(L < R && a[R] < tmp){
			R--;
		}
		a[L] = a[R];
		while(L < R && a[L] >= tmp){
			L++;
		}
		a[R] = a[L];
	}
	a[L] = tmp;
	return L;
}

int qselect(int L, int R, int k){
	if(L == R){
		return a[L];
	}
	else if(L < R){
		int pos = randPartition(L, R);
		int M = pos - L + 1;
		if(M == k){
			return a[pos];
		}
		else if(M > k){
			return qselect(L, pos - 1, k);
		}
		else{
			return qselect(pos + 1, R, k - M);
		}
	}
}


int main(){
//	srand((unsigned)time(NULL));
	while(scanf("%d%d", &n, &k) != EOF){
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
		}
		int ans = qselect(0, n - 1, k);
		printf("%d\n", ans);
	}
	return 0;
}

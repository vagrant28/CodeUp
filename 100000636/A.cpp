#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define lowbit(i) ((i) & (-i))
const int maxn = 500000 + 10;

struct node{
	int val;
	int pos;
}temp[maxn];

int A[maxn], c[maxn];
int n;

bool cmp(node a, node b){
	return a.val > b.val;
}

void update(int x, int v){
	for(int i = x; i < maxn; i += lowbit(i)){
		c[i] += v;
	}
}

int getSum(int x){
	int sum = 0;
	for(int i = x; i > 0; i -= lowbit(i)){
		sum += c[i];
	}
//	printf("sum=%d\n", sum);
	return sum;
}

int main(){
	while(scanf("%d", &n) != EOF){
		if(n == 0){
			break;
		}
		memset(c, 0, sizeof(c));
		for(int i = 0; i < n; i++){
			scanf("%d", &temp[i].val);
			temp[i].pos = i;
		}
		sort(temp, temp + n, cmp);
		for(int i = 0; i < n; i++){
			if(i == 0 || temp[i].val != temp[i - 1].val){
				A[temp[i].pos] = i + 1;
			}
			else{
				A[temp[i].pos] = A[temp[i - 1].pos];
			}
		}
//		printf("A[]: ");
//		for(int i = 0; i < n; i++){
//			printf("%d ", A[i]);
//		}
//		printf("\n");
		long long sum = 0;
		for(int i = 0; i < n; i++){
			update(A[i], 1);
//			printf("c[]: ");
//			for(int i = 0; i <= n; i++){
//				printf("%d ", c[i]);
//			}
//			printf("\n");
			sum += getSum(A[i] - 1);
		}
		
		printf("%lld\n", sum);
	}
	return 0;
}

// 9 1 0 5 4
// 0 1 2 1 2

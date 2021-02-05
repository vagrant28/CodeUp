#include <stdio.h>
#include <string.h>
#include <algorithm>
#define lowbit(i) ((i) & (-i))
using namespace std;
const int maxn = 50010;

int a[maxn];
int c[maxn];
int l[maxn], r[maxn];
int n;

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
	return sum;
}

int main(){
	while(scanf("%d", &n) != EOF){
		int t;
		memset(c, 0, sizeof(c));
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
			update(a[i], 1);
			l[i] = getSum(a[i] - 1);
		}
//		printf("l[]: ");
//		for(int i = 0; i < 5; i++){
//			printf("%d ", l[i]);
//		}
//		printf("\n");
		memset(c, 0, sizeof(c));
		for(int i = n - 1; i >= 0; i--){
			update(a[i], 1);
			r[i] = getSum(a[i] - 1);
		}
//		printf("r[]: ");
//		for(int i = 0; i < 5; i++){
//			printf("%d ", r[i]);
//		}
//		printf("\n");
		long long num = 0;
		for(int i = 0; i < n; i++){
			num = num + l[i] * r[i];
		}
		printf("%lld\n", num);
	}
	return 0;
}

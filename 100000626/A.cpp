#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 1e4 + 10;

struct node{
	int v;
	int s, t;
};

int a[maxn];
node dp[maxn];

bool cmp(node a, node b){
	if(a.v != b.v){
		return a.v > b.v;
	}
	else{
		if(a.s != b.s){
			return a.s < b.s;
		}
		else{
			return a.t < b.t;
		}
	}
}

int main(){
	int k;
	while(scanf("%d", &k), k){
		int flag = false;
		for(int i = 0; i < k; i++){
			scanf("%d", &a[i]);
			if(a[i] >= 0){
				flag = true;
			}
		}
//		printf("a[]: ");
//		for(int i = 0; i < k; i++){
//			printf("%d ", a[i]);
//		}
//		printf("\n");
		if(flag == false){
			printf("0 %d %d\n", a[0], a[k - 1]);
		}
		else{
			dp[0].v = a[0];
			dp[0].s = 0;
			dp[0].t = 0;
			for(int i = 1; i < k; i++){
				if(dp[i - 1].v > 0){
					dp[i].v = dp[i - 1].v + a[i];
					dp[i].s = dp[i - 1].s;
					dp[i].t = i;
				}
				else{
					dp[i].v = a[i];
					dp[i].s = i;
					dp[i].t = i;
				}
			}
//			printf("dp[]:\n");
//			for(int i = 0; i < k; i++){
//				printf("i=%d, v=%d, s=%d, t=%d\n", i, dp[i].v, dp[i].s, dp[i].t);
//			}
			sort(dp, dp + k, cmp);
			printf("%d %d %d\n", dp[0].v, a[dp[0].s], a[dp[0].t]);
		}
	}	
	return 0;
}


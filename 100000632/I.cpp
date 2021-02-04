#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 50;

struct node{
	int h, l, t;
}bg[maxn];

int dp[1100];

bool cmp(node a, node b){
	return a.t < b.t;
}

int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		if(n < 0){
			break;
		}
		int max_t = -1;
		for(int i = 1; i <= n; i++){
			scanf("%d%d%d", &bg[i].h, &bg[i].l, &bg[i].t);
			max_t = max(max_t, bg[i].t);
		}
		sort(bg + 1, bg + n + 1, cmp);
		fill(dp, dp + 1100, 0);
		for(int i = 1; i <= n; i++){
			for(int j = bg[i].t; j >= bg[i].l; j--){
				dp[j] = max(dp[j], dp[j - bg[i].l] + bg[i].h);
			}
//			printf("dp[]: ");
//			for(int i = 0; i <= max_t; i++){
//				printf("%d ", dp[i]);
//			} 
//			printf("\n");
		}
		int max_h = -1;
		for(int i = 0; i <= max_t; i++){
			max_h = max(max_h, dp[i]);
		}
		printf("%d\n", max_h);

	}
	return 0;
}

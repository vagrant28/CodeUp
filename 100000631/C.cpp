#include <stdio.h>
#include <algorithm>
using namespace std;
const int MAXV = 30;
const int MAXN = 1e4 + 10; 

int main(){
	int V, N;
	int w[MAXV];
	long long dp[MAXN];
	while(scanf("%d%d", &V, &N) != EOF){
		for(int i = 1; i <= V; i++){
			scanf("%d", &w[i]);
		}
		fill(dp, dp + MAXN, 0);
		dp[0] = 1;
		for(int i = 1; i <= V; i++){
			for(int v = w[i]; v <= N; v++){
				dp[v] += dp[v - w[i]];
			}
//			for(int i = 0; i <= N; i++){
//				printf("%d ", dp[i]);
//			}
//			printf("\n");
		}
		printf("%lld\n", dp[N]);
	}
	return 0;
}

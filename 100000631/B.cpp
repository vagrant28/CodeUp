#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 1010;

int T, M;
int w[maxn], v[maxn], dp[maxn];

int main(){
	while(scanf("%d%d", &T, &M) != EOF){
		for(int i = 1; i <= M; i++){
			scanf("%d%d", &w[i], &v[i]);
		}
		fill(dp, dp + maxn, 0);
		for(int i = 1; i <= M; i++){
			for(int t = T; t >= w[i]; t--){
				dp[t] = max(dp[t], dp[t - w[i]] + v[i]);
			}
		}
		int MAX = 0;
		for(int i = 0; i <= T; i++){
			if(dp[i] > MAX){
				MAX = dp[i];
			}
		}
		printf("%d\n", MAX);
	}
	return 0;
}


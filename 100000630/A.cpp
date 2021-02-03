#include <stdio.h>
#include <algorithm>
using namespace std;
const int INF = (1 << 30) - 1;
const int maxn = 1010;

struct rect{
	int a, b;
}rectArr[maxn];

int N, n;
int dp[maxn];
int G[maxn][maxn];

bool isEmbed(int x, int y){
	int a = rectArr[x].a, b = rectArr[x].b;
	int c = rectArr[y].a, d = rectArr[y].b;
	return (a < c && b < d) || (b < c && a < d);
}

int DP(int i){
	if(dp[i] > 0){
		return dp[i];
	}
	for(int j = 0; j < n; j++){
		if(isEmbed(i, j)){
			dp[i] = max(dp[i], DP(j) + 1);
		}
	}
	return dp[i];
}


int main(){
	scanf("%d", &N);
	while(N--){
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			scanf("%d%d", &rectArr[i].a, &rectArr[i].b);
		}
		fill(dp, dp + maxn, 0);
		int MAX = -1;
		for(int i = 0; i < n; i++){
			int t = DP(i);
			if(MAX < t){
				MAX = t;
			}
		}
//		for(int i = 0; i < n; i++){
//			printf("%d ", dp[i]);
//		}
//		printf("\n");
		printf("%d\n", MAX + 1);
	}
	return 0;
}

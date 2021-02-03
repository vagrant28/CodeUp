#include <stdio.h>
#include <algorithm>
using namespace std;
const int INF = (1 << 30) - 1;
const int maxn = 110;

int N;
int M[maxn][maxn];
int dp[maxn], r[maxn];

int subSeq(){
	fill(dp, dp + maxn, 0);
	dp[0] = r[0];
	int ans = dp[0];
	for(int i = 1; i < N; i++){
		if(dp[i - 1] > 0){
			dp[i] = dp[i - 1] + r[i];
		}
		else{
			dp[i] = r[i];
		}
		if(ans < dp[i]){
			ans = dp[i];
		}
	}
	return ans;
}

int main(){
	while(scanf("%d", &N) != EOF){
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				scanf("%d", &M[i][j]);
			}
		}
		int res = M[0][0];
		for(int i = 0; i < N; i++){		 
			fill(r, r + maxn, 0);
			for(int j = i; j < N; j++){
				for(int k = 0; k < N; k++){
					r[k] += M[j][k];
				}
				res = max(res, subSeq());
			}
		}
		printf("%d\n", res);
	}
	return 0;
}

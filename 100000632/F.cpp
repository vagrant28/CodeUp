#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 20;

int M, N;
int dp[maxn][maxn];

int f(int m, int n){
	if(m < n){
		dp[m][n] = f(m, m);
		return dp[m][n];
	}
	if(n == 1 || m == 0){
		dp[m][n] = 1;
		return 1;
	}
	dp[m][n] = f(m, n - 1) + f(m - n, n);
	return dp[m][n];
}


int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &M, &N);
		fill(dp[0], dp[0] + maxn * maxn, 0);
		int ans = f(M, N);
		printf("%d\n", ans);
	}
	return 0;
}

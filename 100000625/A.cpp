#include <stdio.h>
#include <algorithm>
using namespace std;
const int MAXN = 40;

int dp[MAXN];

int fib(int n){
	if(n == 0 || n == 1){
		return 1;
	}
	if(dp[n] != -1){
		return dp[n];
	}
	else{
		dp[n] = fib(n - 1) + fib(n - 2);
		return dp[n];
	}
}


int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		fill(dp, dp + MAXN, -1);
		printf("%d\n", fib(n - 1));
	}
	return 0;
}


#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxc = 1010;
const int maxn = 110;

int c, n;
int dp[maxc], price[maxn], value[maxn];


int main(){
	while(scanf("%d%d", &c, &n) != EOF){
		for(int i = 1; i <= n; i++){
			scanf("%d%d", &price[i], &value[i]);
		}
		fill(dp, dp + maxc, 0);
		for(int i = 1; i <= n; i++){
			for(int j = c; j >= price[i]; j--){
				dp[j] = max(dp[j], dp[j - price[i]] + value[i]);
			}
		}
//		printf("dp[]: ");
//		for(int i = 0; i <= c; i++){
//			printf("%d ", dp[i]);
//		}
//		printf("\n");
		printf("%d\n", dp[c]);
	}
	return 0;
}

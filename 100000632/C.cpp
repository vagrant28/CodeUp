#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 250;

int main(){
	int N;
	int t[maxn], dp[maxn];
	while(scanf("%d", &N), N){
		for(int i = 1; i <= N; i++){
			scanf("%d", &t[i]);
		}
		int MAX = -1;
		for(int k = 1; k <= N; k++){
			int LMAX = -1;
			for(int i = 1; i <= k; i++){
				dp[i] = 1;
				for(int j = 1; j < i; j++){
					if(t[i] > t[j] && dp[j] + 1 > dp[i]){
						dp[i] = dp[j] + 1;
					}
				}
				LMAX = max(LMAX, dp[i]);
			}
			
			int RMAX = -1;
			for(int i = k; i <= N; i++){
				dp[i] = 1;
				for(int j = k; j < i; j++){
					if(t[i] < t[j] && dp[j] + 1 > dp[i]){
						dp[i] = dp[j] + 1;
					}
				}
				RMAX = max(RMAX, dp[i]);
			}
//			printf("k=%d, LMAX=%d, RMAX=%d\n", k, LMAX, RMAX);
			MAX = max(MAX, LMAX + RMAX - 1);
		}
//		printf("MAX=%d\n", MAX);
		printf("%d\n", N - MAX);
	}
	return 0;
}

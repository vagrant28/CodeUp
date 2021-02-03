#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 1e4 + 10;

int a[maxn], dp[maxn];

int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
		}
		int num = -1;
		for(int i = 0; i < n; i++){
			dp[i] = 1;
			for(int j = 0; j < i; j++){
				if(a[i] > a[j] && dp[i] < dp[j] + 1){
					dp[i] = dp[j] + 1;
				}
			}
			num = max(num, dp[i]);
		}
		printf("%d\n", num);
	}
	return 0;
}

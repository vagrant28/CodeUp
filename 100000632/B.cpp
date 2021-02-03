#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxk = 30;

int arr[maxk], dp[maxk];

int main(){
	int k;
	while(scanf("%d", &k), k){
		for(int i = 1; i <= k; i++){
			scanf("%d", &arr[i]);
		}
		int MAX = -1;
		for(int i = 1; i <= k; i++){
			dp[i] = 1;
			for(int j = 1; j < i; j++){
				if(arr[i] <= arr[j] && dp[j] + 1 > dp[i]){
					dp[i] = dp[j] + 1;
				}
//				printf("j=%d, i= %d, arr[j]=%d, arr[i]=%d,  ", j, i, arr[j], arr[i]);
//				for(int i = 1; i <= k; i++){
//					printf("%d ", dp[i]);
//				}
//				printf("\n");
			}
			MAX = max(MAX, dp[i]);
		}
		printf("%d\n", MAX);
	}
	return 0;
}

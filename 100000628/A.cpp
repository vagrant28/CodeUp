#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn = 110;

char a[maxn], b[maxn];
int dp[maxn][maxn];


int main(){
	while(scanf("%s%s", a + 1, b + 1) != EOF){
		int lenA = strlen(a + 1);
		int lenB = strlen(b + 1);
		fill(dp[0], dp[0] + maxn * maxn, 0);
		for(int i = 1; i <= lenA; i++){
			for(int j = 1; j <= lenB; j++){
				if(a[i] == b[j]){
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		printf("%d\n", dp[lenA][lenB]);
	}	
	return 0;
}

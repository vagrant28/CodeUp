#include <stdio.h>
#include <string.h>
const int maxn = 65;
int res[maxn][maxn];

float fact(int m, int n){
	if(m == n || n == 0){
		return res[m][n] = 1;
	} 
	if(res[m][n]){
		return res[m][n];
	}
	else{
		return res[m][n] = fact(m - 1, n - 1) + fact(m - 1, n);
	}
}

int main(){
	int m, n;
	memset(res, 0, sizeof(res));
	while(scanf("%d%d", &m, &n) != EOF){
		int ans = (int)fact(m, n);
		printf("%d\n", ans);
	}
	return 0;
} 

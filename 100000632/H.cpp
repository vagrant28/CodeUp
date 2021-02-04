#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 50;
const int maxq = 2010 * 100;

int dp[maxq], check[maxn]; 
double q;
int n, m, num, Q;

int main(){
	while(scanf("%lf%d", &q, &n) != EOF && n != 0){
		Q = (int)(q * 100);
		num = 0;
		while(n--){	
			scanf("%d", &m);
			double p;
			bool flag = true;
			char type;
			int sum = 0, price;
			getchar();
			while(m--){
				scanf("%c:%lf%*c", &type, &p);
				price = (int)(p * 100);
				if((type == 'A' || type == 'B' || type == 'C') && price <= 60000){
					sum += price;
				}
				else{
					flag = false;
				}
			}
			if(flag && sum <= 100000){
				check[++num] = sum;
			}
		}
		fill(dp, dp + maxq, 0);
		for(int i = 1; i <= num; i++){
			for(int j = Q; j >= check[i]; j--){
				dp[j] = max(dp[j], dp[j - check[i]] + check[i]);
			}
		}
		printf("%.2f\n", (double)dp[Q] / 100.0);
	}
	return 0;
}





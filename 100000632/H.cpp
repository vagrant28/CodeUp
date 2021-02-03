#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 40;
const int maxq = 200000 + 10;

double check[maxn];
int dp[maxq]; 
double q;
int n, m, num;

int main(){
	while(scanf("%lf%d",  &q, &n), n){
		num = 0;
		while(n--){	
			scanf("%d", &m);
			double sum = 0, p;
			bool flag = true;
			char type;
			while(m--){
				scanf(" %c:%lf", &type, &p);
				if((type == 'A' || type == 'B' || type == 'C') && p <= 600){
					sum += p;
				}
				else{
					flag = false;
					break;
				}
			}
			if(flag){
				check[++num] = sum;
			}
		}
//		printf("check[]: ");
//		for(int i = 1; i <= num; i++){
//			printf("%f ", check[i]);
//		}
//		printf("\n");
		fill(dp, dp + maxq, 0);
		for(int i = 1; i <= num; i++){
			for(int j = (int)(q * 100); j >= (int)(check[i] * 100); j--){
				dp[j] = max(dp[j], dp[j - (int)(check[i] * 100)] + (int)(check[i] * 100));
			}
		}
		printf("%.2f\n", (double)(dp[(int)(q * 100)] / 100.0));
	}
	return 0;
}


// 用dfs大概是爆栈了吧 
//#include <stdio.h>
//#include <algorithm>
//using namespace std;
//const int maxn = 40;
//const int maxq = 2010;
//
//double check[maxn]; 
//double q, ans;
//int n, m, num;
//
//void dfs(int id, double sum){
//	if(id > num){
//		return;
//	}
//	if(sum + check[id] <= q){
//		ans = max(ans, sum + check[id]);
//		dfs(id + 1, sum + check[id]);
//	}
//	dfs(id + 1, sum);
//}
//
//int main(){
//	while(scanf("%lf%d",  &q, &n), n){
//		num = 0;
//		while(n--){	
//			scanf("%d", &m);
//			double sum = 0, p;
//			bool flag = true;
//			char type;
//			while(m--){
//				scanf(" %c:%lf", &type, &p);
//				if((type == 'A' || type == 'B' || type == 'C') && p <= 600){
//					sum += p;
//				}
//				else{
//					flag = false;
//					break;
//				}
//			}
//			if(flag){
//				check[++num] = sum;
//			}
//		}
////		printf("check[]: ");
////		for(int i = 1; i <= num; i++){
////			printf("%f ", check[i]);
////		}
////		printf("\n");
//		ans = -1;
//		dfs(1, 0);
//		printf("%.2f\n", ans);
//	}
//	return 0;
//}



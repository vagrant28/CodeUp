#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 50;

double check[maxn]; 
double q, ans;
int n, m, num;

void dfs(int id, double sum){
	if(id == num){
		return;
	}
	if(sum + check[id] <= q){
		ans = max(ans, sum + check[id]);
		dfs(id + 1, sum + check[id]);
	}
	dfs(id + 1, sum);
}

int main(){
	while(scanf("%lf%d", &q, &n) != EOF && n != 0){
//		printf("n=%d\n", n);
		num = 0;
		while(n--){	
//			printf("# n=%d\n", n);
			scanf("%d", &m);
			double sum = 0, p;
			char type;
			bool flag = true;
			getchar();
			while(m--){
				scanf("%c:%lf%*c", &type, &p);
				if((type == 'A' || type == 'B' || type == 'C') && p <= 600){
					sum += p;
				}
				else{
					flag = false;
				}
			}
			if(flag && sum <= 1000){
				check[num++] = sum;
			}
		}
		ans = 0;
		dfs(0, 0);
		printf("%.2f\n", ans);
	}
	return 0;
}

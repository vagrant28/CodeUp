#include <stdio.h>
typedef long long LL;

// 包括num在内全部都要用long long 
int main(){
	LL m;
	LL a, b;
	while(scanf("%d", &m) != EOF){
		if(m == 0){
			break;
		}
		scanf("%lld%lld", &a, &b);
		LL tmp = a + b;
		LL ans[40];
		LL num = 0;
		do{
			ans[num++] = tmp % m;
			tmp = tmp / m;
		}while(tmp != 0);
		for(LL i = num - 1; i >= 0; i--){
			printf("%lld", ans[i]);
		}
		putchar('\n');
	}
	return 0;
}

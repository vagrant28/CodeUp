#include <stdio.h>
typedef long long LL;

int main(){
	int n;
	scanf("%d", &n);
	if(n == 1 || n == 2){
		printf("%d\n", 1);
	}
	else{
		int i = 3;
		LL res;
		LL a =1, b = 1;
		while(i <= n){
			res = a + b;
			a = b;
			b = res;
			i++;
		}
		printf("%lld\n", res);
	}
	return 0;
}
#include <stdio.h>
typedef long long LL;
const int maxn = 1010;
LL a[maxn];

LL gcd(LL a, LL b){
	if(b == 0){
		return a;
	}
	else{
		return gcd(b, a % b);
	}
}

LL lcm(LL a, LL b){
	return a / gcd(a, b) * b;
}

int main(){
	int n;
	scanf("%d", &n);
	while(n--){
		int m;
		scanf("%d", &m);
		for(int i = 0; i < m; i++){
			scanf("%lld", &a[i]);
		}
		LL ans = a[0];
		for(int i = 1; i < m; i++){
			ans = lcm(ans, a[i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}

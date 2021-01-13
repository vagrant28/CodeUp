#include <stdio.h>

int main(){
	int m;
	int a[15];
	scanf("%d", &m);
	while(m--){
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n + 1; i++){
			scanf("%d", &a[i]);
		}
		int x;
		scanf("%d", &x);
		int ans = 0, product = 1;
		for(int i = 0; i < n + 1; i++){
			ans += a[i] * product;
			product *= x;
		}
		printf("%d\n", ans);
	}
	return 0;
}

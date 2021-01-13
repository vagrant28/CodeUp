#include <stdio.h>

int main(){
	int N, m;
	scanf("%d", &m);
	while(m--){
		scanf("%d", &N);
		int ans;
		if(N == 0){
			ans = 0;
		}
		else if(N > 0){
			ans = (N + 2 * N) * (N + 1) / 2;
		}
		else{
			ans = (2 * N + N) * (1 - N) / 2;
		}
		printf("%d\n", ans);
	}
	return 0;
}

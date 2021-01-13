#include <stdio.h>

int main(){
	int N;
	while(scanf("%d", &N), N){
		double ans = 0;
		for(int i = 1; i <= N; i++){
			ans += 1.0 / i * (N - i + 1);
		}
		ans *= 2;
		ans -= N;
		printf("%.2f\n", ans);
	}
	return 0;
}

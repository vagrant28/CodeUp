#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
	int N;
	int a[10005];
	while(scanf("%d", &N), N){
		for(int i = 0; i < N; i++){
			scanf("%d", &a[i]);
		}
		sort(a, a + N);
		int ans;
		if(N % 2 == 1){
			ans = a[N / 2];
		}
		else{
			ans = (a[N / 2] + a[N / 2 - 1]) / 2;
		}
		printf("%d\n", ans);
	}
	return 0;
}

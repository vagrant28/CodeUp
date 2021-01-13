#include <stdio.h>

int main(){
	int N, x;
	int a[1005];
	while(scanf("%d", &N), N){
		int num = 0;
		for(int i = 0; i < N; i++){
			scanf("%d", &a[i]);
		}
		scanf("%d", &x);
		for(int i = 0; i < N; i++){
			if(a[i] == x){
				num++;
			}
		}
		printf("%d\n", num);
	}
	return 0;
}

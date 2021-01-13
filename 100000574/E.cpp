#include <stdio.h>

int main(){
	int N, M;
	scanf("%d", &N);
	while(N--){
		scanf("%d", &M);
		int sum = 0, tmp;
		while(M--){
			scanf("%d", &tmp);
			sum += tmp;
		}
		printf("%d\n", sum);
	}
	return 0;
} 

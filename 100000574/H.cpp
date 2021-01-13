#include <stdio.h>

int main(){
	int N, M;
	scanf("%d", &N);
	while(N--){
		int sum = 0, tmp;
		scanf("%d", &M);
		while(M--){
			scanf("%d", &tmp);
			sum += tmp;
		}
		printf("%d\n\n", sum);
	}
	return 0;
}

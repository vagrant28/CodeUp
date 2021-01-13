#include <stdio.h>

int main(){
	int n;
	while(scanf("%d", &n), n){
		int sum = 0;
		int tmp;
		while(n--){
			scanf("%d", &tmp);
			sum += tmp;
		}
		printf("%d\n", sum);
	}
	return 0;
}

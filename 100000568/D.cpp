#include <stdio.h>

int main(){
	int n, sum = 0, i = 1;
	scanf("%d", &n);
	while(1){
		if(i > n){
			break;
		}
		sum += i;
		i++;
	}
	printf("%d\n", sum);
	return 0;
}
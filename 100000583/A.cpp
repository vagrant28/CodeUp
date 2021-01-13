#include <stdio.h>
int count;

void P(int n){
	if(n == 0){
		count++;
		return;
	}
	if(n == 1){
		P(n - 1);
	}
	else{
		P(n - 1);
		P(n - 2);
	}
}

int main(){
	int N;
	while(scanf("%d", &N) != EOF){
		count = 0;
		P(N);
		printf("%d\n", count);
	}
	return 0;
}

#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
	int N;
	char strN[5];
	while(scanf("%s", strN) != EOF){
//		printf("strN = %s\n", strN);
		sscanf(strN, "%d", &N);
//		printf("N = %d\n", N);
		int sqN = N * N;
		int len = strlen(strN);
		int M = pow(10, len);
		int low = sqN % M;
		if(low == N){
			puts("Yes!");
		}else{
			puts("No!");
		}
	}
	return 0;
}

#include <stdio.h>
#include <math.h>
#include <string.h>
const int maxn = 1e6 + 10;

int prime[maxn], pNum;
bool flag[maxn];

void findPrime(){
	pNum = 0;
	
}

int main(){
	int N;
	while(scanf("%d", &N) != EOF){
		int cnt = 0;
		while(1){
			int h = (int)sqrt(1.0 * N);
			int flag = 0; 
			for(int i = 2; i <= h; i++){
				if(N % i == 0){
					cnt++;
					N /= i;
					flag = 1;
					break;
				}
			}
			if(!flag){
				cnt++;
				break;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}

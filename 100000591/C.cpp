#include <stdio.h>
#include <string.h>
const int maxNum = 1e6 + 10;
const int maxn = 2 << 15;

int prime[maxNum], num;
bool flag[maxNum];

void findPrime(){
	num = 0;
	memset(prime, 0, sizeof(prime));
	memset(flag, 0, sizeof(flag));
	for(int i = 2; i <= maxn / 2; i++){
		if(!flag[i]){
			prime[num++] = i;
			for(int j = i + i; j <= maxn / 2; j += i){
				flag[j] = true;
			}
		}
	}
}

int main(){
	findPrime();
//	printf("%d %d\n", num, prime[num - 1]);
	int n;
	while(scanf("%d", &n), n){
		int cnt = 0;
		for(int i = 0; i < num && prime[i] <= n / 2; i++){
			if(flag[n - prime[i]] == false){
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}

#include <stdio.h>
#include <string.h>
const int maxn = 1e6 + 10;

int prime[maxn], num;
bool flag[maxn];

void findPrime(){
	num = 0;
	memset(prime, 0, sizeof(prime));
	memset(flag, 0, sizeof(flag));
	for(int i = 2; i < maxn; i++){
		if(!flag[i]){
			prime[num++] = i;
			if(num == 10000){
				break;
			}
			for(int j = i + i; j < maxn; j += i){
				flag[j] = true;
			}
		}
	}
}

int main(){
	findPrime();
	int k;
	while(scanf("%d", &k) != EOF){
		printf("%d\n", prime[k - 1]);
	}
	return 0;
} 

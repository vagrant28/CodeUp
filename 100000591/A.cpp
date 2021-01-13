#include <stdio.h>
#include <string.h>
const int maxn = 1e4 + 10;

int prime[maxn], num;
bool flag[maxn];

void findPrime(){
	num = 0;
	memset(prime, 0, sizeof(prime));
	memset(flag, 0, sizeof(flag));
	for(int i = 2; i < maxn; i++){
		if(!flag[i]){
			prime[num++] = i;
			for(int j = i + i; j < maxn; j += i){
				flag[j] = true;
			}
		}
	}
}

int main(){
	findPrime();
	int n;
	while(scanf("%d", &n) != EOF){
		int f = 0;
		for(int i = 0; i < num && prime[i] < n; i++){
			if(prime[i] % 10 == 1){
				if(f){
					printf(" ");
				}
				printf("%d", prime[i]);
				f = 1;
			}
		}
		if(f){
			printf("\n");
		}
		else{
			printf("-1\n");
		}
	}
}

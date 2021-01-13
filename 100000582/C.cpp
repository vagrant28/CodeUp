#include <stdio.h>
const int maxn = 1e5 + 10;

int main(){
	int N;
	while(scanf("%d", &N) != EOF){
		int hashTable[maxn] = {0};
		int a[maxn];
		for(int i = 0; i < N; i++){
			scanf("%d", &a[i]);
			hashTable[a[i]]++;
		}
		int flag = 1;
		for(int i = 0; i < N; i++){
			if(hashTable[a[i]] == 1){
				printf("%d\n", a[i]);
				flag = 0;
				break;
			}
		}
		if(flag){
			printf("None\n");
		}
	}
	return 0;
}

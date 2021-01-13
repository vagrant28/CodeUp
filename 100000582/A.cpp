#include <stdio.h>
#include <string.h>

int main(){
	int N, M;
	while(scanf("%d%d", &N, &M) != EOF){
		int hashTable[3000];
		memset(hashTable, 0, sizeof(hashTable));
		int p[3000];
		for(int i = 0; i < N; i++){
			scanf("%d", &p[i]);
			hashTable[p[i]]++;
		}
		for(int i = 0; i < N; i++){
			if(hashTable[p[i]] - 1 == 0){
				printf("BeiJu\n");
			}
			else{
				printf("%d\n", hashTable[p[i]] - 1);
			}
		}
	}
	return 0;
} 

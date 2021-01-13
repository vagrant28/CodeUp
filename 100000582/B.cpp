#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
const int maxn = 2010;
int hashTable[200][maxn];

int main(){
	int m, n;
	scanf("%d", &m);
	while(m--){
		int a[200];
		memset(hashTable, 0, sizeof(hashTable));
		scanf("%d", &n);
		int t;
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
			hashTable[0][a[i]] = 1;	// 该列需要输出 
		}
		for(int i = 0; i < n; i++){
			scanf("%d", &t);
			hashTable[t][0] = 1;
			hashTable[t][a[i]]++;
		}
		for(int i = 1; i <= 100; i++){
			if(hashTable[i][0])
			{
				printf("%d={", i);
				int flag = 0;
				for(int j = 0; j < maxn; j++){
					if(hashTable[0][j]){
						if(flag){
							printf(",");
						}
						else{
							flag = 1;
						}
						printf("%d=%d", j, hashTable[i][j]);
					}
				}
				printf("}\n");
			}
		}
	}
	return 0;
}

//1
//7
//3 2 3 8 8 2 3
//1 2 3 2 1 3 1

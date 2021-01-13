#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
const int maxn = 26 * 26 * 26 * 10 + 10; 

vector<int> hashTable[maxn];

int StoI(char* a){
	int ans = 0;
	for(int i = 0; i < 3; i++){
		ans = ans * 26 + (a[i] - 'A');
	}
	ans = ans * 10 + (a[3] - '0');
//	printf("%d\n", ans);
	return ans;
}

int main(){
	int N, K, hashName;
	char tmpName[5]; 
	while(scanf("%d%d", &N, &K) != EOF){
		while(K--){
			int i, ni;
			scanf("%d%d", &i, &ni);
			while(ni--){
				scanf("%s", tmpName);
				hashName = StoI(tmpName);
				hashTable[hashName].push_back(i);
			}
		}
		while(N--){
			scanf("%s", tmpName);
			hashName = StoI(tmpName);
			if(hashTable[hashName].size() == 0){
				printf("%s 0\n", tmpName);
			}	
			else{
				sort(hashTable[hashName].begin(), hashTable[hashName].end());
				printf("%s %d", tmpName, hashTable[hashName].size());
				for(int j = 0; j < hashTable[hashName].size(); j++){
					printf(" %d", hashTable[hashName][j]);
				}
				putchar('\n');
			}
		}
	}
	return 0;
}

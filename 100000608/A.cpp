#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

int n;
vector<int> v;
bool hashTable[15];

void dfs(int index){
	if(index == n){
		for(int i = 0; i < index; i++){
			if(i == index - 1){
				printf("%d\n", v[i]);
			}
			else{
				printf("%d ", v[i]);
			}
		}
		return;
	}
	for(int i = 1; i <= n; i++){
		if(!hashTable[i]){
			v.push_back(i);
			hashTable[i] = true;
			dfs(index + 1);
			hashTable[i] = false;
			v.pop_back();
		}
	}
}

int main(){
	while(scanf("%d", &n) != EOF){
		memset(hashTable, 0, sizeof(hashTable));
		dfs(0);
	}
	return 0;
}

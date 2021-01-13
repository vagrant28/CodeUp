#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
const int maxK = 2500 + 10; 

bool cmp(char* a, char* b){
	return strcmp(a, b) < 0;
}

int main(){
	int N, K;
	while(scanf("%d%d", &N, &K) != EOF){
		vector<char*> course[maxK];
		while(N--){
			char* tmpName = (char*)malloc(sizeof(char) * 5);
			int C;
			scanf("%s%d", tmpName, &C);
			while(C--){
				int id;
				scanf("%d", &id);
				course[id].push_back(tmpName);
			}
		}
		for(int i = 0; i < maxK; i++){
			int t = course[i].size();
			if(t != 0){
				sort(course[i].begin(), course[i].end(), cmp);
				printf("%d %d\n", i, t);
				for(int j = 0; j < t; j++){
					puts(course[i][j]);
				}
			}
		}
	}
	return 0;
}

#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <string.h>
using namespace std;
const int MAXV = 60;

vector<int> G[MAXV];
int n, m, inDegree[MAXV];


bool topoSort(){
	stack<int> s;
	int count, k, i;
	for(int i = 0; i < n; i++){
		if(inDegree[i] == 0){
			s.push(i);
		}
	}
	count = 0;
	while(!s.empty()){
		int u = s.top();
		s.pop();
		printf("%d ", u);
		count++;
		for(int i = 0; i < G[u].size(); i++){
			int v = G[u][i];
			inDegree[v]--;
			if(inDegree[v] == 0){
				s.push(v);
			}
		}
	}
	if(count < n){
		return false;
	}
	else{
		return true;
	}
}

int main(){
	while(scanf("%d", &n) != EOF){
		memset(inDegree, 0, sizeof(int));
		int flag;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				scanf("%d", &flag);
				if(flag == 1){
					G[i].push_back(j);
					inDegree[j]++;
				}
			}
		}
		bool flag_sort = topoSort();
		if(flag_sort == true){
			printf("\n");
		}
		else{
			printf("ERROR\n");
		}
	}
	return 0;
}

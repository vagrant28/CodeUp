#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXV = 110;

int n, m, inDegree[MAXV];
vector<int> G[MAXV];

void topoSort(){
	int num = 0;
	queue<int> q;
	for(int i = 0; i < n; i++){
		if(inDegree[i] == 0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int u = q.front();
		q.pop();
		num++;
		for(int i = 0; i < G[u].size(); i++){
			int v = G[u][i];
			inDegree[v]--;
			if(inDegree[v] == 0){
				q.push(v);
			}
		}
	}
	if(num == n){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return;
}


int main(){
	while(scanf("%d%d", &n, &m), n){
		fill(inDegree, inDegree + MAXV, 0);
		for(int i = 0; i < n; i++){
			G[i].clear();
		}
		int u, v;
		for(int i = 0; i < m; i++){
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			inDegree[v]++;
		}
		topoSort();
	}
	return 0;
}

#include <stdio.h>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
const int MAXV = 510;

vector<int> G[MAXV];
int n, m, inDegree[MAXV];

bool topoSort(){
	int num = 0;
	bool flag = false;
	priority_queue<int, vector<int>, greater<int> > q;
//	queue<int> q;
	for(int i = 1; i <= n; i++){
		if(inDegree[i] == 0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int u = q.top();
		if(flag == true){
			printf(" ");
		}
		printf("%d", u);
		flag = true;
		q.pop();
		for(int i = 0; i < G[u].size(); i++){
			int v = G[u][i];
			inDegree[v]--;
			if(inDegree[v] == 0){
				q.push(v);
			}
		}
		G[u].clear();
		num++;
	}
	if(num == n){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	while(scanf("%d%d", &n, &m) != EOF){
		if(n == 0 && m == 0){
			break;
		}
		memset(inDegree, 0, sizeof(int));
		int u, v;
		for(int i = 0; i < m; i++){
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			inDegree[v]++;
		}
		topoSort();
		printf("\n");
	}
	return 0;
}

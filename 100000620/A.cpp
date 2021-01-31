#include <stdio.h>
#include <vector>
using namespace std;
const int maxn = 1e6+10; // 数组要开大些，不然会报运行错误 

vector<int> Adj[maxn];
bool vis[maxn] = {false};

void dfs(int s){
//	printf("hello\n");
	vis[s] = true;
	for(int i = 0; i < Adj[s].size(); i++){
		if(vis[Adj[s][i]] == false){
			dfs(Adj[s][i]);
		}
	}
}

int main(){
	int a, b;
	while(scanf("%d%d", &a, &b) != EOF){
		Adj[a].push_back(b);
		Adj[b].push_back(a);
	}
//	printf("hi\n");
	int num = 0;
	for(int i = 0; i < maxn; i++){
		if(vis[i] == false && Adj[i].size() > 0){
			dfs(i);
			num++;
		}
	}
	printf("%d\n", num);
	return 0;
}

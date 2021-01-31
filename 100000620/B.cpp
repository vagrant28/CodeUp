#include <stdio.h>
#include <string.h>
const int maxn = 1010;

int n, m;
int G[maxn][maxn];
bool vis[maxn];

void dfs(int u){
	vis[u] = true;
	for(int i = 1; i <= n; i++){
		if(G[u][i] == 1 && vis[i] == false){
			dfs(i);
		}
	}	
}

int main(){
	while(scanf("%d%d", &n, &m), n){
		memset(G, 0, sizeof(G));
		memset(vis, 0, sizeof(vis));
		int a, b;
		while(m--){
			scanf("%d%d", &a, &b);
			G[a][b] = G[b][a] = 1;
		}
		int num = 0;
		for(int i = 1; i <= n; i++){
			if(vis[i] == false){
				dfs(i);
				num++;
			}
		}
//		printf("num=%d\n", num);
		if(num == 1){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
} 

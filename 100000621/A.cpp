#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxv = 60;
const int INF = (1 << 30) - 1;

int n, s;
int G[maxv][maxv], d[maxv];
bool vis[maxv] = {false};

void Dijkstra(int s){
	fill(d, d + maxv, INF);
	d[s] = 0;
	fill(vis, vis + maxv, false);
	
	for(int i = 0; i < n; i++){
		int u = -1, MIN = INF;
		for(int j = 0; j < n; j++){
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		if(u == -1){
			return;
		}
		vis[u] = true;
		for(int v = 0; v < n; v++){
			if(vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v]){
				d[v] = d[u] + G[u][v];
			}
		}
	}
}

int main(){
	while(scanf("%d%d", &n, &s) != EOF){
		int t;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				scanf("%d", &t);
				if(t == 0){
					G[i][j] = INF;
				}	
				else{
					G[i][j] = t;
				}
			}
		}
		Dijkstra(s);
		for(int i = 0; i < n; i++){
			if(i != s){
				if(d[i] == INF){
					printf("-1 ");
				}
				else{
					printf("%d ", d[i]);
				}
			}
		}
		printf("\n");
	}
	return 0;
}

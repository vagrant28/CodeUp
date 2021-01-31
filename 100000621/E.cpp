#include <stdio.h>
#include <algorithm>
using namespace std;
const int MAXV = 1010;
const int INF = (1 << 30) - 1;

int n, m, s, t;
int G[MAXV][MAXV], cost[MAXV][MAXV];
int d[MAXV], c[MAXV];
bool vis[MAXV];

void Dijkstra(int s){
	fill(d, d + MAXV, INF);
	d[s] = 0;
	fill(c, c + MAXV, INF);
	c[s] = 0;
	fill(vis, vis + MAXV, false);
	
	for(int i = 0; i < n; i++){
		int u = -1, MIN = INF;
		for(int j = 1; j <= n; j++){
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		if(u == -1){
			return;
		}
		vis[u] = true;
		for(int v = 1; v <= n; v++){
			if(vis[v] == false && G[u][v] != INF){
				if(d[u] + G[u][v] < d[v]){
					d[v] = d[u] + G[u][v];
					c[v] = c[u] + cost[u][v];
				}
				else if(d[u] + G[u][v] == d[v] && c[u] + cost[u][v] < c[v]){
					c[v] = c[u] + cost[u][v];
				}
			}
		}
	}
}

int main(){
	while(scanf("%d%d", &n, &m) != EOF){
		if(n == 0 && m == 0){
			break;
		}
		fill(G[0], G[0] + MAXV * MAXV, INF);
		for(int i = 0; i < m; i++){
			int u, v, d, p;
			scanf("%d%d%d%d", &u, &v, &d, &p);
			G[u][v] = G[v][u] = d;
			cost[u][v] = cost[v][u] = p;
		}
		scanf("%d%d", &s, &t);
		Dijkstra(s);
		printf("%d %d\n", d[t], c[t]);
	}
	return 0;
}

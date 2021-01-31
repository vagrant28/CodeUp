#include <stdio.h>
#include <algorithm>
using namespace std;
const int MAXV = 1010;
const int INF = (1 << 30) - 1;

int n, m, s, t;
int G[MAXV][MAXV], d[MAXV], pre[MAXV];
bool vis[MAXV] = {false};

void print(){
	for(int i = 0; i <= n; i++)
		printf("%d ", d[i]);
	printf("\n");
}

void Dijkstra(int s){
	fill(d, d + MAXV, INF);
	fill(vis, vis + MAXV, false);
	d[s] = 0;
	for(int i = 1; i <= n; i++){
		pre[i] = i;
	}
	
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
//		printf("u=%d\n", u);
		vis[u] = true;
//		for(int i = 0; i <= n; i++){
//			printf("%d ", vis[i]);
//		}
//		printf("\n");
		
		for(int v = 1; v <= n; v++){
			if(vis[v] == false && G[u][v] != INF){
//				printf("## v=%d\n", v);
				if(d[u] + G[u][v] < d[v]){
					d[v] = d[u] + G[u][v];
					pre[v] = u;
				}
				else if(d[u] + G[u][v] == d[v]){
					if(u < pre[v]){
						pre[v] = u;
					}
				}
			}
		}
//		print();
	}
}

void DFS(int s, int v){
	if(s == v){
		printf("%d ", s);
		return;
	}
	DFS(s, pre[v]);
	printf("%d ", v);
}

int main(){
	while(scanf("%d%d%d%d", &n, &m, &s, &t) != EOF){
		int u, v, dis;
		fill(G[0], G[0] + MAXV * MAXV, INF);
		for(int i = 0; i < m; i++){
			scanf("%d%d%d", &u, &v, &dis);
			if(G[u][v] == INF){	// 这两个if是考虑到输入的边有重复的情况 
				G[u][v] = G[v][u] = dis;
			}
			else if(G[u][v] > dis){
				G[u][v] = G[v][u] = dis;
			}
		}
		Dijkstra(s);

		if(d[t] == INF){
			printf("can't arrive\n");
		}
		else{
			printf("%d\n", d[t]);
			DFS(s, t);
			printf("\n");
		}
	}
	return 0;
}

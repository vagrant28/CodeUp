#include <stdio.h>
#include <algorithm>
using namespace std;
const int MAXV = 110;
const int INF = (1 << 30) - 1;
int N;
int G[MAXV][MAXV];
int d[MAXV];
bool vis[MAXV];

int prim(int s){
	int ans = 0;
	fill(d, d + MAXV, INF);
	fill(vis, vis + MAXV, false);
	d[s] = 0;
	
	for(int i = 0; i < N; i++){
		int u = -1, MIN = INF;
		for(int j = 1; j <= N; j++){
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		if(u == -1){
			return -1;
		}
		vis[u] = true;
		ans += d[u];
		int v;
		for(v = 1; v <= N; v++){
			if(vis[v] == 0 && G[u][v] < d[v]){
				d[v] = G[u][v];
			}
		}
	}
	return ans;
}

int main(){
	while(scanf("%d", &N), N){
		int h = N * (N - 1) / 2;
		int u, v, dis;
		for(int i = 0; i < h; i++){
			scanf("%d%d%d", &u, &v, &dis);
			G[u][v] = G[v][u] = dis;
		}
		printf("%d\n", prim(1));
	}
	return 0;
}

#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXV = 110;
const int INF = (1 << 30) - 1;

int N, M;
int pre[MAXV];
LL G[MAXV][MAXV], d[MAXV];
bool vis[MAXV] = {false};

LL quickPow(LL a, LL b, LL m){
	if(b == 0){
		return 1;
	}
	if(b % 2 == 1){
		return a * quickPow(a, b - 1, m) % m;
	}
	else{
		LL mul = quickPow(a, b / 2, m);
		return mul * mul % m;
	}
}

void print(){
	printf("d[]: ");
	for(int i = 0; i < N; i++){
		printf("%d ", d[i]);
	}
	printf("\n");
	printf("pre[]: ");
	for(int i = 0; i < N; i++){
		printf("%d ", pre[i]);
	}
	printf("\n");
}

void Dijkstra(int s){
	fill(d, d + MAXV, INF);
	d[s] = 0;
	fill(vis, vis + MAXV, false);
	for(int i = 0; i < N; i++){
		pre[i] = i;
	}
	
	for(int i = 0; i < N; i++){
		int u = -1;
		LL MIN = INF;
		for(int j = 0; j < N; j++){
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
//		print();
		for(int v = 0; v < N; v++){
			if(vis[v] == false && G[u][v] != INF && d[u] < d[v] && G[u][v] < d[v]){
//				printf("v=%d\n", v);
				d[v] = G[u][v];
				pre[v] = u;
			}
		}
	}
}

void DFS(int s, int v, LL &sum){
	if(s == v){
		return;
	}
	sum = (sum + quickPow(2, d[v], 100000)) % 100000; // 重要！！相加后还需要模一次确保不超过100000 
	DFS(s, pre[v], sum);
}

int main(){
	while(scanf("%d%d", &N, &M) != EOF){
		int u, v;
		fill(G[0], G[0] + MAXV * MAXV, INF);
		for(LL i = 0; i < M; i++){
			scanf("%d%d", &u, &v);
			G[u][v] = G[v][u] = i;
		}
		int st = 0;
		Dijkstra(st);
		for(int i = 1; i < N; i++){
			if(d[i] == INF){
				printf("-1\n");
			}
			else{
				LL sum = 0;
				DFS(0, i, sum);
				printf("%d\n", sum);
			}
		}
	}	
	return 0;
}

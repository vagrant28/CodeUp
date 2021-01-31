#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 60;
const int INF = (1 << 30) - 1;

int n;
int G[maxn][maxn];

int main(){
	while(scanf("%d", &n) != EOF){
		int t;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				scanf("%d", &t);
				if(t == 0){
					if(i == j)
						G[i][j] = 0;
					else
						G[i][j] = INF;
				}	
				else{
					G[i][j] = t;
				}
			}
		}
		for(int k = 0; k < n; k++){
			for(int u = 0; u < n; u++){
				for(int v = 0; v < n; v++){
					if(G[u][k] != INF && G[k][v] != INF && G[u][k] + G[k][v] < G[u][v]){
						G[u][v] = G[u][k] + G[k][v];
					}
				}
			}
		}
		for(int u = 0; u < n; u++){
			for(int v = 0; v < n; v++){
				if(G[u][v] == INF){
					printf("-1 ");
				} 
				else{
					printf("%d ", G[u][v]);
				}
			}
			printf("\n");
		}
	}
	return 0;
}

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXV = 110;
const int MAXE = 110;

struct edge{
	int u, v, dist;
}E[MAXE];

int father[MAXV];

bool cmp(edge a, edge b){
	return a.dist < b.dist;
}

int findFather(int x){
	int root = x;
	while(root != father[root]){
		root = father[root];
	}
	while(x != father[x]){
		int t = x;
		x = father[x];
		father[t] = root;
	}
	return root;
}

int kruskal(int n, int m){
	int ans = 0, num_edge = 0;
	for(int i = 1; i <= n; i++){
		father[i] = i;
	}
	sort(E, E + m, cmp);
	for(int i = 0; i < m; i++){
		int faU = findFather(E[i].u);
		int faV = findFather(E[i].v);
		if(faU != faV){
			father[faU] = faV;
			ans += E[i].dist;
			num_edge++;
			if(num_edge == n - 1){
				break;
			}
		}
	}
	if(num_edge != n - 1){
		return -1;
	}
	else{
		return ans;
	}
}

int main(){
	int n, m;	// n: number of vertex; m:number of edge
	while(scanf("%d%d", &m, &n) != EOF){
		if(m == 0){
			break;
		}
		for(int i = 0; i < m; i++){
			scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].dist);
		}
		int ans = kruskal(n, m);
		if(ans == -1){
			printf("?\n");
		}
		else{
			printf("%d\n", ans);
		}
	} 
	return 0;
} 

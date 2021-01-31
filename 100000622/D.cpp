#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXV = 110;
const int MAXE = 5010;
const int INF = (1 << 30) - 1;

struct edge{
	int u, v, dist, flag;
	edge(){}
	edge(int _u, int _v, int _dist, int _flag): u(_u), v(_v), dist(_dist), flag(_flag){}
}E[MAXE];

int n, h;
int father[MAXV];

bool cmp(edge a, edge b){
	if(a.flag == b.flag){
		return a.dist < b.dist;
	}
	else{
		return a.flag > b.flag;
	}
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
			if(E[i].flag == 0){
				ans += E[i].dist;
			}
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
//		printf("ans=%d\n", ans);
		return ans;
	}
}

int main(){
	while(scanf("%d", &n), n){
		h = n * (n - 1) / 2;
		int u, v, dis, flag;
		for(int i = 0; i < h; i++){
			scanf("%d%d%d%d", &u, &v, &dis, &flag);
			E[i] = edge(u, v, dis, flag);
		}
		int ans = kruskal(n, h);
		printf("%d\n", ans);
	}
	return 0;
}

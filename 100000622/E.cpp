#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXV = 30;
const int MAXE = 100;

struct edge{
	int u, v, dist;
	edge(){}
	edge(int _u, int _v, int _dist): u(_u), v(_v), dist(_dist){}
}E[MAXE];


int n;
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
	for(int i = 0; i < n; i++){
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
	while(scanf("%d", &n), n){
		char ch_u, ch_v;
		int k, dist;
		int m = 0;
		for(int i = 0; i < n - 1; i++){
			getchar();
			ch_u = getchar();
			int k;
			scanf("%d", &k);
			for(int j = 0; j < k; j++){
				getchar();
				ch_v = getchar();
				scanf("%d", &dist);
				E[m++] = edge(ch_u - 'A', ch_v - 'A', dist);
			}
		}
//		for(int i = 0; i < m; i++){
//			printf("i=%d, u=%c, v=%c, dist=%d\n", i, E[i].u + 'A', E[i].v + 'A', E[i].dist);
//		}
		int ans = kruskal(n, m);
		printf("%d\n", ans);
	}
	return 0;
}

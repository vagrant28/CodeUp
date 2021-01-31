#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
const int MAXV = 1010;
const double INF = (1 << 30) - 1.0;

struct node{
	double x, y;
	node(){}
	node(double _x, double _y): x(_x), y(_y){}
};

int n;
node nodeArr[MAXV];
double G[MAXV][MAXV], d[MAXV];
bool vis[MAXV] = {false};

double calDist(node a, node b){
	double diff_x = a.x - b.x;
	double diff_y = a.y - b.y;
	return (double)sqrt(diff_x * diff_x + diff_y * diff_y);
}

double prim(int s){
	double ans = 0;
	fill(d, d + MAXV, INF);
	d[s] = 0;
	fill(vis, vis + MAXV, false);
	
	for(int i = 0; i < n; i++){
		int u = -1, MIN = INF;
		for(int j = 0; j < n; j++){
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
		for(int v = 0; v < n; v++){
			if(vis[v] == false && G[u][v] < d[v]){
				d[v] = G[u][v];
			}
		}
	}
	return ans;
}

int main(){
	while(scanf("%d", &n), n){
		double u, v;
		for(int i = 0; i < n; i++){
			scanf("%lf%lf", &u, &v);
			nodeArr[i] = node(u, v);
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < i; j++){
				double t = calDist(nodeArr[i], nodeArr[j]);
				G[i][j] = G[j][i] = t;
			}
			G[i][i] = 0;
		}
		int s = 0;
		double ans = prim(s);
//		printf("%f\n", ans);
		printf("%.2lf\n", ans - 0.001);
	}
	return 0;
}

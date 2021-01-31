#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string.h>
using namespace std;
const int MAXV = 30;


struct node{
	int v, w;
	node(){}
	node(int _v, int _w): v(_v), w(_w){}
};

int n, x, y;
int inDegree[MAXV], ve[MAXV], vl[MAXV];
vector<node> G[MAXV];
char nodeArr[MAXV];
stack<int> topOrder;

int change(int x){
	return nodeArr[x] - 'a';
}


bool topSort(){
	queue<int> q;
	for(int i = 0; i < x; i++){
		int u = change(i);
		if(inDegree[u] == 0){
			q.push(u);
		}
	}
	while(!q.empty()){
		int u = q.front();
		q.pop();
		topOrder.push(u);
		for(int i = 0; i < G[u].size(); i++){
			int v = G[u][i].v;
			inDegree[v]--;
			if(inDegree[v] == 0){
				q.push(v);
			}
			if(ve[u] + G[u][i].w > ve[v]){
				ve[v] = ve[u] + G[u][i].w;
			}
		}
	}
	if(topOrder.size() == x){
		return true;
	}
	else{
		return false;
	}
}


int criticalPath(){
//	printf("enter\n");
	fill(ve, ve + MAXV, 0);
	if(topSort() == false){
		return -1;
	}
//	printf("topSortSuccess!\n");
	fill(vl, vl + MAXV, ve[x - 1]);
//	printf("maxLen=%d, topOrder.size=%d\n", ve[x - 1], topOrder.size());
	while(!topOrder.empty()){
		int u = topOrder.top();
		topOrder.pop();
		for(int i = 0; i < G[u].size(); i++){
			int v = G[u][i].v;
			if(vl[v] - G[u][i].w < vl[u]){
				vl[u] = vl[v] - G[u][i].w;
			}
		}
	}
//	printf("ve[]: ");
//	for(int i = 0; i < x; i++){
//		printf("%d ", ve[change(i)]);
//	}
//	printf("\n");
//	printf("vl[]: ");
//	for(int i = 0; i < x; i++){
//		printf("%d ", vl[change(i)]);
//	}
//	printf("\n");
//	printf("G[]:\n");
//	for(int i = 0; i < x; i++){
//		int u = change(i);
//		for(int j = 0; j < G[u].size(); j++){
//			printf("%c %c %d\n", u + 'a', G[u][j].v + 'a', G[u][j].w);
//		}
//	}
//	printf("\n");
	vector<int> path[MAXV];
	for(int i = 0; i < x; i++){
		int u = change(i);
		for(int j = 0; j < G[u].size(); j++){
			int v = G[u][j].v, w = G[u][j].w;
			int e = ve[u], l = vl[v] - w;
			if(e == l){
//				printf("(%c,%c) ", u + 'a', v + 'a');
				path[u].push_back(v);
			}
		}
	}
	int s;
	for(int i = 0; i < x; i++){
		int u = change(i);
		if(ve[u] == 0){
			s = u;
			break;
		}
	}
	while(path[s].size()){
		printf("(%c,%c) ", s + 'a', path[s][0] + 'a');
		s = path[s][0];
	}
	printf("%d\n", ve[x - 1]);
	return ve[x - 1];
}


int main(){
	scanf("%d", &n);
	while(n--){
		scanf("%d%d", &x, &y);
		scanf("%s", nodeArr);
//		printf("x=%d, y=%d, nodeArr=%s\n", x, y, nodeArr);
		char ch_u, ch_v;
		int len;
		
		fill(inDegree, inDegree + MAXV, 0);
		for(int i = 0; i < x; i++){
			G[change(i)].clear();
		}
		while(y--){
			getchar();
			scanf("%c %c %d", &ch_u, &ch_v, &len);
//			printf("## %c, %c, %d\n", ch_u, ch_v, len);
			int u = ch_u - 'a', v = ch_v - 'a';
			G[u].push_back(node(v, len));
			inDegree[v]++;
		}
		criticalPath();
	}
	return 0;
}

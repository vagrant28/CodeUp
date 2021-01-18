#include <stdio.h>
#include <string.h>
#include <utility>
#include <vector>
using namespace std;
const int maxL = 20;

int flag;
int m, n;
int startx, starty, endx, endy;
int a[maxL][maxL];
vector<pair<int, int> > ans;
int dir[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

void print(){
//	printf("%d\n", ans.size());
	int i;
	for(i = 0; i < ans.size() - 1; i++){
		printf("(%d,%d)->", ans[i].first, ans[i].second);
	}
	printf("(%d,%d)\n", ans[i].first, ans[i].second);
	return;
}


void dfs(int x, int y){
	ans.push_back(make_pair(x, y));
	if(x == endx && y == endy){
		print();
		flag = true;
		return;
	}
	int nx, ny;
	for(int i = 0; i < 4; i++){
		nx = x + dir[i][0];
		ny = y + dir[i][1];
		if(a[nx][ny]){
			a[nx][ny] = 0;
			dfs(nx, ny);
			a[nx][ny] = 1;
			ans.pop_back();
		}
	}
}

int main(){
	while(scanf("%d%d", &m, &n) != EOF){
		memset(a, 0, sizeof(a));
		ans.clear();
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= n; j++){
				scanf("%d", &a[i][j]);
			}
		}
		scanf("%d%d", &startx, &starty);
		scanf("%d%d", &endx, &endy);
		flag = false;
		a[startx][starty] = 0;
		dfs(startx, starty);
		if(!flag){
			printf("-1\n");
		}
	}
	return 0;
}

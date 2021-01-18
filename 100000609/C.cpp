#include <stdio.h>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;

struct node{
	int x, y;
	int maze[3][3];
	LL hashV;
	node(){}
	node(int _x, int _y, int _maze[3][3], LL _hashV){
		x = _x, y = _y;
		hashV = _hashV;
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				maze[i][j] = _maze[i][j];
			}
		}
	}
};

int a[3][3], b[3][3];
int sx, sy, cnt;
int X[5] = {-1, 1, 0, 0};
int Y[5] = {0, 0, 1, -1};
LL hA, hB;
queue<node> q;
map<LL, bool> mp;

LL HASH(int a[3][3]){
	LL h = 0;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			h = h * 10 + a[i][j];
		}
	}
	return h;
}

void input(){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			scanf("%d", &a[i][j]);
			if(a[i][j] == 0){
				sx = i, sy = j;
			}
		}
	}
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			scanf("%d", &b[i][j]);
		}
	}
	hA = HASH(a), hB = HASH(b);
	return;
}

bool judge(node N){
	if(N.x < 0 || N.y < 0 || N.x >= 3 || N.y >= 3){
		return false;
	}
	if(mp[N.hashV] == true){
		return false;
	}
	return true;
}

void bfs(){
	while(!q.empty()){
		q.pop();
	}
	mp.clear();
	cnt = 1;
	
	node cur = node(sx, sy, a, hA);
	q.push(cur);
	mp[hA] = true;
	
	while(!q.empty()){
		int num = q.size();
		cnt++;
		while(num--){
			cur = q.front();	
			q.pop();
			for(int i = 0; i < 4; i++){
				int nx = cur.x + X[i];
				int ny = cur.y + Y[i];
				node next = node(nx, ny, cur.maze, 0);
				swap(next.maze[nx][ny], next.maze[cur.x][cur.y]);
				next.hashV = HASH(next.maze);
				if(judge(next)){
					if(next.hashV == hB){
						printf("%d\n", cnt);
						return;
					}
					q.push(next);
					mp[next.hashV] = true;
				}
			}
				
		}
	}
	return;
}


void output(){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			printf("%d ", a[i][j]);
		}
		putchar('\n');
	}
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			printf("%d ", b[i][j]);
		}
		putchar('\n');
	}
	return;
}

int main(){
	input();
//	output();
	bfs();
	return 0;
}

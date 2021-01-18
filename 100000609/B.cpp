#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;

struct node{
	int x, y;
};

char maze[10][10];
int X[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int Y[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

bool judge(int x, int y){
	if(x < 0 || y < 0 || x >= 8 || y >= 8){
		return false;
	}
	else if(maze[x][y] == 'S'){
		return false;
	}
	else if(x >= 1 && maze[x - 1][y] == 'S'){
		return false;
	}
	return true;
}

void drop(){
	for(int i = 7; i >= 1; i--){
		strcpy(maze[i], maze[i - 1]);
	}
	strcpy(maze[0], "........");
	return;
}

bool bfs(){
	node cur;
	cur.x = 7, cur.y = 0;
	queue<node> q;
	q.push(cur);
	while(!q.empty()){
		int num = q.size();
		while(num--){
			cur = q.front();
			q.pop();
			for(int i = 0; i < 9; i++){
				node tmp;
				tmp.x = cur.x + X[i];
				tmp.y = cur.y + Y[i];
				if(judge(tmp.x, tmp.y)){
					if(tmp.x == 0 && tmp.y == 7){
						return true;
					}
					q.push(tmp);
				}
			}
		}
		drop();
	}
	return false;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int Case = 1; Case <= T; Case++){
		for(int i = 0; i < 8; i++){
			scanf("%s", maze[i]);
		}
		maze[7][0] = maze[0][7] = '.';
//		puts("======");
//		for(int i = 0; i < 8; i++){
//			printf("%s\n", maze[i]);
//		}
//		drop();
//		puts("======");
//		for(int i = 0; i < 8; i++){
//			printf("%s\n", maze[i]);
//		}
		int flag = bfs();
		if(flag){
			printf("Case #%d: Yes\n", Case);
		}
		else{
			printf("Case #%d: No\n", Case);
		}
	}
	
	return 0;
} 

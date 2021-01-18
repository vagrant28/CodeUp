#include <stdio.h>
#include <queue>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;

struct node{
	int m[2][4];
	int hashV;
	int op;
	node(){}
	node(int _m[2][4], int _hashV){
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 4; j++){
				m[i][j] = _m[i][j];
			}
		}
		hashV = _hashV;
		op = 0;
	}
};

int a[2][4] = {{1, 2, 3, 4}, {8, 7, 6, 5}};
int b[2][4];
int hA, hB, cnt;
queue<node> q;
map<int, int> mp;
map<int, node> HashToNode;
char op_name[4] = {' ', 'A', 'B', 'C'};

int HASH(int a[2][4]){
	int h = 0;
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 4; j++){
			h = h * 10 + a[i][j];
		}
	} 
	return h;
}

bool judge(node N){
	if(mp[N.hashV] != 0){
		return false;
	}
	return true;
}

void print(node N){
	puts("======");
	printf("op = %d\n", N.op);
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 4; j++){
			printf("%d ", N.m[i][j]);
		}
		putchar('\n');
	}
	return;
}

void output(int end){
	stack<char> ans;
	int p = end;
	while(p != -1){
		ans.push(op_name[HashToNode[p].op]);
		p = mp[p];
	}
//	printf("ans.size = %d\n", ans.size());
	ans.pop();	// µ¯³ö¿Õ¸ñ
	int i;
	while(!ans.empty()){
		i = 0;
		while(i < 60 && !ans.empty()){
			char c = ans.top();
			printf("%c", c);
			ans.pop();
			i++;
		}
		if(i == 60)
			printf("\n");
	} 
	putchar('\n');
	return;
}

void bfs(){
	if(hA == hB){
		printf("0\n\n");
		return;
	}
	
	cnt = 0;
	mp.clear();
	HashToNode.clear();
	while(!q.empty()){
		q.pop();
	}
	
	node cur = node(a, hA);
	q.push(cur);
	mp[cur.hashV] = -1;
	HashToNode[cur.hashV] = cur;
	
	while(!q.empty()){
		int num = q.size();
		cnt++;
		while(num--){
			cur = q.front();
			q.pop();
//			print(cur);
			for(int i = 1; i <= 3; i++){
				node tmp = node(cur.m, 0);
				if(i == 1){
					for(int j = 0; j < 4; j++){
						swap(tmp.m[0][j], tmp.m[1][j]);
					}
					tmp.op = 1;
				}
				else if(i == 2){
					for(int j = 3; j >= 1; j--){
						swap(tmp.m[0][j], tmp.m[0][j - 1]);
						swap(tmp.m[1][j], tmp.m[1][j - 1]);
					}
					tmp.op = 2;
				}
				else if(i == 3){
					int t = tmp.m[0][1];
					tmp.m[0][1] = tmp.m[1][1];
					tmp.m[1][1] = tmp.m[1][2];
					tmp.m[1][2] = tmp.m[0][2];
					tmp.m[0][2] = t;
					tmp.op = 3;
				}
				tmp.hashV = HASH(tmp.m);
				if(judge(tmp)){
					q.push(tmp);
					mp[tmp.hashV] = cur.hashV;
					HashToNode[tmp.hashV] = tmp;
					if(tmp.hashV == hB){
						printf("%d\n", cnt);
						output(tmp.hashV);
						return;
					}
				}
			}
		}
	}
	return;
}


int main(){
	while(scanf("%d%d%d%d%d%d%d%d", &b[0][0], &b[0][1], &b[0][2], &b[0][3], &b[1][3], &b[1][2], &b[1][1], &b[1][0]) != EOF){
		hA = HASH(a), hB = HASH(b);
//		for(int i = 0; i < 2; i++){
//			for(int j = 0; j < 4; j++){
//				printf("%d ", a[i][j]);
//			}
//			putchar('\n');
//		}
//		for(int i = 0; i < 2; i++){
//			for(int j = 0; j < 4; j++){
//				printf("%d ", b[i][j]);
//			}
//			putchar('\n');
//		}
		bfs();
	}
	return 0;
}

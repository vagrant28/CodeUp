#include <stdio.h>
#include <queue>
#include <stack>
#include <string.h>
using namespace std;
const int maxN = 1010;

struct node{	// bfs寻找时记录每次的操作后的体积 
	int a, b;
};

struct record{	// 记录父节点 和 得到当前节点的操作 
	int a, b;
	int op;
};

int Ca, Cb, N, cnt;
bool inQ[maxN][maxN];
record mark[maxN][maxN];
queue<node> q;
char op_name[7][20] = {"", "fill A", "fill B", "empty A", "empty B", "pour A B", "pour B A"};


void print(node end){
	stack<int> ans;
	node p = end;
//	puts("~~~~~~~");
//	printf("@p a = %d\t b = %d\n", p.a, p.b);
	do{
		ans.push(mark[p.a][p.b].op);
		int x =  p.a, y = p.b;
		p.a = mark[x][y].a;
		p.b = mark[x][y].b;
//		printf("?p a = %d\t b = %d\n", p.a, p.b);
		
	}while(p.a != 0 || p.b != 0);
//	puts("~~~~~~~");
	while(!ans.empty()){
		int t = ans.top();
		ans.pop();
		puts(op_name[t]);
	}
	puts("success");
	return;
}

void show(){
	for(int i = 0; i <= Ca; i++){
		for(int j = 0; j <= Cb; j++){
			printf("a=%d,b=%d,op=%d\t", mark[i][j].a, mark[i][j].b, mark[i][j].op);
		}
		putchar('\n');
	}
	return;
}

void init_mark(){
	for(int i = 0; i <= Ca; i++){
		for(int j = 0; j <= Cb; j++){
			mark[i][j].a = 0;
			mark[i][j].b = 0;
			mark[i][j].op = 0;
		}
	}
}

void bfs(){
	node cur;
	cur.a = 0, cur.b = 0;
	q.push(cur);
	inQ[0][0] = true;
	init_mark();
	
	while(!q.empty()){
		cur = q.front();
		q.pop();
		if(cur.b == N){
//			printf("**cur a = %d\t b = %d\n", cur.a, cur.b);
//			show();
			print(cur);
			break;
		}
		node tmp;
		for(int i = 1; i <= 6; i++){
			if(i == 1){
				tmp.a = Ca;
				tmp.b = cur.b;
			}
			else if(i == 2){
				tmp.a = cur.a;
				tmp.b = Cb;
			}
			else if(i == 3){
				tmp.a = 0;
				tmp.b = cur.b;
			}
			else if(i == 4){
				tmp.a = cur.a;
				tmp.b = 0;
			} 
			else if(i == 5){
				if(cur.a >= Cb - cur.b){
					tmp.a = cur.a - (Cb - cur.b);
					tmp.b = Cb;
				}
				else{
					tmp.a = 0;
					tmp.b = cur.a + cur.b;
				}
			}
			else if(i == 6){
				if(cur.b >= Ca - cur.a){
					tmp.a = Ca;
					tmp.b = cur.b - (Ca - cur.a);
				}
				else{
					tmp.a = cur.a + cur.b;
					tmp.b = 0;
				}
			}
			
//			printf("tmp a = %d\t b = %d\n", tmp.a, tmp.b);
			if(inQ[tmp.a][tmp.b] == false && tmp.a >= 0 && tmp.b >= 0 && tmp.a <= Ca && tmp.b <= Cb){
//				printf("tmp a = %d\t b = %d\n", tmp.a, tmp.b);
				q.push(tmp);
				inQ[tmp.a][tmp.b] = true;
				mark[tmp.a][tmp.b].a = cur.a;
				mark[tmp.a][tmp.b].b = cur.b;
				mark[tmp.a][tmp.b].op = i;
			}
		}
//		puts("==========");
	}
}

int main(){
	while(scanf("%d%d%d", &Ca, &Cb, &N) != EOF){
		memset(inQ, 0, sizeof(inQ));
		memset(mark, -1, sizeof(mark));
		while(!q.empty()){
			q.pop();
		}
		bfs();
	}
	return 0;
} 

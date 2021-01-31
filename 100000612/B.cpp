#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 1010;

struct node{
	vector<int> child;
	int level;
}tree[maxn];

int h;

void bfs(){
	queue<int> q;
	int now = 1;
	tree[now].level = 1;
	q.push(now);
	while(!q.empty()){
		now = q.front();
		q.pop();
		for(int i = 0; i < tree[now].child.size(); i++){
			tree[tree[now].child[i]].level = tree[now].level + 1;
			q.push(tree[now].child[i]);
			if(h < tree[tree[now].child[i]].level){
				h = tree[tree[now].child[i]].level;
			}
		}
	}
}

int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		int a, b;
		for(int i = 0; i < n - 1; i++){
			scanf("%d%d", &a, &b);
			tree[a].child.push_back(b);
		}
		h = 0;
		bfs();
		printf("%d\n", h);
	}
	return 0;
}

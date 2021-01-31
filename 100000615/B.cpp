#include <stdio.h>
const int maxn = 1e5 + 10;

int father[maxn];
int N, M, a, b; 

int findFather(int x){
	int root = x;
	while(root != father[root]){
		root = father[root];
	}
	while(x != father[x]){
		int tmp = x;
		x = father[x];
		father[tmp] = root;
	}
	return root;
}

void Union(int a, int b){
	int fA = findFather(a);
	int fB = findFather(b);
	if(fA != fB){
		father[fA] = fB;
	}
	return;
}

int main(){
	while(scanf("%d", &N), N){
		scanf("%d", &M);
		for(int i = 1; i <= N; i++){
			father[i] = i;
		}
		for(int i = 0; i < M; i++){
			scanf("%d%d", &a, &b);
			Union(a, b);
		}
		int sum = 0;
		for(int i = 1; i<= N; i++){
			if(i == father[i]){
				sum++;
			}
		}
		printf("%d\n", sum - 1);
	}
	return 0;
}

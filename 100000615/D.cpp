#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn = 10000000 + 10;

int father[maxn], numRoot[maxn];
int n, a, b;

int findFather(int x){
	if(father[x] == 0){
		father[x] = x;
		return x;
	}
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
	while(scanf("%d", &n) != EOF){
		if(n == 0){ // 相当于一对朋友也不存在，那只能选一个人 
			printf("1\n");
			continue;
		}
		memset(father, 0, sizeof(father));
		memset(numRoot, 0, sizeof(numRoot));
		int maxb = 0;
		for(int i = 0; i < n; i++){
			scanf("%d%d", &a, &b);
			Union(a, b);
			int t = max(a, b);
			if(maxb < t){
				maxb = t;
			}
		}
		int maxSum = -1;
		for(int i = 1; i <= maxb; i++){
			int t = ++numRoot[findFather(i)];
			if(maxSum < t){
				maxSum = t;
			}
		}
		printf("%d\n", maxSum);
		
//		printf("father[]:\n");
//		for(int i = 1; i <= maxb; i++){
//			printf("%d ", father[i]);
//		}
//		printf("\n");
//		printf("numRoot[]:\n");
//		for(int i = 1; i <= maxb; i++){
//			printf("%d ", numRoot[i]);
//		}
//		printf("\n");
	}
	return 0;
}

#include <stdio.h>
const int maxn = 1010;

int father[maxn];
int N, M;
int a, b;

int findFather(int x){
	if(x == father[x]){
		return x;
	}
	else{
		int F = findFather(father[x]);
		father[x] = F;
		return F;
	}
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
	while(scanf("%d%d", &N, &M) != EOF){
		if(N == 0 && M == 0){
			break;
		}
		for(int i = 1; i <= N; i++){
			father[i] = i;
		}
		for(int i = 0; i < M; i++){
			scanf("%d%d", &a, &b);
			Union(a, b);
		}
		if(M > N - 1){
			printf("No\n");
			continue;
		}
		int sum = 0;
		for(int i = 1; i <= N; i++){
			if(i == father[i]){
				sum++;
			}
		}
		if(sum == 1){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
	return 0;
}

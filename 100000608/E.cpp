#include <stdio.h>
#include <stack>
#include <string.h>
using namespace std;

int n;
int cnt;

void dfs(int in, int op){
//	printf("in = %d; op = %d\n", in, op);
	if(op == 2 * n && in == 0){
		
//		printf("#1\n");
		cnt++;
		return;
	}
	else if(in < 0 || in > n || op > 2 * n){
//		printf("#2\n");
		return;
	}
	dfs(in + 1, op + 1);
	dfs(in - 1, op + 1);
}

int main(){
	while(scanf("%d", &n) != EOF){
		cnt = 0;
		dfs(0, 0);
		printf("%d\n", cnt);
	}
	return 0;
}

// 2
// 1 2 
// 2 1

// 3
// 1 2 3
// 1 3 2
// 2 1 3
// 2 3 1
// 3 1 2*
// 3 2 1

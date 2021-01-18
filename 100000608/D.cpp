#include <stdio.h>
#include <string.h>
#include <vector>
#include <stdlib.h>
using namespace std;

int n, cnt;
bool vis[15];
vector<int> v;

void dfs(int index){
	if(index == n){
		cnt++;
		for(int i = 0; i < n; i++){
			printf("%d ", v[i]);
		}
		putchar('\n');
		return;
	}
	for(int col = 1; col <= n; col++){
		if(!vis[col]){
			bool flag = true;
			for(int pre = 0; pre < index; pre++){
				if(abs(pre - index) == abs(v[pre] - col)){
					flag = false;
					break;
				}
			}
			if(flag){
				vis[col] = true;
				v.push_back(col);
				dfs(index + 1);
				vis[col] = false;
				v.pop_back();
			}
		}
	}
}

int main(){
	while(scanf("%d", &n) != EOF){
		memset(vis, 0, sizeof(vis));
		cnt = 0;
		dfs(0);
		if(cnt == 0){
			printf("no solute!\n");
		}
	}
	return 0;
}

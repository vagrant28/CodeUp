#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

int n, r;
bool vis[25];
vector<int> v;

void dfs(int index){
	if(index == r){
		for(int i = 0; i < r; i++){
			printf("%d ", v[i]);
		}
		putchar('\n');
		return;
	}
	if(index == 0){
		for(int i = 1; i <= n; i++){
			vis[i] = true;
			v.push_back(i);
			dfs(index + 1);
			v.pop_back();
			vis[i] = false;
		}
	}
	else{
		for(int i = v[index - 1] + 1; i <= n; i++){
			if(!vis[i]){
				vis[i] = true;
				v.push_back(i);
				dfs(index + 1);
				v.pop_back();
				vis[i] = false;
			}
		}
	}
}

int main(){
	while(scanf("%d%d", &n, &r) != EOF){
		memset(vis, 0, sizeof(vis));
		dfs(0);
	}
	return 0;
}

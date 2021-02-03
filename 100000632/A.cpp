#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6 + 10;  // 也不能开的太大，会报运行错误 

char str[maxn];
LL arr[maxn];
LL num, sum;

void dfs(int id, LL tmp_sum, LL &ans){
	if(id == num){
		return;
	}
	if(tmp_sum + arr[id] <= sum / 2){
		ans = max(ans, tmp_sum + arr[id]);
		if(ans == sum / 2){
			return;
		}
		else{
			dfs(id + 1, tmp_sum + arr[id], ans);
		}
	}
	dfs(id + 1, tmp_sum, ans);
}


int main(){
	while(scanf("%[^\n]", str) != EOF){
		getchar();
		LL len = strlen(str), digit = 0;
		num = 0, sum = 0;
		bool flag = true;
		for(LL i = 0; i < len; i++){
			if(str[i] == ' '){
				arr[num++] = digit;
				sum += digit;
				digit = 0;
			}
			else if(str[i] >= '0' && str[i] <= '9'){
				digit = digit * 10 + str[i] - '0';
			}
			else{
				flag = false;
				break;
			}
		}
		if(flag == false){
			printf("ERROR\n");
			continue;
		}
		arr[num++] = digit;
		sum += digit;
		
		LL ans = 0;
		dfs(0, 0, ans);
		printf("%d %d\n", sum - ans, ans);
	}
	return 0;
}


#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 610;

int L, N;
int b[maxn]; 

bool cmp(int a, int b){
	return a > b;
}

int main(){
	while(scanf("%d%d", &L, &N) != EOF){
		for(int i = 0; i < N; i++){
			scanf("%d", &b[i]);
		}
		sort(b, b + N, cmp);
		int len = 0, num = 0, flag = 0;
		for(int i = 0; i < N; i++){
			len += b[i];
			num++;
			if(len > L){
				flag = 1;
				printf("%d\n", num);
				break;
			}
		}
		if(!flag){
			printf("impossible\n");
		}
	}
	return 0;
}

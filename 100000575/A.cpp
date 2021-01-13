#include <stdio.h>
#include <string.h>
int main(){
	int L, M;
	int a[10005];
	while(scanf("%d%d", &L, &M), L || M){
		memset(a, 0, sizeof(a));	// 0表示有树，1表示没树 
		int s, e;
		while(M--){
			scanf("%d%d", &s, &e);
			for(int i = s; i <= e; i++){
				a[i] = 1;
			}
		}
		int num = 0;
		for(int i = 0; i <= L; i++){
			if(a[i] == 0){
				num++;
			}
		}
		printf("%d\n", num);
	}
	return 0;
}

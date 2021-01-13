#include <stdio.h>
#include <string.h>

int main(){
	int n, m;
	int a[200];
	while(scanf("%d", &n) != EOF){
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
		}
		scanf("%d", &m);
		while(m--){
			int x;
			scanf("%d", &x);
			int flag = 0;
			for(int i = 0; i < n; i++){
				if(a[i] == x){
					puts("YES");
					flag = 1;
					break;
				}
			}
			if(flag == 0){
				puts("NO");
			}
		}
	}
	return 0;
} 

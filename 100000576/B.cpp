#include <stdio.h>

int main(){
	int n, x;
	int a[205];
	while(scanf("%d", &n) != EOF){
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
		}
		scanf("%d", &x);
		int index = -1;
		for(int i = 0; i < n; i++){
			if(a[i] == x){
				index = i;
				break;
			}
		}
		printf("%d\n", index);
	}
	return 0;
} 

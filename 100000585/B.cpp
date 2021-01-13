#include <stdio.h>
const int maxn = 90;

int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		while(n--){
			int a[maxn], k;
			bool h[maxn] = {false};
			scanf("%d", &k);
			for(int i = 0; i < k; i++){
				scanf("%d", &a[i]);
			}
			if(a[0] != a[1]){
				h[0] = true;
			}
			if(a[k - 1] != a[k - 2]){
				h[k - 1] = true;
			}
			for(int i = 1; i <= k - 2; i++){
				if((a[i]<a[i-1] && a[i]<a[i+1]) || (a[i]>a[i-1] && a[i]>a[i+1])){
					h[i] = true;
				}
			}
			int flag = 0;
			for(int i = 0; i < k; i++){
				if(h[i]){
					if(flag){
						printf(" ");
					}
					printf("%d", i);
					flag = 1;
				}
			}
			if(flag)
				putchar('\n');
		} 
		
	}
	return 0;
}

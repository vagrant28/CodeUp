#include <stdio.h>


int main(){
	int tot;
	int a[6] = {50, 20, 10, 5, 1};
	while(scanf("%d", &tot) != EOF){
		int cnt[6] = {0};
		for(int i = 0; i < 5; i++){
			if(tot >= a[i]){
				cnt[i] = tot / a[i];
				tot = tot % a[i];
			}
		}
		int flag = 0;
		for(int i = 0; i < 5; i++){
			if(cnt[i] != 0){
				if(flag){
					putchar('+');
				}
				printf("%d*%d", a[i], cnt[i]);
				flag = 1;
			}
		}
		putchar('\n');
	}
	return 0;
}

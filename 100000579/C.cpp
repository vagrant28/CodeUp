#include <stdio.h>
#include <string.h>

int main(){
	int n[40];
	int ans[500];
	char str[40];
	while(scanf("%s", str) != EOF){
		int len = strlen(str);
		for(int i = 0; i < len; i++){
			n[i] = str[i] - '0';
		}
		int flag = 1, pre = 0, num = 0;
		while(flag){
			flag = 0;
			pre = 0;
			ans[num++] = n[len - 1] % 2;
			for(int i = 0; i < len; i++){
				int tmp = n[i];
				n[i] = (pre * 10 + n[i]) / 2;
				if(n[i]){
					flag = 1;
				}
				if(tmp % 2 == 0){
					pre = 0;
				}
				else{
					pre = 1;
				}
			}
//			for(int i = 0; i < len; i++){
//				printf("%d", n[i]);
//			}
//			putchar('\n');
		}
		for(int i = num - 1; i >= 0; i--){
			printf("%d", ans[i]);
		}
		putchar('\n');
	}
	return 0;
}

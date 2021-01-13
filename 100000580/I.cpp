#include <stdio.h>
#include <string.h>

int main(){
	char str[300];
	while(scanf("%s", str) != EOF){
		int len = strlen(str);
		int flag = 1;
		for(int i = 0; i < (len - 1) / 2; i++){
			if(str[i] != str[len - 1 - i]){
				flag = 0;
				break;
			}
		}
		if(flag){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}

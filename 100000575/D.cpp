#include <stdio.h>

int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		int flag = 0;
		int tmp;
		while(n--){
			scanf("%d", &tmp);
			if(tmp % 2 == 0){
				flag++;
			}
			else{
				flag--;
			}
		}
		if(flag > 0){
			puts("NO");
		}
		else{
			puts("YES");
		}
	} 
}

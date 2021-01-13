#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	while(n--){
		int a;
		scanf("%d", &a);
		if(a & 1){
			printf("0 0\n");
		}
		else{
			if(a % 4 == 0){
				printf("%d %d\n", a / 4, a / 2);
			}
			else{
				printf("%d %d\n", (a - 2) / 4 + 1, a / 2);
			}
			
		}
	}
}

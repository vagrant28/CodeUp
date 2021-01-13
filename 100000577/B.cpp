#include <stdio.h>
#include <string.h> 

int main(){
	char str[100];
	while(scanf("%s", str) != EOF){
		int len = strlen(str);
		int n1 = (len + 2) / 3;
		int n2 = len + 2 - 2 * n1;
		for(int i = 0; i < n1 - 1; i++){
			putchar(str[i]);
			for(int j = 1; j <= n2 - 2; j++){
				putchar(' ');
			}
			putchar(str[len - 1 - i]);
			putchar('\n');
		}
		for(int i = n1 - 1; i <= len - n1; i++){
			putchar(str[i]); 
		}
		putchar('\n');
	}
	return 0;
}

// n1 + n2 + n3 - 2 = N
// 2k + n2 = N + 2
// 2k <= 2n2
// 3 <= n2 <= N
// N + 2 - n2 <= 2n2
// 3n2 >= N + 2
// (N+2)/3 <= n2 <= N
// 



#include <stdio.h>
#include <string.h>

int main(){
	char str[300];
	while(gets(str) != NULL){
		int len = strlen(str);
		for(int i = len - 1; i >= 0; i--){
			putchar(str[i]);
		}
		putchar('\n');
	}
	return 0;
}

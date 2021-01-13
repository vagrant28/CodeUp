#include <stdio.h>
#include <string.h>

int main(){
	char str[200];
	while(gets(str) != NULL){
		int len = strlen(str);
		for(int i = 0; i < len; i++){
			if(str[i] >= 'a' && str[i] <= 'z'){
				if(i==0 || str[i-1]==' ' || str[i-1]=='\t' || str[i-1]=='\r' || str[i-1]=='\n' || str[i-1]==',' || str[i]=='.'){
					str[i] = str[i] - 'a' + 'A';
				}
			}
		}
		puts(str);
	}
	return 0;
}

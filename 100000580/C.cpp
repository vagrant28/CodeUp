#include <stdio.h>
#include <string.h>

char p[1000];
char str[1000][1000];
char ans[1000][1000];
int plen;

char low(char c){
	if(c >= 'A' && c <= 'Z'){
		return c - 'A' + 'a';
	}
	else if(c >= 'a' && c <= 'z'){
		return c;
	}
}

bool isChar(char c){
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

bool isPattern(int s, int num){
	if(isChar(str[num][s])){
		int flag = 1;
		for(int i = 0; i < plen; i++){
			if(low(p[i]) != low(str[num][s + i])){
				return false;
			}
		}
		return true;
	}
	else{
		return false;
	}
}

int main(){
	gets(p);
	plen = strlen(p);
	int num = 0;
	while(gets(str[num]) != NULL){
		int len = strlen(str[num]);
		int i = 0, j = 0;
		while(i < len){
			if(isPattern(i, num)){
				i = i + plen;
			}
			else if(str[num][i] == ' '){
				i = i + 1;
			}
			else{
				ans[num][j++] = str[num][i++];
			}
		}
		ans[num][j] = '\0';
		num++;
	}
	for(int k = 0; k < num; k++){
		puts(ans[k]);
//		printf("%d\n", strlen(ans[k]));
	}
	return 0;
} 

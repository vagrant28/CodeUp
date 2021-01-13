#include <stdio.h>
#include <string.h>

int main(){
	char str[3][100];
	gets(str[0]);
	gets(str[1]);
	gets(str[2]);
	int max = 0;
	if(strcmp(str[0], str[1]) < 0){
		max = 1;
	}
	if(strcmp(str[max], str[2]) < 0){
		max = 2;
	}
	puts(str[max]);
	return 0;
}

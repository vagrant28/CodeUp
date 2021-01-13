#include <stdio.h>
#include <string.h>

int main(){
	char str[100];
	gets(str);
	int len = strlen(str);
	char tmp;
	for(int i = 0; i <= (len - 1) / 2; i++){
		tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
	}
	puts(str);
	return 0;
} 

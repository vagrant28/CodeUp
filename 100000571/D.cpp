#include <stdio.h>
#include <string.h>

void swap(char* x, char* y){
	char tmp[20];
//	puts(x);
//	puts(y);
	strcpy(tmp, x);
//	puts(tmp);
	strcpy(x, y);
	strcpy(y, tmp);
}

int main(){
	char str[3][20];
	for(int i = 0; i < 3; i++)
		gets(str[i]);
//	for(int i = 0; i < 3; i++)
//		puts(str[i]);
	swap(str[0], str[1]);
//	for(int i = 0; i < 3; i++)
//		puts(str[i]);
	if(strcmp(str[0], str[1]) > 0)
		swap(str[0], str[1]);
	if(strcmp(str[1], str[2]) > 0)
		swap(str[1], str[2]);
	if(strcmp(str[0], str[1]) > 0)
		swap(str[0], str[1]);
	for(int i = 0; i < 3; i++)
		puts(str[i]);
	return 0;
}

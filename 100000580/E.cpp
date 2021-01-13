#include <stdio.h>
#include <string.h>

int main(){
	char a[100000];
	char b[100000];
	char c;
	while(gets(a) != NULL){
		scanf("%c", &c);
		getchar();
		int len = strlen(a);
		int i = 0, j = 0;
		while(i < len){
			if(a[i] == c){
				i++;
			}
			else{
				b[j++] = a[i++];
			}
		}
		b[j] = '\0';
		puts(b);
	}
	return 0;
}

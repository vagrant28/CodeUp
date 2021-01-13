#include <stdio.h>

int main(){
	int flag;
	char str1[100], str2[100];
	gets(str1);
	gets(str2);
	int i = 0;
	while(str1[i] != 0){
		flag = str1[i] - str2[i];
		if(flag == 0)
			i++;
		else{
			printf("%d\n", flag);
			break;
		}
	}
	return 0;
}

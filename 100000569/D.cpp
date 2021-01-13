#include <stdio.h>
#include <string.h>

int main(){
	//A-Z 65-90,a-z 97-122
	char str[100];
	gets(str);
	int len = strlen(str);
	for(int i = 0; i < len; i++){
		if(str[i] >= 65 && str[i] <= 90){
			str[i] = 90 - (str[i] - 65);
		}
		else if(str[i] >= 97 && str[i] <= 122){
			str[i] = 122 - (str[i] - 97);
		}
	}
	puts(str);
	return 0;
} 

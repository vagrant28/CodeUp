#include <stdio.h>

void vowels(char s1[], char s2[]){
	int i = 0, j = 0;
	while(s1[i]){
		switch(s1[i]){
			case 'A':
				s2[j] = 'A';
				j++;
				break;
			case 'E':
				s2[j] = 'E';
				j++;
				break;
			case 'I':
				s2[j] = 'I';
				j++;
				break;
			case 'O':
				s2[j] = 'O';
				j++;
				break;
			case 'U':
				s2[j] = 'U';
				j++;
				break;
			case 'a':
				s2[j] = 'a';
				j++;
				break;
			case 'e':
				s2[j] = 'e';
				j++;
				break;
			case 'i':
				s2[j] = 'i';
				j++;
				break;
			case 'o':
				s2[j] = 'o';
				j++;
				break;
			case 'u':
				s2[j] = 'u';
				j++;
				break;
		}
		i++;
	}
}

int main(){
	char str1[100], str2[100];
	gets(str1);
	vowels(str1, str2);
	puts(str2);
	return 0;
}

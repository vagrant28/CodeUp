#include <stdio.h>

int main(){
	char str1[150], str2[150];
	char ans[300];
	while(scanf("%s%s", str1, str2) != EOF){
		int i = 0;
		while(str1[i] != '\0'){
			ans[i] = str1[i];
			i++;
		}
		int j = 0;
		while(str2[j] != '\0'){
			ans[i++] = str2[j++];
		} 
		ans[i] = '\0';
		puts(ans);
	}
	return 0;
}

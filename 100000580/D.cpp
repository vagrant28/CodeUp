#include <stdio.h>
#include <string.h>

int main(){
	char str[105][105];
	char a[105], b[105];
	char tmp;
	int num = 0;
	while(scanf("%s", &str[num++]) != EOF){
		tmp = getchar();
		if(tmp == '\n'){
			gets(a);
			gets(b);
			for(int i = 0; i < num; i++){
				if(strcmp(str[i], a) == 0){
					strcpy(str[i], b);
				}
			}
			for(int i = 0; i < num; i++){
				printf("%s", str[i]);
				if(i == num - 1){
					putchar('\n');
				}
				else{
					putchar(' ');
				}
			}
			num = 0;
		}
	}
	return 0;
} 

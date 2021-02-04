#include <stdio.h>
#include <string.h>
const int maxw = 20;
const int maxd = 1e7 + 10;

int next[maxw];
char pattern[maxw], text[maxd];

void standard(char str[]){
	int len = strlen(str);
	for(int i = 0; i < len; i++){
		if(str[i] >= 'A' && str[i] <= 'Z'){
			str[i] = str[i] - 'A' + 'a';
		}
	}
}

void getNext(){
	int j = -1;
	next[0] = -1;
	int len = strlen(pattern);
	for(int i = 1; i < len; i++){
		while(j != -1 && pattern[i] != pattern[j + 1]){
			j = next[j];
		}
		if(pattern[i] == pattern[j + 1]){
			j++;
		}
		next[i] = j;
	}
}

void KMP(){
	int n = strlen(text), m = strlen(pattern);
	getNext();
	int ans = 0, j = -1, s;
	bool flag = false;
	for(int i = 0; i < n; i++){
		while(j != -1 && text[i] != pattern[j + 1]){
			j = next[j];
		}
		if(text[i] == text[j + 1]){
			j++;
		}
		if(j == m - 1){
			if(((i - m + 1 == 0) || (text[i - m] == ' ')) && ((i == n - 1) || text[i + 1] == ' ')){
				if((i- m + 1 == 0) || text[i - m] == ' '){
//					printf("i=%d\n", i);
					ans++;
					if(flag == false){
						s = i - m + 1;
						flag = true;
					}
				}
			}
			j = next[j];
		}
	}
	if(ans == 0){
		printf("-1\n");
	}
	else{
		printf("%d %d\n", ans, s);
	}
}

int main(){
	while(scanf("%s", pattern) != EOF){
		getchar();
		scanf("%[^\n]", text);
		standard(pattern);
		standard(text);
		KMP();
	}
	return 0;
}

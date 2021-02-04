#include <stdio.h>
#include <string.h>
const int maxn = 3010;
const int maxL = 300;

int n;
int next[maxL];
char pattern[maxL], text[maxL];

void standard(char str[]){
	int len = strlen(str);
	for(int i = 0; i < len; i++){
		if(str[i] >= 'A' && str[i] <= 'Z'){
			str[i] = str[i] - 'A' + 'a';
		}
	}
}

void getNext(char s[], int len){
	int j = -1;
	next[0] = -1;
	for(int i = 1; i < len; i++){
		while(j != -1 && s[i] != s[j + 1]){
			j = next[j];
		}
		if(s[i] == s[j + 1]){
			j++;
		}
		next[i] = j;
	}
}

int KMP(char text[], char pattern[]){
	int n = strlen(text), m = strlen(pattern);
	getNext(pattern, m);
	int ans = 0, j = -1;
	for(int i = 0; i < n; i++){
		while(j != -1 && text[i] != pattern[j + 1]){
			j = next[j];
		}
		if(text[i] == pattern[j + 1]){
			j++;
		}
		if(j == m - 1){
			ans++;
			j = next[j];
		}
	}
	return ans;
}

int main(){
	while(scanf("%d", &n) != EOF){
		scanf("%s", pattern);
//		standard(pattern);
		int num = 0;
		while(n--){
			getchar();
			scanf("%[^\n]", text);
//			standard(text);
			num += KMP(text, pattern);
		}
		printf("%d\n", num);
	}
	return 0;
}

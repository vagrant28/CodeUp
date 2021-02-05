#include <stdio.h>
#include <string.h>
const int maxn = 1100;

int next[maxn];
char text[maxn], pattern[maxn];

void getNext(){
	int j = -1, len = strlen(pattern);
	next[0] = -1;
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
	int j = -1, ans = 0;
	for(int i = 0; i < n; i++){
		while(j != -1 && text[i] != pattern[j + 1]){
			j = next[j]; 
		}
		if(text[i] == pattern[j + 1]){
			j++;
		}
		if(j == m - 1){
			j = -1;
			ans++;
		}
	}
	printf("%d\n", ans);
}

int main(){
	while(scanf("%s", text) != EOF){
		if(text[0] == '#'){
			break;
		}
		scanf("%s", pattern);
		KMP();
	}
	return 0;
}

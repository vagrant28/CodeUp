#include <stdio.h>
#include <string.h>
const int maxn = 5010;

int dp[maxn][maxn];

bool isAlpha(char ch){
	return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

bool isDigit(char ch){
	return (ch >= '0' && ch <= '9');
}

char toUpper(char ch){
	if(ch >= 'A' && ch <= 'Z'){
		return ch;
	}
	else if(ch >= 'a' && ch <= 'z'){
		return ch - 'a' + 'A';
	}
}

int main(){
	char s[maxn], b[maxn];
	int p[maxn];
	while(scanf("%[^\n]", s) != EOF){
		getchar();
		int k = 0;
		int len = strlen(s);
		for(int i = 0; i < len; i++){
			if(isAlpha(s[i])){
				b[k] = toUpper(s[i]);
				p[k] = i;
				k++;
			}
			else if(isDigit(s[i])){
				b[k] = s[i];
				p[k] = i;
				k++;
			}
		}
		b[k] = '\0';
//		printf("%s\n", b);
		memset(dp, 0, sizeof(b));
		int st, ed;
		for(int i = 0; i < k; i++){
			dp[i][i] = 1;
			if(b[i] == b[i + 1]){
				dp[i][i + 1] = 1;
				st = i;
				ed = i + 1;
			}
		}
//		printf("lenb = %d, k = %d\n", strlen(b), k);
		for(int L = 3; L <= k; L++){
			for(int i = 0; i + L - 1 < k; i++){
				int j = i + L - 1;
				if(b[i] == b[j] && dp[i + 1][j - 1] == 1){
					dp[i][j] = 1;
					st = i;
					ed = j;
				}
			}
		}
		for(int i = p[st]; i <= p[ed]; i++){
			printf("%c", s[i]);
		}
		printf("\n");
	}
	return 0;
}

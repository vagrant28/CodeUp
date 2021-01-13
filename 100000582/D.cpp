#include <stdio.h>
#include <string.h>
const int maxn = 1e4+10;

int main(){
	char a[maxn], b[maxn], ans[maxn];
	while(gets(a) != NULL){
		gets(b);
		int hashTable[maxn] = {0};
		int blen = strlen(b);
		for(int i = 0; i < blen; i++){
			hashTable[b[i]] = 1;
		}
		int alen = strlen(a);
		int num = 0;
		for(int i = 0; i < alen; i++){
			if(!hashTable[a[i]]){
				ans[num++] = a[i];
			}
		}
		ans[num] = '\0';
		puts(ans);
	}
	return 0;
}

#include <stdio.h>
#include <string.h>

int a[25];
int HashTable[25];
int count;
int n;

void P(int res, int pos){
	if(res < 0 || pos > n){
//		puts("111");
		return;
	}
	else if(res == 0){
//		puts("222");
		count++;
		return;
	}
	else{
//		puts("333");
		P(res - a[pos], pos + 1);
		P(res, pos + 1);
	}
}

int main(){
	while(scanf("%d", &n) != EOF){
		count = 0;
		memset(HashTable, 0, sizeof(HashTable));
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
		}
//		printf("count = %d\n", count);
		P(40, 0);
		printf("%d\n", count);
	}
	return 0;
}

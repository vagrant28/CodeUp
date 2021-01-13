#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxN = 110;
const int maxL = 1010;

char str[maxN][maxL];

bool cmp(char *a, char *b){
	return strcmp(a, b) < 0;
}

void swap(char* a, char* b){
	char tmp[maxL];
	strcpy(tmp, a);
	strcpy(a, b);
	strcpy(b, tmp);
	return;
}

int compare(char* a, char* b){
	int lenA = strlen(a);
	int lenB = strlen(b); 
	if(lenA == lenB){
		return strcmp(a, b);
	}
	else{
		return (lenA < lenB) ? -1 : 1;
	}
}


int main(){
	int N;
	while(scanf("%d", &N) != EOF){
		for(int i = 0; i < N; i++){
			scanf("%s", str[i]);
		}
		for(int i = 1; i <= N - 1; i++){
			for(int j = 1; j <= N - i; j++){
//				printf("i=%d j=%d %s %s %d\n", i, j, str[j], str[j+1], compare(str[j], str[j + 1]));
//				printf("%d\n", compare(str[j], str[j + 1]));
				if(compare(str[j - 1], str[j]) > 0){
					swap(str[j - 1], str[j]);
				}
			}
		}
		for(int i = 0; i < N; i++){
			puts(str[i]);
		}
	}
	return 0;
}

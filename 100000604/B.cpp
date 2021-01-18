#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int main(){
	char s[10];
	while(scanf("%s", s) != EOF){
		do{
			puts(s);
		}while(next_permutation(s, s + strlen(s)));
		putchar('\n');
	}
	return 0;
}

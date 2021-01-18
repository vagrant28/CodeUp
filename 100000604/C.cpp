#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int main(){
	char s[210];
	while(gets(s) != NULL){
		reverse(s, s + strlen(s));
		puts(s);
	}
	return 0;
}

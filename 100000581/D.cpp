#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main(){
	char str[300];
	while(gets(str) != NULL){
		int len = strlen(str);
		sort(str, str + len);
		puts(str);
	}
	return 0;
}

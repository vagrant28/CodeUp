#include <stdio.h>

int main(){
	char* a = "I love China!";
	int n;
	scanf("%d", &n);
	char* b = a + n;
	puts(b);
	return 0; 
}

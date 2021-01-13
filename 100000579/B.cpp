#include <stdio.h>
#include <string.h>

int CtoI(char a){
	if(a >= '0' && a <= '9'){
		return a - '0';
	}
	else if(a >= 'A' && a <= 'Z'){
		return a - 'A' + 10;
	}
	else if(a >= 'a' && a <= 'z'){
		return a - 'a' + 10;
	}
}

char ItoC(int x){
	if(x >= 0 && x <= 9){
		return x - 0 + '0';
	}
	if(x > 9){
		return x - 10 + 'A';
	}
}

int main(){
	int a, b;
	char n[40];
	char ans[40];
	while(scanf("%d%s%d", &a, n, &b) != EOF){
		int tmp = 0, len = strlen(n);
		int product = 1;
		for(int i = len - 1; i >= 0; i--){
			tmp = tmp + CtoI(n[i]) * product;
			product *= a;
		}
		int num = 0;
		do{
			ans[num++] = ItoC(tmp % b);
			tmp /= b;
		}while(tmp != 0);
		for(int i = num - 1; i >= 0; i--){
			putchar(ans[i]);
		}
		putchar('\n');
	}
	return 0;
}

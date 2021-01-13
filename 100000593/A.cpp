#include <stdio.h>
#include <string.h>
const int maxn = 1010;

struct bign{
	int d[maxn];
	int len;
	bign(){
		memset(d, 0, sizeof(d));
		len = 0;
	}
};

bign change(char* str){
	bign a;
	a.len = strlen(str);
	for(int i = 0; i < a.len; i++){
		a.d[i] = str[a.len - 1 - i] - '0';
	}
	return a;
}

bign add(bign a, bign b){
	bign c;
	int carry = 0;
	for(int i = 0; i < a.len || i < b.len; i++){
		int tmp = a.d[i] + b.d[i] + carry;
		c.d[c.len++] = tmp % 10;
		carry = tmp / 10;
	}
	if(carry != 0){
		c.d[c.len++] = carry;
	}
	return c;
}

bign sub(bign a, bign b){
	bign c;
	for(int i = 0; i < a.len && i < b.len; i++){
		if(a.d[i] < b.d[i]){
			a.d[i + 1]--;
			a.d[i] += 10;
		}
		c.d[c.len++] = a.d[i] - b.d[i];
	}
	while(c.len >= 1 && c.d[c.len - 1] == 0){
		c.len--;
	}
	return c;
}

void print(bign a){
	for(int i = a.len - 1; i >= 0; i--){
		printf("%d", a.d[i]);
	}
}

int main(){
	char str1[maxn], str2[maxn];
	while(scanf("%s%s", str1, str2) != EOF){
		if(str1[0] == '-' && str2[0] == '-'){
			bign a = change(str1 + 1);
			bign b = change(str2 + 1);
			printf("-");
			print(add(a, b));
			putchar('\n');
		}
		else if(str1[0] == '-' && str2[0] != '-'){  // b - |a|
			bign a = change(str1 + 1);
			bign b = change(str2);
			if(strcmp(str2, str1 + 1) < 0){
				
				printf("-");
				print(sub(a, b));
				putchar('\n');
			}
			else{
				print(sub(b, a));
				putchar('\n');
			}
		}
		else if(str1[0] != '-' && str2[0] == '-'){  // a - |b|
			bign a = change(str1);
			bign b = change(str2 + 1);
			if(strcmp(str1, str2 + 1) < 0){
				printf("-");
				print(sub(b, a));
				putchar('\n');
			}
			else{
				print(sub(a, b));
				putchar('\n');
			}
		}
		else{
			bign a = change(str1);
			bign b = change(str2);
			print(add(a, b));
			putchar('\n');
		}
	}
	return 0;
}

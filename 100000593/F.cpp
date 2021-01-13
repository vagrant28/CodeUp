#include <stdio.h>
#include <string.h>
const int maxL = 1e4 + 10;
const int maxB = 1e5 + 10;

struct bign{
	int d[maxL];
	int len;
	bign(){
		len = 0;
		memset(d, 0, sizeof(d));
	}
};

bign change(char* a){
	bign b;
	b.len = strlen(a);
	for(int i = 0; i < b.len; i++){
		b.d[i] = a[b.len - 1 - i] - '0';
	}
	return b;
}

void print(bign a){
	puts("Start of print function!");
	printf("%d\n", a.len);
	for(int i = 0; i < a.len; i++){
		printf("%d", a.d[i]);
	}
	putchar('\n');
	puts("End of print function!");
}

bign divide(bign a, int m, int b, int &r){
	bign c;
	c.len = a.len;
	r = 0;
	for(int i = a.len - 1; i >= 0; i--){
		r = r * m + a.d[i];
		if(r < b){
			c.d[i] = 0;
		}
		else{
			c.d[i] = r / b;
			r = r  % b;
		}
	}
	while(c.len >= 1 && c.d[c.len - 1] == 0){
		c.len--;
	}
	return c;
}

int main(){
	char A[maxL];
	while(scanf("%s", A) != EOF){
		char b[maxB];
		int k = 0, r = 0;
		bign a = change(A);
//		print(a);
		while(a.len > 0){
			a = divide(a, 10, 2, r);
//			print(a);
			b[k++] = r + '0';
		}
		b[k] = '\0';
//		for(int i = k - 1; i >= 0; i--){
//			printf("%d", b[i]);
//		}
//		putchar('\n');
		char ans[maxL];
		int p = 0;
		bign x = change(b);
		while(x.len > 0){
			x = divide(x, 2, 10, r);
			ans[p++] = r + '0';
		}
		ans[p] = '\0';
		for(int i = p - 1; i >= 0; i--){
			putchar(ans[i]);
		}
		putchar('\n');
	}
	return 0;
}

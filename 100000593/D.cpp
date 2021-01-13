#include <stdio.h>
#include <string.h>
const int maxn = 1e5 + 10;

struct bign{
	int d[maxn];
	int len;
	bign(){
		memset(d, 0, sizeof(d));
		len = 0;
	}
};

int CtoI(char a){
	if(a >= '0' && a <= '9'){
		return a - '0';
	}
	else if(a >= 'A' && a <= 'Z'){
		return a - 'A' + 10;
	}
} 

char ItoC(int x){
	if(x >= 0 && x <= 9){
		return x + '0';
	}
	else if(x >= 10 && x <= 35){
		return x - 10 + 'a';
	}
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

bign change(char* a){
	bign b;
	b.len = strlen(a);
	for(int i = 0; i < b.len; i++){
		b.d[i] = CtoI(a[b.len - 1 - i]);
	}
	return b;
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
			r = r % b;
		}
	}
	while(c.len >= 1 && c.d[c.len - 1] == 0){
		c.len--;
	}
	return c;
}

int main(){
	int M, N;
	while(scanf("%d%d", &M, &N) != EOF){
		char X[maxn], ans[maxn];
		scanf("%s", X);
		// 似乎默认M>N,即高进制->低进制 
		bign a = change(X);
//		print(a);
		int k = 0, r = 0;
		while(a.len != 0){
			a = divide(a, M, N, r);
//			print(a);
			ans[k++] = ItoC(r);	
		}
		ans[k] = '\0';
		for(int i = k - 1; i >= 0; i--){
			putchar(ans[i]);
		}
		putchar('\n');
	}
	return 0;
}

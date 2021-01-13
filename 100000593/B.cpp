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
	bign(int a[], int _len){
		for(int i = 0; i < len; i++){
			d[i] = a[i];
		}
		len = _len;
	}
};

void print(bign a){
	for(int i = 0; i < a.len; i++){
		printf("%d", a.d[a.len - 1 - i]);
	}
}

bign multi(bign a, int b){
	bign c;
	int carry = 0;
	for(int i = 0; i < a.len; i++){
		int tmp = a.d[i] * b + carry;
		c.d[c.len++] = tmp % 10;
		carry = tmp / 10;
	}
	while(carry != 0){
		c.d[c.len++] = carry % 10;
		carry /= 10;
	}
	return c;
}

int main(){
	int N;
	while(scanf("%d", &N) != EOF){
		if(N == 0){
			printf("1\n");
		}
		else{
			bign ans;
			ans.len = 1;
			ans.d[0] = 1;
			for(int i = 2; i <= N; i++){
				ans = multi(ans, i);
			}
			print(ans);
			putchar('\n');
		}
	}
	return 0;
}

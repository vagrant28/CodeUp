#include <stdio.h>
#include <string.h>
const int maxn = 1010;

struct bigf{
	int d[maxn];	// 数组从左到右 记录了 数据从右到左 
	int len;	// 数字位数，包括小数点 
	int pos;	// 小数的位数 
	bigf(){
		memset(d, 0, sizeof(d));
		len = 0;
		pos = 0;
	}
};

void print(bigf a){
	for(int i = 0; i < a.len; i++){
		printf("%d", a.d[a.len - 1 - i]);
		if(i == a.len - a.pos - 1){
			putchar('.');
		}
	}
}

bigf change(char* a){
	bigf b;
	b.len = 0;
	int tmpLen = strlen(a);
	for(int i = 0; i < tmpLen; i++){
		if(a[tmpLen - 1 - i] == '.'){
			b.pos = i;
		}
		else{
			b.d[b.len++] = a[tmpLen - 1 - i] - '0';
		}
	}
//	puts("######");
//	print(b);
//	putchar('\n'); 
//	puts("######");
	return b;
}



bigf add(bigf a, bigf b){
	bigf c;
	if(a.pos > b.pos){
		int x = a.pos - b.pos;
		for(int i = b.len - 1; i >= 0; i--){
			b.d[i + x] = b.d[i];
		}
		for(int i = 0; i < x; i++){
			b.d[i] = 0;
		}
		b.len = b.len + x;
		b.pos = a.pos;
	}
	else if(a.pos < b.pos){
		int x = b.pos - a.pos;
		for(int i = a.len - 1; i >= 0; i--){
			a.d[i + x] = a.d[i];
		}
		for(int i = 0; i < x; i++){
			a.d[i] = 0;
		}
		a.len = a.len + x;
		a.pos = b.pos;		
	}
//	printf("** pos_a = %d, pos_b = %d\n", a.pos, b.pos); 
//	printf("** len_a = %d, len_b = %d\n", a.len, b.len); 
//	print(a);
//	printf("******\n");
//	print(b);
//	printf("******\n");
	int carry = 0;
	for(int i = 0; i < a.len || i < b.len; i++){
		int tmp = a.d[i] + b.d[i] + carry;
		c.d[c.len++] = tmp % 10;
		carry = tmp / 10;
	}
	if(carry != 0){
		c.d[c.len++] = carry;
	} 
	c.pos = a.pos;
	int left = 0;
	while(c.d[left] == 0){
		left++;
	}
	for(int i = 0; i < c.len - left; i++){
		c.d[i] = c.d[i + left];
	}
	c.len -= left;
	c.pos -= left;
	return c;
}



int main(){
	int n;
	scanf("%d", &n);
	while(n--){
		char str1[maxn], str2[maxn];
		scanf("%s%s", str1, str2);
		bigf a = change(str1);
		bigf b = change(str2);
//		printf("pos_a = %d, pos_b = %d\n", a.pos, b.pos); 
//		printf("len_a = %d, len_b = %d\n", a.len, b.len); 
		bigf ans = add(a, b);
		print(ans);
		putchar('\n');
	}
	return 0;
}

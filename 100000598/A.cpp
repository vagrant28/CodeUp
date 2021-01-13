#include <stdio.h>
#include <string.h>
typedef long long LL;
const int maxn = 50;

char s1[maxn], s2[maxn];

void deal(char* a, LL &w, int &e){
	int flag = 1, c = 0;
	if(a[0] == '-'){
		flag = -1;
	}
	int i = (flag == 1) ? 0 : 1;
	w = 0, e = 0;	// c用来计算尾数部分的小数位数 
	for(; a[i]; i++){
		if(a[i] == '.'){
			c = 1;
		}
		else if(a[i] == 'e' || a[i] == 'E'){
			int t;
			sscanf(a + i + 1, "%d", &t);
			e += t;
			break;
		}
		else{
			w = w * 10 + a[i] - '0';
			e -= c;
		}
	}
	w = w * flag;
}

// 为了保证尾数仍是整数，根据指数向低阶靠齐 
void normalize(LL &w, int x){
	while(x){
		w *= 10;
		x--;
	}
}

int main(){
	while(scanf("%s%s", s1, s2) != EOF){
		LL w1, w2;
		int e1, e2;
		deal(s1, w1, e1);
		deal(s2, w2, e2);
		if(e1 > e2){
			normalize(w1, e1 - e2);
			e1 = e2;
		}
		else{
			normalize(w2, e2 - e1);
			e2 = e1;
		}
//		printf("w1 = %lld; e1 = %d\n", w1, e1);
//		printf("w2 = %lld; e2 = %d\n", w2, e2);
		
		LL w = w1 + w2;
		int e = e1;
		if(w == 0){
			printf("0\n");
		}
		else{
			while(w % 10 == 0){
				w /= 10;
				e++;
			}
//			printf("w = %lld; e = %d\n", w, e);
			if(e >= 0){
				printf("%lld", w);
				while(e--){
					printf("0");
				}
				putchar('\n');
			} 
			else{
				char w_str[maxn];
				sprintf(w_str, "%lld", w);
				int len = strlen(w_str), i;
				if(w > 0){
					e = e + len - 1;
					i = 1;
					printf("%c", w_str[0]);
				}
				else{
					e = e + len - 2;
					i = 2;
					printf("-%c", w_str[1]);
				}
				if(w_str[i] != '\0'){
					printf(".");
					int cnt = 0;
					for(; w_str[i] != '\0' && cnt <= 9; i++){
						printf("%c", w_str[i]);
						cnt++;
					}
				}
				printf("e%d\n", e);
			}
		}
	}	
	return 0;
}

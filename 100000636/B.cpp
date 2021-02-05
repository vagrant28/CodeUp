#include <stdio.h>
#include <string.h>
#define lowbit(i) ((i) & (-i))
const int maxn = 30000 + 10;
const int maxa = 100;

int t, n, x, y;
int c[maxn];
char op[20];

void update(int x, int v){
	for(int i = x; i < maxn; i += lowbit(i)){
		c[i] += v;
	}
}

int getSum(int x){
	int sum = 0;
	for(int i = x; i > 0; i -= lowbit(i)){
		sum += c[i];
	}
	return sum;
}

int main(){
	scanf("%d", &t);
	for(int Case = 1; Case <= t; Case++){
		memset(c, 0, sizeof(c));
		printf("Case %d:\n", Case);
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			int tmp;
			scanf("%d", &tmp);
			update(i, tmp);
		}
		while(1){
			scanf("%s", op);
			if(strcmp(op, "End") == 0){
				break;
			}
			else if(strcmp(op, "Add") == 0){
				scanf("%d%d", &x, &y);
				update(x, y);
			}
			else if(strcmp(op, "Sub") == 0){
				scanf("%d%d", &x, &y);
				update(x, -y);
			}
			else if(strcmp(op, "Query") == 0){
				scanf("%d%d", &x, &y);
				printf("%d\n", getSum(y) - getSum(x - 1));
			}
		}
	}
	return 0;
}

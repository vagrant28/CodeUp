#include <stdio.h>
#include <string.h>
const int maxw = 30000 + 10;
const int maxn = 100;

int window[maxw];
int t, n;
char op[20];

int main(){
	scanf("%d", &t);
	for(int c = 1; c <= t; c++){
		printf("Case %d:\n", c);
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			scanf("%d", &window[i]);
		}
		while(1){
			scanf("%s", op);
			int x, y;
			if(strcmp(op, "End") == 0){
				break;
			}
			else if(strcmp(op, "Add") == 0){
				scanf("%d%d", &x, &y);
				window[x] += y;
			}
			else if(strcmp(op, "Sub") == 0){
				scanf("%d%d", &x, &y);
				window[x] -= y;
 			}
			else if(strcmp(op, "Query") == 0){
				scanf("%d%d", &x, &y);
				int sum = 0;
				for(int i = x; i <= y; i++){
					sum += window[i];
				}
				printf("%d\n", sum);
			}
		}
	}
	return 0;
}

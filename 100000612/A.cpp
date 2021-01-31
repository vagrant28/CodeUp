#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
const int maxn = 1010;

int n, d;
int tree[maxn];

int main(){
	while(scanf("%d", &n), n){
		for(int i = 1; i <= n; i++){
			scanf("%d", &tree[i]);
		}
		scanf("%d", &d);
		int h = (int)ceil(log(n + 1) / log(2));
//		printf("h = %d\n", h);
		if(d > h){
			printf("EMPTY\n");
		}
		else{
			int left = pow(2, d - 1);
			int right = pow(2, d) - 1;
//			printf("left = %d, right = %d\n", left, right);
			if(d < h){
//				printf("d < h\n");
				for(int i = left; i < right; i++){
					printf("%d ", tree[i]); 
				}
				printf("%d\n", tree[right]);
			}
			else if(d == h){
//				printf("h == d\n");
				int t = min(n, right);
				if(t == left){
					printf("%d\n", tree[t]);
				}
				else{
					for(int i = left; i < t; i++){
						printf("%d ", tree[i]);
					}
					printf("%d\n", tree[t]);
				}
			}
		}
	}
	return 0;
}

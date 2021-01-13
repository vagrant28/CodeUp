#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
	int n;
	int a[1005];
	while(scanf("%d", &n) != EOF){
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
		}
		sort(a, a+n);
		printf("%d\n", a[n-1]);
		if(n == 1){
			printf("-1\n");
		}
		else{
			for(int i = 0; i < n - 1; i++){
				printf("%d ", a[i]);
			}
			putchar('\n');
		}
	}
	return 0;
}

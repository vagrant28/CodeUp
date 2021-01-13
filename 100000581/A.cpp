#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
	int n;
	int a[150];
	while(scanf("%d", &n) != EOF){
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		for(int i = 0; i < n; i++){
			printf("%d ", a[i]);
		}
		putchar('\n');
	}
	return 0;
}

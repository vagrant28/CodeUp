#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 105;

struct prog{
	int s, e;
}a[maxn];

bool cmp(prog a, prog b){
	if(a.e == b.e)
		return a.s > b.s;
	return a.e < b.e;
}

int main(){
	int n;
	while(scanf("%d", &n), n){
		for(int i = 0; i < n; i++){
			scanf("%d%d", &a[i].s, &a[i].e);
		}
		sort(a, a + n, cmp);
		int cnt = 1;
		int lastE = a[0].e;
		for(int i = 1; i < n; i++){
			if(a[i].s >= lastE){
				cnt++;
				lastE = a[i].e;
//				printf("(%d, %d)\n", a[i].s, a[i].e);
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}

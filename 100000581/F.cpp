#include <stdio.h>
#include <algorithm>
using namespace std;

struct mouse {
	int w;
	char c[15];
}m[150];

bool cmp(mouse a, mouse b){
	return a.w > b.w;
}

int main(){
	int N;
	while(scanf("%d", &N) != EOF){
		for(int i = 0; i < N; i++){
			scanf("%d%s", &m[i].w, m[i].c);
		}
		sort(m, m + N, cmp);
		for(int i = 0; i < N; i++){
			puts(m[i].c);
		}
	} 
	return 0;
}

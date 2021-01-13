#include <stdio.h>
#include <string.h>

int main(){
	int N;
	int dist[100005];
	memset(dist, 0, sizeof(dist));
	scanf("%d", &N);
	int sum = 0, tmp;
	for(int i = 1; i <= N; i++){
		scanf("%d", &tmp);
		sum += tmp;
		dist[i] = dist[i - 1] + tmp;
	}
	int M, s, e;
	scanf("%d", &M);
	while(M--){
		scanf("%d%d", &s, &e);
		if(s > e){
			int tmp = s;
			s = e;
			e = tmp;
		}
		int d1 = dist[e - 1] - dist[s - 1];
		int d2 = sum - d1;
		int d = (d1 < d2) ? d1 : d2; 
		printf("%d\n", d);
 	}
	return 0;
}

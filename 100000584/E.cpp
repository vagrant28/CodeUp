#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 1010;

struct item{
	double j, f, r;
}a[maxn];

bool cmp(item a, item b){
	return a.r < b.r;
}

int main(){
	int M, N;
	while(scanf("%d%d", &M, &N) != EOF){
		if(M == -1 && N == -1){
			break;
		}
		for(int i = 0; i < N; i++){
			scanf("%lf%lf", &a[i].j, &a[i].f);
			a[i].r = a[i].f / a[i].j;
		}
		sort(a, a + N, cmp);
//		for(int i = 0; i < N; i++){
//			printf("%f %f %f\n", a[i].j, a[i].f, a[i].r);
//		}
		double res = M;
		double sum = 0;
		for(int i = 0; i < N; i++){
			if(a[i].f >= res){
				sum += a[i].j * res / a[i].f;
				break;
			}
			else{
				sum += a[i].j;
				res -= a[i].f;
			}
		}
		printf("%.3f\n", sum);
	}
	return 0;
}

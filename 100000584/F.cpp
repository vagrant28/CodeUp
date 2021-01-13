#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 110;
int a[maxn];

int main(){
	int C;
	scanf("%d", &C);
	while(C--){
		int n, V, W;
		scanf("%d%d%d", &n, &V, &W);
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		double sum = 0, avg;
		int i;
		for(i = 0; i < n; i++){
			if(a[i] <= W){
				sum += a[i];
			}
			else{
				avg = (sum + a[i]) / (i + 1);
				if(avg <= W){
					sum += a[i];
				}
				else{
					break;
				}
			}
		}
		if(sum == 0){
			printf("0 0.00\n");
		}
		else{
			int t = (sum / (i * 100) + 0.005) * 100;
			double ans = t / 100.0;
			printf("%d %.2f\n", i * V, ans);
		}
	}
	return 0;
}

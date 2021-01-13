#include <stdio.h>
#include <math.h>
const int maxn = 1010;

struct factor{
	int x, cnt;
}fac[15];

int a[maxn], fNum;

void solve(int x){
	if(x == 1){
		printf("1\n");
	}
	else{
		fNum = 0;
		int h = (int)sqrt(1.0 * x);
		for(int i = 2; i <= h && i <= x; i++){
			if(x % i == 0){
				fac[fNum].x = i;
				fac[fNum].cnt = 0;
				while(x % i == 0){
					fac[fNum].cnt++;
					x /= i;
				}
				fNum++;
			}
		}
		if(x != 1){
			fac[fNum].x = x;
			fac[fNum].cnt = 1;
			fNum++;
		}
//		printf("fNum = %d\n", fNum);
//		for(int i = 0; i < fNum; i++){
//			printf("fac = %d   num = %d\n", fac[i].x, fac[i].cnt);
//		}	
		int ans = 1;
		for(int i = 0; i < fNum; i++){
			ans *= (fac[i].cnt + 1);
		}	
		printf("%d\n", ans);
	}
	return;
}

int main(){
	int N;
	while(scanf("%d", &N), N){
		for(int i = 0; i < N; i++){
			scanf("%d", &a[i]);
		}
		for(int i = 0; i < N; i++){
			solve(a[i]);
		}
	}
	return 0;
}

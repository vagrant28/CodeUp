#include <stdio.h>
#include <algorithm>
#include <math.h>
#define eps 1e-8
using namespace std;

struct station{
	double p;
	int l;
};

int cmp(station a, station b){
	return a.l < b.l;
}

int main(){
	double C, D, avg;
	station a[510];
	int N;
	while(scanf("%lf%lf%lf%d", &C, &D, &avg, &N) != EOF){
		for(int i = 0; i < N; i++){
			scanf("%lf%d", &a[i].p, &a[i].l);
		}
		sort(a, a + N, cmp);
		a[N].l = D;
		a[N].p = 0;
		if(fabs(a[0].l) > eps){
			printf("The maximum travel distance = 0.00\n");
			return 0;
		}
		
		double sum = 0, cur_oil = 0;
		int now = 0, unreachable = 0;
		double maxD = C * avg;
		while(now < N){
			double expect_oil;
			if( (a[now+1].l - a[now].l) > maxD ){
				printf("The maximum travel distance = %.2f\n", a[now].l + maxD);
				unreachable = 1;
				break;
			}
			int min = now;
			for(int i = now + 1; ((a[i].l - a[now].l) <= maxD) && (i <= N); i++){
				if(a[i].p < a[now].p){
					min = i;
					break;
				}
			}
			if(min == now){
            	expect_oil = C;
          	}
            else{
                expect_oil = (a[min].l - a[now].l)/avg;
            }
			double add_oil = 0;
			if(cur_oil < expect_oil){
				add_oil = expect_oil - cur_oil;
			} 
			// 计算油钱
			sum += add_oil * a[now].p;
			// 更新开至下一个途经加油站的油量 
			cur_oil = cur_oil + add_oil - (a[now + 1].l - a[now].l) / avg; 
			now++;
		} 
		if(!unreachable){
			printf("%.2f\n", sum);
		}
	}
	return 0;
}

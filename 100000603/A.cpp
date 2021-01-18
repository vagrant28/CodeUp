#include <stdio.h>
#include <utility>
using namespace std;

int main(){
	int n;
	while(scanf("%d", &n), n){
		double x1, y1, x2, y2, x3, y3;
		while(n--){
			scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
			printf("%.1f %.1f\n", (x1 + x2 + x3) / 3, (y1 + y2 + y3) / 3); 
		}
	}
	return 0;
}

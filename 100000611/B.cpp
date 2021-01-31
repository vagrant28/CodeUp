#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int m, n;

int main(){
	while(scanf("%d%d", &m, &n), m && n){
		int hm = (int)floor(log(m) / log(2)) + 1;
		int hn = (int)floor(log(n) / log(2)) + 1;
//		printf("hm = %d, hn = %d\n", hm, hn);
		int num = pow(2, hn - hm) - 1;
//		printf("num = %d\n", num);
		int left = m * pow(2, hn - hm);
		int right = m;
		for(int i = 1; i <= hn - hm; i++){
			right = 2 * right + 1;
		}
		if(n >= left){
			num = num + min(right, n) - left + 1;
		} 
//		printf("left = %d, right = %d\n", left, right);
		printf("%d\n", num);
	}
	return 0;
}

#include <stdio.h>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
	return a > b;
}

int main(){
	int s[100];
	int a[20][20];
	int m;
	while(scanf("%d", &m) != EOF){
		for(int i = 0; i < m; ++i){
			for(int j = 0; j < m; ++j){
				scanf("%d", &a[i][j]);
			}
		}
		int num = 0;
		for(int i = 0; i < m; i++){
			int sum1 = 0, sum2 = 0;
			for(int j = 0; j < m; j++){
				sum1 += a[i][j];
				sum2 += a[j][i];
			}
			s[num++] = sum1;
			s[num++] = sum2;
		}
		int sum3 = 0, sum4 = 0;
		for(int i = 0; i < m; i++){
			sum3 += a[i][i];
			sum4 += a[i][m - 1 - i];
		}
		s[num++] = sum3;
		s[num++] = sum4;
//		printf("num = %d\n", num);
		sort(s, s + num, cmp);
		for(int i = 0; i < num; i++){
			printf("%d ", s[i]);
		}
		putchar('\n');
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

int month[13][2] = {{0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};

bool isLeap(int y){
	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);	
}

// 通过 (应该可以直接从当年开始计算，这个方法太烦了)
// 注意点是年份也需要补充前导0 
int main(){
	int y1, n;
	while(scanf("%d%d", &y1, &n) != EOF){
		int y2 = 2021, m2 = 1, d2 = 6;
		int days1, days2;
		days1 = (y1-1)*365 + (y1-1)/4 - (y1-1)/100 + (y1-1)/400 + n;
		days2 = (y2-1)*365 + (y2-1)/4 - (y2-1)/100 + (y2-1)/400 + 6;
		int d = days2 - days1;
		int fd = abs(d);
		if(d >= 0){
			while(fd--){
				d2--;
				if(d2 == 0){
					m2--;
					if(m2 == 0){
						y2--;
						m2 = 12;
					}
					d2 = month[m2][isLeap(y2)];
				}
			}
		}
		else{
			while(fd--){
				d2++;
				if(d2 > month[m2][isLeap(y2)]){
					d2 = 1;
					m2++;
					if(m2 > 12){
						y2++;
						m2 = 1;
					}
				}
			}
		}
		printf("%04d-%02d-%02d\n", y2, m2, d2);
	}
	return 0;
}

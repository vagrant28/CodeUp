#include <stdio.h>

int month[13][2] = {{0,0}, {31,31}, {28,29}, {31,31}, {30,30}, {31, 31}, {30,30},
					{31,31}, {31,31}, {30, 30}, {31,31}, {30,30}, {31,31}};
					
bool isLeap(int year){
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main(){
	int time1, y1, m1, d1;
	int time2, y2, m2, d2;
	while(scanf("%d%d", &time1, &time2) != EOF){
		if(time1 > time2){
			int tmp = time1;
			time1 = time2;
			time2 = tmp;
		}
		y1 = time1 / 10000;
		y2 = time2 / 10000;
		m1 = (time1 % 10000) / 100;
		m2 = (time2 % 10000) / 100;
		d1 = time1 % 100;
		d2 = time2 % 100;
		int sum = 0;
		if(y1 == y2){
			if(m1 == m2){
				sum = d2 - d1 + 1;
			}
			else{
				int flag = isLeap(y1);
				sum = month[m1][flag] - d1 + 1 + d2;
				for(int i = m1 + 1; i <= m2 - 1; i++){
					sum += month[i][flag];
				}
			}
		}
		else{
			for(int i = y1 + 1; i <= y2 - 1; i++){
				sum += (isLeap(i)) ? 366 : 365;
			}
			int flag = isLeap(y1);
			sum += month[m1][flag] - d1 + 1;
			for(int i = m1 + 1; i <= 12; i++){
				sum += month[i][flag];
			}
			flag = isLeap(y2);
			for(int i = 1; i <= m2 - 1; i++){
				sum += month[i][flag];
			}
			sum += d2;
		}
		printf("%d\n", sum);
	}
	return 0;
}

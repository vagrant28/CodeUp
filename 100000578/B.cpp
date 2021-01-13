#include <stdio.h>
#include <string.h>

int month[13][2] = {{0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};
char week[10][20] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

bool isLeap(int y){
	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);	
}

int get_month(char* a){
	if(strcmp(a, "January") == 0)			return 1;
	else if(strcmp(a, "February") == 0)		return 2;
	else if(strcmp(a, "March") == 0)		return 3;
	else if(strcmp(a, "April") == 0)		return 4;
	else if(strcmp(a, "May") == 0)			return 5;
	else if(strcmp(a, "June") == 0)			return 6;
	else if(strcmp(a, "July") == 0)			return 7;
	else if(strcmp(a, "August") == 0)		return 8;
	else if(strcmp(a, "September") == 0)	return 9;
	else if(strcmp(a, "October") == 0)		return 10;
	else if(strcmp(a, "November") == 0)		return 11;
	else if(strcmp(a, "December") == 0)		return 12;
}

void swap(int &x, int &y){
	int tmp = x;
	x = y;
	y = tmp;
}

int main(){
	int y1, m1, d1;
	char mon[20];
	while(scanf("%d%s%d", &d1, mon, &y1) != EOF){
		int y2 = 2021, m2 = 1, d2 = 6;	// 2021.1.6ÊÇÖÜÈý 
		int time1, time2 = time2 = y2 * 10000 + m2 * 100 + d2;
		m1 = get_month(mon);
		time1 = y1 * 10000 + m1 * 100 + d1;
		int flag = -1;	//time1 < time2
		if(time1 > time2){
			swap(time1, time2);
			swap(y1, y2);
			swap(m1, m2);
			swap(d1, d2);
			flag = 1;
		}
		int sum = 0;
		while(y1 < y2 || m1 < m2 || d1 < d2){
			d1++;
			if(d1 > month[m1][isLeap(y1)]){
				d1 = 1;
				m1++;
			}
			if(m1 > 12){
				m1 = 1;
				y1++;
			}
			sum++;
		}
		sum = sum * flag;
//		printf("%d\n", sum);
		int ind = ((2 + (sum % 7)) + 7) % 7;
		printf("%s\n", week[ind]);
	}
	return 0;
}

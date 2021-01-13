#include <stdio.h>

int month[13][2] = {{0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};

bool isLeap(int y){
	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);	
}

int main(){
	int y, n;
	while(scanf("%d%d", &y, &n) != EOF){
		int m = 1, n = 1;
		while(n--){
			d++;
			if(d > month[m][isLeap(y)]){
				d = 1;
				m++;
			}
		}
		printf("%d-%2")
	}
	return 0;
}

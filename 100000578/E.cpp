#include <stdio.h>

int month[13][2] = {{0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};

bool isLeap(int y){
	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);	
}

int main(){
	int M;
	int y, m, d, a;
	scanf("%d", &M);
	while(M--){
		scanf("%d%d%d%d", &y, &m, &d, &a);
		while(a--){
			d++;
			if(d > month[m][isLeap(y)]){
				d = 1;
				m++;
				if(m > 12){
					m = 1;
					y++;
				}
			}
		}
		printf("%04d-%02d-%02d\n", y, m, d);
	}
	return 0;
}

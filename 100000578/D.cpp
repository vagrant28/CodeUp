#include <stdio.h>

int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){
	int y, m, d;
	int M;
	scanf("%d", &M);
	while(M--){
		scanf("%d%d%d", &y, &m, &d);
		d++;
		if(d > month[m]){
			m++;
			d = 1;
			if(m > 12){
				m = 1;
				y++;
			}
		}
		printf("%04d-%02d-%02d\n", y, m, d);
	}
	return 0;
}

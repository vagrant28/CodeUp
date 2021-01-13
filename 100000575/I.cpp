#include <stdio.h>

int main(){
	// B>C 
	// C>J 
	// J>B
	int N;
	scanf("%d", &N);
	int a[2][3] = {0};	//C,J,B
	int win = 0, lose = 0, draw = 0;
	while(N--){
		char x, y;
		getchar();
		scanf("%c %c", &x, &y);
//		printf("x = %c; y = %c\n", x, y);
		if(x == y)
			draw++;
		else if(x == 'B' && y == 'C'){
			win++;
			a[0][0]++;
		}
		else if(x == 'C' && y == 'B'){
			lose++;
			a[1][0]++; 
		}
		else if(x == 'C' && y == 'J'){
			win++;
			a[0][1]++;
		}
		else if(x == 'J' && y == 'C'){
			lose++;
			a[1][1]++;
		}
		else if(x == 'J' && y == 'B'){
			win++;
			a[0][2]++;
		}
		else if(x == 'B' && y == 'J'){
			lose++;
			a[1][2]++;
		}
		
	}
	printf("%d %d %d\n", win, draw, lose);
	printf("%d %d %d\n", lose, draw, win);
	if(a[0][0] >= a[0][1] && a[0][0] >= a[0][2])
		printf("B ");
	else if(a[0][1] > a[0][0] && a[0][1]>= a[0][2])
		printf("C ");
	else
		printf("J ");
	if(a[1][0] >= a[1][1] && a[1][0] >= a[1][2])
		printf("B\n");
	else if(a[1][1] > a[1][0] && a[1][1]>= a[1][2])
		printf("C\n");
	else
		printf("J\n");
	return 0;
}

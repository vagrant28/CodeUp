#include <stdio.h>

struct{
	int num;
	char name[20];
	double a, b, c;
}s[10];

int main(){
	double sum_a = 0, sum_b = 0, sum_c = 0;
	double avg = 0, max = 0;
	int index = 0;
	for(int i = 0; i < 10; i++){
		scanf("%d %s %lf %lf %lf", &s[i].num, s[i].name, &s[i].a, &s[i].b, &s[i].c);
		sum_a += s[i].a;
		sum_b += s[i].b;
		sum_c += s[i].c;
		avg = (s[i].a + s[i].b + s[i].c) / 3;
		if(avg > max){
			index = i;
			max = avg;
		}	
	}
	printf("%.2f %.2f %.2f\n", sum_a / 10, sum_b / 10, sum_c / 10);
	printf("%d %s %d %d %d\n", s[index].num, s[index].name, (int)s[index].a, (int)s[index].b, (int)s[index].c);
	return 0;
}

#include <stdio.h>

struct{
	int num;
	char name[20];
	int a, b, c;
}r[5];

void input(){
	for(int i = 0; i < 5; i++){
		scanf("%d %s %d %d %d", &r[i].num, &r[i].name, &r[i].a, &r[i].b, &r[i].c);
	}
}

void print(){
	for(int i = 0; i < 5; i++){
		printf("%d %s %d %d %d\n", r[i].num, r[i].name, r[i].a, r[i].b, r[i].c);
	}
}

int main(){
	input();
	print();
	return 0;
}

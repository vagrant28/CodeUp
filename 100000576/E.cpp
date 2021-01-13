#include <stdio.h>

struct{
	int num;
	char name[100];
	char sex[20];
	int age;
}a[30];

int main(){
	int n, m;
	scanf("%d", &n);
	while(n--){
		scanf("%d", &m);
		for(int i = 0; i < m; i++){
			scanf("%d%s%s%d", &a[i].num, a[i].name, a[i].sex, &a[i].age);
		}
		int x;
		scanf("%d", &x);
		for(int i = 0; i < m; i++){
			if(x == a[i].num){
				printf("%d %s %s %d\n", a[i].num, a[i].name, a[i].sex, a[i].age);
				break;
			}
		}
	}
	return 0;
}

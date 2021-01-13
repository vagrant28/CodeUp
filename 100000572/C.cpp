#include <stdio.h>

struct {
    int num;
    char name[10];
    char sex;
    char job;
    union {
        int Class;
        char position[10];
    }category;
}table[100];

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %s %c %c", &table[i].num, &table[i].name, &table[i].sex, &table[i].job);
		if(table[i].job == 's'){
			scanf("%d", &table[i].category.Class);
		}	
		else{
			scanf("%s", &table[i].category.position);
		}
	}
	for(int i = 0; i < n; i++){
		if(table[i].job == 's')
			printf("%d %s %c %c %d\n", table[i].num, table[i].name, table[i].sex, table[i].job, table[i].category.Class);
		else
			printf("%d %s %c %c %s\n", table[i].num, table[i].name, table[i].sex, table[i].job, table[i].category.position);	
	}
	return 0;	
}

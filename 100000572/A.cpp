#include <stdio.h>
#include <string.h>

struct person{
	char name[20];
	int count;
}leader[3] = {"Li", 0, "Zhang", 0, "Fun", 0};

int main(){
	int n;
	scanf("%d", &n);
	getchar();
	char vote[20];
	for(int i = 0; i < n; i++){
		gets(vote);
		if(strcmp(vote, "Li") == 0){
			leader[0].count++;
		}
		else if(strcmp(vote, "Zhang") == 0){
			leader[1].count++;
		}
		else{
			leader[2].count++;
		}
	}
	for(int i = 0; i < 3; i++){
		printf("%s:%d\n", leader[i].name, leader[i].count);
	}
	return 0;
}

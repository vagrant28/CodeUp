#include <stdio.h>
#include <string.h>

struct{
	char num[100];
	char name[200];
	char sex[10];
	int age;
}r[1010];

int flag[1010];

int main(){
	int N, M;
	while(scanf("%d", &N) != EOF){
		memset(flag, 0, sizeof(flag));
		for(int i = 1; i <= N; i++){
			char num_str[100];
			int tmp;
			scanf("%s", num_str);
			sscanf(num_str, "%d", &tmp);
//			printf("tmp = %d\n", tmp);
			strcpy(r[tmp].num, num_str);
			scanf("%s%s%d", r[tmp].name, r[tmp].sex, &r[tmp].age);
			flag[tmp] = 1;
		}
		scanf("%d", &M);
		while(M--){
			int x;
			scanf("%d", &x);
			if(flag[x] == 0){
				printf("No Answer!\n");
			}
			else{
				printf("%s %s %s %d\n", r[x].num, r[x].name, r[x].sex, r[x].age);
			}
		}
	}
	return 0;
}

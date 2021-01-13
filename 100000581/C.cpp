#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

struct person {
	int id;
	char name[20];
	int score;
}a[100005];

bool cmp1(person a, person b){
	return a.id < b.id;
}

bool cmp2(person a, person b){
	if(strcmp(a.name, b.name) == 0)
		return a.id < b.id;
	return strcmp(a.name, b.name) < 0;
}

bool cmp3(person a, person b){
	if(a.score == b.score)
		return a.id < b.id;
	return a.score < b.score;
}

int main(){
	int Case = 1;
	int N, C;
	while(scanf("%d%d", &N, &C), N){
		for(int i = 0; i < N; i++){
			scanf("%d%s%d", &a[i].id, a[i].name, &a[i].score);
		}
		if(C == 1){
			sort(a, a + N, cmp1);
		}
		else if(C == 2){
			sort(a, a + N, cmp2);
		}
		else if(C == 3){
			sort(a, a + N, cmp3);
		}
		printf("Case %d:\n", Case++);
		for(int i = 0; i < N; i++){
			printf("%06d %s %d\n", a[i].id, a[i].name, a[i].score);
		}
	}
	return 0;
}

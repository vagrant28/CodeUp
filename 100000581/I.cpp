#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

struct person{
	char id[30];
	int score;
}a[1005];

bool cmp(person a, person b){
	if(a.score == b.score)
		return strcmp(a.id, b.id) < 0;
	return a.score > b.score;
}

int main(){
	int N;
	int value[15];
	while(scanf("%d", &N), N){
//		printf("N = %d\n", N);
		int M, G;
		scanf("%d%d", &M, &G);
		for(int i = 1; i <= M; i++){
			scanf("%d", &value[i]);
		}
		int num = 0;
		for(int i = 0; i < N; i++){
			int count;
			scanf("%s%d", a[num].id, &count);
			int sum = 0;
			while(count--){
				int tmp;
				scanf("%d", &tmp);
				sum += value[tmp];
			}
			a[num].score = sum; 
			num++;
		}
		sort(a, a + N, cmp);
		int amount = 0;
		while(a[amount].score >= G){
			amount++;
		}
		printf("%d\n", amount);
		for(int i = 0; i < amount; i++){
			printf("%s %d\n", a[i].id, a[i].score);
		}
	}
	return 0;
}

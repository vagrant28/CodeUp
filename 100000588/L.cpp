#include <stdio.h>

int main(){
	bool isRelevant[120] = {false};
	isRelevant[7] = {true};
	for(int i = 10; i <= 99; i++){
		if( (i % 7 == 0) || (i / 10 == 7 || i % 10 == 7)){
			isRelevant[i] = true;
		}
	}
//	for(int i = 0; i < 100; i++){
//		if(isRelevant[i]){
//			printf("%d ", i);
//		}
//	}
//	putchar('\n');
	int n;
	while(scanf("%d", &n) != EOF){
		int ans = 0;
		for(int i = 1; i <= n; i++){
			if(!isRelevant[i]){
				ans += i * i;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
	
}

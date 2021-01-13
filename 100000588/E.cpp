#include <stdio.h>

int main(){
	int tmp;
	while(scanf("%d", &tmp) != EOF){
		int a[15] = {0};
		a[tmp]++;
		for(int i = 1; i <= 19; i++){
			scanf("%d", &tmp);
			a[tmp]++;
		}
		int index = 1;
		int max = a[1];
		for(int i = 2; i <= 10; i++){
			if(a[i] > max){
				max = a[i];
				index = i;
			}
		}
		printf("%d\n", index);
	}
	return 0;
}

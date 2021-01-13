#include <stdio.h>

int main(){
	int A[2][3];
	int B[3][2];
	int tmp;
	while(scanf("%d", &tmp) != EOF){
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 3; j++){
				if(i == 0 && j == 0){
					A[i][j] = tmp;
				}
				else{
					scanf("%d", &A[i][j]);
				}
			}
		}
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 2; j++){
				scanf("%d", &B[i][j]);
			}
		}
		int ans[2][2] = {0};
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 2; j++){
				for(int k = 0; k < 3; k++){
					ans[i][j] += A[i][k] * B[k][j];
				}
			}
		}
		printf("%d %d\n", ans[0][0], ans[0][1]);
		printf("%d %d\n", ans[1][0], ans[1][1]);
	}
	return 0;
}

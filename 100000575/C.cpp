#include <stdio.h>
#include <string.h>

int main(){
	char strA[15], strB[15];
	int A[15], B[15];
	while(scanf("%s%s", strA, strB) != EOF){
		int lenA = strlen(strA);
		int lenB = strlen(strB);
		for(int i = 0; i < lenA; i++){
			A[i] = strA[i] - '0';
		}
		for(int i = 0; i < lenB; i++){
			B[i] = strB[i] - '0';
		}
		int sum = 0;
		for(int i = 0; i < lenA; i++){
			for(int j = 0; j < lenB; j++){
				sum += A[i] * B[j];
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}

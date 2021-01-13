#include <stdio.h>

int main(){
	char A[100], B[100];
	int m;
	scanf("%d", &m);
	while(m--){
		scanf("%s%s", A, B);
		int i = 0;
		while(1){
			if(A[i] == '\0' && B[i] == '\0'){
				printf("%s is equal long to %s\n", A, B);
				break;
			}
			else if(A[i] == '\0' && B[i] != '\0'){
				printf("%s is shorter than %s\n", A, B);
				break;
			}
			else if(A[i] != '\0' && B[i] == '\0'){
				printf("%s is longer than %s\n", A, B);
				break;
			}
			else{
				i++;
			}
		}
	}
	return 0;
}

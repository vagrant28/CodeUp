#include <stdio.h>
#include <string.h>
typedef long long LL;

int main(){
	char strA[15], strB[15];
	while(scanf("%s%s", strA, strB) != EOF){
		LL A = 0, B = 0;
		int lenA = strlen(strA);
		int lenB = strlen(strB);
		int flag = 1;
		for(int i = 0; i < lenA; i++){
			if(strA[i] == '-'){
				flag = -1;
				continue;
			}
			else if(strA[i] == ','){
				continue;
			}
			else{
				A = A * 10 + strA[i] - '0';
			}
		}
		A = A * flag;
		flag = 1;
		for(int i = 0; i < lenB; i++){
			if(strB[i] == '-'){
				flag = -1;
				continue;
			}
			else if(strB[i] == ','){
				continue;
			}
			else{
				B = B * 10 + strB[i] - '0';
			}
		}
		B = B * flag;
		printf("%lld\n", A + B);
	}
	return 0;
}

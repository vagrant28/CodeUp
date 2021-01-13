#include <stdio.h>
typedef long long LL;

int main(){
	int n;
	scanf("%d", &n);
	int case_num = 1;
	while(n--){
		LL A, B, C;
		scanf("%lld%lld%lld", &A, &B, &C);
		if(A + B > C)
			printf("Case #%d: true\n", case_num);
		else
			printf("Case #%d: false\n", case_num);
		case_num++;
	}
	return 0;
} 

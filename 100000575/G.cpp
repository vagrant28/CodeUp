#include <stdio.h>

int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		int tmp;
		int a[6] = {0};
		int A1 = 0, A2 = 0, A3 = 0, A5 = -1;
		double A4 = 0;
		int flag = -1;
		while(n--){
			scanf("%d", &tmp);
			switch(tmp % 5){
				case 0:
					if(tmp % 2 == 0){
						A1 += tmp;
						a[1]++;
					}
					break;
				case 1:
					flag *= -1;
					A2 = A2 + flag * tmp;
					a[2]++;
					break;
				case 2:
					A3++;
					a[3]++;
					break;
				case 3:
					A4 += tmp;
					a[4]++;
					break;
				case 4:
					a[5]++;
					if(tmp > A5)
						A5 = tmp;
					break;
			} 
		}
		if(a[1])
			printf("%d ", A1);
		else
			printf("N ");
		if(a[2])
			printf("%d ", A2);
		else
			printf("N ");
		if(a[3])
			printf("%d ", A3);
		else
			printf("N ");
		if(a[4])
			printf("%.1f ", A4 / a[4]);
		else
			printf("N ");
		if(a[5])
			printf("%d\n", A5);
		else
			printf("N\n");
	}
	return 0;
}

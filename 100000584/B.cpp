#include <stdio.h>

int flag;
double cal(int d){
	printf("#");
	if(d <= 4){
		return 10;
	}
	else if(d <= 8){
		return 10 + 2 * (d - 4);
	}
	else if(d <= 12){
		flag = 1;
		return 18 + 2.4 * (d - 8);
	}
	else{
		int t = d / 8 - 1;
		return 18 * t + cal(d - 8 * t);
	}
}

int main(){
	int n;
	while(scanf("%d", &n), n){
		flag = 0;
//		double ans = cal(n);
		
		double ans = 0;
		int flag = 0;
		while(n > 0){
			if(n <= 4){
				ans += 10;
				break;
			}
			else if(n <= 8){
				ans += 10 + 2 * (n - 4);
				break;
			}
			else if(n <= 12){
				flag = 1;
				ans += 18 + 2.4 * (n - 8);
				break;
			} 
			else{
				ans += 18;
				n -= 8;
			}
		}
		if(flag){
			printf("%.1f\n", ans);
		}
		else{
			printf("%d\n", (int)ans);
		}
	}
	return 0;
}

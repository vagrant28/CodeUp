#include <stdio.h>

bool isReverse(int x){
	int y = x * 9;
	int t = 0;
	while(y != 0){
		t = t * 10 + y % 10;
		y /= 10;
	}
	if(t == x){
		return true;
	}else{
		return false;
	}
}

int main(){
	int num = 0;
	int ans[200];
	for(int i = 1000; i <= 1111; i++){
		if(isReverse(i)){
			ans[num++] = i;
		}
	}
	for(int i = 0; i < num; i++){
		printf("%d\n", ans[i]);
	}
	return 0;
}

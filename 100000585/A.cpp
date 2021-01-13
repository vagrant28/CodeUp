#include <stdio.h>
const int maxn = 210;

int n;
int a[maxn];

int BinarySearch(int left, int right, int x){
	while(left <= right){
		int mid = (left + right) / 2;
		if(a[mid] == x){
			return mid;
		}
		else if(a[mid] < x){
			left = mid + 1;
		}
		else{
			right = mid - 1;
		}
	}
	return -1;
}

int main(){
	while(scanf("%d", &n) != EOF){
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
		}
		int x;
		scanf("%d", &x);
		int ans = BinarySearch(0, n - 1, x);
		printf("%d\n", ans);
	}
	return 0;
}

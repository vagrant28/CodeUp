#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn = 110;
int n, m;
int a[maxn], b[maxn];

int BinarySearch(int left, int right, int x){
	while(left <= right){
		int mid = (left + right) / 2;
		if(a[mid] == x){
			return mid;
		}
		if(a[mid] > x){
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}
	return -1;
}

int main(){
	while(scanf("%d", &n) != EOF){
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		scanf("%d", &m);
		for(int i = 0; i < m; i++){
			scanf("%d", &b[i]);
		}
		for(int i = 0; i < m; i++){
			int flag = BinarySearch(0, n - 1, b[i]);
			if(flag != -1){
				puts("YES");
			}
			else{
				puts("NO");
			}
		}
		
		
	}
	return 0;
}

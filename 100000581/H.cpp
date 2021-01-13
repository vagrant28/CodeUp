#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
	int a[15];
	int odd[15], even[15];
	while(scanf("%d%d%d%d%d%d%d%d%d%d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6], &a[7], &a[8], &a[9]) != EOF){
		int no = 0, ne = 0;
		for(int i = 0; i < 10; i++){
			if(a[i] % 2 == 1){
				odd[no++] = a[i];
			}
			else{
				even[ne++] = a[i];
			}
		}
		sort(odd, odd + no);
		sort(even, even + ne);
		for(int i = no - 1; i >= 0; i--){
			printf("%d ", odd[i]);
		}
		for(int i = 0; i < ne; i++){
			printf("%d ", even[i]);
		}
		putchar('\n');
	}
	return 0;
}

#include <stdio.h>
#include <algorithm>
using namespace std;
const int INF = 1e6 + 10;

int main(){
	int n, maxN, minN;
	while(scanf("%d", &n) != EOF){
		maxN = -INF, minN = INF;
		while(n--){
			int tmp;
			scanf("%d", &tmp);
			if(tmp > maxN){
				maxN = tmp;
			}
			if(tmp < minN){
				minN = tmp;
			}
		} 
		printf("%d %d\n", maxN, minN);
	}
	return 0;
}

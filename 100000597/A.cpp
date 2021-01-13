#include <stdio.h>
#include <set>
using namespace std;
const int maxN = 50 + 10;

double calSim(int x, int y, set<int> a[]){
	set<int>::iterator it_x = a[x].begin();
	set<int>::iterator it_y = a[y].begin();
	int same = 0;
	while(it_x != a[x].end() && it_y != a[y].end()){
		if(*it_x == *it_y){
			same++;
			it_x++;
			it_y++;
		}
		else if(*it_x < *it_y){
			it_x++;
		}
		else{
			it_y++;
		}
	}
	int diff = a[x].size() + a[y].size() - same;
//	printf("same = %d; diff = %d\n", same, diff);
	double ans = same * 1.0 / diff;
	return ans;
}


int main(){
	int N;
	while(scanf("%d", &N) != EOF){
		set<int> a[maxN];
		for(int i = 1; i <= N; i++){
			int M, tmp;
			scanf("%d", &M);
			while(M--){
				scanf("%d", &tmp);
				a[i].insert(tmp);
			}
		}
		int K, x, y;
		scanf("%d", &K);
		while(K--){
			scanf("%d%d", &x, &y);
			double ans = calSim(x, y, a);
			printf("%.1f%%\n", ans * 100);
		}
	}
	return 0;
}

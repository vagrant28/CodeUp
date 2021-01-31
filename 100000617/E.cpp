#include <queue>
#include <vector>
#include <stdio.h>
using namespace std;

int main(){
	int n;
	
	while(scanf("%d", &n) != EOF){
		priority_queue<int, vector<int>, greater<int> > q;
		int tmp;
		for(int i = 0; i < n; i++){
			scanf("%d", &tmp);
			q.push(tmp);
		}
		int a, b, sum = 0;
		while(q.size() > 1){
			a = q.top();
			q.pop();
			b = q.top();
			q.pop();
			sum = sum + a + b;
			q.push(a + b);
		}
		printf("%d\n", sum);
	}
	return 0;
}

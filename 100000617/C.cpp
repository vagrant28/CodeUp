#include <stdio.h>
#include <queue>
using namespace std;

int n; 
priority_queue<int, vector<int>, greater<int> > q;

int main(){
	while(scanf("%d", &n) != EOF){
		while(!q.empty()){
			q.pop();
		}
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

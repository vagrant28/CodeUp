#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
const int maxX = 5000000 + 10;

int n, k, cnt;
bool notPrime[maxX];
vector<int> prime;
vector<int> a;

void findPrime(){
	for(int i = 2; i < maxX; i++){
		if(notPrime[i] == false){
			prime.push_back(i);
			for(int j = i + i; j < maxX; j += i){
				notPrime[j] = true;
			}
		}
	}
}

void show(){
	for(int i = 0; i < prime.size(); i++){
		printf("%d ", prime[i]);
	}
}

bool isPrime(int x){
	for(int i = 2; i * i <= x; i++){
		if(x % i == 0){
			return false;
		}
	}
	return true;
}

// 打表会判定“运行错误” 
void dfs(int index, int nowK, int sum){
	if(nowK == k && isPrime(sum)){
		cnt++;
		return;
	}
	if(index == n || nowK > k){
		return;
	}
	dfs(index + 1, nowK, sum);
	dfs(index + 1, nowK + 1, sum + a[index]);
}


int main(){
//	memset(notPrime, 0, sizeof(notPrime));
//	findPrime();
//	show();
//	printf("%d\n", prime.size());
	while(scanf("%d%d", &n, &k) != EOF){
		for(int i = 0; i < n; i++){
			int t;
			scanf("%d", &t);
			a.push_back(t);
		}
//		for(int i = 0; i < a.size(); i++){
//			printf("%d ", a[i]);
//		}
//		putchar('\n');
		cnt = 0;
		dfs(0, 0, 0);
		printf("%d\n", cnt);
	}
	return 0;
}

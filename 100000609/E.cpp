#include <stdio.h>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

struct node{
	int a, b, c;
	int hashV;
	node(){}
	node(int _a, int _b, int _c){
		a = _a, b = _b, c = _c;
		hashV = a * 1000000 + b * 1000 + c;
	}
};


int a, b, c;
int Ca, Cb, Cc, k;
int cnt;

int HASH(node N){
	return N.a * 1000000 + N.b * 1000 + N.c;
}

int gcd(int a, int b){
	if(b == 0){
		return a;
	}
	else{
		return gcd(b, a % b);
	}
}

void pour(int &a, int &b, int Cb){ // a->b
	if(a >= Cb - b){
		a = a - (Cb - b);
		b = Cb;
	}
	else{
		b = b + a;
		a = 0;
	}
	return;
}

void print(node N){
	printf("a = %d\tb = %d\tc = %d\t hashV = %d\n", N.a, N.b, N.c, N.hashV);
	return;
}

void bfs(){
	queue<node> q;
	map<int, bool> mp;
	cnt = 0;
	
	node cur = node(a, b, c);
	q.push(cur);
	mp[cur.hashV] = true;
	
	while(!q.empty()){
		int num = q.size();
		cnt++;
		while(num--){
			cur = q.front();
//			printf("cnt:%d  ", cnt);
//			print(cur);
			q.pop();
			for(int i = 1; i <= 6; i++){
				node tmp = cur;
				if(i == 1){ // A->B
					pour(tmp.a, tmp.b, Cb);
				}
				else if(i == 2){ // A->C
					pour(tmp.a, tmp.c, Cc);
				}
				else if(i == 3){ // B->A
					pour(tmp.b, tmp.a, Ca);
				}
				else if(i == 4){ // B->C
					pour(tmp.b, tmp.c, Cc);
				}
				else if(i == 5){ // C->A
					pour(tmp.c, tmp.a, Ca);
				}
				else if(i == 6){ // C->B
					pour(tmp.c, tmp.b, Cb);
				}
				tmp.hashV = HASH(tmp);
				if(mp[tmp.hashV] == false){
					q.push(tmp);
					mp[tmp.hashV] = true;
					if(tmp.a == k || tmp.b == k || tmp.c == k){
						printf("yes\n");
						printf("%d\n", cnt);
						return;
					}
				}
			}
		}
	}	
	printf("no\n");
	return;
}

int main(){
	while(scanf("%d%d%d%d", &Ca, &Cb, &Cc, &k) != EOF){
		int g = gcd(gcd(Ca, Cb), Cc);
//		printf("g = %d\n", g);
//		printf("%d %% %d = %d\n", k, g, k % g);
//		printf("%d\n", max((Ca, Cb), Cc));
		if(k % g != 0 || k > max(max(Ca, Cb), Cc)){
			printf("**no\n");
			continue;
		}
		else if(Ca == k){
			printf("yes\n");
			printf("0\n");
			continue;
		} 
		a = Ca, b = 0, c = 0;
		bfs();
	}
	return 0;
}

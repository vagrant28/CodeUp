#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define lowbit(i) ((i) & (-i))
const int maxn = 1e5 + 10;

struct node{
	int value;
	int pos;
}temp[maxn];

char str[maxn];
int num;
int A[maxn], c[maxn];

bool cmp(node a, node b){
	return a.value > b.value;
}

void update(int x, int v){
	for(int i = x; i < maxn; i += lowbit(i)){
		c[i] += v;
	}
}

int getSum(int x){
	int sum = 0;
	for(int i = x; i > 0; i -= lowbit(i)){
		sum += c[i];
	}
	return sum;
}

int main(){
	while(scanf("%[^\n]", str) != EOF){
		getchar();
		int len = strlen(str);
		int tmp = 0, num = 0;
		for(int i = 0; i <= len; i++){
			if(str[i] >= '0' && tmp <= '9'){
				tmp = tmp * 10 + str[i] - '0';
			}
			else{
				temp[num].value = tmp;
				temp[num].pos = num;
				num++;
				tmp = 0;
			}
		}
//		for(int i = 0; i < num; i++){
//			printf("id=%d, v=%d, p=%d\n", i, temp[i].value, temp[i].pos);
//		}
		sort(temp, temp + num, cmp);
		for(int i = 0; i < num; i++){
			if(i == 0 || temp[i].value != temp[i - 1].value){
				A[temp[i].pos] = i + 1;
			}
			else{
				A[temp[i].pos] = temp[i - 1].pos;
			}
		}
		long long sum = 0;
		memset(c, 0, sizeof(c));
		for(int i = 0; i < num; i++){
			update(A[i], 1);
			sum += getSum(A[i] - 1);	
		}
		printf("%lld\n", sum);
	}
	return 0;
}

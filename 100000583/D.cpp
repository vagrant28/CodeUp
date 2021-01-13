#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ans[100][10];
int HashTable[10];
int num = 1;
int P[10];

void generateP(int index){
	if(index == 8 + 1){
		for(int i = 1; i <= 8; i++){
//			printf("%d", P[i]);
			ans[num][i] = P[i];
		}
//		putchar('\n');
		num++;
		return;
	}
	// index是待选列 
	for(int i = 1; i <= 8; i++){	// 遍历可选行 
		if(!HashTable[i]){
			int flag = 1;
			for(int j = 1; j < index; j++){	// 遍历已选列 
				if(abs(index - j) == abs(i - P[j])){
					flag = 0;
					break;
				}
			}
			if(flag){
				P[index] = i;
				HashTable[i] = 1;
				generateP(index + 1);
				HashTable[i] = 0;
			}
		}
	}
}

void cal(){
	memset(HashTable, 0, sizeof(HashTable));
	generateP(1);
}

int main(){
	cal();
	int n;
	scanf("%d", &n);
	while(n--){
		int tmp;
		scanf("%d", &tmp);
		for(int i = 1; i <= 8; i++){
			printf("%d", ans[tmp][i]);
		}
		putchar('\n');
	}
	return 0;
}

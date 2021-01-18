#include <stdio.h>

int main(){
	int a[10];
	for(int i = 0; i < 10; i++){
		scanf("%d", &a[i]);
	}
	int min = a[0], index;
	for(int i = 0; i < 10; i++){
		if(a[i] < min){
			min = a[i];
			index= i;
		}
	}
	int tmp = a[0];
	a[0] = a[index];
	a[index] = tmp;
	
	int max = 0;
	for(int i = 0; i < 10; i++){
		if(a[i] > max){
			max = a[i];
			index = i;
		}
	}
	tmp = a[9];
	a[9] = a[index];
	a[index] = tmp;
	
	for(int i = 0; i < 10; i++){
		printf("%d ", a[i]);
	}
	return 0;
}


// ´íÎó×ö·¨ 

//#include <stdio.h>
//int a[10], max, min, max_index, min_index;
//
//bool input(){
//	int tmp;
//	if(scanf("%d", &tmp) == EOF){
//		return false;	
//	}
//	else{
//		a[0] = tmp;
//		max = min = tmp;
//		max_index = min_index = 0;
////		printf("%d %d %d %d\n", max, min, max_index, min_index);
//		for(int i = 1; i < 10; i++){
//			scanf("%d", &a[i]);
//			if(a[i] > max){
//				max = a[i];
//				max_index = i;
//			}
//			if(a[i] < min){
//				min = a[i];
//				min_index = i;
//			}
//		}
////		printf("%d %d %d %d\n", max, min, max_index, min_index);
//		return true;
//	}
//}
//
//void swap(int x, int y){
//	int tmp = a[x];
//	a[x] = a[y];
//	a[y] = tmp;
//}
//
//void process(){
//	if(min_index == 9 && max_index == 0){
//		swap(0, 9);
//	}
//	else{
//		swap(0, min_index);
//		swap(9, max_index);
//	}
//}
//
//void print(){
//	for(int i = 0; i < 10; i++){
//		printf("%d ", a[i]);
//	}
//	putchar('\n');
//}
//
//int main(){
//	while(input()){
//		process();
//		print();
//	}
//	return 0;
//}

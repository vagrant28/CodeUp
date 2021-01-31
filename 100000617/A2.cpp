#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct node{
	int w, parent, lchild, rchild;
	node(){}
	node(int _w, int _parent, int _lchild, int _rchild){
		w = _w;
		parent = _parent;
		lchild = _lchild;
		rchild = _rchild;
	}
};

vector<node> HuffmanTree;
vector<string> HuffmanCode; 

void findMinTwo(int &min1, int &min2){
	int i = 0;
	while(HuffmanTree[i].parent != 0){
		i++;
	}
	min1 = i++;
	while(HuffmanTree[i].parent != 0){
		i++;
	}
	min2 = i++;
//	printf("##min1=%d\tmin2=%d\n", min1, min2);
	for(; i < HuffmanTree.size(); i++){
		if(HuffmanTree[i].parent == 0 && HuffmanTree[i].w < max(HuffmanTree[min1].w, HuffmanTree[min2].w)){
			if(HuffmanTree[min1].w != HuffmanTree[min2].w){
				(HuffmanTree[min1].w > HuffmanTree[min2].w ? min1 : min2) = i;
			}
			else{
				(min1 > min2 ? min1 : min2) = i;
			}
		}
	}
	if(min1 > min2){
		swap(min1, min2); 
	}
}


void print(){
	for(int i = 0; i < HuffmanTree.size(); i++){
		printf("i=%d\tw=%d\tparent=%d\tlchid=%d\trchild=%d\n", i, HuffmanTree[i].w, HuffmanTree[i].parent, HuffmanTree[i].lchild, HuffmanTree[i].rchild);
	}
}

int main(){
	int n, input, min1, min2;
	while(cin >> n){
		if(n == 1){
			scanf("%d", &input);
			printf("1\n");
			continue;
		}
		HuffmanTree.clear();
		HuffmanCode.clear();
		for(int i = 0; i < n; i++){
			scanf("%d", &input);
			node tmp = node(input, 0, 0, 0);
			HuffmanTree.push_back(tmp);
		}
//		print();
//		printf("hello\n");
		for(int i = n; i < 2 * n - 1; i++){
			findMinTwo(min1, min2);
//			printf("min1=%d\tmin2=%d\n", min1, min2);
			node tmp = node(HuffmanTree[min1].w + HuffmanTree[min2].w, 0, min1, min2);
			HuffmanTree.push_back(tmp);
			HuffmanTree[min1].parent = HuffmanTree[min2].parent = i;
		}
//		print();
//		printf("hello\n");
		for(int i = 0; i < n; i++){
			int p = i;
			string temp;
			do{
				temp += (p == HuffmanTree[HuffmanTree[p].parent].lchild ? "0" : "1");
				p = HuffmanTree[p].parent;
			}while(p != HuffmanTree.size() - 1);
			reverse(temp.begin(), temp.end());
			HuffmanCode.push_back(temp);
		}
//		printf("hello\n");
		for(int i = 0; i < n; i++){
			cout << HuffmanCode[i] << endl;
		}
	}
	return 0;
}

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
	int i = 1;
	while(HuffmanTree[i].parent != 0){
		i++;
	}
	min1 = i++;
	while(HuffmanTree[i].parent != 0){
		i++;
	}
	min2 = i++;
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

void print(node tmp){
	printf("tmp: w=%d, parent=%d, lchild=%d, rchild=%d\n", tmp.w, tmp.parent, tmp.lchild, tmp.rchild);
}

void p(){
	for(int i = 0; i < HuffmanTree.size(); i++){
		printf("i=%d, w=%d, parent=%d, lchild=%d, rchild=%d\n", i, HuffmanTree[i].w, HuffmanTree[i].parent, HuffmanTree[i].lchild, HuffmanTree[i].rchild);
	}
	printf("\n\n");
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
		HuffmanCode.resize(n + 1);   // 这步申请空间非常重要，不能少 
		node tmp = node(0, 0, 0, 0);
		HuffmanTree.push_back(tmp);
		for(int i = 1; i <= n; i++){
			scanf("%d", &input);
			tmp = node(input, 0, 0, 0);
			HuffmanTree.push_back(tmp);
		}
//		printf("hi\n");
		for(int i = n + 1; i <= 2 * n - 1; i++){
//			printf("enter\n");
			findMinTwo(min1, min2);
//			printf("min1=%d, min2=%d\n", min1, min2);
			HuffmanTree[min1].parent = HuffmanTree[min2].parent = i;
			tmp = node(HuffmanTree[min1].w + HuffmanTree[min2].w, 0, min1, min2);
//			print(tmp);
			HuffmanTree.push_back(tmp);
//			printf("end\n");
		}
//		printf("hello\n");
//		for(int i = 0; i <= 2 * n - 1; i++){
//			printf("i=%d, w=%d, parent=%d, lchild=%d, rchild=%d\n", i, HuffmanTree[i].w, HuffmanTree[i].parent, HuffmanTree[i].lchild, HuffmanTree[i].rchild);
//		}
		for(int i = 1; i <= 2 * n - 1; i++){
			HuffmanTree[i].w = 0;
		}
		int c = 2 * n - 1;
		string temp;
		while(c){
//			printf("enter c=%d\n", c);
			if(HuffmanTree[c].w == 0){
				HuffmanTree[c].w = 1;
				if(HuffmanTree[c].lchild != 0){
					c = HuffmanTree[c].lchild;
					temp += "0";
				}
				else if(HuffmanTree[c].rchild == 0){
					HuffmanCode[c] = temp;	
				}
			}
			else if(HuffmanTree[c].w == 1){
				HuffmanTree[c].w = 2;
				if(HuffmanTree[c].rchild != 0){
					c = HuffmanTree[c].rchild;
					temp += "1";
				}
			}
			else{
				HuffmanTree[c].w = 0;
				c = HuffmanTree[c].parent;
				temp = temp.substr(0, temp.size() - 1);
			}
//			p();
		}
		for(int i = 1; i <= n; i++){
			cout << HuffmanCode[i] << endl;
		}
	}
	return 0;
} 

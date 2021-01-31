#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct node{
	char data;
	int w, parent, lchild, rchild;
	node(){}
	node(char _data, int _w, int _parent, int _lchild, int _rchild){
		data = _data;
		w = _w;
		parent = _parent;
		lchild = _lchild;
		rchild = _rchild;
	}
};

int n;
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
	for(; i < HuffmanTree.size(); i++){
		if(HuffmanTree[i].parent == 0 && HuffmanTree[i].w < max(HuffmanTree[min1].w, HuffmanTree[min2].w)){
			if(HuffmanTree[min1].w != HuffmanTree[min2].w){
				(HuffmanTree[min1].w > HuffmanTree[i].w ? min1 : min2) = i;
			}
			else{
				(min1 > min2 ? min1 : min2) = i;
			}
		}
	}
	if(HuffmanTree[min1].data >= HuffmanTree[min2].data){
		swap(min1, min2);
	}
}

void print(){
	for(int i = 0; i < HuffmanTree.size(); i++){
		cout << HuffmanTree[i].data << " ";
		cout << HuffmanTree[i].w << " ";
		cout << HuffmanTree[i].parent << " ";
		cout << HuffmanTree[i].lchild << " ";
		cout << HuffmanTree[i].rchild << endl;
	}
}

int main(){
	while(cin >> n){
		char c;
		int d;
		if(n == 1){
			getchar();
			scanf("%c%d", &c, &d);
			cout << c << ":" << "1" << endl;
			continue;
		}
		HuffmanTree.clear();
		HuffmanCode.clear();
		for(int i = 0; i < n; i++){
			getchar();
			scanf("%c%d", &c, &d);
			node tmp = node(c, d, 0, 0, 0);
			HuffmanTree.push_back(tmp);
		}
//		print();
		int min1, min2;
		for(int i = n; i < 2 * n - 1; i++){
			findMinTwo(min1, min2);
			node tmp = node(HuffmanTree[min1].data, HuffmanTree[min1].w + HuffmanTree[min2].w, 0, min1, min2);
			HuffmanTree.push_back(tmp);
			HuffmanTree[min1].parent = HuffmanTree[min2].parent = i;
		}
//		print();
		for(int i = 0; i < n; i++){
			string temp;
			int p = i;
			do{
				temp += (p == HuffmanTree[HuffmanTree[p].parent].lchild ? "0" : "1");
				p = HuffmanTree[p].parent;
			}while(p != HuffmanTree.size() - 1);
			reverse(temp.begin(), temp.end());
			HuffmanCode.push_back(temp);
		}
		for(int i = 0; i < n; i++){
			cout << HuffmanTree[i].data << ":" << HuffmanCode[i] << endl;
		}
		
	}
	return 0;
}

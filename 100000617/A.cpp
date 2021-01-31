#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Node {
	int w, parent, lchild, rchild;
	Node(){}
	Node(int _w, int _parent, int _lchild, int _rchild){
		w = _w;
		parent = _parent;
		lchild = _lchild;
		rchild = _rchild; 
	}
};

void findMinTwo(vector<Node> &huffman, int &min1, int &min2) {
	int i = 0, w1, w2;
	while (huffman[i].parent != 0){
		i++;
	}
	min1 = i++;
	while (huffman[i].parent != 0){
		i++;
	}
	min2 = i++;
	for ( ; i < huffman.size(); ++i) { 
		if (huffman[i].parent == 0 && huffman[i].w < max(huffman[min1].w, huffman[min2].w)) { 
			if (huffman[min1].w != huffman[min2].w){
				(huffman[min1].w > huffman[min2].w ? min1 : min2) = i;
			}
			else{
				(min1 > min2 ? min1 : min2) = i; 
			}
		}
	}
	if (min1 > min2)
		swap(min1, min2);
} 

int main() {
	int n, input, min1, min2;
	vector<Node> huffmanTree;
	vector<string> huffmanCode;
	while (scanf("%d", &n) != EOF) {
		// 如果只有一个字符需要编码，则直接输出 1 
		if (n == 1) {
			scanf("%d", &input);
			printf("1\n");
			continue;
		} 
		huffmanTree.clear();
		huffmanCode.clear();
		for (int i = 0; i < n; ++i) {
			scanf("%d", &input);
			Node tmp = Node(input, 0, 0, 0);
			huffmanTree.push_back(tmp);
		}
		for (int i = n; i < 2 * n - 1; ++i) {
			findMinTwo(huffmanTree, min1, min2);
			huffmanTree[min1].parent = huffmanTree[min2].parent = i;
			Node tmp = Node(huffmanTree[min1].w + huffmanTree[min2].w, 0, min1, min2);
			huffmanTree.push_back(tmp);
		}
		for (int i = 0; i < n; ++i) {
			string temp;
			int p = i;
			do {
				temp += (huffmanTree[huffmanTree[p].parent].lchild == p ? "0" : "1");
				p = huffmanTree[p].parent;
			} while (p != huffmanTree.size() - 1);
			reverse(temp.begin(), temp.end()); 
			huffmanCode.push_back(temp);
		}
		for (int i = 0; i < n; ++i)
			cout << huffmanCode[i] << '\n';
	} 
	return 0;
} 


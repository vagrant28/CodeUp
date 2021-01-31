#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Node {
	int w, parent, lchild, rchild;
};

void findMinTwo(std::vector<Node>& huffman, int& min1, int& min2) {
	int i = 1, w1, w2;
	while (huffman[i++].parent != 0)
		continue;
	min1 = i - 1;
	while (huffman[i++].parent != 0)
		continue;
	min2 = i - 1;
	for ( ; i < huffman.size(); ++i) { 
		if (huffman[i].parent == 0 && huffman[i].w < std::max(huffman[min1].w, huffman[min2].w)) { 
			if (huffman[min1].w != huffman[min2].w)
				(huffman[min1].w > huffman[min2].w ? min1 : min2) = i;
			else
				(min1 > min2 ? min1 : min2) = i; 
		}
	}
	if (min1 > min2)
		std::swap(min1, min2);
} 

void print(vector<Node> HuffmanTree){
	for(int i = 0; i < HuffmanTree.size(); i++){
		printf("w=%d\tparent=%d\tlchild=%d\trchild=%d\n", HuffmanTree[i].w, HuffmanTree[i].parent, HuffmanTree[i].lchild, HuffmanTree[i].rchild);
	}
}

int main() {
	int n, input, min1, min2;
	std::vector<Node> huffmanTree;
	std::vector<std::string> huffmanCode;
	while (scanf("%d", &n) != EOF) {
		if (n == 1) {
			scanf("%d", &input);
			printf("1\n");
			continue;
		} 
		huffmanTree.clear();
		huffmanTree.resize(n + 1);
		huffmanTree[0] = {0, 0, 0, 0};
		huffmanCode.clear();
		huffmanCode.resize(n + 1);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &input);
			huffmanTree[i] = {input, 0, 0, 0};
		}
		for (int i = n + 1; i <= 2 * n - 1; ++i) {
			findMinTwo(huffmanTree, min1, min2);
			huffmanTree[min1].parent = huffmanTree[min2].parent = i;
			huffmanTree.push_back( {huffmanTree[min1].w + huffmanTree[min2].w, 0, min1, min2} );
		}
		for (int i = 1; i <= 2 * n - 1; ++i)
			huffmanTree[i].w = 0;
		int c = 2 * n - 1;
		std::string temp;
		while (c) {
			if (huffmanTree[c].w == 0) {
				huffmanTree[c].w = 1;
				if (huffmanTree[c].lchild != 0) {
					c = huffmanTree[c].lchild;
					temp += '0';
				} else if (huffmanTree[c].rchild == 0) {
					huffmanCode[c] = temp; 
				} 
			} else if (huffmanTree[c].w == 1) {
				huffmanTree[c].w = 2;
				if (huffmanTree[c].rchild != 0) {
					c = huffmanTree[c].rchild;
					temp += '1';
				} 
			} else {
				huffmanTree[c].w = 0;
				c = huffmanTree[c].parent;
				temp = temp.substr(0, temp.size() - 1);
			} 
		}
		for (int i = 1; i <= n; ++i)
			std::cout << huffmanCode[i] << '\n';
	} 
	return 0;
} 


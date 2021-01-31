#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
const int maxn = 20;

struct node{
	int data;
	node *lchild, *rchild;
};

void insert(node *&root, int x){
	if(root == NULL){
		root = new node;
		root->data = x;
		root->lchild = root->rchild = NULL;
		return;
	}
	if(root->data == x){
		return;
	}
	else if(root->data > x){
		insert(root->lchild, x);
	}
	else{
		insert(root->rchild, x);
	}
}

node *create(vector<int> v){
	node *root = NULL;
	for(int i = 0; i < v.size(); i++){
		insert(root, v[i]);
	}
	return  root;
}

void preOrder(node *root, vector<int> &v){
	if(root == NULL){
		return;
	}
	v.push_back(root->data);
	preOrder(root->lchild, v);
	preOrder(root->rchild, v);
}

void print(vector<int> v){
	for(int i = 0; i < v.size(); i++){
		printf("%d ", v[i]);
	}
	printf("\n");
	return;
}

int main(){
	int n;
	while(scanf("%d", &n), n){
		vector<int> a, b;
		char str[20];
		scanf("%s", str);
		for(int i = 0; i < strlen(str); i++){
			a.push_back(str[i] - '0');
		}
		vector<int> prea;
		node *rootA = create(a);
		preOrder(rootA, prea);
//		printf("prea:\t");
//		print(prea);
		
		while(n--){
			scanf("%s", str);
			b.clear();
			for(int i = 0; i < strlen(str); i++){
				b.push_back(str[i] - '0');
			}
			node *root = create(b);
			vector<int> preb;
			preOrder(root, preb);
//			printf("preb:\t");
//			print(preb);
			if(preb == prea){
				printf("YES\n");
			}
			else{
				printf("NO\n");
			}
		}
	}
	return 0;
}

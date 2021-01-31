#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 510;

struct node{
	int data;
	int height;
	node *lchild, *rchild;
};

node *newNode(int v){
	node *Node = new node;
	Node->data = v;
	Node->height = 1;
	Node->lchild = Node->rchild = NULL;
	return Node;
}

int getHeight(node *root){
	if(root == NULL){
		return 0;
	}
	return root->height;
}

void updateHeight(node *root){
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

int getBalanceFactor(node *root){
	return getHeight(root->lchild) - getHeight(root->rchild);
}

void L(node *&root){
	node *temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

void R(node *&root){
	node *temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

void insert(node *&root, int v){
	if(root == NULL){
		root = newNode(v);
		return;
	}
	if(v < root->data){
		insert(root->lchild, v);
		updateHeight(root);
		if(getBalanceFactor(root) == 2){
			if(getBalanceFactor(root->lchild) == 1){
				R(root);
			}
			else if(getBalanceFactor(root->lchild) == -1){
				L(root->lchild);
				R(root);
			}
		}
	}
	else{
		insert(root->rchild, v);
		updateHeight(root);
		if(getBalanceFactor(root) == -2){
			if(getBalanceFactor(root->rchild) == -1){
				L(root);
			}
			if(getBalanceFactor(root->rchild) == 1){
				R(root->rchild);
				L(root);
			}
		}
	}
}

node *create(int a[], int n){
	node *root = NULL;
//	printf("befor insert\n");
	for(int i = 0; i < n; i++){
		insert(root, a[i]);
	}
//	printf("after insert\n");
	return root;
}

void search(node *root, int v){
	if(root == NULL){
		printf("0 ");
		return;
	}
	if(root->data == v){
		printf("1 ");
		return;
	}
	else if(v < root->data){
		search(root->lchild, v);
	}
	else{
		search(root->rchild, v);
	}
}

int main(){
	int n, k;
	int seq[maxn];
	while(scanf("%d%d", &n, &k) != EOF){
		for(int i = 0; i < n; i++){
			scanf("%d", &seq[i]);
		}
		node *root = create(seq, n);
		int t;
		while(k--){
			scanf("%d", &t);
			search(root, t);
		}
		putchar('\n');
	}
	return 0;
} 

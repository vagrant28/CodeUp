#include <stdio.h>
const int maxn = 110;

struct node{
	int data;
	node *lchild, *rchild;
};

int seq[maxn], n;

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

node *create(){
	node *root = NULL;
	for(int i = 0; i < n; i++){
		insert(root, seq[i]);
	}
	return root;
}

void preOrder(node *root){
	if(root == NULL){
		return;
	}
	printf("%d ", root->data);
	preOrder(root->lchild);
	preOrder(root->rchild);
}

void inOrder(node *root){
	if(root == NULL){
		return;
	}
	inOrder(root->lchild);
	printf("%d ", root->data);
	inOrder(root->rchild);
}

void postOrder(node *root){
	if(root == NULL){
		return;
	}
	postOrder(root->lchild);
	postOrder(root->rchild);
	printf("%d ", root->data);
}

int main(){
	while(scanf("%d", &n) != EOF){
		for(int i = 0; i < n; i++){
			scanf("%d", &seq[i]);
		}
		node *root = create();
		preOrder(root);
		printf("\n");
		inOrder(root);
		printf("\n");
		postOrder(root);
		printf("\n");
	}
	return 0;
}

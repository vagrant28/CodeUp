#include <stdio.h>
#include <string.h>
const int maxn = 150;

struct node{
	char data;
	node *lchild, *rchild;
};

char seq[maxn];
int i, len;

node *create(){
	i++;
	if(i >= len){
		return NULL;
	}
	if(seq[i] == '#'){
		return NULL;
	}
	node *root = new node;
	root->data = seq[i];
	root->lchild = create();
	root->rchild = create();
	return root;
}

void inOrder(node *root){
	if(root == NULL){
		return;
	}
	inOrder(root->lchild);
	printf("%c ", root->data);
	inOrder(root->rchild);
}

int main(){
	while(scanf("%s", seq) != EOF){
		len = strlen(seq);
		i = -1;
		node *root = create();
		inOrder(root);
		printf("\n");
	}
	return 0;
}

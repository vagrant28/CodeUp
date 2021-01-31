#include <stdio.h>
#include <string.h>
using namespace std;
const int maxN = 1e3 + 10;

struct node{
	char data;
	node *lchild, *rchild;
};

char preSeq[maxN], inSeq[maxN];

node *create(int preL, int preR, int inL, int inR){
	if(preL > preR){
		return NULL;
	}
	node *root = new node;
	root->data = preSeq[preL];
	int k;
	for(k = inL; k <= inR; k++){
		if(inSeq[k] == preSeq[preL]){
			break;
		}
	}
	int numLeft = k - inL;
	root->lchild = create(preL + 1, preL + numLeft, inL, k - 1);
	root->rchild = create(preL + numLeft + 1, preR, k + 1, inR);
	return root;
}

void postOrder(node *root){
	if(root == NULL){
		return;
	}
	postOrder(root->lchild);
	postOrder(root->rchild);
	printf("%c", root->data);
}

int main(){
	while(scanf("%s%s", preSeq, inSeq) != EOF){
		int len = strlen(preSeq);
		node *root = create(0, len - 1, 0, len - 1);
		postOrder(root);
		printf("\n");
	}
	return 0;
}

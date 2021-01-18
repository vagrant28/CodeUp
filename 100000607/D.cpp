#include <stdio.h>

struct node{
	int data;
	node *next;
};

node *create(int len){
	node *h = new node;
	h->next = NULL;
	while(len--){
		node *tmp = new node;
		scanf("%d", &(tmp->data));
		if(h->next == NULL){
			tmp->next = NULL;
			h->next = tmp;
		}
		else{
			node *pre = h;
			node *p = h->next;
			while(p != NULL && p->data < tmp->data){
				pre = p;
				p = p->next;
			}
			tmp->next = p;
			pre->next = tmp;
		}
	}
	return h;
}

void show(node *h){
	node *p = h->next;
	while(p != NULL){
		printf("%d ", p->data);
		p = p->next;
	}
	putchar('\n');
	return;
}

void search(node *h, int x){
	node *pre = h;
	node *p = h->next;
	node *tmp = new node;
	tmp->data = x;
	while(p != NULL && p->data < x){
		pre = p;
		p = p->next;
	}
	if(p->data == x){
		int t = p->data;
		p->data = p->next->data;
		p->next->data = t;
	}
	else{
		tmp->next = p;
		pre->next = tmp;
		printf("no\n");
	}
	return;
}

int main(){
	int x, len;
	scanf("%d", &x);
	scanf("%d", &len);
	node *head = create(len);
//	show(head);
	search(head, x);
	show(head);
	return 0;
}

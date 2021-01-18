#include <stdio.h>

struct node{
	int data;
	node *next;
};

node *create(int n){
	node *head = new node;
	head->next = head;
	node *pre = head;
	while(n--){
		node *tmp = new node;
		int x;
		scanf("%d", &x);
		tmp->data = x;
		tmp->next = pre->next;
		pre->next = tmp;
		pre = tmp;
	}
	return head;
}

node *combine(node *h1, node *h2){
	node *p = h1;
	while(p->next != h1){
		p = p->next;
	}
	p->next = h2->next;
//	printf("%d\n", h2->next->data);
	while(p->next != h2){
		p = p->next;
	}
	p->next = h1;
	return h1;
}

void show(node *h){
	node *p = h->next;
	while(p != h){
		printf("%d ", p->data);
		p = p->next;
	}
	putchar('\n');
	return;
}

int main(){
	int n;
	scanf("%d", &n);
	node *H1 = create(n);
//	show(H1);
	scanf("%d", &n);
	node *H2 = create(n);
//	show(H2);
	combine(H1, H2);
	show(H1);
	return 0;
}

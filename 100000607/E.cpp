#include <stdio.h>

struct node{
	int data;
	node *next;
};

node *create(int len){
	node *head = new node;
	head->next = NULL;
	node *pre = head;
	while(len--){
		node *tmp = new node;
		scanf("%d", &(tmp->data));
		tmp->next = NULL;
		pre->next = tmp;
		pre = tmp;
	}
	return head;
}

void reverse(node *h){
	node *p = h->next;
	if(p->next == NULL){
		return;
	}
	else{
		p = h->next->next;
		h->next->next = NULL;
		while(p != NULL){
			node *tmp = p;
			p = p->next;
			tmp->next = h->next;
			h->next = tmp;
		}
	}
}

void show(node *h){
	node *p = h->next;
	while(p != NULL){
		printf("%d ", p->data);
		p = p->next;
	}
	putchar('\n');
}

int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		if(n == 0){
			printf("list is empty\n");
		}
		else{
			node *head = create(n);
			show(head);
			reverse(head);
			show(head);
		}
	}
	return 0;
}

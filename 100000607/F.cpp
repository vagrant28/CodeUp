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
		tmp->next = pre->next;
		pre->next = tmp;
		pre = tmp;
	}
	return head;
}

void shorten(node *h){
	if(h->next->next == NULL){
		return;
	}
	else{
		node *pre = h->next;
		node *p = pre->next;
		while(p != NULL){
			if(pre->data == p->data){
				pre->next = p->next;
				p = p->next;
			}
			else{
				pre = pre->next;
				p = p->next;
			}
		}
	}
	return;
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

int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		if(n == 0){
			printf("list is empty\n");
		}
		else{
			node *head = create(n);
			show(head);
			shorten(head);
			show(head);
		}
	}
	return 0;
}

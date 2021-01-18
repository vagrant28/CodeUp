#include <stdio.h>
#include <string.h>
int N;

struct node{
	int data;
	node *next;
};

node *create(){
	node *head, *p;
	head = new node;
	head->next = NULL;
	while(N--){
		int x;
		scanf("%d", &x);
		p = new node;
		p->data = x;
		p->next = head->next;
		head->next = p;
	}
	return head;
}

void show(node *h){
	node *p = h->next;
	if(p == NULL){
		printf("Link list is empty\n");
	}
	else{
		while(p != NULL){
			printf("%d ", p->data);
			p = p->next;
		}
		putchar('\n');
	}
	return;
}

void get(node *h, int a){
	node *p = h->next;
	int pos = 1;
	while(p != NULL){
		if(pos == a){
			printf("%d\n", p->data);
			return;
		}
		p = p->next;
		pos++;
	}
	if(p == NULL){
		printf("get fail\n");
		return;
	}
}

void del(node *h, int a){
	node *pre = h;
	node *p = h->next;
	int pos = 1;
	while(pos < a && p != NULL){
		pre = p;
		p = p->next;
		pos++;
	}
	if(p == NULL){
		printf("delete fail\n");
		return;
	}
	else{
		pre->next = p->next;
		delete(p);
		printf("delete OK\n");
		return;
	}
}

void insert(node *h, int a, int e){
	node *pre = h;
	node *p = h->next;
	int pos = 1;
	while(p != NULL){
		if(pos == a){
			break;
		}
		pre = p;
		p = p->next;
		pos++;
	}
	if(pos == a){
		node *tmp = new node;
		tmp->data = e;
		tmp->next = p;
		pre->next = tmp;
		printf("insert OK\n");
		return;
	}
	else{
		printf("insert fail\n");
	}
	return;
}

int main(){
	scanf("%d", &N);
	node *head = create();
	int m;
	scanf("%d", &m);
	while(m--){
		char query[10];
		scanf("%s", query);
		if(strcmp(query, "show") == 0){
			show(head);
		}
		else if(strcmp(query, "delete") == 0){
			int a;
			scanf("%d", &a);
			del(head, a);
		}
		else if(strcmp(query, "get") == 0){
			int a;
			scanf("%d", &a);
			get(head, a);
		}
		else if(strcmp(query, "insert") == 0){
			int a, e;
			scanf("%d%d", &a, &e);
			insert(head, a, e);
		}
	}
	return 0;
}

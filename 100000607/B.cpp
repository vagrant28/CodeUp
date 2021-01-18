#include <stdio.h>

struct node{
	int id, score;
	node *next;
};

void insert(node *h, node *t){
	if(h->next == NULL){
		t->next = NULL;
		h->next = t;
		return;
	}
	else{
		node *pre = h;
		node *p = h->next;
		while(p != NULL && p->id <= t->id){
			pre = p;
			p = p->next;
		}
		t->next = p;
		pre->next = t;
	}
	return;
}

void show(node *h){
	node *p = h->next;
	while(p != NULL){
		printf("%d::%d  ", p->id, p->score);
		p = p->next;
	}
	putchar('\n');
}

int main(){
	int N, M;
	while(scanf("%d%d", &N, &M) != EOF){
		node *head = new node;
		head->next = NULL;
		node *tmp;
		int x, y;
		int T = N + M;
		while(T--){
			scanf("%d%d", &x, &y);
			tmp = new node;
			tmp->id = x;
			tmp->score = y;
			insert(head, tmp);
//			show(head);
		}
		node *p = head->next;
		while(p != NULL){
			printf("%d %d\n", p->id, p->score);
			p = p->next;
		}
	}
	return 0;
}

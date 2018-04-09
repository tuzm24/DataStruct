#include<stdio.h>
#include<stdlib.h>

#pragma warning(disable:4996)


//헤더가 전역변수인 버전

typedef struct _node {
	struct _node *before;
	char alpha;
	struct _node *next;
}_node;


_node* header;
_node* tailer;

_node* getNode() {
	_node *temp;
	temp = (_node*)malloc(sizeof(_node));
	return temp;
}


void initList() {
	header = getNode();
	tailer = getNode();
	header->next = tailer;
	tailer->before = header;
	return;
}

_node* get_entry(int n) {
	_node* temp = header;
	for (int i = 0; i < n; i++) {
		temp = temp->next;
		if (temp == tailer) {
			printf("invalid position\n");
			temp = NULL;
			return temp;
		}
	}
	return temp;
}



_node* insertAfter(int position, char c) {
	_node* q = getNode();
	_node* p = get_entry(position);
	if (p == NULL)
		return p;
	q->alpha = c;
	q->before = p;
	q->next = p->next;
	p->next->before = q;
	p->next = q;
	return q;
}

void traverseList() {
	_node *p = header->next;
	while (p != tailer) {
		printf("%c", p->alpha);
		p = p->next;
	}
	printf("\n");
	return;
}



char Remove(int position) {
	_node *p = get_entry(position);
	if (p == NULL)
		return '\0';
	char c = p->alpha;
	p->before->next = p->next;
	p->next->before = p->before;
	free(p);
	return c;
}

int main() {
	char input;
	int num;
	int position;
	_node* temp;
	initList();
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf(" %c", &input);
		if (input == 'A') {
			scanf("%d %c", &position, &input);
			insertAfter(position - 1, input);
		}
		else if (input == 'D') {
			scanf("%d", &position);
			Remove(position);
		}
		else if (input == 'G') {
			scanf("%d", &position);
			temp = get_entry(position);
			if(temp!=NULL)
				printf("%c\n", temp->alpha);
		}
		else if (input == 'P') {
			traverseList();
		}
		else {
			break;
		}
	}
	return 0;


}


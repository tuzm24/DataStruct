#include <stdio.h>
#include <malloc.h>

#pragma warning(disable:4996)

/* ��� ��尡 �ִ� ���� ���Ḯ��Ʈ�� ����
*/





//============================================
// ���Ͽ��Ḯ��Ʈ ������ ���� �Լ�
//============================================

typedef struct _node {
	int elem;
	struct _node *next;
}_node;


_node* getNode(int elem) {
	_node* temp;
	temp = (_node*)malloc(sizeof(_node));
	temp->elem = elem;
	temp->next = NULL;
	return temp;
}


void insertLast(_node *list, int elem) {
	_node *temp = list;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = getNode(elem);
}

void printAllnode(_node *list) {
	if (list->next == NULL) 
		printf(" 0\n");
	else {
		list = list->next;
		while (list != NULL) {
			printf(" %d", list->elem);
			list = list->next;
		}
		printf("\n");
	}
}


void freeList(_node *list) {
	_node *temp = list;
	while (temp != NULL) {
		list = temp->next;
		free(temp);
		temp = list;
	}
}

// ==================================================
// �Ʒ����� ������, ������ �˰���
// ==================================================

void Union(_node *a, _node *b, _node *c) {
	a = a->next;
	b = b->next; // header ��� ����.
	while (a != NULL && b != NULL) {
		if (a->elem < b->elem) {
			insertLast(c, a->elem);
			a = a->next;
		}
		else if(a->elem > b->elem){
			insertLast(c, b->elem);
			b = b->next;
		}
		else {
			insertLast(c, a->elem);
			a = a->next;
			b = b->next;
		}
	}
	while (a != NULL) { // a�� �����ִ� ���Ұ� �ִٸ� �������� �ٿ���
		insertLast(c, a->elem);
		a = a->next;
	}
	while (b != NULL) { // b�� �����ִ� ���Ұ� �ִٸ� �������� �ٿ���
		insertLast(c, b->elem);
		b = b->next;
	}
	return;
}

void Intersect(_node *a, _node *b, _node *c) {
	a = a->next;
	b = b->next;
	while (a != NULL && b != NULL) {
		if (a->elem < b->elem)
			a = a->next;
		else if (a->elem > b->elem)
			b = b->next;
		else {
			insertLast(c, b->elem);
			a = a->next;
			b = b->next;
		}
	}
}


int main() {
	_node *list[4]; // ���� list 2��, ������, �������� ���ؼ� �� ����Ʈ�� 4���� �ʿ�
	int setsize, elem;
	for (int i = 0; i < 4; i++) 
		list[i] = getNode(-1); // list 4�� �ʱ�ȭ.
	for (int i = 0; i < 2; i++) {
		scanf("%d", &setsize);
		for (int j = 0; j < setsize; j++) { // ������ a,b list�� ���ؼ� ����Ʈ ����
			scanf("%d", &elem);
			insertLast(list[i], elem);
		}
	}
	Union(list[0], list[1], list[2]); // 3��° list header�� ������ ����Ʈ ����
	Intersect(list[0], list[1], list[3]); // 4��° list header�� ������ ����Ʈ ����
	printAllnode(list[2]); // ������ ����Ʈ ���
	printAllnode(list[3]); // ������ ����Ʈ ���
	for (int i = 0; i < 4; i++)
		freeList(list[i]); // ��� ����Ʈ ������ �Ҵ� ����
	return 0;
}
#include <stdio.h>
#include <malloc.h>

#pragma warning(disable:4996)

/* 헤더 노드가 있는 단일 연결리스트로 구현
*/





//============================================
// 단일연결리스트 구현을 위한 함수
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
// 아래부터 합집합, 교집합 알고리즘
// ==================================================

void Union(_node *a, _node *b, _node *c) {
	a = a->next;
	b = b->next; // header 노드 제외.
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
	while (a != NULL) { // a에 남아있는 원소가 있다면 나머지를 붙여줌
		insertLast(c, a->elem);
		a = a->next;
	}
	while (b != NULL) { // b에 남아있는 원소가 있다면 나머지를 붙여줌
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
	_node *list[4]; // 최초 list 2개, 교집합, 합집합을 위해서 총 리스트는 4개가 필요
	int setsize, elem;
	for (int i = 0; i < 4; i++) 
		list[i] = getNode(-1); // list 4개 초기화.
	for (int i = 0; i < 2; i++) {
		scanf("%d", &setsize);
		for (int j = 0; j < setsize; j++) { // 최초의 a,b list에 대해서 리스트 생성
			scanf("%d", &elem);
			insertLast(list[i], elem);
		}
	}
	Union(list[0], list[1], list[2]); // 3번째 list header에 합집합 리스트 생성
	Intersect(list[0], list[1], list[3]); // 4번째 list header에 교집합 리스트 생성
	printAllnode(list[2]); // 합집합 리스트 출력
	printAllnode(list[3]); // 교집합 리스트 출력
	for (int i = 0; i < 4; i++)
		freeList(list[i]); // 모든 리스트 데이터 할당 해제
	return 0;
}
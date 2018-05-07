#include <stdio.h>
#include <malloc.h>

#pragma warning(disable:4996)

/* 
	헤더 노드가 없는 단일 연결리스트로 구현.
   Single linked list without header node.
   노드의 갯수를 count 하지 않는 버전.
	ywkim@sju.ac.kr
*/


typedef struct _node {
	int elem;
	struct _node *next;
}_node;


_node* getNode(int elem){
	_node* temp;
	temp = (_node*)malloc(sizeof(_node));
	temp->elem = elem;
	temp->next = NULL; // 단일연결리스트는 노드가 NULL인지 아닌지로 마지막 노드 판별
	return temp;
}

void insertLast(_node **header, int elem) { //이중포인터를 이용한 node expand
	_node **temp = header;					// 포인터를 완벽하게 이해하고 있지 않다면, 이해하기는 어렵습니다
	while (*temp != NULL)					// 어렵다면 if문을 이용하여 header ==NULL일때 header에 새로운 노드를 만드는
		temp = &((*temp)->next);			// 예외처리를 하시는 형태로 만드시기 바랍니다.
	*temp = getNode(elem);
}

int boolSubset(_node *a, _node *b) {


	while (a != NULL && b != NULL) {
		if (a->elem < b->elem) // 현재 비교하는 A<B인 경우, 더이상 부분집합일수 없으므로 조기리턴한다. (오름차순이기때문)
			return a->elem;
		if (a->elem == b->elem) // 현재비교하는 A==B인경우 다음 A로 비교할수 있게한다.
			a = a->next;
		b = b->next;		 // B는 항상 다음것으로 비교한다.
	}
	if (a == NULL) // 부분집합
		return 0;
	return a->elem; // B == NULL
}

void freeList(_node *list) {
	_node *temp = list;
	while (temp != NULL) {
		list = temp->next;
		free(temp);
		temp = list;
	}
}

int main() {
	int n, elem;
	_node *list[2] = { NULL, NULL };
	for (int i = 0; i < 2; i++) {
		scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			scanf("%d", &elem);
			insertLast(&list[i], elem);
		}
	}
	printf("%d\n", boolSubset(list[0], list[1]));
	freeList(list[0]);
	freeList(list[1]);
	return 0;

}
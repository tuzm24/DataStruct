#include <stdio.h>
#include <malloc.h>

#pragma warning(disable:4996)

/* 
	��� ��尡 ���� ���� ���Ḯ��Ʈ�� ����.
   Single linked list without header node.
   ����� ������ count ���� �ʴ� ����.
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
	temp->next = NULL; // ���Ͽ��Ḯ��Ʈ�� ��尡 NULL���� �ƴ����� ������ ��� �Ǻ�
	return temp;
}

void insertLast(_node **header, int elem) { //���������͸� �̿��� node expand
	_node **temp = header;					// �����͸� �Ϻ��ϰ� �����ϰ� ���� �ʴٸ�, �����ϱ�� ��ƽ��ϴ�
	while (*temp != NULL)					// ��ƴٸ� if���� �̿��Ͽ� header ==NULL�϶� header�� ���ο� ��带 �����
		temp = &((*temp)->next);			// ����ó���� �Ͻô� ���·� ����ñ� �ٶ��ϴ�.
	*temp = getNode(elem);
}

int boolSubset(_node *a, _node *b) {


	while (a != NULL && b != NULL) {
		if (a->elem < b->elem) // ���� ���ϴ� A<B�� ���, ���̻� �κ������ϼ� �����Ƿ� ���⸮���Ѵ�. (���������̱⶧��)
			return a->elem;
		if (a->elem == b->elem) // ������ϴ� A==B�ΰ�� ���� A�� ���Ҽ� �ְ��Ѵ�.
			a = a->next;
		b = b->next;		 // B�� �׻� ���������� ���Ѵ�.
	}
	if (a == NULL) // �κ�����
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
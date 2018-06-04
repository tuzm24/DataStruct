//#pragma warning(disable:4996)
//#include <stdio.h>
//#include <stdlib.h>
//
///*
//�θ� ��������Ͱ� �ִ� ����Ʈ���� ����
//�ش� ���������� �θ��������Ͱ� �ʿ����� �ʽ��ϴ�.
//�ٸ� �θ��������Ͱ� �ְų� ������ ����Ʈ���� ������ ���
//�������� Ʈ������ ���ÿ����÷ο� ����
//��ȸ �� �� �� �ֽ��ϴ�.
//*/
//
//#define LEFT 0
//#define RIGHT 1
//
//typedef struct tree {
//	int elem;
//	struct tree *left;
//	struct tree *right;
//	struct tree *parent;
//}tree;
//
//tree* newExternalNode(tree *parent) {
//	tree *new_node = (tree*)malloc(sizeof(tree));
//	new_node->left = NULL;
//	new_node->right = NULL;
//	new_node->parent = parent;
//	return new_node;
//}
//
//tree* newInternalNode(tree* position, int elem) {
//	position->left = newExternalNode(position);
//	position->right = newExternalNode(position);
//	position->elem = elem;
//	return position;
//}
//
//int isExternalNode(tree *pos) {
//	if (pos->left == NULL && pos->right == NULL)
//		return 1;
//	return 0;
//}
//
//void deleteInternalNode(tree* pos) {
//	pos->elem = 0;
//	free(pos->left);
//	free(pos->right);
//	pos->left = NULL;
//	pos->right = NULL;
//	return;
//}
//
//
//void preOrder(tree *pos) {
//	printf(" %d", pos->elem);
//	if (!isExternalNode(pos->left))
//		preOrder(pos->left);
//	if (!isExternalNode(pos->right))
//		preOrder(pos->right);
//	return;
//}
//
//void inOrder(tree *pos) {
//	if (!isExternalNode(pos->left))
//		inOrder(pos->left);
//	printf(" %d", pos->elem);
//	if (!isExternalNode(pos->right))
//		inOrder(pos->right);
//	return;
//}
//
//void postOrder(tree *pos) {
//	if (!isExternalNode(pos->left))
//		postOrder(pos->left);
//	if (!isExternalNode(pos->right))
//		postOrder(pos->right);
//	printf(" %d", pos->elem);
//	return;
//}
//
//void DeleteTree(tree *pos) {
//	if (!isExternalNode(pos->left))
//		DeleteTree(pos->left);
//	if (!isExternalNode(pos->right))
//		DeleteTree(pos->right);
//	deleteInternalNode(pos);
//	return;
//}
//
//// prev  - node  - next
//// ���� ��ȸ�� ���� Ʈ�������� ť ����
//typedef struct Queue {
//	struct Queue *prev;
//	struct Queue *next;
//	struct tree *node;
//}Queue;
//
//Queue* newQueueNode(tree* tree_node) {
//	Queue *temp = (Queue*)malloc(sizeof(Queue));
//	temp->node = tree_node;
//	return temp;
//
//}
//
//void Enqueue(Queue *back, tree *tree_node) {
//	Queue* node = newQueueNode(tree_node);
//	node->prev = back;
//	node->next = back->next;
//	back->next->prev = node;
//	back->next = node;
//	return;
//}
//
//tree* Dequeue(Queue *front) {
//	if (front->prev->prev == NULL) // if Queue is Empty
//		return NULL;
//	Queue *temp = front->prev;
//	front->prev->prev->next = front;
//	front->prev = front->prev->prev;
//	tree *tree_temp;
//	tree_temp = temp->node;
//	free(temp);
//	return tree_temp;
//}
//
//void freeQueue(Queue *back) {
//	Queue *temp;
//	while (back->next->next != NULL) {
//		temp = back;
//		back = back->next;
//		free(temp);
//	}
//	return;
//}
//
//tree* fineTreeIndex(tree* root, int num) { 
//	Queue *front, *back;
//	tree *temp = NULL;
//	front = newQueueNode(NULL);
//	back = newQueueNode(NULL);
//	front->next = NULL;
//	back->prev = NULL;
//	front->prev = back;
//	back->next = front;
//	if (isExternalNode(root))
//		return NULL;
//	Enqueue(back, root);
//	for (int i = 0; i < num; i++) {
//		temp = Dequeue(front);
//		if (temp == NULL)
//			break;
//		if(!isExternalNode(temp->left))
//			Enqueue(back, temp->left);
//		if(!isExternalNode(temp->right))
//			Enqueue(back, temp->right);
//	}
//	freeQueue(back);
//	return temp;
//}
//
//
//int main() {
//	tree *root = newExternalNode(NULL);
//	int travel;
//	int num;
//	tree *temp;
//	newInternalNode(root, 20);
//	newInternalNode(root->left, 30);
//	newInternalNode(root->right, 50);
//	newInternalNode(root->left->left, 70);
//	newInternalNode(root->left->right, 90);
//	newInternalNode(root->right->right, 120);
//	newInternalNode(root->right->right->left, 130);
//	newInternalNode(root->right->right->right, 80);
//	scanf("%d%d", &travel, &num);
//	temp = fineTreeIndex(root, num);
//	if (temp == NULL)
//		printf("-1\n");
//	else if (travel == 1)
//		preOrder(temp);
//	else if (travel == 2)
//		inOrder(temp);
//	else if (travel == 3)
//		postOrder(temp);
//	DeleteTree(root);
//	free(root);
//	return 0;
//}
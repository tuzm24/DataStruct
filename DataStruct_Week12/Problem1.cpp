#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

/*  
	부모 노드포인터가 있는 이진트리로 구현
	해당 문제에서는 부모노드포인터가 필요하진 않습니다.
	다만 부모노드포인터가 있거나 쓰레드 이진트리로 구현할 경우 
	편향이진 트리에서 스택오버플로우 없이
	순회 할 수 도 있습니다.
*/

#define LEFT 0
#define RIGHT 1

typedef struct tree {
	int elem;
	struct tree *left;
	struct tree *right;
	struct tree *parent;
}tree;

tree* newExternalNode(tree *parent) {
	tree *new_node = (tree*)malloc(sizeof(tree));
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = parent;
	return new_node;
}

tree* newInternalNode(tree* position,  int elem){
	position->left = newExternalNode(position);
	position->right = newExternalNode(position);
	position->elem = elem;
	return position;
}

int isExternalNode(tree *pos) {
	if (pos->left == NULL && pos->right == NULL)
		return 1;
	return 0;
}

void deleteInternalNode(tree* pos) {
	pos->elem = 0;
	free(pos->left);
	free(pos->right);
	pos->left = NULL;
	pos->right = NULL;
	return;
}




void DeleteTree(tree *pos) {
	if (!isExternalNode(pos->left))
		DeleteTree(pos->left);
	if (!isExternalNode(pos->right))
		DeleteTree(pos->right);
	deleteInternalNode(pos);
	return;
}

void printLeftAndRight(tree *pos) {
	if (pos == NULL) {
		printf("-1\n");
		return;
	}
	printf("%d ", pos->elem);
	if (!isExternalNode(pos->left))
		printf("%d ", pos->left->elem);
	if (!isExternalNode(pos->right))
		printf("%d ", pos->right->elem);
	printf("\n");
	return;

}

int main() {
	tree* tree_array[20] = { NULL };
	tree *root = newExternalNode(NULL);
	int num;
	tree_array[1] = newInternalNode(root, 20);
	tree_array[2] = newInternalNode(tree_array[1]->left, 30);
	tree_array[3] = newInternalNode(tree_array[1]->right, 50);
	tree_array[4] = newInternalNode(tree_array[2]->left, 70);
	tree_array[5] = newInternalNode(tree_array[2]->right, 90);
	tree_array[6] = newInternalNode(tree_array[3]->right, 120);
	tree_array[7] = newInternalNode(tree_array[6]->left, 130);
	tree_array[8] = newInternalNode(tree_array[6]->right, 80);
	scanf("%d", &num);
	printLeftAndRight(tree_array[num]);
	DeleteTree(root);
	return 0;
}
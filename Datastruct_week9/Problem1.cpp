#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

// �迭�� Stack ����

#define PUSH "PUSH"
#define PRINT "PRINT"
#define UPR "UpR"
#define DOWNR "DownR"
#define POP "POP"
#define DUP "DUP"
#define PEEK "PEEK"


// top�� ��ġ�� ��Ÿ���� t�� ���������� �����ϰų�, �����ͷ� �����Ѵ�.
void pushStack(char *stack, int *t, int size, char c) {
	if (*t+1 >= size) { 
		printf("Stack FULL\n");
		return;
	}
	(*t)++;
	stack[*t] = c;
	return;
}


char popStack(char *stack, int *t) {
	if (*t < 0) { // if, t is -1 : Stack is Empty.
		printf("Stack Empty\n");
		return 0;
	}
	(*t)--;
	return stack[*t + 1];
}

char peekStack(char *stack, int t) {
	if (t < 0) {
		printf("Stack Empty\n");
		return 0;
	}
	printf("%c\n", stack[t]);
	return stack[t];
}

void upRotate(char *stack, int n, int *t) {
	int size = *t + 1;
	if (n-1 > *t) // ���ÿ� �ִ� ������ ������ �Ѿ�� Rotate�� �Ұ���
		return;
	char *temp = (char*)malloc(sizeof(char)*(n-1)); // �ӽ÷� ������ �ϳ� ����
	int temp_t = -1;
	char elem = popStack(stack, t); // �̸� �ϳ��� ���Ҹ� ���� �����Ѵ�.
	for (; temp_t < n-2; ) // n-1�� �ݺ��Ͽ� ������ ���Ҹ� pop�ϰ� �ӽ� ���ÿ� push�Ѵ�.
		pushStack(temp, &temp_t, n+1, popStack(stack, t));
	pushStack(stack, t, size, elem); // ���ÿ� �̸� ������ ���Ҹ� push�Ѵ�.
	for (; temp_t>=0;) // �ӽý����� ��� ���Ҹ� pop�Ͽ� ������ ���ÿ� push�Ѵ�.
		pushStack(stack, t, size, popStack(temp, &temp_t));
	return;
}

void downRotate(char *stack, int n, int *t) {
	int size = *t + 1;
	if (n - 1 > *t) // ���ÿ� �ִ� ������ ������ �Ѿ�� Rotate�� �Ұ���
		return;
	char *temp = (char*)malloc(sizeof(char)*(n - 1)); // �ӽ÷� ������ �ϳ� ����
	int temp_t = -1;
	for (; temp_t < n - 2; ) // n-1�� �ݺ��Ͽ� ������ ���Ҹ� pop�ϰ�, �ӽ� ���ÿ� push�Ѵ�
		pushStack(temp, &temp_t, n + 1, popStack(stack, t));
	char elem = popStack(stack, t); // �ϳ��� ���Ҹ� ���� �����Ѵ�.
	for (; temp_t >= 0;) // n-1�� �ݺ��Ͽ� �ӽý��ÿ� �ִ� ��� ���Ҹ� pop�ϰ�, ���� ���ÿ� push�Ѵ�.
		pushStack(stack, t, size, popStack(temp, &temp_t));
	pushStack(stack, t, size, elem);// ������ �ϳ��� ���Ҹ� top�� push�Ѵ�.
	return;
}

void printStack(char *stack, int *t) {
	int size = *t+1;
	char *temp = (char*)malloc(sizeof(char)*(size)); // �ӽ� ������ �����.
	int temp_t = -1;
	char c;
	for (; temp_t < (size-1);) { // ���������� �������� ��� ���Ҹ� pop�ϰ� 
		c = popStack(stack, t); //���ÿ� print �ϰ�
		printf("%c", c);		//�ӽ� ���ÿ� push�Ѵ�.
		pushStack(temp, &temp_t, size, c);
	}
	for (; *t < (size - 1);) // �ӽý��ÿ� push�ص� ���ҵ��� pop�Ͽ� ���� ���ÿ� push�Ѵ�.
		pushStack(stack, t, size, popStack(temp, &temp_t));
	printf("\n");
	return;

}

void dupStack(char *stack,int size, int *t) {
	if (*t + 1 >= size)
		return;
	char c = popStack(stack, t); // ���� �ϳ��� pop�Ѵ�.
	pushStack(stack, t, size, c); //�ش� ���Ҹ� 2�� push�Ѵ�.
	pushStack(stack, t, size, c);
	return;

}

int main() {
	int stack_size, num;
	char *stack;
	int t=-1;
	char str[10], c;
	int updownsize;
	scanf("%d%d", &stack_size, &num);
	stack = (char*)malloc(sizeof(char)*(stack_size));
	for (int i = 0; i < num; i++) {
		scanf("%s", str);
		if (!strcmp(str, PUSH)) {
			scanf(" %c", &c);
			pushStack(stack, &t, stack_size, c);
		}
		else if (!strcmp(str, POP))
			popStack(stack, &t);
		else if (!strcmp(str, PRINT))
			printStack(stack, &t);
		else if (!strcmp(str, UPR)) {
			scanf("%d", &updownsize);
			upRotate(stack, updownsize, &t);
		}
		else if (!strcmp(str, DOWNR)) {
			scanf("%d", &updownsize);
			downRotate(stack, updownsize, &t);
		}
		else if (!strcmp(str, DUP))
			dupStack(stack, stack_size, &t);
		else if (!strcmp(str, PEEK))
			peekStack(stack, t);
	}
	
}
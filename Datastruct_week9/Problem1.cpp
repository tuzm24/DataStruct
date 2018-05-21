#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

// 배열로 Stack 구현

#define PUSH "PUSH"
#define PRINT "PRINT"
#define UPR "UpR"
#define DOWNR "DownR"
#define POP "POP"
#define DUP "DUP"
#define PEEK "PEEK"


// top의 위치를 나타내는 t는 전역변수로 선언하거나, 포인터로 접근한다.
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
	if (n-1 > *t) // 스택에 있는 원소의 개수를 넘어서는 Rotate는 불가능
		return;
	char *temp = (char*)malloc(sizeof(char)*(n-1)); // 임시로 스택을 하나 생성
	int temp_t = -1;
	char elem = popStack(stack, t); // 미리 하나의 원소를 빼서 저장한다.
	for (; temp_t < n-2; ) // n-1번 반복하여 스택의 원소를 pop하고 임시 스택에 push한다.
		pushStack(temp, &temp_t, n+1, popStack(stack, t));
	pushStack(stack, t, size, elem); // 스택에 미리 빼놓은 원소를 push한다.
	for (; temp_t>=0;) // 임시스택의 모든 원소를 pop하여 기존의 스택에 push한다.
		pushStack(stack, t, size, popStack(temp, &temp_t));
	return;
}

void downRotate(char *stack, int n, int *t) {
	int size = *t + 1;
	if (n - 1 > *t) // 스택에 있는 원소의 개수를 넘어서는 Rotate는 불가능
		return;
	char *temp = (char*)malloc(sizeof(char)*(n - 1)); // 임시로 스택을 하나 생성
	int temp_t = -1;
	for (; temp_t < n - 2; ) // n-1번 반복하여 스택의 원소를 pop하고, 임시 스택에 push한다
		pushStack(temp, &temp_t, n + 1, popStack(stack, t));
	char elem = popStack(stack, t); // 하나의 원소를 빼서 저장한다.
	for (; temp_t >= 0;) // n-1번 반복하여 임시스택에 있는 모든 원소를 pop하고, 기존 스택에 push한다.
		pushStack(stack, t, size, popStack(temp, &temp_t));
	pushStack(stack, t, size, elem);// 빼놓은 하나의 원소를 top에 push한다.
	return;
}

void printStack(char *stack, int *t) {
	int size = *t+1;
	char *temp = (char*)malloc(sizeof(char)*(size)); // 임시 스택을 만든다.
	int temp_t = -1;
	char c;
	for (; temp_t < (size-1);) { // 기존스택이 빌때까지 모든 원소를 pop하고 
		c = popStack(stack, t); //동시에 print 하고
		printf("%c", c);		//임시 스택에 push한다.
		pushStack(temp, &temp_t, size, c);
	}
	for (; *t < (size - 1);) // 임시스택에 push해둔 원소들을 pop하여 원래 스택에 push한다.
		pushStack(stack, t, size, popStack(temp, &temp_t));
	printf("\n");
	return;

}

void dupStack(char *stack,int size, int *t) {
	if (*t + 1 >= size)
		return;
	char c = popStack(stack, t); // 원소 하나를 pop한다.
	pushStack(stack, t, size, c); //해당 원소를 2번 push한다.
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
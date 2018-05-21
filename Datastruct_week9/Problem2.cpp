#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#pragma warning(disable:4996)

typedef struct stack {
	char data;
	struct stack *next;
}stack;

stack* getNode(char data) {
	stack *temp = (stack*)malloc(sizeof(stack));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

int StackDataNum(stack* top) {
	int n = 0;
	while (top->next != NULL) {
		top = top->next;
		++n;
	}
	return n;
}

void pushStack(char data, stack* top) {
	stack *temp = top->next;
	top->next = getNode(data);
	top->next->next = temp;
}

char popStack(stack *top) {
	if (top->next == NULL) {
		return 0;
	}
	stack* temp = top->next->next;
	char alpa = top->next->data;
	free(top->next);
	top->next = temp;
	return alpa;
}

void freeStrack(stack *top) {
	stack *temp;
	while (top->next != NULL) {
		temp = top->next->next;
		free(top->next);
		top->next = temp;
	}
	free(top);
	return;

}






#define BRACKET_NUM 6
#define SUB_BRACKET_NUM 3
#define OPEN_BRACKET -1
#define CLOSE_BRACKET 1
#define TRUE 1
#define FALSE 0

int countBracket(char str[]) { // 문자열에서 괄호의 갯수 count
	int cnt = 0;
	const char bracket[] = "[]{}()";
	for (int i = 0; i < strlen(str); i++)
		for (int j = 0; j < BRACKET_NUM; j++)
			if (str[i] == bracket[j]) {
				cnt++;
				break;
			}
	return cnt;
}


int isBracket(char brk) {  // [{( 중하나이면 -1, ]}) 중 하나이면 1, 그 외에는 0을 리턴
	const char openbracket[] = "[{(";
	const char closebracket[] = "]})";
	for (int i = 0; i < SUB_BRACKET_NUM; i++) {
		if (openbracket[i] == brk)
			return OPEN_BRACKET;
		if (closebracket[i] == brk)
			return CLOSE_BRACKET;
	}
	return 0;
}

int isPair(char open, char close) { // 한쌍의 char형 자료가, 괄호쌍인지 검사.
	const char openbracket[] = "[{(";
	const char closebracket[] = "]})";
	for (int i = 0; i < SUB_BRACKET_NUM; i++)
		if (open == openbracket[i] && close == closebracket[i])
			return TRUE;
	return FALSE;
}

void rightOperation(char str[]) {
	stack *top = getNode(0);
	int temp;
	int numberofbracket = countBracket(str); //괄호 개수 count
	if (numberofbracket % 2 == 1) { // 괄호개수가 짝수가 아니면 Wrong.
		printf("Wrong_%d\n", numberofbracket);
		return;
	}
	for (int i = 0; i < strlen(str); i++) { //문자열의 문자들에 대해 검사.
		temp = isBracket(str[i]); //괄호이면 -1,1 아니면 0반환.
		if (temp == OPEN_BRACKET) // 문자열이 ({[ 중 하나이면
			pushStack(str[i], top); //스택에 push
		else if (temp == CLOSE_BRACKET) //문자열이 )}]중 하나이면
			if (!isPair(popStack(top), str[i])) { // 스택에서 하나를 pop하여서
				printf("Wrong_%d\n", numberofbracket); // 괄호쌍인지 검사.
				return;							//괄호쌍이 아니면 Wrong출력
			}
	}
	if (StackDataNum(top) == 0) //스택이 비어있으면 OK
		printf("OK_%d\n", numberofbracket);
	else {
		printf("Wrong_%d\n", numberofbracket); //스택이 비어있지 않으면 Wrong
	}
	freeStrack(top);
	return;

}

#define MAX_STRING_INPUT 1000


int main() {
	char buffer[MAX_STRING_INPUT + 1];
	fgets(buffer, MAX_STRING_INPUT + 1, stdin); //visual studio 2017과 gcc Compiler 호환성을 위해 fgets 사용.
	rightOperation(buffer);
	return 0;
}
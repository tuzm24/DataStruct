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

int countBracket(char str[]) { // ���ڿ����� ��ȣ�� ���� count
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


int isBracket(char brk) {  // [{( ���ϳ��̸� -1, ]}) �� �ϳ��̸� 1, �� �ܿ��� 0�� ����
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

int isPair(char open, char close) { // �ѽ��� char�� �ڷᰡ, ��ȣ������ �˻�.
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
	int numberofbracket = countBracket(str); //��ȣ ���� count
	if (numberofbracket % 2 == 1) { // ��ȣ������ ¦���� �ƴϸ� Wrong.
		printf("Wrong_%d\n", numberofbracket);
		return;
	}
	for (int i = 0; i < strlen(str); i++) { //���ڿ��� ���ڵ鿡 ���� �˻�.
		temp = isBracket(str[i]); //��ȣ�̸� -1,1 �ƴϸ� 0��ȯ.
		if (temp == OPEN_BRACKET) // ���ڿ��� ({[ �� �ϳ��̸�
			pushStack(str[i], top); //���ÿ� push
		else if (temp == CLOSE_BRACKET) //���ڿ��� )}]�� �ϳ��̸�
			if (!isPair(popStack(top), str[i])) { // ���ÿ��� �ϳ��� pop�Ͽ���
				printf("Wrong_%d\n", numberofbracket); // ��ȣ������ �˻�.
				return;							//��ȣ���� �ƴϸ� Wrong���
			}
	}
	if (StackDataNum(top) == 0) //������ ��������� OK
		printf("OK_%d\n", numberofbracket);
	else {
		printf("Wrong_%d\n", numberofbracket); //������ ������� ������ Wrong
	}
	freeStrack(top);
	return;

}

#define MAX_STRING_INPUT 1000


int main() {
	char buffer[MAX_STRING_INPUT + 1];
	fgets(buffer, MAX_STRING_INPUT + 1, stdin); //visual studio 2017�� gcc Compiler ȣȯ���� ���� fgets ���.
	rightOperation(buffer);
	return 0;
}
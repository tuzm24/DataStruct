#include <stdio.h>
#include <malloc.h>


#pragma warning(disable:4996)

typedef struct node_{ // 이중연결리스트 노드 정의
	char alpha; // 원소는 알파벳 1개
	struct node_ *before; // 이전 노드에 접근 포인터
	struct node_ *next; // 다음 노드에 접근 포인터
}; 



node_* getNode() { // 새로운 노드를 동적할당하여 반환
	node_ *new_node;
	new_node = (node_*)malloc(sizeof(node_));
	return new_node;
}

void initList(node_ **header, node_ **tailer) { // 최초에 헤더노드와 꼬리노드를 설정
	*header = getNode(); // 동적할당
	*tailer = getNode();
	(*header)->next = *tailer; // 최초에 헤더노드의 다음은 꼬리노드이다.
	(*tailer)->before = *header; // 최초에 꼬리노드의 이전은 헤더노드이다.
	return;
}





node_* insertAfter(node_ *p, char c) { // 현재 노드의 다음에 c의 알파벳을 가진 새로운 노드를 삽입
	node_ *temp;
	temp = getNode(); // 새로운 노드를 동적할당
	temp->alpha = c; // 새로운 노드의 알파벳은 c
	// 새로운 노드를 삽입할때는 포인터 연결의 순서에 유의해야한다.
	// (새로운 노드의 포인터를 먼저 설정, 기존 노드의 포인터를 갱신)
	temp->before = p; // 새로운 노드의 포인터를 먼저 설정
	temp->next = p->next;
	p->next->before = temp; // 기존의 노드의 포인터를 갱신
	p->next = temp;
	return temp;
}



char removeNode(node_ *p) { // 해당하는 노드를 삭제한다.
	char c = p->alpha;
	p->before->next = p->next;
	p->next->before = p->before;
	free(p); // 동적할당 해제를 해준다.
	return c;
}


node_* getnNode(node_ *header, node_ *tailer, int position) { // n번째 노드를 반환하는 함수.
	node_ *temp = header; // node temp를 선언했지만, 사실 header로 그대로 사용해도 무방하다.
	for (int i = 0; i < position; i++) { // n번째 까지 다다를때까지 반복한다.
		temp = temp->next;
		if (temp == tailer) { // 만약 position에 다다르기전에 리스트가 끝났을경우.
			printf("invalid position\n");
			return NULL;
		}
	}
	return temp;
}


// n번째(헤더, 꼬리 노드를 제외한)에 새로운 노드를 추가하는 함수.
void add(node_ *header, node_ *tailer, int position, char item) {
	node_ *temp;
	temp = getnNode(header, tailer, position-1); // n-1번째 뒤에 새로운 노드를 추가해야 하므로 n-1번째 노드를 가져온다.
	if(temp!=NULL)
		insertAfter(temp, item); // n-1번째 뒤에 새로운 노드를 추가.

}

// n번째 노드를 삭제하는 함수.
void _delete(node_ *header, node_ *tailer, int position) {
	node_ *temp;
	temp = getnNode(header, tailer, position); // n번째 노드를 가져온다.
	if(temp!=NULL)
		removeNode(temp); // 가져온 노드를 삭제한다.
}


// n번째 알파벳을 출력하는 함수.
char getEntry(node_ *header, node_ *tailer, int position) {
	node_ *temp;
	temp = getnNode(header, tailer, position); // n번째 노드의 주소를 가져온다.
	if (temp != NULL) { // n번째 노드가 존재하는 경우 출력한다.
		printf("%c\n", temp->alpha);
		return temp->alpha;
	}
	return '\0';
}


void printAllNode(node_ *header, node_* tailer) { // 전체 리스트를 출력하는 함수 (traverseList 와 동일)
	node_ *temp = header->next;
	while (temp != tailer) { // 꼬리노드가 되기 전까지 출력한다.
		printf("%c", temp->alpha);
		temp = temp->next;
	}
	printf("\n");
	return;
}


void freeList(node_ *header, node_* tailer) { // 전체리스트를 동적할당 해제하는 함수.
	node_ *temp = header->next;
	tailer->next = NULL;
	while (header != tailer) { // 꼬리노드가 되기 전까지 해제한다.
		free(header);
		header = temp;  // 미리 temp에 담아논 다음 노드의 주소를 가져온다.
		temp = temp->next; // temp에 다음 노드의 주소를 담는다.
	}
	free(tailer); // 하나 남아있는 꼬리노드를 동적할당 해제한다.
	return;

}


int main() {
	int n;
	char menu;
	int position;
	char input;
	node_ *header=NULL, *tailer=NULL;
	initList(&header, &tailer);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%c%c", &menu, &menu);
		if (menu == 'A') {
			scanf("%d%c%c", &position, &input, &input);
			add(header, tailer, position, input);
		}
		else if (menu == 'D') {
			scanf("%d", &position);
			_delete(header, tailer, position);
		}
		else if (menu == 'G') {
			scanf("%d", &position);
			getEntry(header, tailer, position);
		}
		else if (menu == 'P') {
			printAllNode(header, tailer);
		}
		else
			break;
	}
	freeList(header, tailer);
	return 0;


}

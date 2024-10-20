#include <stdio.h>
#include <stdlib.h>
//단일 연결리스트 규칙
//1.노드에 메모리 할당 2.next맴버에 다음 노드의 메모리 주소저장
//3.data 맴버에 data 저장 4.마지막 노드라면 next 멤버에 NULL 저장

typedef struct { //연결 리스트
	int data; //data를 저장할 맴버
	struct Node* next; //다음 노드의 주소를 저장할 포인터
} Node;

Node* head; //시작 노드

// root=들어갈 위치 , 입력데이터
void addFront(Node* root, int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = root->next; //머리 다음에 연결
	root->next = node;
}

void removeFront(Node* root) {
	Node* front = root->next;
	root->next = front->next; //현재 노드가 가르키는 것으로 연결
	free(front);
}

void freeAll(Node* root) {
	Node* cur = head->next;
	while (cur != NULL) {
		Node* next = cur->next;
		free(cur);
		cur = next;
	}
}

void showAll(Node* root) {
	Node* cur = head->next;
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

int main(void) {
	head = (Node*)malloc(sizeof(Node)); //머리 노드 생성
	head->next = NULL; //NULL로 생성
	addFront(head, 2);
	addFront(head, 1);
	addFront(head, 7);
	addFront(head, 9);
	addFront(head, 8);
	removeFront(head);
	showAll(head);
	freeAll(head);
	system("pause");
	return 0;
}
//삽입,삭제가 배열에 비해 간단함
//원소를 차례대로 검색해야함
//포인터변수를 사용하므로 메모리 공간이 낭비됨
//인덱스를 바로 참조해야 할 때는 배열이 더 효율적 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//양방향
typedef struct {
	int data;
	struct Node* prev; //앞 추가
	struct Node* next;
} Node;

Node* head, *tail; //꼬리도 추가

void insert(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	Node* cur = head->next;

	while (cur->data < data && cur != tail) { //오름차순
		cur = cur->next;
	}
	Node* prev = cur->prev;
	prev->next = node;//삽입할 노드
	node->prev = prev; //삽일 할 노드의 앞은 현재 노드의 앞 
	cur->prev = node; // 현재 노드의 앞은 삽입할 노드
	node->next = cur; //삽입할 노드의 다음이 현재 노드
}

void removeFront() {
	Node* node = head->next;
	head->next = node->next;
	Node* next = node->next;
	next->prev = head;
	free(node);
}

void show() {
	Node* cur = head->next;
	while (cur != tail) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

int main(void) {
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));
	head->next = tail; //서로가 가르킴
	head->prev = head;
	tail->next = tail;
	tail->prev = head; //서로가 가르킴
	insert(2);
	insert(1);
	insert(3);
	insert(9);
	insert(7);
	removeFront();
	show();
	system("pause");
	return 0;

	//예외상황 고려
}
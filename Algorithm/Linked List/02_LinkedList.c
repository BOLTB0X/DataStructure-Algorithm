#include <stdio.h>
#include <stdlib.h>
//단일
typedef struct {
	int data;
	struct Node* next;
} Node; //data와 다음 노드의 주소값을 갖는 구조체 선언

Node* head; //헤드 선언

int main(void) {
	head = (Node*)malloc(sizeof(Node)); //헤드 선언
	Node *node1 = (Node*)malloc(sizeof(Node));
	node1->data = 1;
	Node* node2 = (Node*)malloc(sizeof(Node));
	node2->data = 2;
	Node* node3 = (Node*)malloc(sizeof(Node));
	node3->data = 3;
	head->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	Node* cur = head->next; //current란 변수 선언
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next; //한칸 씩 넘어간다
	}
	system("pause");
	return 0;
}
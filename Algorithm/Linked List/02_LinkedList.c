#include <stdio.h>
#include <stdlib.h>
//����
typedef struct {
	int data;
	struct Node* next;
} Node; //data�� ���� ����� �ּҰ��� ���� ����ü ����

Node* head; //��� ����

int main(void) {
	head = (Node*)malloc(sizeof(Node)); //��� ����
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
	Node* cur = head->next; //current�� ���� ����
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next; //��ĭ �� �Ѿ��
	}
	system("pause");
	return 0;
}
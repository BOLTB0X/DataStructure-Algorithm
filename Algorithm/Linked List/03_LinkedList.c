#include <stdio.h>
#include <stdlib.h>
//���� ���Ḯ��Ʈ ��Ģ
//1.��忡 �޸� �Ҵ� 2.next�ɹ��� ���� ����� �޸� �ּ�����
//3.data �ɹ��� data ���� 4.������ ����� next ����� NULL ����

typedef struct { //���� ����Ʈ
	int data; //data�� ������ �ɹ�
	struct Node* next; //���� ����� �ּҸ� ������ ������
} Node;

Node* head; //���� ���

// root=�� ��ġ , �Էµ�����
void addFront(Node* root, int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = root->next; //�Ӹ� ������ ����
	root->next = node;
}

void removeFront(Node* root) {
	Node* front = root->next;
	root->next = front->next; //���� ��尡 ����Ű�� ������ ����
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
	head = (Node*)malloc(sizeof(Node)); //�Ӹ� ��� ����
	head->next = NULL; //NULL�� ����
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
//����,������ �迭�� ���� ������
//���Ҹ� ���ʴ�� �˻��ؾ���
//�����ͺ����� ����ϹǷ� �޸� ������ �����
//�ε����� �ٷ� �����ؾ� �� ���� �迭�� �� ȿ���� 
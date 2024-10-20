#include <stdio.h>
#define SIZE 10000
#define INF 99999999

int queue[SIZE];
int front = 0; //��
int rear = 0; //��

typedef struct {
	int data;
	struct Node* next;
} Node;

typedef struct {
	Node* front;
	Node* rear;
	int cnt;
} Queue; //����ü�� ť ����

void push(Queue *queue,int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	if (queue->cnt == 0) { //�ƹ��� ������
		queue->front = node; // �� ��尡 ���� ��
	}
	else {
		queue->rear->next=node; //ť�� ���� ������ ���
	}
	queue->rear = node;
	queue->cnt++;
}

void pop(Queue*queue) {
	if (queue->cnt==0) {
		printf("ť �����÷ο� �߻�\n");
		return -INF;
	}
	Node* node = queue->front;
	int data = node->data;
	queue->front = node->next;
	free(node);
	queue->cnt--;
	return data; // data ��ȯ
}

void show(Queue*queue) {
	Node* cur = queue->front;
	printf("---- ť�� �� ----\n");
	while(cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("---- ť�� �� ----\n");
}

int main(void) {
	Queue queue;
	queue.front = queue.rear = NULL;
	queue.cnt = 0;
	push(&queue, 7);
	push(&queue, 5);
	push(&queue, 4);
	pop(&queue);
	push(&queue, 6);
	pop(&queue);
	show(&queue);
	system("pause");
	return 0;
}
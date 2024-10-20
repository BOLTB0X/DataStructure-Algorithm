#include <stdio.h>
#define SIZE 10000
#define INF 99999999

int queue[SIZE];
int front = 0; //앞
int rear = 0; //뒤

typedef struct {
	int data;
	struct Node* next;
} Node;

typedef struct {
	Node* front;
	Node* rear;
	int cnt;
} Queue; //구조체로 큐 선언

void push(Queue *queue,int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	if (queue->cnt == 0) { //아무도 없으면
		queue->front = node; // 이 노드가 앞이 됌
	}
	else {
		queue->rear->next=node; //큐의 뒤의 다음이 노드
	}
	queue->rear = node;
	queue->cnt++;
}

void pop(Queue*queue) {
	if (queue->cnt==0) {
		printf("큐 오버플로우 발생\n");
		return -INF;
	}
	Node* node = queue->front;
	int data = node->data;
	queue->front = node->next;
	free(node);
	queue->cnt--;
	return data; // data 반환
}

void show(Queue*queue) {
	Node* cur = queue->front;
	printf("---- 큐의 앞 ----\n");
	while(cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("---- 큐의 뒤 ----\n");
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
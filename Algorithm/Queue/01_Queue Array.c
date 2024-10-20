#include <stdio.h>
#define SIZE 10000
#define INF 99999999

int queue[SIZE];
int front = 0; //��
int rear = 0; //��

void push(int data) {
	if (rear >= SIZE) {
		printf("ť �����÷ο� �߻�\n");
		return;
	}
	queue[rear++] = data;
}

void pop() {
	if (rear >= SIZE) {
		printf("ť �����÷ο� �߻�\n");
		return;
	}
	return queue[front++]; //���Լ���
}

void show() {
	printf("---- ť�� �� ----\n");
	for (int i = front; i < rear; i++) {
		printf("%d\n", queue[i]);
	}
	printf("---- ť�� �� ----\n");
}

int main(void) {
	push(7);
	push(5);
	push(4);
	pop();
	push(6);
	pop();
	show();
	system("pause");
	return 0;
}
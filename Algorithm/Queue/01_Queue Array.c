#include <stdio.h>
#define SIZE 10000
#define INF 99999999

int queue[SIZE];
int front = 0; //앞
int rear = 0; //뒤

void push(int data) {
	if (rear >= SIZE) {
		printf("큐 오버플로우 발생\n");
		return;
	}
	queue[rear++] = data;
}

void pop() {
	if (rear >= SIZE) {
		printf("큐 오버플로우 발생\n");
		return;
	}
	return queue[front++]; //선입선출
}

void show() {
	printf("---- 큐의 앞 ----\n");
	for (int i = front; i < rear; i++) {
		printf("%d\n", queue[i]);
	}
	printf("---- 큐의 뒤 ----\n");
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
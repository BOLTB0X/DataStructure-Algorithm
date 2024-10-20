#include <stdio.h>
#define INF 10000

int arr[INF];
int cnt = 0;

void addBack(int data) { //�迭 �ڿ� ����
	arr[cnt] = data; //cnt���� ����
	cnt++; //cnt ����
}

void addFirst(int data) { //�迭 �տ� ����
	for (int i = cnt; i >= 1; i--) {
		arr[i] = arr[i - 1]; //������ data �ε��� �� ĭ�� �ڷ� 
	}
	arr[0] = data;
	cnt++;
}
void show() { //�迭 ���� ���
	for (int i = 0; i < cnt; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void removeAt(int index) { //Ư���� ��ġ�� ���Ҹ� ����
	for (int i = index; i < cnt - 1; i++) {
		arr[i] = arr[i + 1];
	}
	cnt--;
}

int main(void) {
	addFirst(4);
	addFirst(5);
	addFirst(1);
	addBack(7);
	addBack(6);
	addBack(8);
	show();
	system("pause");
	return 0;
}
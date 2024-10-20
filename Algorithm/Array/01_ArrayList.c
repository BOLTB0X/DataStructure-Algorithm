#include <stdio.h>
#define INF 10000

int arr[INF];
int cnt = 0;

void addBack(int data) { //배열 뒤에 삽입
	arr[cnt] = data; //cnt값에 삽입
	cnt++; //cnt 증가
}

void addFirst(int data) { //배열 앞에 삽입
	for (int i = cnt; i >= 1; i--) {
		arr[i] = arr[i - 1]; //기존에 data 인덱스 한 칸씩 뒤로 
	}
	arr[0] = data;
	cnt++;
}
void show() { //배열 원소 출력
	for (int i = 0; i < cnt; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void removeAt(int index) { //특정한 위치의 원소를 삭제
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
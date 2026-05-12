#include <iostream>
using namespace std;

char board[100][100];

void print_board(int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << board[i][j] << ' ';
		cout << '\n';
	}
	return;
}

void solution(int n) {
	char alp = 'A';

	for (int i = n - 1; i >= 0; --i) {
		for (int j = n - 1; j >= 0; --j) {
			board[j][i] = alp++;
			if (alp > 'Z')
				alp = 'A';
		}
	}
	
	return;
}

int main(void) {
	int n;

	cin >> n;

	solution(n);
	
	print_board(n);

	return 0;
}
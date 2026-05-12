#include <iostream>

using namespace std;

int board[100][100];

int main(void) {
	int n;
	cin >> n;

	int number = 1;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			board[j][i] = number++;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << board[i][j] << ' ';
		cout << '\n';
	}
	return  0;
}
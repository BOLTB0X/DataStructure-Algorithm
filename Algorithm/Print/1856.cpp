#include <iostream>

using namespace std;

int board[100][100];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	int number = 1;

	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0) {
			for (int j = 0; j < m; ++j)
				board[i][j] = number++;
		}
		else {
			for (int j = m - 1; j >= 0; --j)
				board[i][j] = number++;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cout << board[i][j] << ' ';
		cout << '\n';
	}
	return  0;
}
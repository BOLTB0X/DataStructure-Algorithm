#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n;

    cin >> n;

    if (n < 1 || n > 100 || n % 2 == 0) {
        cout << "INPUT ERROR\n";
        return 0;
    }

    vector<vector<char>> board(n, vector<char>(n, ' '));
    char alp = 'A';

    for (int i = 0; i < n / 2 + 1; ++i) {
        int r = (n / 2) - i, c = (n / 2) - i;

        for (int j = 0; j < 2 * i + 1; ++j) {
            board[r + j][c] = alp++;
            if (alp > 'Z') alp = 'A';
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
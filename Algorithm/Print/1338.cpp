#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n;

    cin >> n;

    vector<vector<char>> board(n, vector<char>(n, ' '));
    char alp = 'A';

    for (int i = 0; i < n; ++i) {
        int r = i, c = n - 1;

        while (r < n && c >= 0) {
            board[r++][c--] = alp++;
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
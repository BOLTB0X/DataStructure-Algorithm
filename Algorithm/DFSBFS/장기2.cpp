// https://jungol.co.kr/problem/4189?cursor=OCw3LDA=
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct info {
    int x, y, d;
};

const int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int main(void) {
    int n, m;
    int r,c,s,k;

    cin >> n >> m;
    cin >> r >> c >> s >> k;

    vector<vector<int>> board(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> visited(n + 1, vector<int>(m + 1, false));
    board[r][c] = 1;
    board[s][k] = -1;

    int answer = 0;
    queue<info> que;
    que.push({r, c, 0});
    visited[r][c] = true;

    while (!que.empty()) {
        info cur = que.front();
        que.pop();

        if (cur.x == s && cur.y == k) {
            answer = cur.d;
            break;
        }

        for (int i = 0; i < 8; ++i) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 1 || ny < 1 || nx > n || ny > m) continue;

            if (visited[nx][ny]) continue;

            que.push({nx, ny, cur.d + 1});
            visited[nx][ny] = true;
        }
    }

    cout << answer << '\n';
    return 0;
}
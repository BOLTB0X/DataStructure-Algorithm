#include <iostream>

using namespace std;

int n,m;
int board[201][201];
int parents[201];
int plans[1001];

int Find(int x) {
    if (x != parents[x]) {
        parents[x] = Find(parents[x]);
    }
    return parents[x];
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if (x != y) {
        if (x < y)
            parents[y] = x;
        else
            parents[x] = y;
    }

    return;
}

void solution(void) {
    string answer = "YES";

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j || !board[i][j])
                continue;
            
            Union(i, j);
        }
    }

    for (int i = 1; i < m; ++i) {
        if (Find(plans[i-1]) != Find(plans[i])) {
            answer = "NO";
            break;
        }
    }

    cout << answer << '\n';
    return;
}

int main(void) {
    cin >> n;
    cin >> m;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < m; ++i) {
        cin >> plans[i];
    }

    for (int i = 0;  i <= n; ++i)
        parents[i] = i;
    
    solution();
    return 0;
}
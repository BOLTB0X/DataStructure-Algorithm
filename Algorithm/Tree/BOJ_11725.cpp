#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001

using namespace std;

void input(int &n, vector<vector<int>>& info) {
    cin >> n;
    for (int i = 0; i < n-1; ++i) {
        int a, b;

        cin >> a >> b;
        info.push_back({a, b});
    }
    return;
}

void BFS(int n, vector<int> adj[], vector<int>& node) {
    queue<int> que;
    vector<bool> visited(n+1, false);

    que.push(1);
    visited[1] = true;

    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        for (const int next: adj[cur]) {
            if (visited[next]) continue;

            node[next] = cur;
            que.push(next);
            visited[next] = true;
        }
    }

    return;

}

void solution(int n, vector<vector<int>> info) {
    vector<int> node(n+1, 0);
    vector<int> adj[MAX];

    for (const vector<int> i: info) {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }

    BFS(n, adj, node);

    for (int i = 2; i <= n; ++i)
        cout << node[i] << '\n';
    return;
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    vector<vector<int>> info;

    input(n, info);
    solution(n, info);
    return 0;
}
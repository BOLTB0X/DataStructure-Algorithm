#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<pair<int, pair<int,int>>> edges;
vector<int> parents;

void input(void) {
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int a, b, c;

        cin >> a >> b >> c;
        edges.push_back({c, { a, b }});
    }

    return;
}

int find_parents(int x) {
    if (x == parents[x]) return x;
    return parents[x] = find_parents(parents[x]);
}

void unite_parents(int x, int y) {
    x = find_parents(x);
    y = find_parents(y);

    if (x != y) {
        if (x < y)
            parents[y] = x;
        else
            parents[x] = y;
    }

    return;
}

int solution(void) {
    int answer = 0;

    parents = vector<int>(N+1, 0);
    for (int i = 0; i <= N; ++i) parents[i] = i;

    sort(edges.begin(), edges.end());

    for (const auto edge: edges) {
        int cost = edge.first;
        int from = edge.second.first;
        int to = edge.second.second;

        if (find_parents(from) != find_parents(to)) {
            unite_parents(from, to);
            answer += cost;
        }
    }

    return answer;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();
    cout << solution();

    return 0;
}
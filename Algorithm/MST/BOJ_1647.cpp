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
        edges.push_back({c, {a, b}});
    }
    return;
}

int find_parents(int x) {
    if (x == parents[x]) return x;
    return parents[x] = find_parents(parents[x]);
}

void union_parenets(int x, int y) {
    x = find_parents(x);
    y = find_parents(y);

    if (x < y) parents[y] = x;
    else parents[x] = y;
    return;
}

bool is_cycle(int x, int y) {
    x = find_parents(x);
    y = find_parents(y);

    return x == y;
}

int solution(void) {
    int total_cost = 0, max_cost = -1;

    for (int i = 0; i <= N; ++i)
        parents.push_back(i);

    sort(edges.begin(),edges.end());

    for (const auto edge: edges) {
        if (!is_cycle(edge.second.first, edge.second.second)) {
            total_cost += edge.first;
            union_parenets(edge.second.first, edge.second.second);
            max_cost = max_cost > edge.first ? max_cost : edge.first;
        }
    }

    //cout << max_cost << '\n';
    return total_cost - max_cost;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();
    cout << solution();

    return 0;
}
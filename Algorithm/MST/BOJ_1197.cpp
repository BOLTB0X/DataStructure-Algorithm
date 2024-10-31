#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int V, E;
vector<pair<int, pair<int, int>>> edges;

void input() {
    cin >> V >> E;

    for (int i = 0; i < E; ++i) {
        int from, to, cost;

        cin >> from >> to >> cost;
        edges.push_back({ cost, { from, to } });
    }

    sort(edges.begin(), edges.end());
    return;
}

int find(vector<int>& parents, int x) {
    if (x == parents[x]) return x;
    return parents[x] = find(parents, parents[x]);
}

void unite(vector<int>& parents, int x, int y) {
    x = find(parents, x);
    y = find(parents, y);

    if (x != y) {
        if (x < y)
            parents[y] = x;
        else
            parents[x] = y;
    }
    return;
}

int solution() {
    int answer = 0, cnt = 0;
    vector<int> parents(V+1, 0);

    for (int i = 1; i <= V; ++i) parents[i] = i;

    for (int i = 0; i < E; ++i) {
        if (find(parents, edges[i].second.first) != find(parents, edges[i].second.second)) {
            unite(parents, edges[i].second.first, edges[i].second.second);
            answer += edges[i].first;
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


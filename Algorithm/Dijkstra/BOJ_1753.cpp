#include<iostream>
#include<vector>
#include<queue>
#define INF 98765432

using namespace std;

int V, E, K;
vector<pair<int,int>> adj[20001];

void input(void) {
    cin >> V >> E;
    cin >> K;

    for (int i = 0; i < E; ++i) {
        int a, b, c;

        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    return;
}


void solution(void) {
    vector<int> dist(V+1, INF);
    priority_queue<pair<int,int>> pq;

    pq.push({0, K});
    dist[K] = 0;

    while(!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cost) continue;

        for (const pair<int,int> next: adj[cur]) {
            if (dist[next.first] <= cost + next.second)
                continue;

            dist[next.first] = cost + next.second;
            pq.push({-dist[next.first], next.first});
        }
    }

    for (int i = 1; i <= V; ++i) {
        if (dist[i] == INF)
            cout << "INF" << '\n';
        else
            cout << dist[i] << '\n';
    }
    return;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();
    return 0;
}
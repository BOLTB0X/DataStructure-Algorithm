#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N, M, X;
vector<pair<int,int>> adj[1001];

void input(void) {
    cin >> N >> M >> X;

    for (int i = 0; i < M; ++i) {
        int a, b, c;

        cin >> a >> b >> c;
        adj[a].push_back({ b, c });
    }

    return;
}

void dijkstra(vector<int> &dist, int x) {
    priority_queue<pair<int,int>> pq;

    pq.push({0, x});
    dist[x] = 0;

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cost) continue;

        for (const pair<int,int> next: adj[cur]) {
            if (dist[next.first] <= dist[cur] + next.second) 
                continue;
            
            dist[next.first] = dist[cur] + next.second;
            pq.push({-dist[next.first], next.first});
        }
    }

    return;
}

int solution(void) {
    int answer = -1;

    for (int i = 1; i <= N; ++i) {
        vector<int> before(N+1, 1e9);
        dijkstra(before, i);

        vector<int> after(N+1, 1e9);
        dijkstra(after, X);

        answer = answer > before[X] + after[i] ? answer : before[X] + after[i];
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
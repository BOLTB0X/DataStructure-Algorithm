#include<iostream>
#include<vector>
#include<queue>
#define INF 1e9

using namespace std;

int N, M, s, e;
vector<pair<int,int>> adj[20001];

void input(void) {
    cin >> N;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int a, b, c;

        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    cin >> s >> e;
    return;
}

int solution(void) {
    int answer = 0;
    vector<int> dist(N+1, INF);
    priority_queue<pair<int,int>> pq;
    pq.push( { 0, s });
    dist[s] = 0;

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cost) continue;

        for (const pair<int,int> next: adj[cur]) {
            if (dist[next.first] <= cost + next.second)
                continue;
            
            dist[next.first] = cost + next.second;
            pq.push({ -dist[next.first], next.first});
        }
    }

    answer = dist[e];
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
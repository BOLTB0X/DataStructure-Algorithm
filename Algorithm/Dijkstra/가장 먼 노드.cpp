#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0, max_dist = -1;
    vector<int> adj[20001], dist(n+1, 1e9);
    
    for (const vector<int> e: edge) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    
    priority_queue<pair<int,int>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if (dist[cur] < cost) continue;
        
        for (const int next: adj[cur]) {
            if (dist[next] <= dist[cur] + 1) continue;
            
            dist[next] = dist[cur] + 1;
            pq.push({-dist[next], next});
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        //cout << i << " " << dist[i] << '\n';
        if (max_dist < dist[i])
            max_dist = dist[i];
    }
        
    return count(dist.begin() + 1, dist.end(), max_dist);
}
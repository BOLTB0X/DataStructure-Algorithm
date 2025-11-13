#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;

int BFS(int n, int start);
int abs(int n);
int min(int a, int b);

int solution(int n, vector<vector<int>> wires) {
    int answer = 201;
    adj = vector<vector<int>>(n + 1, vector<int>(n+1, 0));
    
    for (const vector<int> wire: wires) {
        int a = wire[0], b = wire[1];
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    
    for (const vector<int> wire: wires) {
        adj[wire[0]][wire[1]] = 0;
        adj[wire[1]][wire[0]] = 0;
        
        int a = BFS(n, wire[0]);
        int b = BFS(n, wire[1]);
        
        answer = min(answer, abs(a-b));
        
        adj[wire[0]][wire[1]] = 1;
        adj[wire[1]][wire[0]] = 1;
    }
    
    return answer;
}

int BFS(int n, int start) {
    int res = 1;
    vector<int> visited(n + 1, false);
    queue<int> que;
    
    que.push(start);
    visited[start] = true;
    
    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        
        for (int i = 1; i <= n; ++i) {
            if (!adj[cur][i] || visited[i])
                continue;
            
            visited[i] = true;
            res++;
            que.push(i);
        }
    }
    
    return res;
}

int abs(int n) {
    return n < 0 ? -n : n;
}

int min(int a, int b) {
    return a < b ? a : b;
}
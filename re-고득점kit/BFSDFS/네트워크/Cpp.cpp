#include <string>
#include <vector>

using namespace std;

vector<bool> visited;

void dfs(int n, vector<vector<int>> computers, int cur);

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    visited = vector<bool>(n, false);
    
    for (int i = 0; i < n; ++i) {
        if (visited[i]) continue;
        
        dfs(n, computers, i);
        answer++;
    }
    return answer;
}

void dfs(int n, vector<vector<int>> computers, int cur) {
    visited[cur] = true;
    
    for (int i = 0; i < n; ++i) {
        if (!computers[cur][i])
            continue;
        if (visited[i])
            continue;
        
        dfs(n, computers, i);
    }
}
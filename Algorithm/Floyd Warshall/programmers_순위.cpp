#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int>> adj(n+1, vector<int>(n+1, 0));
    
    for (const vector<int> result: results)
        adj[result[0]][result[1]] = 1;
    
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (adj[i][k] && adj[k][j])
                    adj[i][j] = 1;
            }
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        int cnt = 0;
        for (int j = 1; j <= n; ++j) 
            if (adj[i][j] || adj[j][i]) cnt++;
        
        if (cnt == n-1) answer++;
    }
    return answer;
}
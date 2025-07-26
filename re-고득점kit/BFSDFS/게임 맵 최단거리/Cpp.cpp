#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int> > maps) {
    int n = maps.size() , m = maps[0].size();
    queue<pair<int,int>> que;
    vector<vector<int>> dist(n, vector<int>(m, 0));
    
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};
    
    que.push({0, 0});
    dist[0][0] = 1;
    
    while (!que.empty()) {
        pair<int,int> cur = que.front();
        que.pop();
        
        for (size_t i = 0; i < 4; ++i) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            
            if (maps[nx][ny] != 1 || dist[nx][ny])
                continue;
            
            que.push({nx, ny});
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
        }
    }
    
    return dist[n - 1][m - 1] == 0 ? -1 : dist[n - 1][m - 1];
}
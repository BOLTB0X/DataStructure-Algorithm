#include <string>
#include <vector>
#include <cstring>

using namespace std;

int flag = 1;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int visited[5][5];

void DFS(vector<string> place, int x, int y, int depth) {
    if (!flag) return;
    
    if (depth == 2) return;
    
    for (auto& d: dir)
    {
        int nx = x + d[0];
        int ny = y + d[1];
        
        if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) 
            continue;
        
        if (visited[nx][ny]) 
            continue;
        
        if (place[nx][ny] == 'X')
            continue;
        
        if (depth < 2 && place[nx][ny] == 'P')
        {
            flag = 0;
            return;
        }
        
        visited[nx][ny] = 1;
        DFS(place, nx, ny, depth+1);
    }
    
    return;
}

int isSafeRule(vector<string> place) {
    flag = 1;
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (place[i][j] == 'P')
            {
                memset(visited, 0, sizeof(visited));
                visited[i][j] = true;
                DFS(place, i, j, 0);
            }
            
            if (!flag) break;
        }
    }
    return flag;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (auto& place: places) 
    {
        answer.push_back(isSafeRule(place));
    }
    return answer;
}
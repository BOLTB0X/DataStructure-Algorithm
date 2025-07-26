#include <string>
#include <vector>
#include <queue>

#define MAX_SIZE 102

using namespace std;

typedef struct {
    int x, y, dist;
} Pos;

vector<vector<int>> board;

void update_board(int x1, int y1, int x2, int y2);
int bfs(int start_x, int start_y, int target_x, int target_y);

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    board = vector<vector<int>>(MAX_SIZE, vector<int>(MAX_SIZE, -1));
    
    for (const vector<int> rect: rectangle) {
        int x1 = rect[0], y1 = rect[1];
        int x2 = rect[2], y2 = rect[3];
        
        update_board(x1 * 2, y1 * 2, x2 * 2, y2 * 2);
    }
    
    return bfs(characterX * 2, characterY * 2, itemX * 2, itemY * 2);
}

void update_board(int x1, int y1, int x2, int y2) {
    for (int i = x1; i <= x2; ++i) {
        for (int j = y1; j <= y2; ++j) {
            if (i > x1 && i < x2 && j > y1 && j < y2)
                board[i][j] = 0;
            else if (board[i][j] == -1)
                board[i][j] = 1;
        }
    }
    return;
}

int bfs(int start_x, int start_y, int target_x, int target_y) {
    int res = -1;
    queue<Pos> que;
    vector<vector<bool>> visited(MAX_SIZE, vector<bool>(MAX_SIZE, false));
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};
    
    visited[start_x][start_y] = true;
    que.push({start_x, start_y, 0});
    
    while (!que.empty()) {
        Pos cur = que.front();
        que.pop();
        
        if (cur.x == target_x && cur.y == target_y) {
            res = cur.dist / 2;
            break;
        }
        
        for (size_t i = 0; i < 4; ++i) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            
            if (visited[nx][ny]) continue;
            
            if (board[nx][ny] != 1) continue;
            
            visited[nx][ny] = true;
            que.push({nx, ny, cur.dist + 1});
        }
    }
    
    return res;
}
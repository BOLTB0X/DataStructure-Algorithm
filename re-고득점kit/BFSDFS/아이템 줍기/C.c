#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 102

typedef struct {
    int x;
    int y;
    int dist;
} Pos;

int **board;
bool **visited;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

void dynamic_malloc(void);
void all_free(void);
void init_board(void);
void update_board(int x1, int y1, int x2, int y2);
int bfs(int start_x, int start_y, int target_x, int target_y);

// rectangle_row_len은 2차원 배열 rectangle의 행(세로) 길이입니다.
// rectangle_col_len은 2차원 배열 rectangle의 열(가로) 길이입니다.
// rectangle[i][j]는 rectangle의 i번째 행의 j번째 열에 저장된 값을 의미합니다.
int solution(int **rectangle, size_t rectangle_row_len, size_t rectangle_col_len, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    dynamic_malloc();
    init_board();
    
    for (size_t i = 0; i < rectangle_row_len; ++i) {
        int x1 = rectangle[i][0], y1 = rectangle[i][1];
        int x2 = rectangle[i][2], y2 = rectangle[i][3];
        update_board(x1 * 2, y1 * 2, x2 * 2, y2 * 2);
    }
    
    answer = bfs(characterX * 2, characterY * 2, itemX * 2, itemY * 2);
    answer /= 2;
    
    all_free();
    return answer;
}

void dynamic_malloc(void) {
    board = (int**)malloc(sizeof(int*) * MAX_SIZE);
    visited = (bool**)malloc(sizeof(bool*) * MAX_SIZE);
    
    for (size_t i = 0; i < MAX_SIZE; ++i)  {
        board[i] = (int*)malloc(sizeof(int) * MAX_SIZE);
        visited[i] = (bool*)malloc(sizeof(bool) * MAX_SIZE);
    }
    return;
}

void all_free(void) {
    for (size_t i = 0; i < MAX_SIZE; ++i)  {
        free(board[i]);
        free(visited[i]);
    }
    
    free(board);
    free(visited);
    return;
}

void init_board(void) {
    for (size_t i = 0; i < MAX_SIZE; ++i)  {
        for (size_t j = 0; j < MAX_SIZE; ++j) {
            board[i][j] = -1;
            visited[i][j] = false;
        }
    }
}

void update_board(int x1, int y1, int x2, int y2) {
    for (size_t i = x1; i <= x2; ++i) {
        for (size_t j = y1; j <= y2; ++j) {
            if (x1 < i && i < x2 && y1 < j && j < y2)
                board[i][j] = 0;
            
            else if (board[i][j] == -1)
                board[i][j] = 1;
        }
    }
}

int bfs(int start_x, int start_y, int target_x, int target_y) {
    int res = -1;
    Pos *que = malloc(sizeof(Pos) * (MAX_SIZE * MAX_SIZE));
    int front = 0, rear = 0;
    
    que[rear].x = start_x;
    que[rear].y = start_y;
    que[rear].dist = 0;
    rear++;
    visited[start_x][start_y] = true;
    
    while (front < rear) {
        int cx = que[front].x;
        int cy = que[front].y;
        int cd = que[front].dist;
        front++;
        
        if (cx == target_x && cy == target_y) {
            res = cd;
            break;
        }
        
        for (size_t i = 0; i < 4; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= MAX_SIZE || ny >= MAX_SIZE)
                continue;
            
            if (visited[nx][ny] || board[nx][ny] != 1)
                continue;
            
            que[rear].x = nx;
            que[rear].y = ny;
            que[rear].dist = cd + 1;
            visited[nx][ny] = true;
            rear++;
        }
    }
    
    free(que);
    return res;
}
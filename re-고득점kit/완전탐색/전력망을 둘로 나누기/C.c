#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int **adj;
int *visited;

int bfs(int n, int start);
int abs(int n);
int min(int a, int b);

// wires_rows는 2차원 배열 wires의 행 길이, wires_cols는 2차원 배열 wires의 열 길이입니다.
int solution(int n, int** wires, size_t wires_rows, size_t wires_cols) {
    int answer = n + 1;
    
    adj = (int**)malloc(sizeof(int*) * (n + 1));
    for (size_t i = 0; i <= n; ++i) {
        adj[i] = (int*)malloc(sizeof(int) * (n + 1));
        memset(adj[i], 0, sizeof(int) * (n + 1));
    }
    visited = (int*)malloc(sizeof(int) * (n + 1));
    
    for (size_t i = 0; i < wires_rows; ++i) {
        int a = wires[i][0], b = wires[i][1];
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    
    for (size_t i = 0; i < wires_rows; ++i) {
        int a = wires[i][0], b = wires[i][1];
        
        adj[a][b] = 0;
        adj[b][a] = 0;
        
        int cnt1 =  bfs(n, a);
        int cnt2 = bfs(n, b);
        
        answer = min(answer, abs(cnt1-cnt2));
        
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    
    for (size_t i = 0; i <= n; ++i) free(adj[i]);
    free(adj);
    free(visited);
    return answer;
}

int bfs(int n, int start) {
    int res = 1;
    int *que = malloc(sizeof(int) * (n + 1));
    int front = 0, rear = 0;
    
    memset(visited, 0, sizeof(int) * (n + 1));
    visited[start] = 1;
    que[rear++] = start;
    
    while (front < rear) {
        int cur = que[front++];
        
        for (size_t i = 1; i <= n; ++i) {            
            if (adj[cur][i] == 0) continue;
            
            if (visited[i]) continue;
            
            visited[i] = 1;
            que[rear++] = i;
            res++;
        }
    }
    
    free(que);
    return res;
}

int abs(int n) {
    return n < 0 ? -n : n;
}

int min(int a, int b) {
    return a < b ? a : b;
}
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int **indexs;
int total_count = 0;
int *visited;

void dfs(int n, int* arr, int depth);
int max(int a, int b);

// dungeons_rows는 2차원 배열 dungeons의 행 길이, dungeons_cols는 2차원 배열 dungeons의 열 길이입니다.
int solution(int k, int** dungeons, size_t dungeons_rows, size_t dungeons_cols) {
    int answer = -1;
    
    indexs = malloc(sizeof(int*) * 40320);
    for (size_t i = 0; i < 40320; ++i)
        indexs[i] = malloc(sizeof(int*) * dungeons_rows);
    
    visited = malloc(sizeof(int) * dungeons_rows);
    memset(visited, 0, sizeof(int) * dungeons_rows);
    
    int* arr = malloc(sizeof(int) * dungeons_rows);
    memset(arr, 0, sizeof(int) * dungeons_rows);

    dfs(dungeons_rows, arr, 0);
    
    for (size_t i = 0; i < total_count; ++i) {
        int cnt = 0, current = k;
        for (size_t j = 0; j < dungeons_rows; ++j) {
            int need = dungeons[indexs[i][j]][0];
            int used = dungeons[indexs[i][j]][1];
            if (need > current)
                break;
            current -= used;
            cnt++;
        }
        
        answer = answer > cnt ? answer : cnt;
    }
    
    free(visited);
    free(arr);
    return answer;
}

void dfs(int n, int* arr, int depth) {
    if (n == depth) {
        for (size_t i = 0; i < n; ++i) {
            indexs[total_count][i] = arr[i];
        }
        total_count++;
        return;
    }
    
    for (size_t i = 0; i < n; ++i) {
        if (visited[i]) continue;
        
        visited[i] = 1;
        arr[depth] = i;
        dfs(n, arr, depth + 1);
        visited[i] = 0;
    }
    return;
}

int max(int a, int b) {
    return a > b ? a : b;
}
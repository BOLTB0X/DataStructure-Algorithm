#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int max(int a, int b);
int min(int a, int b);

// sizes_rows는 2차원 배열 sizes의 행 길이, sizes_cols는 2차원 배열 sizes의 열 길이입니다.
int solution(int** sizes, size_t sizes_rows, size_t sizes_cols) {
    int answer[2] = {0, 0};
    
    for (size_t i = 0; i < sizes_rows; ++i) {
        int maxVal = max(sizes[i][0], sizes[i][1]);
        int minVal = min(sizes[i][0], sizes[i][1]);
        
        answer[0] = max(max(sizes[i][0], sizes[i][1]), answer[0]);
        answer[1] = max(min(sizes[i][0], sizes[i][1]), answer[1]);
    }
    
    return answer[0] * answer[1];
}

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}
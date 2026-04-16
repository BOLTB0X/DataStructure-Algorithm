// https://school.programmers.co.kr/learn/courses/30/lessons/43105?language=cpp
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), 0));
    
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < triangle.size(); ++i) {
        for (int j = 0; j <= i; ++j) {
            dp[i][j] = triangle[i][j] + max(dp[i-1][j], dp[i-1][j-1]);
        }
    }
    
    for (int i = 0; i < triangle.size(); ++i) {
        answer = max(answer, dp[triangle.size() - 1][i]);
    }
    return answer;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, const vector<vector<int>> &stickers) {
    int answer = 0;
    vector<vector<int>> dp = vector<vector<int>>(2, vector<int>(n, 0));

    dp[0][0] = stickers[0][0];
    dp[1][0] = stickers[1][0];

    for (unsigned int i = 1; i < n; ++i) {
        if (i == 1) {
            dp[0][i] = dp[1][i - 1] + stickers[0][i];
            dp[1][i] = dp[0][i - 1] + stickers[1][i];
            continue;
        }
        dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + stickers[0][i];
        dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + stickers[1][i];
    }
    answer = max(dp[0][n - 1], dp[1][n - 1]);
    return answer;
}

int main(void) {
    int T, n;

    cin >> T;
    while (T--) {
        vector<vector<int>> stickers;
        cin >> n;

        stickers = vector<vector<int>>(2, vector<int>(n, 0));
        for (unsigned int i = 0; i < 2; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                cin >> stickers[i][j];
            }
        }

        cout << solution(n, stickers) << endl;
    }
    return 0;
}
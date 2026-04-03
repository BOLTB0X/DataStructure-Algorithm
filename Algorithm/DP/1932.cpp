#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int n, answer = 0;

    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (unsigned int i = 1; i <= n; ++i) {
        int val;
        for (unsigned int j = 1; j <= i; ++j) {
            cin >> val;
            dp[i][j] = val;
        }
    }

    for (unsigned int i = 2; i <= n; ++i) {
        for (unsigned int j = 1; j <= i; ++j) {
            dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
        }
    }

    for (unsigned int j = 1; j <= n; ++j) {
        answer = max(answer, dp[n][j]);
    }

    cout << answer << endl;
    return 0;
}
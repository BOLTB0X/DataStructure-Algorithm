#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int solution(int n) {
    vector<int> dp(n + 1, INF);
    dp[1] = 0;

    if (n >= 2) {
        dp[2] = 1;
    }

    if (n >= 3) {
        dp[3] = 1;
    }

    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0) {
            dp[i] = min(dp[i] , dp[i / 2] + 1);
        }
        if (i % 3 == 0) {
            dp[i] = min(dp[i] , dp[i / 3] + 1);
        }
    }

    // for (int i = 1; i <= n; ++i) {
    //     cout << dp[i] << ' ';
    // }
    // cout << '\n';

    return dp[n];
}

int main(void) {
    int n;

    cin >> n;
    cout << solution(n) << '\n';

    return 0;
}
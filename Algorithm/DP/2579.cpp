#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> stairs) {
    vector<int> dp(n, 0);

    dp[0] = stairs[0];
    dp[1] = stairs[0] + stairs[1];
    dp[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);

    for (int i = 3; i < n; ++i) {
        dp[i] = max(dp[i - 3] + stairs[i - 1] + stairs[i], stairs[i] + dp[i - 2]);
    }

    // for (int i = 0; i < n; ++i) {
    //     cout << dp[i] << ' ';
    // }
    // cout << '\n';

    return dp[n-1];
}

int main(void) {
    int n;
    vector<int> stairs;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int input;
        cin >> input;
        stairs.push_back(input);
    }

    cout << solution(n, stairs) << '\n';
    return 0;
}
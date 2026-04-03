#include <iostream>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> dp(n + 1, 0);

    dp[1] = 1;
    dp[2] = 2;

    for (unsigned int i = 3; i <= n; ++i) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }

    return dp[n];
}

int main(void) {
    int n;
    cin >> n;
    cout << solution(n) << endl;
    return 0;
}
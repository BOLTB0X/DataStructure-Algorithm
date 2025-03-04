#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long N, long long M, vector<long long> heights) {
    long long answer = 0;

    sort(heights.begin(), heights.end());
    long long l = 0, r = heights.back();

    while (l <= r) {
        long long mid = (l + r) / 2;
        long long tot = 0;

        for (long long h: heights) {
            if (mid < h) {
                tot += (h - mid);
            }
        }

        if (tot >= M) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    answer = r;
    return answer;
}

int main(void) {
    long long N, M;
    vector<long long> heights;

    cin >> N >> M;

    heights = vector<long long>(N, 0);
    for (long long i = 0; i < N; ++i) {
        cin >> heights[i];
    }

    cout << solution(N, M, heights) << '\n';
    return 0;
}
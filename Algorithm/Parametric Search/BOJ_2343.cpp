#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int solution(int N, int M, vector<int> bluelays) {
    int answer = 0;
    int l = *max_element(bluelays.begin(), bluelays.end()); 
    int r = accumulate(bluelays.begin(), bluelays.end(), 0);

    while (l <= r) {
        int mid = (l + r) / 2;
        int tot = 0, cnt = 1;

        for (int bluelay: bluelays) {
            if (bluelay > mid) {
                cnt = M + 1;
                break;
            }

            if (bluelay + tot > mid) {
                cnt++;
                tot = 0;
            }
            tot += bluelay;
        } // for

        if (cnt > M) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    } // while

    answer = l;
    return answer;
}

int main(void) {
    int N, M;
    vector<int> bluelays;

    cin >> N >> M;
    bluelays = vector<int>(N, 0);

    for (int i = 0; i < N; ++i) {
        cin >> bluelays[i];
    }

    cout << solution(N, M, bluelays);
    return 0;
}
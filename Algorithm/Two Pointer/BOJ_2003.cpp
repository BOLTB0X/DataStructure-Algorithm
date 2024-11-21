#include<iostream>
#include<vector>

using namespace std;

int main(void) {
    int N, M;
    vector<int> seq;

    cin >> N >> M;
    seq = vector<int>(N, 0);
    for (int i = 0; i < N; ++i)
        cin >> seq[i];

    long long answer = 0;
    int s = 0, e = 0, partial_sum = 0;

    while (s <= e && e <= N) {
        if (M == partial_sum) answer++;

        if (M <= partial_sum) {
            partial_sum -= seq[s++];
        }
        else if (M > partial_sum) {
            partial_sum += seq[e++];
        }
    }

    cout << answer << '\n';
    return 0;
}
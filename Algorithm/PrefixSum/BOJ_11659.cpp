#include<iostream>
#include<vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, s, e;
    vector<int> seq;

    cin >> N >> M;
    seq = vector<int>(N, 0);
    for (int i = 0; i < N; ++i)
        cin >> seq[i];
    
    vector<int> prefix_sum(N+1, 0);
    for (int i = 1; i <= N; ++i)
        prefix_sum[i] = prefix_sum[i-1] + seq[i-1];

    for (int i = 0; i < M; ++i) {
        cin >> s >> e;

        cout << prefix_sum[e] - prefix_sum[s-1] << '\n';
    }
    return 0;
}
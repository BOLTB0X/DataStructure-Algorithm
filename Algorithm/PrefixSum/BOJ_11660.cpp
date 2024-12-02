#include<iostream>
#include<vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    int arr[1025][1025];
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> prefix_sum(N+1, vector<int>(N+1, 0));

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            prefix_sum[i][j] = arr[i-1][j-1] + (prefix_sum[i][j-1] + prefix_sum[i-1][j] - prefix_sum[i-1][j-1]);
        }
    }

    for (int i = 0; i < M; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout << prefix_sum[x2][y2] - prefix_sum[x1-1][y2] - prefix_sum[x2][y1-1] + prefix_sum[x1-1][y1-1] << '\n';
    }

    return 0;
}
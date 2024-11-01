#include<iostream>
#include<vector>

using namespace std;

int N;
int adj[101][101];

void input(void) {
    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> adj[i][j];
        }
    }
    return;
}

void solution(void) {
    vector<vector<int>> answer(N, vector<int>(N, 0));

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (adj[i][k] && adj[k][j])
                    adj[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << adj[i][j] << ' ';
        }
        cout << '\n';
    }

    return;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    input();
    solution();
    return 0;
}
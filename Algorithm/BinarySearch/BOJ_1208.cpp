#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

int N, S;
vector<int> v;
unordered_map<int,int> umap;
long long answer = 0;

void input(void) {
    cin >> N >> S;
    v = vector<int>(N);

    for (int i = 0; i < N; ++i)
        cin >> v[i];

    return;
}

void left(int i, int tot) {
    if (i == N / 2) {
        answer += umap[S - tot];
        return;
    }

    left(i + 1, tot + v[i]);
    left(i + 1, tot);
    return;
}

void right(int i, int tot) {
    if (i == N) {
        umap[tot]++;
        return;
    }

    right(i + 1, tot + v[i]);
    right(i + 1, tot);
    return;
}

void solution(void) {
    right(N/2, 0);
    left(0, 0);

    if (!S) answer--;
    return;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();
    cout << answer;
    return 0;
}
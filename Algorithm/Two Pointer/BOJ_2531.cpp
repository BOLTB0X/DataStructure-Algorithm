#include<iostream>
#include<vector>

using namespace std;

int N, d, k, c;
vector<int> seq;

void input(void) {
    cin >> N >> d >> k >> c;
    seq = vector<int>(N, 0);

    for (int i = 0; i < N; ++i)
        cin >> seq[i];
    return;
}

int solution(void) {
    int answer = 0;
    
    for (int i = 0; i < N; ++i) {
        vector<bool> visited(N+1, false);
        int cnt = 0;

        for (int j = i; j < i + k; ++j) {
            if (!visited[seq[j % N]]) {
                visited[seq[j % N]] = true;
                cnt++;
            }
        }

        cnt += (!visited[c] ? 1 : 0);
        answer = answer > cnt ? answer : cnt;
    }
    return answer;
}

int main(void) {
    input();
    cout << solution();
    return 0;
}
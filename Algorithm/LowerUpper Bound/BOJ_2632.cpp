#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

int pizza;
int n, m;
vector<int> A, B;

void input(void) {
    cin >> pizza;
    cin >> m >> n;

    for (int i = 0; i < m; ++i) {
        int a;
        cin >> a;
        A.push_back(a);
    }

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        B.push_back(a);        
    }

    return;
}

int solution(void) {
    int answer = 0;
    vector<int> a_sum(1, 0), b_sum(1, 0);

    for (int i = 0; i < m; ++i) {
        int tot = 0;
        for (int j = i; j < i + m -1; ++j) {
            tot += A[j % m];
            a_sum.push_back(tot);
        }
    }

    a_sum.push_back(accumulate(A.begin(), A.end(), 0));

    for (int i = 0; i < n; ++i) {
        int tot = 0;
        for (int j = i; j < i + n -1; ++j) {
            tot += B[j % n];
            b_sum.push_back(tot);
        }
    }

    b_sum.push_back(accumulate(B.begin(), B.end(), 0));

    sort(a_sum.begin(), a_sum.end());
    sort(b_sum.begin(), b_sum.end());

    for (const int a: a_sum) {
        int target = pizza - a;

        if (target < 0) break;

        int l = lower_bound(b_sum.begin(), b_sum.end(), target) - b_sum.begin();
        int h = upper_bound(b_sum.begin(), b_sum.end(), target) - b_sum.begin();

        answer += h - l;
    }

    return answer;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();
    cout << solution();
    return 0;
}
// 2798 블랙잭
// https://www.acmicpc.net/problem/2798
#include <iostream>

using namespace std;

int N, M;
int cards[101];

int mx(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int answer = 0;

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        cin >> cards[i];
    }

    for (int i = 0; i < N-2; ++i) 
    {
        for (int j = i+1; j < N-1; ++j) 
        {
            for (int k = j+1; k < N; ++k) 
            {
                if (cards[i]+cards[j]+cards[k] <= M)
                {
                    answer = mx(answer, cards[i]+cards[j]+cards[k]);
                }
            }
        }
    }

    cout << answer;

    return 0;
}
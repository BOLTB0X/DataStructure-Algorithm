// 1436 영화감독 숌
// https://www.acmicpc.net/problem/1436
#include <iostream>
#include <string>

using namespace std;

bool isSixSixSix(string s) {
    for (int i = 0; i < s.size()-2; ++i)
    {
        if (s[i] == '6' && s[i+1] == '6' && s[i+2] == '6') return true;
    }
    return false;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, number = 666, cnt = 0;
    cin >> N;

    while (1)
    {
        //cout << number << ' ' << cnt << '\n';
        if (isSixSixSix(to_string(number))) cnt++;

        if (N == cnt) break;
        number++;
    }

    cout << to_string(number);

    return 0;
}
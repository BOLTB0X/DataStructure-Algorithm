// https://jungol.co.kr/problem/1692
#include <iostream>

using namespace std;

int main(void) {
    int a, b;

    cin >> a >> b;

    int answer = a * b;
    while (b > 0) {
        cout << a * (b % 10) << '\n';
        b /= 10;
    }

    cout << answer << '\n';
    return 0;
}
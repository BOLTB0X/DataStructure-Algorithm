// https://jungol.co.kr/problem/1430
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int a, b, c;
    vector<int> answer(10, 0);

    cin >> a >> b >> c;

    int n = a * b * c;

    while (n) {
        answer[n % 10]++;
        n /= 10;
    }

    for (const int& a: answer) {
        cout << a << '\n';
    }

    return 0;
}
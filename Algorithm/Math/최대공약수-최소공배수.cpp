// https://jungol.co.kr/problem/1002
#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
} // gcd

long long lcm(long long a, long b) {
    return a * b / gcd(a, b);
} // lcm

int main(void) {
    int n, answer1;
    long long answer2;
    vector<int> numbers;

    cin >> n;
    numbers = vector<int>(n, 0);

    for (int i = 0; i < n; ++i) cin >> numbers[i];

    answer1 = numbers[0];
    answer2 = numbers[0];

    for (int i = 1; i < n; ++i) {
        answer1 = gcd(answer1, numbers[i]);
        answer2 = lcm(answer2, numbers[i]);
    }

    cout << answer1 << ' ' << answer2 << '\n';
    return 0;
}
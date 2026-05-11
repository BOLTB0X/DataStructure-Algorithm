// https://jungol.co.kr/problem/5545?cursor=NiwxLDc=
#include <iostream>

using namespace std;

long long gcd(long long a, long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
} // gcd

long long lcm(int a, int b) {
    if (a == 0 || b == 0) return 0;
    return (a / gcd(a, b)) * b;
} // lcm

int main(void) {
    long long P, V, K;
    long long A, B, C, D;
    cin >> P >> V >> K;

    B = K/ lcm(P+1,V+1);
    C = K/(V+1) - B; 
    D = K/(P+1) - B;
    A = K - (B + C + D);

    cout << A << ' ' << B << ' ' << C << ' ' << D << '\n';

    return 0;
}
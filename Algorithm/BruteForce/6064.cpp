// 6064 카잉 달력
// https://www.acmicpc.net/problem/6064
#include <iostream>
#include <vector>

using namespace std;

// 최대 공약수
int gcd(int a, int b) {
    if (!b) return a;

    return gcd(b, a%b); 
}

// 최소공배수
int lcm(int a, int b) {
    return (a*b) / gcd(a, b);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    int M, N, x, y;

    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        cin >> M >> N >> x >> y;
        int answer = -1;
        int destructionYear = lcm(M, N);

        for (int year = x; year <= destructionYear; year += M)
        {
            int ny = year % N;
            if (!ny) ny = N;
            
            if (ny == y) 
            {
                answer = year;
                break;
            }
        }
        cout << answer << '\n';
    }
    return 0;
}
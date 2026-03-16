//https://school.programmers.co.kr/learn/courses/30/lessons/468371
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
} // gcd

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
} // lcm

int solution(vector<vector<int>> signals) {
    int answer = -1;
    vector<int> Ts;
    int T = 1;
    
    for (const vector<int>& signal: signals) {
        Ts.push_back(signal[0] + signal[1] + signal[2]);
    }
    
    for (const int& t: Ts) {
        T = lcm(T, t);
    }
    
    //cout << T << '\n';
    for (int t = 1; t <= T; ++t) {
        bool flag = true;
        
        for (const vector<int>& signal: signals) {
            int g = signal[0];
            int y = signal[1];
            int r = signal[2];
            
            int phase = (t - 1) % (g + y + r);
            
            if (!(g <= phase && phase < g + y)) {
                flag = false;
                break;
            } 
        }
        
        if (flag) { 
            answer = t;
            //cout << t << '\n';
            break;
        }
    }
    return answer;
}
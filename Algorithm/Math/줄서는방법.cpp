// https://school.programmers.co.kr/learn/courses/30/lessons/12936
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> v;
    long long fact[21];
    
    fact[0] = 1;
    for (int i = 1; i <= 20; ++i)
    {
        fact[i] = fact[i - 1] * i;
        v.push_back(i);
    }
    
    k--;
    
    while (n > 0)
    {
        long long p = fact[n - 1]; 
        int index = k / p;
        
        answer.push_back(v[index]);
        v.erase(v.begin() + index);
        
        k %= p;
        n--;
    }
    
    return answer;
}

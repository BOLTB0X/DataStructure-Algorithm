// https://school.programmers.co.kr/learn/courses/30/lessons/142085
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = enemy.size();
    priority_queue<int> pq;
    
    for (int i = 0; i < enemy.size(); ++i)
    {
        pq.push(-enemy[i]);
        if (pq.size() > k)
        {
            int cur = -pq.top();
            pq.pop();
            
            if (n < cur)
            {
                answer = i;
                break;
            }
            n -= cur;
        }
    }
    
    return answer;
}
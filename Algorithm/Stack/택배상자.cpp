// https://school.programmers.co.kr/learn/courses/30/lessons/131704
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> order) {
    int answer = 0, cur = 1;
    vector<int> stack;
    
    for (const int ord: order) {
        while (cur <= order.size() && cur <= ord)
        {
            stack.push_back(cur++);
        }
        
        if (stack.empty() == false && stack.back() == ord)
        {
            answer++;
            stack.pop_back();
        }
        else {
            break;
        }
    }
        
    return answer;
}
// https://school.programmers.co.kr/learn/courses/30/lessons/131130
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int solution(vector<int> cards) {
    int answer = 1;
    vector<bool> checked(cards.size(), false);
    vector<int> res;
    
    for (int i = 0; i < cards.size(); ++i)
    {
        int cnt = 0;
        int idx = cards[i] - 1;
        while (checked[idx] == false)
        {
            cnt++;
            checked[idx] = true;
            idx = cards[idx] - 1;
        }
        res.push_back(cnt);
    }
    
    sort(res.begin(), res.end(), compare);
    answer = res[0] * res[1];
    return answer;
}
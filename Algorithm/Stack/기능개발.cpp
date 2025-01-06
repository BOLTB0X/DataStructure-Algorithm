#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> p, s;
    
    for (int i = progresses.size() - 1; i >= 0; --i) {
        p.push_back(progresses[i]);
        s.push_back(speeds[i]);
    }
    
    while(!p.empty()) {
        int cnt = 0;
        while (!p.empty() && p.back() >= 100) {
            p.pop_back();
            s.pop_back();
            cnt++;
        }
        
        if (cnt > 0) answer.push_back(cnt);
        
        for (int i = 0; i < p.size(); ++i) {
            p[i] += s[i];
        }
    }
    
    return answer;
}
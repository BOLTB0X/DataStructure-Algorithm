#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> score(3, 0);
    const int supoja1[5] = {1, 2, 3, 4, 5};
    const int supoja2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    const int supoja3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    for (int i = 0; i < answers.size(); ++i) {
        if (supoja1[i % 5] == answers[i])
            score[0]++;
        if (supoja2[i % 8] == answers[i])
            score[1]++;
        if (supoja3[i % 10] == answers[i])
            score[2]++;
    }
    
    int maxVal = *max_element(score.begin(), score.end());
    
    for (int i = 0; i < 3; ++i) {
        if (maxVal == score[i])
            answer.push_back(i + 1);
    }
    
    return answer;
}
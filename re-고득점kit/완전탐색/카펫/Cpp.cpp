#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for (int i = 3; i <= brown + yellow; ++i) {
        int w = (brown + yellow) / i;
        
        if (w >= i && (w - 2) * (i - 2) == yellow) {
            answer = {w, i};
            break;
        }
    }
    return answer;
}
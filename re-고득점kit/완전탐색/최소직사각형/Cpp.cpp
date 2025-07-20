#include <string>
#include <vector>

using namespace std;

int max(int a, int b);
int min(int a, int b);

int solution(vector<vector<int>> sizes) {
    vector<int> answer = {-1, -1};
    
    for (vector<int> size: sizes) {
        int maxVal = max(size[0], size[1]);
        int minVal = min(size[0], size[1]);
        
        answer[0] = max(maxVal, answer[0]);
        answer[1] = max(minVal, answer[1]);
        
    }
    
    return answer[0] * answer[1];
}

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}
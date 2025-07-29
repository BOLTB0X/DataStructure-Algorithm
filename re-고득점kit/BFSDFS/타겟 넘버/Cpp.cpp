#include <string>
#include <vector>

using namespace std;

void dfs(vector<int> arr, int target, int result, int &cnt, int depth);

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    dfs(numbers, target, 0, answer, 0);

    return answer;
}

void dfs(vector<int> arr, int target, int result, int &cnt, int depth) {
    if (depth == arr.size()) {
        cnt += (result == target ? 1 : 0);
        return;
    }
    
    dfs(arr, target, result + arr[depth], cnt, depth + 1);
    dfs(arr, target, result - arr[depth], cnt, depth + 1);
    return;
}
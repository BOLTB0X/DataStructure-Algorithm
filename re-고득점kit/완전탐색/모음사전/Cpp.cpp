#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> permutations;

void DFS(string n, int r, string cur, int depth);

int solution(string word) {
    int answer = 0;
    
    for (int i = 1; i <= 5; ++i)
        DFS("AEIOU", i, "", 0);
    
    sort(permutations.begin(), permutations.end());
    
    answer = find(permutations.begin(), permutations.end(), word) - permutations.begin() + 1;
    return answer;
}

void DFS(string n, int r, string cur, int depth) {
    if (depth == r) {
        if (find(permutations.begin(), permutations.end(), cur) == permutations.end())
            permutations.push_back(cur);
        return;
    }
    
    for (const char c : n) {
        DFS(n, r, cur + c, depth + 1);
    }
    return;
}
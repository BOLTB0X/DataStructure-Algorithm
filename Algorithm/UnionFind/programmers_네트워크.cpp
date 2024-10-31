#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int find_parents(vector<int>& parents, int x) {
    if (x == parents[x]) return x;
    return x = find_parents(parents, parents[x]);
}

void union_parents(vector<int>& parents, int x, int y) {
    x = find_parents(parents, x);
    y = find_parents(parents, y);
    
    if (x != y) {
        if (x < y) parents[y] = x;
        else parents[x] = y;
    }
    
    return;
}

int solution(int n, vector<vector<int>> computers) {
    vector<int> answer;
    vector<int> parents(n, 0);
    
    for (int i = 0; i < n; ++i) parents[i] = i;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j || !computers[i][j]) continue;
            
            union_parents(parents, i, j);
        }
    }
    
    for (int i = 0; i < n; ++i) {
        if (find(answer.begin(), answer.end(), find_parents(parents, i)) == answer.end())
            answer.push_back(i);
    }
    
    return answer.size();
}
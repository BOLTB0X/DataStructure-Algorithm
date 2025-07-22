#include <string>
#include <vector>

using namespace std;

vector<vector<int>> per;
vector<bool> visited;

void permutation(vector<int> p, int size, int depth);
int explore(vector<int> p, int k, vector<vector<int>> dungeons);

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    visited = vector<bool>(dungeons.size(), false);
    permutation({}, dungeons.size(), 0);
    
    for (const vector<int> p: per) {
        int cnt = explore(p, k, dungeons);
        answer = answer > cnt ? answer : cnt;
    }
    
    return answer;
}

void permutation(vector<int> p, int size, int depth) {
    if (size == depth) {
        per.push_back(p);
        return;
    }
    
    for (int i = 0; i < size; ++i) {
        if (visited[i]) continue;
        
        visited[i] = true;
        p.push_back(i);
        permutation(p, size, depth + 1);
        p.pop_back();
        visited[i] = false;
    }
    return;
}

int explore(vector<int> p, int k, vector<vector<int>> dungeons) {
    int cnt = 0;
    
    for (const int idx : p) {
        if (k < dungeons[idx][0])
            break;
        k -= dungeons[idx][1];
        cnt++;
    }
    
    return cnt;
}
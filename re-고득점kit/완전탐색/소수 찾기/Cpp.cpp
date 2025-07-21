#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> per;
vector<bool> visited;

void DFS(string numbers, string cur, int level, int depth);
bool is_prime(int n);

int solution(string numbers) {
    int answer = 0;
    
    for (int i = 1; i <= numbers.size(); ++i) {
        visited = vector<bool>(numbers.size(), false);
        DFS(numbers, "", i, 0);
    }
    
    for (const int p : per)
        if (is_prime(p)) answer++;
    
    return answer;
}

void DFS(string numbers, string cur, int level, int depth) {
    if (depth == level) {
        if (find(per.begin(), per.end(), stoi(cur)) == per.end())
            per.push_back(stoi(cur));
        return;
    }
    
    for (int i = 0; i < numbers.size(); ++i) {
        if (visited[i]) continue;
        
        visited[i] = true;
        DFS(numbers, cur + numbers[i], level, depth + 1);
        visited[i] = false;
    }
    
    return;
}

bool is_prime(int n) {
    if (n == 0 || n == 1) return false;
    
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}
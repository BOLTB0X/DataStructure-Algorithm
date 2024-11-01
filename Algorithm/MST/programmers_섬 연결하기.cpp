#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int from, to, cost;
    
    bool operator<(Node& n) {
        return this->cost < n.cost;
    }
};

int find_parents(vector<int>& parents, int x) {
    if (x == parents[x]) return x;
    return parents[x] = find_parents(parents, parents[x]);
}

void union_parents(vector<int>& parents, int x, int y) {
    x = find_parents(parents, x);
    y = find_parents(parents, y);
    
    if (x == y) return;
    
    if (x < y) parents[y] = x;
    else parents[x] = y;
    return;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<int> parents(n+1, 0);
    vector<Node> edges;
    
    for (auto info: costs) {
        int from = info[0], to = info[1], cost = info[2];
        edges.push_back({from, to, cost});
    }
    
    for (int i = 1; i <= n; ++i) parents[i] = i;
    
    sort(edges.begin(), edges.end());
    for (const Node edge: edges) {
        if (find_parents(parents, edge.from) != find_parents(parents, edge.to)) {
            union_parents(parents, edge.from, edge.to);
            answer += edge.cost;
        }
    }
    
    // for (int i = 0; i < n; ++i) {
    //     cout << i << " : " << parents[i] << '\n';
    // }
    return answer;
}

int main(void) {
    cout << solution(4, {{0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8}});
}
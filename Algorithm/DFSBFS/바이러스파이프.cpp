#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> totalCase;

void permutation(const vector<int>& arr, vector<int> per, int depth, int k) {
    if (k == per.size()) {
        totalCase.push_back(per);
        return;
    }
    
    for (int i = 0; i < arr.size(); ++i) {
        per.push_back(arr[i]);
        permutation(arr, per, i + 1, k);
        per.pop_back();
    }
    return;
} // permutation

int simulate(int start, const vector<vector<pair<int,int>>>& adj, const vector<int>& per) {
    vector<bool> infected(adj.size() + 1, false);
    infected[start] = true;

    for (int pipe : per) {
        queue<int> q;

        for (int i = 1; i <= adj.size(); ++i) {
            if (infected[i]) {
                q.push(i);
            }
        }

        vector<bool> visited(adj.size(), false);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (auto [next, p] : adj[cur]) {
                if (p != pipe) continue;
                if (infected[next]) continue;

                infected[next] = true;
                q.push(next);
            }
        } // while
    }

    int count = 0;
    for (int i = 1; i < infected.size(); ++i) {
        if (infected[i]) count++;
    }

    return count;
}

int solution(int n, int infection, vector<vector<int>> edges, int k) {
    int answer = 0;
    vector<vector<pair<int,int>>> adj(n + 1);
    
    for (const vector<int>& edge: edges) {
        adj[edge[0]].push_back({edge[1], edge[2]});
        adj[edge[1]].push_back({edge[0], edge[2]});
    }
    // cout << pipeCount << '\n';
    // for (int i = 1; i <= n; ++i) {
    //     cout << i << '\n';
    //     for (const auto& inf: adj[i]) {
    //         cout << inf.first << ' ' << inf.second << '\n';
    //     }
    //     cout << '\n';
    // }
    
    permutation({1, 2, 3}, {}, 0, k);
    
    for (auto& per : totalCase) {
        int result = simulate(infection, adj, per);
        //cout << result << '\n';
        answer = max(answer, result);
    }

    return answer;
}
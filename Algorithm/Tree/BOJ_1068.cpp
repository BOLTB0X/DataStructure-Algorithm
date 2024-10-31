#include <iostream>
#include <vector>

using namespace std;

int answer = 0;

void input(int &n, vector<int> &node, int &deleted_node) {
    cin >> n;

    node = vector<int>(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> node[i];
    
    cin >> deleted_node;
    return;
}

bool DFS(vector<int> tree[], int node, int deleted_node) {
    if (node == deleted_node)
        return false;
    
    if (tree[node].empty())  {
        answer++;
        return true;
    }

    for (const int child: tree[node]) {
        int flag = DFS(tree, child, deleted_node);

        if (!flag && tree[node].size() == 1) 
            answer++;
    }
    
    return true;
}

void solution(int &n, vector<int> &node, int &deleted_node) {
    int answer = 0, root;
    vector<int> tree[51];
    vector<bool> visited(n, false);

    for (int i = 0; i < n; ++i) {
        if (node[i] == -1) 
            root = i;
        else 
            tree[node[i]].push_back(i);
    }

    DFS(tree, root, deleted_node);

    return;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, deleted_node;
    vector<int> node;
    
    input(n, node, deleted_node);
    solution(n, node, deleted_node);
    cout << answer;
    return 0;
}
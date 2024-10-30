#include <iostream>
#include <vector>

using namespace std;

void input(int& n, vector<pair<int,int>>& tree) {
    char node, left, right;
    cin >> n;

    tree = vector<pair<int, int>> (n, {-1, -1});

    for (int i = 0; i < n; ++i) {
        cin >> node >> left >> right;

        node = node - 'A';
        if (left != '.') {
            tree[node].first = left - 'A';
        }

        if (right != '.') {
            tree[node].second = right - 'A';
        }
    }
    return;
}

void preorder(int node, vector<pair<int,int>>tree) {
    if (node == -1) return;

    cout << (char)(node + 'A');
    preorder(tree[node].first, tree);
    preorder(tree[node].second, tree);
    return;
}

void inorder(int node, vector<pair<int,int>>tree) {
    if (node == -1) return;

    inorder(tree[node].first, tree);
    cout << (char)(node + 'A');
    inorder(tree[node].second, tree);
    return;
}

void postorder(int node, vector<pair<int,int>>tree) {
    if (node == -1) return;

    postorder(tree[node].first, tree);
    postorder(tree[node].second, tree);
    cout << (char)(node + 'A');
    return;
}

int main(void) {
    int n;
    vector<pair<int,int>> tree;

    input(n, tree);
    preorder(0, tree);
    cout << '\n';
    inorder(0, tree);
    cout << '\n';
    postorder(0, tree);

    // for (auto t : tree) {
    //     cout << t.first << ' ' << t.second << '\n';
    // }
    return 0;
}
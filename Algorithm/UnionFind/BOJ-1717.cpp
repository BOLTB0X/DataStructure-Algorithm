#include <iostream>

using namespace std;

int n, m;
int parents[1000001];

int Find(int x) {
    if (x != parents[x])
        parents[x] = Find(parents[x]);
    return parents[x];
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if (x != y) {
        if (x < y)
            parents[y] = x;
        else
            parents[x] = y;
    }

    return;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i <= n; ++i)
        parents[i] = i;

    for (int i = 0; i < m; ++i) {
        int c, a, b;

        cin >> c >> a >> b;

        if (!c) {
            Union(a, b);
        }
        else {
            if (Find(a) == Find(b)) {
                cout << "YES\n";
            } 
            else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}

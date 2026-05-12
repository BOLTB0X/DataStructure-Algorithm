#include <iostream>
#include <iomanip>

using namespace std;

int main(void) {
    int n,m;

    while (1) {
        cin >> n >> m;

        if (n < 2 || m < 2 || n > 9 || m > 9)
        {
            cout << "INPUT ERROR!\n";
            continue; 
        }

        if (n < m) {
            for (int i = n; i <= m; ++i) {
                for (int j = 1; j <= 9; ++j) {
                    cout << i << " * " << j << " = " << setw(2) << j * i;
                    cout << "   ";
                    if (j % 3 == 0) {
                        cout << '\n';
                    }
                }
                cout << '\n';
            }
        } else {
            for (int i = n; i >= m; --i) {
                for (int j = 1; j <= 9; ++j) {
                    cout << i << " * " << j << " = " << setw(2) << j * i;
                    cout << "   ";
                    if (j % 3 == 0) {
                        cout << '\n';
                    }
                }
                cout << '\n';
            }
        }
        break;
    }
    return 0;
}